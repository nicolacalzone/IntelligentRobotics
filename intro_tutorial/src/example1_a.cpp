#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "example1_a"); //initialize ROS system
    ros::NodeHandle n; // Create a Handle Node

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("message", 1000); 
    // create a Publisher object
    // std_msgs::String --> the message is a simple string
    // 1000             --> size of the message queue
    // "message"        --> is the NAME of the TOPIC

    ros::Rate loop_rate(10); // HZ FREQUENCY RATE for publishing messages 

    while (ros::ok()) {
        std_msgs::String msg;
        std::stringstream ss;
        ss << " Hello World! ";
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());
        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}