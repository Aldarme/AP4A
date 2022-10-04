cmake_minimum_required(VERSION 3.7)

project(AP4A)
set (EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})
set (SOURCE main.cpp)
add_executable(project_AP4A main.cpp Humidity.cpp Humidity.hpp Light.cpp Light.hpp Pressure.cpp Pressure.hpp Scheduler.hpp Scheduler.cpp Sensor.hpp Sensor.cpp Server.cpp Server.hpp Temperature.cpp Temperature.hpp)
