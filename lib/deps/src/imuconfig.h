//IMU Setting Variables
bool imu_calibration_mode = false;
int imu_int_pin = 4;
bool dmpReady = false;      //IMU Init Variables
volatile bool imuInterruptReady = false;
uint8_t imuInterruptStatus;
uint8_t imuDevStatus;
uint16_t imuPacketSize;
uint16_t imuFifoCount;
uint8_t imuFifoBuffer [64];
int last_millis[3]; //Number of tasks
float imu_offsets[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}; //Acc X, Y, Z, Gyro X, Y, Z
float acc_scale = 0.00059855;   // measured in m/s^2 is 9.80665/16384 
float gyro_scale = 0.000133231; // measured in rad/s is 0,017453293/131
float acc_stddev = 0.0;
float gyro_stddev = 0.0;
float orientation_stddev = 0.0;

/*Acc scale ranges:
 * 2G = 16384          *Used in this lib
 * 4G = 16384/2 = 8192 
 * 8G = 16384/4 = 4096 
 * 16G= 16384/8 = 2048 
 * 
 * Gyro scale ranges:
 * 250dps  = 131 *used in this lib
 * 500dps  = 65.5
 * 1000dps = 32.8
 * 2000dps = 16.4
 * 
 * This only applicable if 
 * the sensitivity register of the MPU is set
 * to its according scale
 */