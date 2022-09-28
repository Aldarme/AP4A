### AP4A - Projet | Rendu Final

L'écosystème génère les données de 4 capteurs, retournant des types de données différents:
- Température, Humidité : float
- Lumière : boolean
- Pression : integer

Chaque capteur a sa propre classe héritant d'une classe template Sensor, le template étant utilisé pour modifier le type de retour des mesures du capteur.

Le serveur (classe Server) gère la sortie de données. Elle écrit les mesures dans la console et dans des fichiers de log, en utilisant des méthodes templates pour être modulaire quant aux types de retour des capteurs .

La classe Scheduler gère l'envoie de données au serveur et la récupération de données des capteurs.<br/>
Elle utilise un thread différent pour chaque capteur, le délai entre deux mesures étant différent pour chaque capteur. Ces mesures sont donc récupérées à intervalle régulier pour chaque capteur et envoyées au serveur.

L'utilisateur peut choisir au début du programme si les données seront écrites dans les fichiers de log et dans la
console. Il peut aussi choisir la durée de la simulation.

Commit final : <br/>
Commit intérmédiaire : https://github.com/Aldarme/AP4A/tree/48d6141ba2cdadfe6410bcc164c9742776daa537