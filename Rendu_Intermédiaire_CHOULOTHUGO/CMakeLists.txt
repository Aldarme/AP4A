cmake_minimum_required(VERSION 3.0)

project(MonProjet)

set(SRCS
    Main.cpp
    Server.cpp
    Sensor.cpp
    Scheduler.cpp
    )
    
set(HEADERS
    Server.hpp
    Sensor.hpp
    Scheduler.hpp
    )

add_executable(Main ${SRCS} ${HEADERS})