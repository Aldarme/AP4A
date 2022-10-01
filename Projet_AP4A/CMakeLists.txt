cmake_minimum_required(VERSION 3.23)
project(Projet_AP4A)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projet_AP4A main.cpp server.cpp server.hpp sensor.cpp sensor.hpp scheduler.cpp scheduler.hpp Sensors/Temperature.cpp Sensors/Temperature.hpp Sensors/Light.cpp Sensors/Light.hpp Sensors/Humidite.cpp Sensors/Humidite.hpp Sensors/Pression.cpp Sensors/Pression.hpp)
