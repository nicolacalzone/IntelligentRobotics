#include "ros/ros.h"
#include "ex2/srv1.h"  // import the service type
#include "ex2/msg1.h"  // import the message type

void send_request(int charging_station_id, ros::NodeHandle& n)
{
    ros::ServiceClient client = n.serviceClient<ex2::srv1>("service");
    ex2::srv1 srv;

    srv.request.header.stamp = ros::Time::now();
    srv.request.charging_station_id = charging_station_id;

    if (client.call(srv))
    {
        ROS_INFO("Request sent: %d", srv.request.charging_station_id);
        ROS_INFO("Response received: %d - %s - %d ", srv.response.message.ROOM_ID,
         srv.response.message.ROOM_NAME, (float)srv.response.message.BATTERY_LEVEL);
    }
    else
    {
        ROS_ERROR("Failed to call service \'service\'");
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "charging_station_ex2");
    ros::NodeHandle n;
    int charging_station_id = 2;

    double X = 5.0; // if X is put to int, it gives error.
    ros::Rate loop_rate(1 / X);  
    while (ros::ok())
    {
        send_request(charging_station_id, n);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
