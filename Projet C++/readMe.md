# Projet C++ --- BENEDUCI Marie

## Rendu Intermédiaire

### Compilation et Lancement de l'application

#### 1. Creation des differents fichiers .o (apres s'etre placé dans le dossier cpp)
    g++ -c Sensor.cpp
    g++ -c Temperature.cpp
    g++ -c Light.cpp
    g++ -c Humidity.cpp
    g++ -c Sound.cpp
    g++ -c Server.cpp
    g++ -c Scheduler.cpp
    g++ -c main.cpp

#### 2. Création du fichier executable
    g++ -o app main.o Scheduler.o Sensor.o Server.o Temperature.o Light.o Sound.o Humidity.o

#### 3. Lancement du programme
    ./app

### Remarques

- Lors de la compilation du fichier 'Scheduler.cpp' des warnings concerant les char[] apparaissent me demandant de les remplacer par des Strings cependant je n'ai pas réussi à les implémenter

- Lors de l'execution du programme, uniquement 5 instances seront lancés et il s'arretera automatiquement, c'est un choix. Concernant l'affichage que ce soit dans le fichier log ou la console, l'instance en cours sera affiché à chaque fois.

## Rendu Final

#### 1. Creation des differents fichiers .o (apres s'etre placé dans le dossier cpp)
    g++ -c Sensor.cpp Temperature.cpp Pression.cpp Humidity.cpp Light.cpp Server.cpp Scheduler.cpp main.cpp 

#### 2. Création du fichier executable
    g++ -o app Sensor.o Temperature.o Pression.o Humidity.o Light.o Server.o Scheduler.o main.o 
    
#### 3. Lancement du programme
    ./app

### Remarques

- Les commandes de lancement sont legerement differente car par inadvertance j'avais nommé une de mes classes capteurs "Sound" au lieu de "Pression" lors de mon rendu intermédiaire. J'ai donc réalisé les modifications nécéssaire pour le rendu final.
- Depuis le rendu intermédiaire j'ai trouvé une solution à mon problème de char[]
- Lors de l'execution du programme, apres les differents choix de l'utilisateur, uniquement 15 instances seront lancés et il s'arretera automatiquement, c'est un choix. Concernant l'affichage que ce soit dans le fichier log ou la console, l'instance en cours sera affiché à chaque fois (elle pourra etre differente dans le fichier et dans le terminal car l'instance général de 1 seconde ne correspond pas forcement à l'instance d'un capteur particulier qui peut etre relevé toute les 6 secondes par exemple).
