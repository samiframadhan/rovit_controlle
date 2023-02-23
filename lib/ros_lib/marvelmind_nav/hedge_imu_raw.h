#ifndef _ROS_marvelmind_nav_hedge_imu_raw_h
#define _ROS_marvelmind_nav_hedge_imu_raw_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace marvelmind_nav
{

  class hedge_imu_raw : public ros::Msg
  {
    public:
      typedef int64_t _timestamp_ms_type;
      _timestamp_ms_type timestamp_ms;
      typedef int16_t _acc_x_type;
      _acc_x_type acc_x;
      typedef int16_t _acc_y_type;
      _acc_y_type acc_y;
      typedef int16_t _acc_z_type;
      _acc_z_type acc_z;
      typedef int16_t _gyro_x_type;
      _gyro_x_type gyro_x;
      typedef int16_t _gyro_y_type;
      _gyro_y_type gyro_y;
      typedef int16_t _gyro_z_type;
      _gyro_z_type gyro_z;
      typedef int16_t _compass_x_type;
      _compass_x_type compass_x;
      typedef int16_t _compass_y_type;
      _compass_y_type compass_y;
      typedef int16_t _compass_z_type;
      _compass_z_type compass_z;

    hedge_imu_raw():
      timestamp_ms(0),
      acc_x(0),
      acc_y(0),
      acc_z(0),
      gyro_x(0),
      gyro_y(0),
      gyro_z(0),
      compass_x(0),
      compass_y(0),
      compass_z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_timestamp_ms;
      u_timestamp_ms.real = this->timestamp_ms;
      *(outbuffer + offset + 0) = (u_timestamp_ms.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timestamp_ms.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timestamp_ms.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timestamp_ms.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_timestamp_ms.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_timestamp_ms.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_timestamp_ms.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_timestamp_ms.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->timestamp_ms);
      union {
        int16_t real;
        uint16_t base;
      } u_acc_x;
      u_acc_x.real = this->acc_x;
      *(outbuffer + offset + 0) = (u_acc_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->acc_x);
      union {
        int16_t real;
        uint16_t base;
      } u_acc_y;
      u_acc_y.real = this->acc_y;
      *(outbuffer + offset + 0) = (u_acc_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->acc_y);
      union {
        int16_t real;
        uint16_t base;
      } u_acc_z;
      u_acc_z.real = this->acc_z;
      *(outbuffer + offset + 0) = (u_acc_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_z.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->acc_z);
      union {
        int16_t real;
        uint16_t base;
      } u_gyro_x;
      u_gyro_x.real = this->gyro_x;
      *(outbuffer + offset + 0) = (u_gyro_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyro_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gyro_x);
      union {
        int16_t real;
        uint16_t base;
      } u_gyro_y;
      u_gyro_y.real = this->gyro_y;
      *(outbuffer + offset + 0) = (u_gyro_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyro_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gyro_y);
      union {
        int16_t real;
        uint16_t base;
      } u_gyro_z;
      u_gyro_z.real = this->gyro_z;
      *(outbuffer + offset + 0) = (u_gyro_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyro_z.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gyro_z);
      union {
        int16_t real;
        uint16_t base;
      } u_compass_x;
      u_compass_x.real = this->compass_x;
      *(outbuffer + offset + 0) = (u_compass_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_compass_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->compass_x);
      union {
        int16_t real;
        uint16_t base;
      } u_compass_y;
      u_compass_y.real = this->compass_y;
      *(outbuffer + offset + 0) = (u_compass_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_compass_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->compass_y);
      union {
        int16_t real;
        uint16_t base;
      } u_compass_z;
      u_compass_z.real = this->compass_z;
      *(outbuffer + offset + 0) = (u_compass_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_compass_z.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->compass_z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_timestamp_ms;
      u_timestamp_ms.base = 0;
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->timestamp_ms = u_timestamp_ms.real;
      offset += sizeof(this->timestamp_ms);
      union {
        int16_t real;
        uint16_t base;
      } u_acc_x;
      u_acc_x.base = 0;
      u_acc_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->acc_x = u_acc_x.real;
      offset += sizeof(this->acc_x);
      union {
        int16_t real;
        uint16_t base;
      } u_acc_y;
      u_acc_y.base = 0;
      u_acc_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->acc_y = u_acc_y.real;
      offset += sizeof(this->acc_y);
      union {
        int16_t real;
        uint16_t base;
      } u_acc_z;
      u_acc_z.base = 0;
      u_acc_z.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_z.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->acc_z = u_acc_z.real;
      offset += sizeof(this->acc_z);
      union {
        int16_t real;
        uint16_t base;
      } u_gyro_x;
      u_gyro_x.base = 0;
      u_gyro_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyro_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gyro_x = u_gyro_x.real;
      offset += sizeof(this->gyro_x);
      union {
        int16_t real;
        uint16_t base;
      } u_gyro_y;
      u_gyro_y.base = 0;
      u_gyro_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyro_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gyro_y = u_gyro_y.real;
      offset += sizeof(this->gyro_y);
      union {
        int16_t real;
        uint16_t base;
      } u_gyro_z;
      u_gyro_z.base = 0;
      u_gyro_z.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyro_z.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gyro_z = u_gyro_z.real;
      offset += sizeof(this->gyro_z);
      union {
        int16_t real;
        uint16_t base;
      } u_compass_x;
      u_compass_x.base = 0;
      u_compass_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_compass_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->compass_x = u_compass_x.real;
      offset += sizeof(this->compass_x);
      union {
        int16_t real;
        uint16_t base;
      } u_compass_y;
      u_compass_y.base = 0;
      u_compass_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_compass_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->compass_y = u_compass_y.real;
      offset += sizeof(this->compass_y);
      union {
        int16_t real;
        uint16_t base;
      } u_compass_z;
      u_compass_z.base = 0;
      u_compass_z.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_compass_z.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->compass_z = u_compass_z.real;
      offset += sizeof(this->compass_z);
     return offset;
    }

    virtual const char * getType() override { return "marvelmind_nav/hedge_imu_raw"; };
    virtual const char * getMD5() override { return "809304d028f09940bd722db544d5d2e8"; };

  };

}
#endif
