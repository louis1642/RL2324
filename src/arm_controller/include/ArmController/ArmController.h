//
// Created by luigi on 30/10/23.
//

#ifndef ARM_CONTROLLER_ARMCONTROLLER_H
#define ARM_CONTROLLER_ARMCONTROLLER_H

// ROS
#include <ros/ros.h>
#include "std_msgs/Float64.h"
#include "sensor_msgs/JointState.h"
//#include "std_msgs/String.h"

class ArmController {

    public:
        /*!
         * Constructor.
         * @param nodeHandle the ROS node handle.
         */
        ArmController(ros::NodeHandle& nodeHandle);

        /*!
         * Destructor.
         */
        virtual ~ArmController();

    private:
//        /*!
//         * Reads and verifies the ROS parameters.
//         * @return true if successful.
//         */
//        bool readParameters();

        /*!
         * ROS topic callback method.
         * @param message the received message.
         */
        void jointPositionPrintCallback(const sensor_msgs::JointState& jointState);

        //! ROS node handle.
        ros::NodeHandle& nodeHandle_;

        //! ROS topic subscriber.
        ros::Subscriber subscriber_;

        //! ROS topic name to subscribe to.
        std::string subscriberTopic_;
};


#endif //ARM_CONTROLLER_ARMCONTROLLER_H
