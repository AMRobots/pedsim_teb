#  Introduction
This project used navigation stack (move_base), plus [teb_local_planner](http://wiki.ros.org/teb_local_planner)
to control different robot in environment created by [pedsim_ros](https://github.com/srl-freiburg/pedsim_ros).

# Using
## Clone and build [pedsim_ros](https://github.com/srl-freiburg/pedsim_ros)
Follow the guide [here](https://github.com/srl-freiburg/pedsim_ros/blob/master/README.md) to clone, build pedsim_ros.

**Note:**
- If you use Ubuntu 16.04/ROS Kinetic and earlier. you can skip to [Clone this project](./README.md##Clone-this-project)
- With Ubuntu 18.04/ROS Melodic, maybe you must fix [**spencer_tracking_rviz_plugin/TrackedPersons' failed to load**](https://github.com/srl-freiburg/pedsim_ros/issues/34) error as following:
```
$ cd to/top/level/catkin/workspace
$ catkin_make --only-pkg-with-deps spencer_tracking_rviz_plugin
```

## Clone this project
```
$ git clone https://github.com/AMRobots/pedsim_teb.git
```
## Try it out
```
$ roslaunch pedsim_teb pedsim_teb.launch
```
