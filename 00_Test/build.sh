#!/bin/bash
# Program:build a  project

###
 # @Descripttion: build.sh
 # @version: V1.00
 # @Company: SUNRI
 # @Author: Allen zhuang
 # @Date: 2020-09-23 14:20:38
 # @LastEditors: Allen Zhuang
 # @LastEditTime: 2020-09-23 15:56:37
### 

test -e build/ || mkdir build
echo "mkdir build"

test -e bin/ || mkdir bin
echo "mkdir bin"

cd build/
cmake ..
make

