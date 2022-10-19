cmake_minimum_required(VERSION 3.0.0)
project(ProjetSensor VERSION 0.1.0)

add_executable(ProjetSensor src/main.cpp
    src/Scheduler.hpp src/Scheduler.cpp 
    src/Sensor.hpp  
    src/HumiditySensor.hpp src/HumiditySensor.cpp 
    src/LightSensor.hpp src/LightSensor.cpp 
    src/PressureSensor.hpp src/PressureSensor.cpp 
    src/TemperatureSensor.hpp src/TemperatureSensor.cpp 
    src/Server.hpp src/Server.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
