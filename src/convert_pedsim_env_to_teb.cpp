#include <ros/ros.h>
#include <pedsim_msgs/AgentStates.h>
#include <costmap_converter/ObstacleArrayMsg.h>
#include <costmap_converter/ObstacleMsg.h>

ros::Publisher obstacles_pub_;

void agentStatesCallback(const pedsim_msgs::AgentStates::ConstPtr& msg)
{
    // Create an ObstacleArrayMsg to hold the converted obstacles
    costmap_converter::ObstacleArrayMsg obstacles_msg;
    obstacles_msg.header = msg->header;

    // Iterate through each agent in the AgentStates message
    for (const auto& agent : msg->agent_states)
    {
        // Create an ObstacleMsg for each agent
        costmap_converter::ObstacleMsg obstacle;

        // Set the position of the obstacle based on the agent's position
        obstacle.polygon.points.resize(1);
        obstacle.polygon.points[0].x = agent.pose.position.x;
        obstacle.polygon.points[0].y = agent.pose.position.y;

        // Set the velocity of the obstacle based on the agent's velocity
        obstacle.velocities.twist.linear.x = agent.twist.linear.x;
        obstacle.velocities.twist.linear.y = agent.twist.linear.y;

        // Add the obstacle to the ObstacleArrayMsg
        obstacles_msg.obstacles.push_back(obstacle);
    }

    // Publish the ObstacleArrayMsg
    obstacles_pub_.publish(obstacles_msg);
}

int main(int argc, char** argv)
{
    // Initialize the ROS node
    ros::init(argc, argv, "agent_to_obstacle_converter");
    // Initialize the ROS subscriber and publisher
    ros::NodeHandle nh;
    ros::Subscriber agent_states_sub_ = nh.subscribe("/pedsim_simulator/simulated_agents", 10, &agentStatesCallback);
    obstacles_pub_ = nh.advertise<costmap_converter::ObstacleArrayMsg>("/test_optim_node/obstacles", 10);

    // Spin to keep the node running and processing callbacks
    ros::spin();

    return 0;
}
