#ifndef _ROS_marvelmind_nav_hedge_quality_h
#define _ROS_marvelmind_nav_hedge_quality_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace marvelmind_nav
{

  class hedge_quality : public ros::Msg
  {
    public:
      typedef uint8_t _address_type;
      _address_type address;
      typedef uint8_t _quality_percents_type;
      _quality_percents_type quality_percents;

    hedge_quality():
      address(0),
      quality_percents(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->address >> (8 * 0)) & 0xFF;
      offset += sizeof(this->address);
      *(outbuffer + offset + 0) = (this->quality_percents >> (8 * 0)) & 0xFF;
      offset += sizeof(this->quality_percents);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->address =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->address);
      this->quality_percents =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->quality_percents);
     return offset;
    }

    virtual const char * getType() override { return "marvelmind_nav/hedge_quality"; };
    virtual const char * getMD5() override { return "32c7aef52b6208c1c5cea12793225e6e"; };

  };

}
#endif
