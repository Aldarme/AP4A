# Projet C++ --- BENEDUCI Marie

## Compilation et Lancement de l'application

    - Creation des differents fichiers .o (apres s'etre placé dans le dossier cpp)
    ''' g++ -c Sensor.cpp '''
    ''' g++ -c Temperature.cpp '''
    ''' g++ -c Light.cpp '''
    ''' g++ -c Humidity.cpp '''
    ''' g++ -c Sound.cpp '''
    ''' g++ -c Server.cpp '''
    ''' g++ -c Scheduler.cpp '''
    ''' g++ -c main.cpp '''

    - Création de mon fichier executable
    ''' g++ -o app main.o Scheduler.o Sensor.o Server.o Temperature.o Light.o Sound.o Humidity.o '''

    - Lancement du programme
    ''' ./app '''

