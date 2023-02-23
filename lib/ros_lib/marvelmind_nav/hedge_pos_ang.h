#ifndef _ROS_marvelmind_nav_hedge_pos_ang_h
#define _ROS_marvelmind_nav_hedge_pos_ang_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace marvelmind_nav
{

  class hedge_pos_ang : public ros::Msg
  {
    public:
      typedef uint8_t _address_type;
      _address_type address;
      typedef int64_t _timestamp_ms_type;
      _timestamp_ms_type timestamp_ms;
      typedef float _x_m_type;
      _x_m_type x_m;
      typedef float _y_m_type;
      _y_m_type y_m;
      typedef float _z_m_type;
      _z_m_type z_m;
      typedef uint8_t _flags_type;
      _flags_type flags;
      typedef float _angle_type;
      _angle_type angle;

    hedge_pos_ang():
      address(0),
      timestamp_ms(0),
      x_m(0),
      y_m(0),
      z_m(0),
      flags(0),
      angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->address >> (8 * 0)) & 0xFF;
      offset += sizeof(this->address);
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
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flags);
      offset += serializeAvrFloat64(outbuffer + offset, this->angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->address =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->address);
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
      this->flags =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->flags);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angle));
     return offset;
    }

    virtual const char * getType() override { return "marvelmind_nav/hedge_pos_ang"; };
    virtual const char * getMD5() override { return "757a5c747784795643dfe2d2ca2ac03e"; };

  };

}
#endif
