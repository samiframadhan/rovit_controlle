#ifndef _ROS_marvelmind_nav_hedge_telemetry_h
#define _ROS_marvelmind_nav_hedge_telemetry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace marvelmind_nav
{

  class hedge_telemetry : public ros::Msg
  {
    public:
      typedef float _battery_voltage_type;
      _battery_voltage_type battery_voltage;
      typedef int8_t _rssi_dbm_type;
      _rssi_dbm_type rssi_dbm;

    hedge_telemetry():
      battery_voltage(0),
      rssi_dbm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->battery_voltage);
      union {
        int8_t real;
        uint8_t base;
      } u_rssi_dbm;
      u_rssi_dbm.real = this->rssi_dbm;
      *(outbuffer + offset + 0) = (u_rssi_dbm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rssi_dbm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->battery_voltage));
      union {
        int8_t real;
        uint8_t base;
      } u_rssi_dbm;
      u_rssi_dbm.base = 0;
      u_rssi_dbm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rssi_dbm = u_rssi_dbm.real;
      offset += sizeof(this->rssi_dbm);
     return offset;
    }

    virtual const char * getType() override { return "marvelmind_nav/hedge_telemetry"; };
    virtual const char * getMD5() override { return "71969b1e6d7b7ffa3f313a22d80cf863"; };

  };

}
#endif
