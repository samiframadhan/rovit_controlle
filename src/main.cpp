#include <includes.h>

ros::NodeHandle nh;
MPU6050 imu;
ESP32Encoder left_encoder;
ESP32Encoder right_encoder;

sensor_msgs::Imu imu_msg;
rospy_tutorials::Floats debug_msg;
std_msgs::Header debug_header;
rovit_navsys::debug debug_message;


//Debug variables
int statusLedPin = 2;
short successCount = 0;
char noVelDataCount = 0;
short cmdVelNoDataMillis;
short cmdVelLastMillis;
short cmdVelTimeout = 0;
bool timeout;

//PID Setting Variables
const float PID_Left_Param[3] = {0.3055939155039545, 9.86003191826279, 0.0};
// opsi lain gain 0.22459699617741438, 7.246654591938676 adjust here https://pidtuner.com/#/DxuRkeRLrY
const float PID_Right_Param[3] = {0.5240459349708211, 9.21523683674757, 0.0};

double leftPIDOut, rightPIDOut, leftSpeed, rightSpeed, leftSetpoint, rightSetpoint;
float debug_array[7];
float tempLSpeed, tempRSpeed;

PID PIDLeftMotor(&leftSpeed, &leftPIDOut, &leftSetpoint, PID_Left_Param[0], PID_Left_Param[1], PID_Left_Param[2], DIRECT);
PID PIDRightMotor(&rightSpeed, &rightPIDOut, &rightSetpoint, PID_Right_Param[0], PID_Right_Param[1], PID_Right_Param[2], DIRECT);

Quaternion imuQ;
VectorInt16 aa;
VectorInt16 gyro;
VectorInt16 aaReal;
VectorInt16 aaWorld;
VectorFloat gravity;

void calibCb(const std_msgs::Empty& cal_mode);
void cmdVelCb(const geometry_msgs::Twist& cmd_vel);
void imu_calibration_routine();
void measureSpeed();
float SpeedtoPWM(float speed, int motor);
float SpeedtoPWM(float speed, int motor, float correction);

ros::Subscriber <geometry_msgs::Twist> cmdVel("cmd_vel", cmdVelCb);
ros::Subscriber <std_msgs::Empty> calib_f("imu/calibration", calibCb);

ros::Publisher imu_pub("imu/data_raw", &imu_msg);
ros::Publisher debug_pub("debug/data", &debug_message);

void statusLedSetup(){
  ledcSetup(2, 2000, 8);
  ledcAttachPin(statusLedPin, 2);
}

void safetyCmdVelWD(){
  cmdVelNoDataMillis++;
  if(cmdVelNoDataMillis > 100){
    cmdVelTimeout += millis() - cmdVelLastMillis;
    cmdVelLastMillis = millis();
  }
  if (cmdVelTimeout > 100)
  {
    timeout = true;
  }
  else
  {
    timeout = false;
  }
  
  
}

void statusLed(bool isConnected){
  if(isConnected){
    successCount++;
    ledcWrite(2, abs(successCount));
    if (successCount > 250)
    {
      successCount = -successCount;
    }
  }
  else
  {
    successCount = 0;
    ledcWrite(2, 0);
  }
  
}

void calibCb(const std_msgs::Empty& cal_mode){
  imu_calibration_routine();
}

void cmdVelCb(const geometry_msgs::Twist& cmd_vel){
  leftSetpoint = cmd_vel.linear.x - cmd_vel.angular.z * (wheelbase / 2);
  rightSetpoint = cmd_vel.linear.x + cmd_vel.angular.z * (wheelbase / 2);
  cmdVelNoDataMillis = 0;
}

void imu_calibration_routine(){
  imu_calibration_mode = true;
  nh.logwarn("IMU IS CALIBRATING. DONT MOVE");
  nh.spinOnce();
  imu.CalibrateAccel(6);
  imu.CalibrateGyro(6);
  imu_calibration_mode = false;
  nh.logdebug("IMU Have been Calibrated");
  nh.spinOnce();
}

void update_debug(){
  measureSpeed();
  debug_array[0] = leftSetpoint;
  debug_array[1] = rightSetpoint;
  debug_array[2] = leftPIDOut;
  debug_array[3] = rightPIDOut;
  debug_array[4] = 0.01;
  debug_message.data = debug_array;
  debug_message.leftSpeed = leftSpeed;
  debug_message.rightSpeed = rightSpeed;
  debug_message.data_length = 5;
  debug_message.header.stamp = nh.now();
  debug_pub.publish(&debug_message);
  nh.spinOnce();
}

float calculateSpeed(long count, long time){
  float speed = (((count/encoder_cpr)/wheel_gear_ratio) * PI  * wheel_dia) * (1000 / time);
  return speed;
}

void motor_setup(){
  left_encoder.attachHalfQuad(ENCODER_PINS[0], ENCODER_PINS[1]);
  right_encoder.attachHalfQuad(ENCODER_PINS[2], ENCODER_PINS[3]);
  for (int i = 0; i < 4; i++)
  {
    pinMode(MOTOR_PINS[i], OUTPUT);
  }
  ledcSetup(0, 2000, 8);
  ledcSetup(1, 2000, 8);
  ledcAttachPin(MOTOR_PINS[4], 0);
  ledcAttachPin(MOTOR_PINS[5], 1);
  PIDLeftMotor.SetMode(AUTOMATIC);
  PIDRightMotor.SetMode(AUTOMATIC);
  PIDLeftMotor.SetSampleTime(95);
  PIDRightMotor.SetSampleTime(95);
  PIDLeftMotor.SetOutputLimits(-0.7, 0.7);
  PIDRightMotor.SetOutputLimits(-0.7, 0.7);
}

void measureSpeed(){
  left_encoder.pauseCount();
  right_encoder.pauseCount();
  leftSpeed = calculateSpeed(left_encoder.getCount(), 10);
  rightSpeed = calculateSpeed(right_encoder.getCount(), 10);
  left_encoder.clearCount();
  right_encoder.clearCount();
  left_encoder.resumeCount();
  right_encoder.resumeCount(); 

  /*
  if(pauseMeasurement){
    //Dont change left&right speed
  }
  else{
    leftSpeed = calculateSpeed(left_encoder.getCount(), 10)
    rightSpeed = calculateSpeed(right_encoder.getCount(), 10)
  }
   */
}

void setMotorPWM(short PWM, bool left){
  if (PWM >0)
  {
    if (left)
    {
      digitalWrite(MOTOR_PINS[0], HIGH);
      digitalWrite(MOTOR_PINS[1], LOW);
      ledcWrite(0, PWM);
    }
    else
    {
      digitalWrite(MOTOR_PINS[2], HIGH);
      digitalWrite(MOTOR_PINS[3], LOW);
      ledcWrite(1, PWM);
    }
  }
  else
  {
    if (left)
    {
      digitalWrite(MOTOR_PINS[0], LOW);
      digitalWrite(MOTOR_PINS[1], HIGH);
      ledcWrite(0, abs(PWM));
    }
    else
    {
      digitalWrite(MOTOR_PINS[2], LOW);
      digitalWrite(MOTOR_PINS[3], HIGH);
      ledcWrite(1, abs(PWM));
    }
  }
  
  if(PWM == 0)
  {
    if (left)
    {
      digitalWrite(MOTOR_PINS[0], HIGH);
      digitalWrite(MOTOR_PINS[1], HIGH);
      ledcWrite(0, brakeDuty);
    }
    else
    {
      digitalWrite(MOTOR_PINS[2], HIGH);
      digitalWrite(MOTOR_PINS[3], HIGH);
      ledcWrite(0, brakeDuty);
    }
  }
  // else if (timeout == true)
  // {
  //   for (char i = 0; i < 4; i++)
  //   {
  //     digitalWrite(MOTOR_PINS[i], HIGH);
  //   }
  //   ledcWrite(0, brakeDuty);
  //   ledcWrite(1, brakeDuty);
  // }
  
}

void motor_run(){
  /* Compute speed
   * Compute PID
   * Compute Speed to PWM
   * Execute PWM
   */
  float Left_PWM;
  float Right_PWM;
  // pauseMeasurement = true;
  PIDLeftMotor.Compute();
  PIDRightMotor.Compute();
  // pauseMeasurement = false;
  
  Left_PWM = SpeedtoPWM(leftSetpoint, 0, leftPIDOut);
  // Left_PWM = SpeedtoPWM(leftSetpoint, 0);
  Right_PWM = SpeedtoPWM(rightSetpoint, 1, rightPIDOut);
  // Right_PWM = SpeedtoPWM(rightSetpoint, 1);

  setMotorPWM(Left_PWM, 1);
  setMotorPWM(Right_PWM, 0);

  if(leftSetpoint == 0){
    setMotorPWM(0, 1);
  }
  else{
    setMotorPWM(Left_PWM, 1); 
  }

  if(rightSetpoint == 0){
    setMotorPWM(0, 0);
  }
  else{
    setMotorPWM(Right_PWM, 0);
  }
}

float SpeedtoPWM(float speed, int motor){
  float PWM;
  if(speed>0){
    PWM = (speed + min_speed[motor])/speed_to_pwm[motor];
    // PWM = speed * 25;
  }
  else
  {
    PWM = (speed - min_speed[motor+2])/speed_to_pwm[motor+2];
    // PWM = speed * 25;
  }
  return PWM;
}

float SpeedtoPWM(float speed, int motor, float correction){
  int PWM;
  if(speed>0){
    PWM = (speed + correction + min_speed[motor])/speed_to_pwm[motor];
  }
  else
  {
    PWM = (speed + correction - min_speed[motor+2])/speed_to_pwm[motor+2];
  }
  return PWM;
}

void dmpDataReady(){
  imuInterruptReady = true;
}

void setIMUOffsets(){
  imu.setXGyroOffset(imu_offsets[0]);
  imu.setYGyroOffset(imu_offsets[1]);
  imu.setZGyroOffset(imu_offsets[2]);
  imu.setXAccelOffset(imu_offsets[3]);
  imu.setYAccelOffset(imu_offsets[4]);
  imu.setZAccelOffset(imu_offsets[5]);
}

void imu_setup(){
  nh.spinOnce();
  Wire.begin();
  Wire.setClock(400000);
  imu.initialize();
  pinMode(imu_int_pin, INPUT);
  imuDevStatus = imu.dmpInitialize();
  setIMUOffsets();
  if(imuDevStatus == 0){
    imu.CalibrateAccel(6);
    imu.CalibrateGyro(6);
    imu.setDMPEnabled(true);
    // attachInterrupt(imu_int_pin, dmpDataReady, RISING);
    // imuInterruptStatus = imu.getIntStatus();
    dmpReady = true;
    // imuPacketSize = imu.dmpGetFIFOPacketSize();
    imu_msg.header.frame_id = "imu_link";
  }
  else
  {
    dmpReady = true;
    /* Error!, if
     * devstatus == 1; initial memory failed
     * devstatus == 2; DMP Config updates failed
     */
  }
  
}

void imu_update(){
  if(imu_calibration_mode == true){  
    nh.loginfo("Imu is not updating due to calibration");
    nh.spinOnce();
  }
  else
  {
    if (!dmpReady)
    {
      nh.loginfo("IMU Not Ready yet");
      nh.spinOnce();
      return;
    }
    else
    {
      if (imu.dmpGetCurrentFIFOPacket(imuFifoBuffer))
      {
        imu.dmpGetQuaternion(&imuQ, imuFifoBuffer);
        imu.dmpGetGravity(&gravity, &imuQ);
        imu.dmpGetGyro(&gyro, imuFifoBuffer);
        imu.dmpGetAccel(&aa, imuFifoBuffer);
        imu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
        imu_msg.header.stamp = nh.now();
        imu_msg.orientation.w = imuQ.w;
        imu_msg.orientation.x = imuQ.x;
        imu_msg.orientation.y = imuQ.y;
        imu_msg.orientation.z = imuQ.z; //Perlu konversi ke NED(?)
        imu_msg.angular_velocity.x = gyro.x * gyro_scale;
        imu_msg.angular_velocity.y = gyro.y * gyro_scale;
        imu_msg.angular_velocity.z = gyro.z * gyro_scale;
        imu_msg.linear_acceleration.x = aaReal.x * acc_scale;
        imu_msg.linear_acceleration.y = aaReal.y * acc_scale;
        imu_msg.linear_acceleration.z = aaReal.z * acc_scale;
        // imu_msg.linear_acceleration.x = aa.x * acc_scale;
        // imu_msg.linear_acceleration.y = aa.y * acc_scale;
        // imu_msg.linear_acceleration.z = aa.z * acc_scale;
        imu_msg.linear_acceleration_covariance[0] = acc_stddev;
        imu_msg.linear_acceleration_covariance[4] = acc_stddev;
        imu_msg.linear_acceleration_covariance[8] = acc_stddev;
        imu_msg.angular_velocity_covariance[0] = gyro_stddev;
        imu_msg.angular_velocity_covariance[4] = gyro_stddev;
        imu_msg.angular_velocity_covariance[8] = gyro_stddev;
        imu_msg.orientation_covariance[0] = orientation_stddev;
        imu_msg.orientation_covariance[4] = orientation_stddev;
        imu_msg.orientation_covariance[8] = orientation_stddev;
        imu_pub.publish(&imu_msg);
        nh.spinOnce();
      }
    }
  }
}

void ros_init(){
  nh.getHardware()->setBaud(576000);
  nh.initNode();
  nh.advertise(imu_pub);
  nh.advertise(debug_pub);
  // nh.advertise(debug_stamp);
  nh.subscribe(cmdVel);
  nh.subscribe(calib_f);
  nh.spinOnce();
}

void task1(){
  if(millis() - last_millis[0] > 10){
    last_millis[0] = millis();
    imu_update();
  }
}

void task2(){
  if(millis() - last_millis[1] > 100){
    last_millis[1] = millis();
    motor_run();
  }
}

void task3(){
  if(millis() - last_millis[2] > 10){
    last_millis[2] = millis();
    update_debug();
  }
}

void setup() {
  // put your setup code here, to run once:
  ros_init();
  // imu_setup();
  dmpReady = true;
  motor_setup();
  WiFi.mode(WIFI_OFF);
  btStop();
}

void loop() {
  // put your main code here, to run repeatedly:
  // task1();
  task2();
  task3();
  nh.spinOnce();
}