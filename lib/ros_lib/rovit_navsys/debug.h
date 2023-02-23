#ifndef _ROS_rovit_navsys_debug_h
#define _ROS_rovit_navsys_debug_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rovit_navsys
{

  class debug : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t data_length;
      typedef float _data_type;
      _data_type st_data;
      _data_type * data;
      typedef float _leftSpeed_type;
      _leftSpeed_type leftSpeed;
      typedef float _rightSpeed_type;
      _rightSpeed_type rightSpeed;

    debug():
      header(),
      data_length(0), st_data(), data(nullptr),
      leftSpeed(0),
      rightSpeed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      union {
        float real;
        uint32_t base;
      } u_datai;
      u_datai.real = this->data[i];
      *(outbuffer + offset + 0) = (u_datai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_datai.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_datai.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_datai.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_leftSpeed;
      u_leftSpeed.real = this->leftSpeed;
      *(outbuffer + offset + 0) = (u_leftSpeed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leftSpeed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_leftSpeed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_leftSpeed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->leftSpeed);
      union {
        float real;
        uint32_t base;
      } u_rightSpeed;
      u_rightSpeed.real = this->rightSpeed;
      *(outbuffer + offset + 0) = (u_rightSpeed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rightSpeed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rightSpeed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rightSpeed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rightSpeed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (float*)realloc(this->data, data_lengthT * sizeof(float));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_data;
      u_st_data.base = 0;
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_data = u_st_data.real;
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(float));
      }
      union {
        float real;
        uint32_t base;
      } u_leftSpeed;
      u_leftSpeed.base = 0;
      u_leftSpeed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leftSpeed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_leftSpeed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_leftSpeed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->leftSpeed = u_leftSpeed.real;
      offset += sizeof(this->leftSpeed);
      union {
        float real;
        uint32_t base;
      } u_rightSpeed;
      u_rightSpeed.base = 0;
      u_rightSpeed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rightSpeed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rightSpeed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rightSpeed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rightSpeed = u_rightSpeed.real;
      offset += sizeof(this->rightSpeed);
     return offset;
    }

    virtual const char * getType() override { return "rovit_navsys/debug"; };
    virtual const char * getMD5() override { return "f1b41bdf0f62fad14787c3f9671d9cfa"; };

  };

}
#endif
