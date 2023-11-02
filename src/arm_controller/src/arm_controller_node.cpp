//
// Created by luigi on 30/10/23.
//
#include "ros/ros.h"
#include "ArmController/ArmController.h"

#define PI 3.1415

int main(int argc, char **argv) {
    ros::init(argc, argv, "arm_controller_node");
    ros::NodeHandle nh;
    ros::Rate loop_rate(10);

    ArmController armController(nh);

    std_msgs::Float64 positionCmds[4];
    int t = 0;
    while (ros::ok()) {
        // alternating between two configurations
        if (t > 250) {
            positionCmds[0].data = PI / 2;
            positionCmds[1].data = -PI / 2;
            positionCmds[2].data = PI / 2;
            positionCmds[3].data = -PI / 2;
        } else {
            positionCmds[0].data = -PI / 2;
            positionCmds[1].data = PI / 2;
            positionCmds[2].data = -PI / 2;
            positionCmds[3].data = PI / 2;
        }
        armController.jointPositionCommand(positionCmds[0], positionCmds[1], positionCmds[2], positionCmds[3]);
        loop_rate.sleep();
        ros::spinOnce();
        ++t;
        t = t % 500;
    }

    return 0;
}