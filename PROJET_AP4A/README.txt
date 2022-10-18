RENON Emilien
PROJET AP4A

===================

Le but du projet est de simuler le fonctionnement de capteur à l'intérieur d'un avion : capteur de température,
d'humidité, de pression et de lumière.
Les données des capteurs sont récupérés par un Scheduler. Ce Scheduler va envoyer ces données au Serveur.

===================

Class Sensor :

Elle permet d'initialiser les classes filles de chaque capteur.
Un Sensor aura pour attributs :
 - Un nom
 - Une énumération
 - Une valeur
Elle aura comme méthodes :
 - void aleavalue() : générer aléatoirement les valeurs des capteurs.
Elle aura comme fonction amies : 
 - ostream& operator<<(std::ostream &param_os,const Sensor<U> &param_sensor)
 - ofstream& operator<<(std::ofstream &param_of, const Sensor<U> &param_sensor)
 qui sont des surcharges d'opérateurs pour écrire dans la console et dans un fichier.

===================

Class Server :

Elle permet d'écrire les données dans la console et dans un fichier.
Elle aura comme méthodes :
 - void consoleWrite(const Sensor<T> &param_sensor)
 - void fileWrite(const Temperature<T> &param_sensor)
 - void fileWrite(const Humidity<T> &param_sensor)
 - void fileWrite(const Pression<T> &param_sensor)
 - void fileWrite(const Light<T> &param_sensor)

===================

Class Scheduler :

Elle est la jointure entre le Serveur et les Capteurs.
Un Scheduler aura pour attributs :
 - Temperature
 - Humidity
 - Light
 - Pression
 - Server 
Elle aura comme méthode :
 - void sendServer(int param_time_occur,int param_time_temperature,int param_time_pression,int param_time_light,int param_time_humidity)
 qui utilise les méthodes du Serveur afin de lui envoyer directement les valeurs des capteurs.


===================

Main :

Dans le main, le programme demande les intervals de temps de chaque capteur et le temps d'étude des capteurs.
Une boucle est alors mise en place temps que le temps d'étude n'est pas fini, appelant la méthode sendServer de Scheduler.