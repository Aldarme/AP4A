cmake_minimum_required(VERSION 3.0.0)
project(ProjetSensor VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ProjetSensor main.cpp
Scheduler.cpp Scheduler.hpp Sensor.hpp Server.cpp Server.hpp 
Temperature.hpp Temperature.cpp Pression.cpp Pression.hpp Light.cpp Light.hpp Humidity.cpp Humidity.hpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
