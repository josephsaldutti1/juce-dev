# juce-dev
Audio Plugins and Extensions developed from JUCE


Setting up and installing JUCE using CMAKE on a windows environment

Download and install Cmake

Download Cmake from the following website:
https://cmake.org/download/

Run the installer. After it is complete, add the cmake path to the PATH envirnoment variable:

- go to Control Panel > System and Security > System > Advanced System Settings > Environment Variables
- edit the path and add the path to Cmake. Mine was "C:\Program Files\CMake\bin

To confirm CMake is installed correctly run cmake --version in powershell or terminal

Download and Install MinGW (C and C++ compiler)

Download and install MinGW from the following website: https://nuwen.net/mingw.html
I have installed MinGW at C:\MinGW


Run Cmake

Before running CMake, we set the environment variables CC and CXX to tell cmake where to find the gcc and g++ compilers

On windows powershell:
- $env:CC = "C:\MinGW\bin\gcc"
- $env:CXX = "C:\MinGW\bin\g++"

JUCE Documentation for this part for reference (some is used): https://github.com/juce-framework/JUCE/blob/master/docs/CMake%20API.md

Run the cmake build command with the following options:

-G "MinGW Makefiles" - tells to use MinGW makefiles. Not sure exactly how this works
-B cmake-build-install - tells cmake to create the cmake build install directory here

cmake -G "MinGW Makefiles" -B cmake-build-install

I had to checkout version 6.1.2 of JUCE to get cmake with MinGW to work

Run the cmake install command:

cmake --build cmake-build-install --target install

Use cmake for your own project

Got to project directory and:

cmake -G "MinGW Makefiles" -B cmake-build -D CMAKE_PREFIX_PATH=<path_to_juce_install>
cmake --build cmake-build

For VST3 Plugin see the following:
https://github.com/pongasoft/vst3-again-sample

building this project

VST3 SDK

The VST3 SDK comes with JUCE but is not supported with MinGW: https://forum.juce.com/t/cmake-you-need-to-enable-at-least-one-plugin-format/45956/8

********************************
Needed to use Visual Studio 2022 and the Projucer to create this project. Only the source code is included here