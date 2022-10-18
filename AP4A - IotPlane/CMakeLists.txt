cmake_minimum_required(VERSION 3.20.0)

project(IotPlane)

add_executable( IotPlane
  IotPlane.cpp
  Sensor/Sensor.hpp
  Sensor/Humidity/Humidity.cpp  Sensor/Humidity/Humidity.hpp
  Sensor/Light/Light.cpp  Sensor/Light/Light.hpp
  Sensor/Pression/Pression.cpp  Sensor/Pression/Pression.hpp
  Sensor/Temperature/Temperature.cpp  Sensor/Temperature/Temperature.hpp
  Serveur/Serveur.cpp  Serveur/Serveur.hpp
  Scheduler/Scheduler.cpp  Scheduler/Scheduler.hpp
)