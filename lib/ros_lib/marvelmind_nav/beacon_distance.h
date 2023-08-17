#ifndef _ROS_marvelmind_nav_beacon_distance_h
#define _ROS_marvelmind_nav_beacon_distance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace marvelmind_nav
{

  class beacon_distance : public ros::Msg
  {
    public:
      typedef uint8_t _address_hedge_type;
      _address_hedge_type address_hedge;
      typedef uint8_t _address_beacon_type;
      _address_beacon_type address_beacon;
      typedef float _distance_m_type;
      _distance_m_type distance_m;

    beacon_distance():
      address_hedge(0),
      address_beacon(0),
      distance_m(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->address_hedge >> (8 * 0)) & 0xFF;
      offset += sizeof(this->address_hedge);
      *(outbuffer + offset + 0) = (this->address_beacon >> (8 * 0)) & 0xFF;
      offset += sizeof(this->address_beacon);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance_m);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->address_hedge =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->address_hedge);
      this->address_beacon =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->address_beacon);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance_m));
     return offset;
    }

    virtual const char * getType() override { return "marvelmind_nav/beacon_distance"; };
    virtual const char * getMD5() override { return "0961792211a42c14a3b38a49e24931f3"; };

  };

}
#endif
