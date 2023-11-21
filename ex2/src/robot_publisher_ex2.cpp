#include "ros/ros.h"
#include "ex2/msg1.h"   // import the message type
#include "ex2/srv1.h"  // import the service type
#include <sstream>

bool handle_request(ex2::srv1::Request &req, ex2::srv1::Response &res)
{
    res.header = req.header;
    res.message.ROOM_ID = 1;
    res.message.ROOM_NAME = "Robot vision lab";
    res.message.BATTERY_LEVEL = 85;
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "robot_publisher_ex2"); //initialize ROS system
    ros::NodeHandle n;

    // HANDLE FUNCTION IS CALLED HERE
    ros::ServiceServer service = n.advertiseService("service", handle_request);
    ros::spin();

    return 0;
}


    