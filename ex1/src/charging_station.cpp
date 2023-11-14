#include "ros/ros.h"
#include "ex1/msg1.h"

void messageCallback(const ex1::msg1::ConstPtr& msg)
{
    ROS_INFO("I heard: [%d] [%s] [%f]", msg->ROOM_ID, msg->ROOM_NAME.c_str(), msg->BATTERY_LEVEL);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "charging_station");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("charge_status", 1000, messageCallback);
    ros::spin();
    return 0;
}