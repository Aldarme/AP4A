# Projet C++ --- BENEDUCI Marie

## Compilation et Lancement de l'application

### 1. Creation des differents fichiers .o (apres s'etre placé dans le dossier cpp)
    g++ -c Sensor.cpp
    g++ -c Temperature.cpp
    g++ -c Light.cpp
    g++ -c Humidity.cpp
    g++ -c Sound.cpp
    g++ -c Server.cpp
    g++ -c Scheduler.cpp
    g++ -c main.cpp

### 2. Création du fichier executable
    g++ -o app main.o Scheduler.o Sensor.o Server.o Temperature.o Light.o Sound.o Humidity.o

### 3. Lancement du programme
    ./app

