cmake_minimum_required(VERSION 3.0.0)
project(ProjetAP4A VERSION 0.1.0)

add_executable(ProjetAP4A 
  src/Package.hpp
  src/Scheduler.cpp src/Scheduler.hpp
  src/Server.cpp src/Server.hpp
  src/Sensor/Sensor.hpp
  src/Sensor/Humidity.cpp src/Sensor/Humidity.hpp
  src/Sensor/Light.cpp src/Sensor/Light.hpp
  src/Sensor/Pressure.cpp src/Sensor/Pressure.hpp
  src/Sensor/Temperature.cpp src/Sensor/Temperature.hpp
  src/main.cpp)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "./src")