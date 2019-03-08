// This program publishes randomly-generated velocity messages for turtlesim
#include <ros/ros.h>
#include <geometry_msgs/Twist.h> //msg to control turtlesim
#include <stdlib.h>  //For rand() and RANDMAX

int main(int argc, char **argv) {
    //Initialize the ROS system and become a node
    ros::init(argc, argv, "publish_velocity");
    ros::NodeHandle nh;

    // Create a Publisher object
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);

    //Seed the random number generator.
    srand(time(0));

    //Loop at 2Hz until the node is shut down
    ros::Rate rate(2);
    while(ros::ok()) {
        //Create and fill in the message.  Te other four fields, which are ignored by turtlesim
        //default to 0.
        geometry_msgs::Twist msg;
        msg.linear.x = double(rand())/double(RAND_MAX);
        msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1;

        //Publish Message
        pub.publish(msg);

        //Log details to rosout
        ROS_INFO_STREAM("Sending random velocity command: "
            << " linear=" << msg.linear.x
            << " angular=" << msg.angular.z);
        
        //Wait until it's time for another iteration
        rate.sleep();
    }
}