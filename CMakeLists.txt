cmake_minimum_required(VERSION 3.7)

project(AP4A)
set (EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})
set (SOURCE main.cpp)
add_executable(project_AP4A main.cpp  Scheduler.hpp Scheduler.cpp Server.cpp Server.hpp Humidity.cpp Humidity.hpp Light.cpp Light.hpp Pressure.cpp Pressure.hpp Sensor.hpp Sensor.cpp Temperature.cpp Temperature.hpp)
