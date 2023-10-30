//
// Created by luigi on 14/10/23.
//
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "my_pkg/my_msg.h"
#include <sstream>
int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_package_node");
    ros::NodeHandle n;
    ros::Publisher my_package_pub = n.advertise<my_pkg::my_msg>("my_package_topic", 1000);
    ros::Rate loop_rate(10);
    int count = 0;
    my_pkg::my_msg msg;
    int param = 0;
    msg.name = "my_msg_name";
    if (n.getParam("talker_number", param)) {
        ROS_INFO("Number assigned: %u", param);
    }
    while (ros::ok())
    {
        msg.data = count;
        ROS_INFO("%u", msg.data);
        my_package_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    return 0;
}