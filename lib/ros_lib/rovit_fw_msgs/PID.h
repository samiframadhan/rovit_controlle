#ifndef _ROS_rovit_fw_msgs_PID_h
#define _ROS_rovit_fw_msgs_PID_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rovit_fw_msgs
{

  class PID : public ros::Msg
  {
    public:
      typedef float _KP_type;
      _KP_type KP;
      typedef float _KI_type;
      _KI_type KI;
      typedef float _KD_type;
      _KD_type KD;
      typedef float _input_type;
      _input_type input;
      typedef float _output_type;
      _output_type output;
      typedef float _setpoint_type;
      _setpoint_type setpoint;

    PID():
      KP(0),
      KI(0),
      KD(0),
      input(0),
      output(0),
      setpoint(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_KP;
      u_KP.real = this->KP;
      *(outbuffer + offset + 0) = (u_KP.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_KP.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_KP.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_KP.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->KP);
      union {
        float real;
        uint32_t base;
      } u_KI;
      u_KI.real = this->KI;
      *(outbuffer + offset + 0) = (u_KI.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_KI.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_KI.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_KI.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->KI);
      union {
        float real;
        uint32_t base;
      } u_KD;
      u_KD.real = this->KD;
      *(outbuffer + offset + 0) = (u_KD.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_KD.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_KD.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_KD.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->KD);
      union {
        float real;
        uint32_t base;
      } u_input;
      u_input.real = this->input;
      *(outbuffer + offset + 0) = (u_input.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_input.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_input.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_input.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->input);
      union {
        float real;
        uint32_t base;
      } u_output;
      u_output.real = this->output;
      *(outbuffer + offset + 0) = (u_output.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_output.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_output.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_output.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->output);
      union {
        float real;
        uint32_t base;
      } u_setpoint;
      u_setpoint.real = this->setpoint;
      *(outbuffer + offset + 0) = (u_setpoint.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_setpoint.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_setpoint.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_setpoint.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->setpoint);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_KP;
      u_KP.base = 0;
      u_KP.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_KP.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_KP.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_KP.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->KP = u_KP.real;
      offset += sizeof(this->KP);
      union {
        float real;
        uint32_t base;
      } u_KI;
      u_KI.base = 0;
      u_KI.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_KI.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_KI.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_KI.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->KI = u_KI.real;
      offset += sizeof(this->KI);
      union {
        float real;
        uint32_t base;
      } u_KD;
      u_KD.base = 0;
      u_KD.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_KD.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_KD.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_KD.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->KD = u_KD.real;
      offset += sizeof(this->KD);
      union {
        float real;
        uint32_t base;
      } u_input;
      u_input.base = 0;
      u_input.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_input.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_input.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_input.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->input = u_input.real;
      offset += sizeof(this->input);
      union {
        float real;
        uint32_t base;
      } u_output;
      u_output.base = 0;
      u_output.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_output.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_output.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_output.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->output = u_output.real;
      offset += sizeof(this->output);
      union {
        float real;
        uint32_t base;
      } u_setpoint;
      u_setpoint.base = 0;
      u_setpoint.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_setpoint.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_setpoint.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_setpoint.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->setpoint = u_setpoint.real;
      offset += sizeof(this->setpoint);
     return offset;
    }

    virtual const char * getType() override { return "rovit_fw_msgs/PID"; };
    virtual const char * getMD5() override { return "ccdbdd140aec9c0136f28cd7f7c11b67"; };

  };

}
#endif
