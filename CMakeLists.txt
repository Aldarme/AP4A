cmake_minimum_required(VERSION 3.23)
project(AP4A)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP4A
        TP1/hello_world.cpp src/Server.cpp src/Server.hpp src/Scheduler.cpp src/Scheduler.hpp src/Sensor.cpp src/Sensor.hpp src/Temperature.cpp src/Temperature.hpp src/Humidity.cpp src/Humidity.hpp src/Light.cpp src/Light.hpp src/Pressure.cpp src/Pressure.hpp src/main.cpp)
