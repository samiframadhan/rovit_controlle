#ifndef _ROS_marvelmind_nav_beacon_pos_a_h
#define _ROS_marvelmind_nav_beacon_pos_a_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace marvelmind_nav
{

  class beacon_pos_a : public ros::Msg
  {
    public:
      typedef uint8_t _address_type;
      _address_type address;
      typedef float _x_m_type;
      _x_m_type x_m;
      typedef float _y_m_type;
      _y_m_type y_m;
      typedef float _z_m_type;
      _z_m_type z_m;

    beacon_pos_a():
      address(0),
      x_m(0),
      y_m(0),
      z_m(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->address >> (8 * 0)) & 0xFF;
      offset += sizeof(this->address);
      offset += serializeAvrFloat64(outbuffer + offset, this->x_m);
      offset += serializeAvrFloat64(outbuffer + offset, this->y_m);
      offset += serializeAvrFloat64(outbuffer + offset, this->z_m);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->address =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->address);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x_m));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y_m));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->z_m));
     return offset;
    }

    virtual const char * getType() override { return "marvelmind_nav/beacon_pos_a"; };
    virtual const char * getMD5() override { return "2ebe9b8512406c92c2dbfed7a627f03c"; };

  };

}
#endif
