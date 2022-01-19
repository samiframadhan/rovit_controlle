bool pauseMeasurement;
const float min_speed[4] = {0.008631, -0.01431, -0.0317697, 0.00723746}; //Minimum speed for left forward, right forward, left reverse, right reverse respectively
const float speed_to_pwm[4] = {0.0083231642859, 0.0080549944, 0.00824112673728, 0.007929}; //Speed to pwm conversion for left forward, right forward, left reverse, right reverse respectively
const float min_speed_reverse_cmd = 0.0247354; //Adjustment for wheelchair motor
const float wheel_dia = 0.32; //Wheel radius, in m
const float wheelbase = 0.57; //Wheelbase, in m
const float encoder_cpr = 400; //Encoder ticks or counts per rotation
const float speed_to_pwm_ratio = 0.0123677; //Ratio to convert speed (in m/s) to PWM value. 
//It was obtained by plotting the wheel speed in relation to the PWM motor command (the value is the slope of the linear function).

const float wheel_gear_ratio = 26.26; //Gearbox ratio
const float max_speed = 0.4;
const int brakeDuty = 255; //Full brake. Adjustable 0-255