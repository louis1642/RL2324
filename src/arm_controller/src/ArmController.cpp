//
// Created by luigi on 30/10/23.
//

#include "ArmController/ArmController.h"

// constructor
ArmController::ArmController(ros::NodeHandle& nodeHandle)
        : nodeHandle_(nodeHandle)
{
    // initialize subscriber
    subscriber_ = nodeHandle_.subscribe("/arm/joint_states", 1, &ArmController::jointPositionPrintCallback, this);

    // initialize publishers
    joint0CmdPublisher = nodeHandle_.advertise<std_msgs::Float64>("/arm/J0_positionController/command", 3);
    joint1CmdPublisher = nodeHandle_.advertise<std_msgs::Float64>("/arm/J1_positionController/command", 3);
    joint2CmdPublisher = nodeHandle_.advertise<std_msgs::Float64>("/arm/J2_positionController/command", 3);
    joint3CmdPublisher = nodeHandle_.advertise<std_msgs::Float64>("/arm/J3_positionController/command", 3);

    ROS_INFO("Successfully launched ArmController node.");
}


// trivial destructor
ArmController::~ArmController()
= default;


void ArmController::jointPositionPrintCallback(const sensor_msgs::JointState& jointState) {
    ROS_INFO("\n##### JOINT STATES #####");
    // loop through joints
    for (size_t i = 0; i < jointState.name.size(); ++i) {
        ROS_INFO("Joint %s position: %.4f", jointState.name.at(i).c_str(), jointState.position.at(i));
    }
}

void ArmController::jointPositionCommand(std_msgs::Float64 j0, std_msgs::Float64 j1, std_msgs::Float64 j2, std_msgs::Float64 j3) {
    joint0CmdPublisher.publish(j0);
    joint1CmdPublisher.publish(j1);
    joint2CmdPublisher.publish(j2);
    joint3CmdPublisher.publish(j3);

}
