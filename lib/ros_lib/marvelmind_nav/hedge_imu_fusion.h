#ifndef _ROS_marvelmind_nav_hedge_imu_fusion_h
#define _ROS_marvelmind_nav_hedge_imu_fusion_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace marvelmind_nav
{

  class hedge_imu_fusion : public ros::Msg
  {
    public:
      typedef int64_t _timestamp_ms_type;
      _timestamp_ms_type timestamp_ms;
      typedef float _x_m_type;
      _x_m_type x_m;
      typedef float _y_m_type;
      _y_m_type y_m;
      typedef float _z_m_type;
      _z_m_type z_m;
      typedef float _qw_type;
      _qw_type qw;
      typedef float _qx_type;
      _qx_type qx;
      typedef float _qy_type;
      _qy_type qy;
      typedef float _qz_type;
      _qz_type qz;
      typedef float _vx_type;
      _vx_type vx;
      typedef float _vy_type;
      _vy_type vy;
      typedef float _vz_type;
      _vz_type vz;
      typedef float _ax_type;
      _ax_type ax;
      typedef float _ay_type;
      _ay_type ay;
      typedef float _az_type;
      _az_type az;

    hedge_imu_fusion():
      timestamp_ms(0),
      x_m(0),
      y_m(0),
      z_m(0),
      qw(0),
      qx(0),
      qy(0),
      qz(0),
      vx(0),
      vy(0),
      vz(0),
      ax(0),
      ay(0),
      az(0)
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
      offset += serializeAvrFloat64(outbuffer + offset, this->x_m);
      offset += serializeAvrFloat64(outbuffer + offset, this->y_m);
      offset += serializeAvrFloat64(outbuffer + offset, this->z_m);
      offset += serializeAvrFloat64(outbuffer + offset, this->qw);
      offset += serializeAvrFloat64(outbuffer + offset, this->qx);
      offset += serializeAvrFloat64(outbuffer + offset, this->qy);
      offset += serializeAvrFloat64(outbuffer + offset, this->qz);
      offset += serializeAvrFloat64(outbuffer + offset, this->vx);
      offset += serializeAvrFloat64(outbuffer + offset, this->vy);
      offset += serializeAvrFloat64(outbuffer + offset, this->vz);
      offset += serializeAvrFloat64(outbuffer + offset, this->ax);
      offset += serializeAvrFloat64(outbuffer + offset, this->ay);
      offset += serializeAvrFloat64(outbuffer + offset, this->az);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x_m));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y_m));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->z_m));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qy));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qz));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vy));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vz));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ax));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ay));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->az));
     return offset;
    }

    virtual const char * getType() override { return "marvelmind_nav/hedge_imu_fusion"; };
    virtual const char * getMD5() override { return "80fa4231724bd716826855f463bf5400"; };

  };

}
#endif
