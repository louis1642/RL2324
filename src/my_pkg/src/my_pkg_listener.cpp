//
// Created by luigi on 14/10/23.
//
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "my_pkg/my_msg.h"
#include <sstream>

void messageCallback(const my_pkg::my_msg& msg) {
    ROS_INFO("Received message:\n\tName: %s\n\tData: %u", msg.name.c_str(), msg.data);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "my_pkg_listener");
    ros::NodeHandle n;
    ros::Subscriber subscriber = n.subscribe("my_package_topic", 1000, messageCallback);
    ros::spin();
    return 0;

}