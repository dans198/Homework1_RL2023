#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/JointState.h>

void Callback(const sensor_msgs::JointState& msg)
{
	ROS_INFO("I heard: ");
	for(int i=0; i<msg.position.size(); ++i) {
	ROS_INFO_STREAM(msg.position[i]);	
	}

}

int main(int argc, char* argv[])
{ 	
	ros::init(argc, argv, "controller");
	ros::NodeHandle nodeHandle;

	ros::Rate loopRate(10);
	
	
	ros::Subscriber subscriber = nodeHandle.subscribe("/arm/joint_states",10,Callback);
	
	ros::Publisher publisher0 = nodeHandle.advertise<std_msgs::Float64>("/arm/PositionJointInterface_J0_controller/command", 1);
	
	ros::Publisher publisher1 = nodeHandle.advertise<std_msgs::Float64>("/arm/PositionJointInterface_J1_controller/command", 1);
	
	ros::Publisher publisher2 = nodeHandle.advertise<std_msgs::Float64>("/arm/PositionJointInterface_J2_controller/command", 1);
	
	ros::Publisher publisher3 = nodeHandle.advertise<std_msgs::Float64>("/arm/PositionJointInterface_J3_controller/command", 1);
	

	
	while (ros::ok()) {
	std_msgs::Float64 msg0;
	std_msgs::Float64 msg1;
	std_msgs::Float64 msg2;
	std_msgs::Float64 msg3;

	
	msg0.data=1.0;
	msg1.data=1.0;
	msg2.data=1.0;
	msg3.data=1.0;
	
	//ROS_INFO_STREAM(message.data);
	
	publisher0.publish(msg0);
	publisher1.publish(msg1);
	publisher2.publish(msg2);
	publisher3.publish(msg3);
	
	ros::spinOnce();
	loopRate.sleep();
	
	} 
	

	return 0;
}









