# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté hello
project(PROJET_AP4A)

# Crée des variables avec les fichiers à compiler
set(SRCS
    Main.cpp
    Server.cpp
    Sensor.cpp
    Scheduler.cpp
    )
    
set(HEADERS
    Server.hpp
    Sensor.hpp
    Scheduler.hpp
    )

# On indique que l'on veut un exécutable "hello" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(PROJET_AP4A ${SRCS} ${HEADERS})
