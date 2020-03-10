#!/bin/bash
# this is a script shell sets up an ubuntu (16.04, 18.04) environment where
# MeshLab can be compiled.
#
# Run this script if you never installed any of the MeshLab dependencies.

sudo apt-get update 
sudo apt-get install -y qt5-default qttools5-dev-tools qtscript5-dev libqt5xmlpatterns5-dev mesa-common-dev libglu1-mesa-dev lib3ds-dev libglew-dev libeigen3-dev libopenctm-dev libgmp-dev libqhull-dev
