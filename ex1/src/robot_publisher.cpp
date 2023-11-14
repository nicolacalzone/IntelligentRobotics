#include "ros/ros.h"
#include "ex1/msg1.h"   // import the message type
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "robot_publisher"); //initialize ROS system
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<ex1::msg1>("charge_status", 1000);
    // create a Publisher object
    // ex1::msg1 --> the message is defined in msg1
    // 1000      --> size of the message queue

    ros::Rate loop_rate(5); // 5 Hz

    while (ros::ok())
    {
        ex1::msg1 msg;  
        msg.ROOM_ID = 1;                        // Fields of the msg from msg1 model
        msg.ROOM_NAME = "Robot vision lab";     // 
        msg.BATTERY_LEVEL = 85.4;               // 

        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}