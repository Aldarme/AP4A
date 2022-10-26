cmake_minimum_required(VERSION 3.0.0)
project(Projet VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Projet main.cpp Humidity.cpp Humidity.hpp Light.cpp Light.hpp Temperature.cpp Temperature.hpp Sensor.cpp Sensor.hpp Pressure.cpp Pressure.hpp Server.cpp Server.hpp Scheduler.cpp Scheduler.hpp) 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)