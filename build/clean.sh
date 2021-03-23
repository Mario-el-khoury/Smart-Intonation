#!/bin/sh
buildPath=$(cd dirname $0;pwd)
echo $buildPath

if [ -f "$buildPath/Smarto" ];then
    rm -f Smarto
    echo "rm -f Smarto"
fi 
if [ -f "$buildPath/Makefile" ];then
    rm -f Makefile
    echo "rm -f Makefile"
fi
if [ -f "$buildPath/CMakeCache.txt" ];then
    rm -f CMakeCache.txt
    echo "rm -f CMakeCache.txt"
fi
if [ -d "$buildPath/CMakeFiles" ];then
    rm -rf CMakeFiles
    echo "rm -rf CMakeFiles"
fi
if [ -d "$buildPath/Smarto_autogen" ];then
    rm -rf Smarto_autogen
    echo "rm -rf Smarto_autogen"
fi
if [ -f "$buildPath/cmake_install.cmake" ];then
    rm -f cmake_install.cmake
    echo "rm -f cmake_install.cmake"
fi