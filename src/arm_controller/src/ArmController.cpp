//
// Created by luigi on 30/10/23.
//

#include "ArmController/ArmController.h"

ArmController::ArmController(ros::NodeHandle& nodeHandle)
        : nodeHandle_(nodeHandle)
{
//    if (!readParameters()) {
//        ROS_ERROR("Could not read parameters.");
//        ros::requestShutdown();
//    }
    subscriber_ = nodeHandle_.subscribe("/arm/joint_states", 1,
                                        &ArmController::jointPositionPrintCallback, this);

    ROS_INFO("Successfully launched node.");
}

// trivial destructor
ArmController::~ArmController()
= default;

//bool ArmController::readParameters()
//{
//    if (!nodeHandle_.getParam("subscriber_topic", subscriberTopic_)) return false;
//    return true;
//}

void ArmController::jointPositionPrintCallback(const sensor_msgs::JointState& jointState)
{
    ROS_INFO("\n##### JOINT STATES #####");
    // loop through joints
    for (size_t i = 0; i < jointState.name.size(); ++i) {
        ROS_INFO("Joint %s position: %.4f", jointState.name.at(i).c_str(), jointState.position.at(i));
    }
}