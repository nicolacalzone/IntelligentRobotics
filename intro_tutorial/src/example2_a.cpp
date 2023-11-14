#include "ros/ros.h"
#include "intro_tutorial/msg1.h"
#include <sstream>
int main(int argc, char **argv)
{
    ros::init(argc, argv, "example2_a"); //initialize ROS system
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<intro_tutorial::msg1>("message", 1000);
    // create a Publisher object
    // intro_tutorial::msg1 --> the message is defined in msg1
    // 1000             --> size of the message queue
    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        intro_tutorial::msg1 msg;
        msg.A = 1;      // Field A is assigned 1
        msg.B = 2;      // Field B is assigned 2
        msg.C = 3;      // Field C is assigned 3
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}