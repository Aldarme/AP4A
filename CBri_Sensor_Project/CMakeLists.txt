cmake_minimum_required(VERSION 3.10)

project(Sensor_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sensor_Project main.cpp Humidity.cpp Humidity.hpp Pressure.cpp Pressure.hpp Temperature.cpp Temperature.hpp Light.cpp Light.hpp Sensor.cpp Sensor.hpp Scheduler.cpp Scheduler.hpp Server.cpp Server.hpp)