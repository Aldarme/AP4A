cmake_minimum_required(VERSION 3.19)
project(untitled72)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled72 main.cpp Server/Server.cpp Server/Server.h Scheduler/Scheduler.cpp Scheduler/Scheduler.h Sensor/Sensor.cpp Sensor/Sensor.h Sensor/Temperature.cpp Sensor/Temperature.h)