cmake_minimum_required(VERSION 3.19)
project(projet)

set(CMAKE_CXX_STANDARD 14)

include_directories(Logs)
include_directories(sources)
include_directories(sources/scheduler)
include_directories(sources/sensor)
include_directories(sources/server)
include_directories(sources/log)


add_executable(projet
        Sources/Scheduler/scheduler.cpp
        Sources/Scheduler/scheduler.h
        Sources/Scheduler/Time.cpp
        Sources/Sensor/humidity.cpp
        Sources/Sensor/humidity.h
        Sources/Sensor/light.cpp
        Sources/Sensor/light.h
        Sources/Sensor/pression.cpp
        Sources/Sensor/pression.h
        Sources/Sensor/temperature.cpp
        Sources/Sensor/temperature.h
        Sources/Sensor/sensor.cpp
        Sources/Sensor/sensor.h
        Sources/Server/server.cpp
        Sources/Server/server.h
        Sources/enum.h
        main.cpp)
