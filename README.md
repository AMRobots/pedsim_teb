#  Introduction
This project used for bridging pedsim simulator and teb_local_planner

# Using
## Install deps
```
sudo apt install ros-melodic-costmap-converter
```

## Create workspace
```
cd
mkdir -p catkin_ws/src
cd catkin_ws/src
git clone https://github.com/AMRobots/pedsim_teb.git
wstool init
wstool merge ./pedsim_teb/install/pedsim_teb.rosinstall
wstool update
```

## Build
```
cd ~/catkin_ws
catkin_make
source devel/setup.bash
```

## Try it out without mapping and navigation
Directly convert agents from pedim to teb_local_planner's obstacles by `convert_pedsim_env_to_teb` node:

```
$ roslaunch pedsim_teb pedsim_teb_no_mapping.launch
```

## Try it out with navigation
```
$ roslaunch pedsim_teb pedsim_teb.launch
```
