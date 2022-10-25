SZATKOWSKI Maxime
PROJET AP4A

*************************

L'objectif de ce projet est de simuler un environnement de capteurs à l'intérieur d'un avion en vol.
Cette environnement est  composé de quatre types de capteurs différents : 
température, la lumière, l’humidité et pression. 
Les données des capteurs sont récupérées par un Scheduler puis transmises au Serveur par ce même Scheduler.

*************************

Utilisation : 

- Le projet a été rendu avec un makefile et un fichier .exe afin de le rendre utilisable sur d'autres IDE que visual studio community et d'autres OS que windows
Le code a été commenté afin de faciliter sa compréhension

*************************

Difficultés rencontrées :

- installation du compilateur C++ impossible sur ma machine

- Utilisation de Visual Studio Community

- Risque de non fonctionnement du makefile sur des différents IDE que Visual studio Community

*************************

Class Sensor :

Elle permet de définir les classes filles de chaque capteur et donc les caractéristiques de chaque capteur.
Un capteur est composé de :
- Une valeur maximale que celui ci peut prendre
- Une valeur minimale

Elle possède comme méthode :
- getData() : Permet de créer la valeur de chaque capteur en appelant aleaGenVal
- aleaGenVal() : Génère des valeurs aléatoires pour les capteurs dans l'intervalle de valeurs propre à chacun

*************************

class Server :

Elle permet d'écrire les valeurs des différents capteurs dans les fichiers log propres à chaque capteur et/ou dans la console selon le choix de l'utilisateur
Elle comporte les méthodes suivantes :
- FileWrite() : permet d'écrire les valeurs des capteurs dans un fichier log
- ConsoleWrite() : permet d'écrire les valeurs des capteurs dans la console

*************************

class Scheduler :

Cette classe permet de faire le lien entre les classes Sensor et Server.
Elle récupère les valeurs de Sensor pour les envoyer à Server.


*************************

main() :

Dans le main, on demande à l'utilisateur combien de fois il souhaite faire l'acquisition des valeurs
Par choix, il a été décidé d'imposer l'envoi des capteurs à des intervalles définis et non modifiables pour chaques capteurs :

- Temperature : Toutes les secondes (1s)
- Humidity    : Toutes les 2 secondes (2s)
- Pressure    : Toutes les 5 secondes (4s)
- Light       : Toutes les 10 secondes (10s)


*************************

Points d'améliorations : 

- Ajouter plus de capteurs pour se rapprocher d'une simulation plus "réaliste" d'un avion
- Générer des valeurs aléatoires pour les capteurs avec des écarts moins importants et donc plus réaliste d'un instant t à un instant t+1 (avoir 20°c à 1 seconde puis 17°c à 2 secondes puis 23°c à 3 secondes)
--> mise en place d'une autre fonction aléatoire qui ajoute +/- 3% de la première valeur générée d'un instant t à un instant t+1
