#ifndef _ROS_marvelmind_nav_marvelmind_waypoint_h
#define _ROS_marvelmind_nav_marvelmind_waypoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace marvelmind_nav
{

  class marvelmind_waypoint : public ros::Msg
  {
    public:
      typedef uint8_t _total_items_type;
      _total_items_type total_items;
      typedef uint8_t _item_index_type;
      _item_index_type item_index;
      typedef uint8_t _movement_type_type;
      _movement_type_type movement_type;
      typedef int16_t _param1_type;
      _param1_type param1;
      typedef int16_t _param2_type;
      _param2_type param2;
      typedef int16_t _param3_type;
      _param3_type param3;

    marvelmind_waypoint():
      total_items(0),
      item_index(0),
      movement_type(0),
      param1(0),
      param2(0),
      param3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->total_items >> (8 * 0)) & 0xFF;
      offset += sizeof(this->total_items);
      *(outbuffer + offset + 0) = (this->item_index >> (8 * 0)) & 0xFF;
      offset += sizeof(this->item_index);
      *(outbuffer + offset + 0) = (this->movement_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->movement_type);
      union {
        int16_t real;
        uint16_t base;
      } u_param1;
      u_param1.real = this->param1;
      *(outbuffer + offset + 0) = (u_param1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_param1.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->param1);
      union {
        int16_t real;
        uint16_t base;
      } u_param2;
      u_param2.real = this->param2;
      *(outbuffer + offset + 0) = (u_param2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_param2.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->param2);
      union {
        int16_t real;
        uint16_t base;
      } u_param3;
      u_param3.real = this->param3;
      *(outbuffer + offset + 0) = (u_param3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_param3.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->param3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->total_items =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->total_items);
      this->item_index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->item_index);
      this->movement_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->movement_type);
      union {
        int16_t real;
        uint16_t base;
      } u_param1;
      u_param1.base = 0;
      u_param1.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_param1.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->param1 = u_param1.real;
      offset += sizeof(this->param1);
      union {
        int16_t real;
        uint16_t base;
      } u_param2;
      u_param2.base = 0;
      u_param2.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_param2.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->param2 = u_param2.real;
      offset += sizeof(this->param2);
      union {
        int16_t real;
        uint16_t base;
      } u_param3;
      u_param3.base = 0;
      u_param3.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_param3.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->param3 = u_param3.real;
      offset += sizeof(this->param3);
     return offset;
    }

    virtual const char * getType() override { return "marvelmind_nav/marvelmind_waypoint"; };
    virtual const char * getMD5() override { return "c0d0bd68d8638aec15ccca2e2f6be8d8"; };

  };

}
#endif
