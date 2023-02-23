#ifndef _ROS_rovit_fw_msgs_RovitDebug_h
#define _ROS_rovit_fw_msgs_RovitDebug_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "rovit_fw_msgs/PID.h"

namespace rovit_fw_msgs
{

  class RovitDebug : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef rovit_fw_msgs::PID _PID_kiri_type;
      _PID_kiri_type PID_kiri;
      typedef rovit_fw_msgs::PID _PID_kanan_type;
      _PID_kanan_type PID_kanan;

    RovitDebug():
      header(),
      PID_kiri(),
      PID_kanan()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->PID_kiri.serialize(outbuffer + offset);
      offset += this->PID_kanan.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->PID_kiri.deserialize(inbuffer + offset);
      offset += this->PID_kanan.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rovit_fw_msgs/RovitDebug"; };
    virtual const char * getMD5() override { return "292d8c9dffc00698ae962441ea991ba0"; };

  };

}
#endif
