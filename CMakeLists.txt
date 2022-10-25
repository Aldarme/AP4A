cmake_minimum_required(VERSION 3.21)
project(AP4A)
set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(AP4A
        main.cpp
        Sensor.cpp Sensor.hpp Humidity.cpp Humidity.hpp Light.cpp Light.hpp Scheduler.cpp Scheduler.hpp
        Server.cpp Server.hpp Temperature.cpp Temperature.hpp Pression.cpp Pression.hpp)