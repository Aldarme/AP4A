cmake_minimum_required(VERSION 3.10)

# set the project name
project(SimulationAvion)

find_package(Threads REQUIRED)

# add the executable
add_executable(SimulationAvion 
    main.cpp 
    Server/Server.cpp Server/Server.hpp
    Sensor/Sensor.cpp Sensor/Sensor.hpp
    Sensor/Humidity.cpp Sensor/Humidity.hpp
    Sensor/Light.cpp Sensor/Light.hpp
    Sensor/Pression.cpp Sensor/Pression.hpp
    Sensor/Temperature.cpp Sensor/Temperature.hpp
    Scheduler/Scheduler.cpp Scheduler/Scheduler.hpp
)

target_link_libraries(SimulationAvion PUBLIC Threads::Threads)