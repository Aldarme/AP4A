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

## Remarques

- Lors de la compilation du fichier 'Scheduler.cpp' des warnings concerant les char[] apparaissent me demandant de les remplacer par des Strings cependant je n'ai pas réussi à les implémenter

- Lors de l'execution du programme, uniquement 5 instances seront lancés et il s'arretera automatiquement, c'est un choix. Concernant l'affichage que ce soit dans le fichier log ou la console, l'instance en cours sera affiché à chaque fois.
