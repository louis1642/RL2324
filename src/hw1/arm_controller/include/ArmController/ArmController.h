//
// Created by luigi on 30/10/23.
//

#ifndef ARM_CONTROLLER_ARMCONTROLLER_H
#define ARM_CONTROLLER_ARMCONTROLLER_H

// ROS
#include <ros/ros.h>
#include "std_msgs/Float64.h"
#include "sensor_msgs/JointState.h"

class ArmController {

    public:
        /*!
         * Constructor.
         * @param nodeHandle the ROS node handle.
         */
        explicit ArmController(ros::NodeHandle& nodeHandle);

        /*!
         * Destructor.
         */
        virtual ~ArmController();

        /*!
         * ROS publishers for PositionJointInterface commands
         * @param j0 position command for joint j0
         * @param j1 position command for joint j1
         * @param j2 position command for joint j2
         * @param j3 position command for joint j3
         */
        void jointPositionCommand(std_msgs::Float64 j0, std_msgs::Float64 j1, std_msgs::Float64 j2, std_msgs::Float64 j3);

    private:
        /*!
         * ROS topic callback method.
         * @param message the received message.
         */
        void jointPositionPrintCallback(const sensor_msgs::JointState& jointState);

        //! ROS node handle.
        ros::NodeHandle& nodeHandle_;

        //! ROS topic subscriber.
        ros::Subscriber subscriber_;

        //! ROS topic publishers.
        ros::Publisher joint0CmdPublisher;
        ros::Publisher joint1CmdPublisher;
        ros::Publisher joint2CmdPublisher;
        ros::Publisher joint3CmdPublisher;

};


#endif //ARM_CONTROLLER_ARMCONTROLLER_H
