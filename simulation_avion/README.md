Projet AP4A
================ 
par Gilles Maurer 
12/10/2022

Simulation du système interne d'un avion en c++.

Le scheduler récupère les informations de 4 sensors (Humidity, Pression, Light et Température) et les envoies au server. 
Le server écrit les données dans la console et dans les fichiers de log correspondant à chaque capteur. 

L'utilisateur peut choisir d'activer ou non la console et les logs. 
L'utilisateur peut choisir le délai de temps entre chaque relevé d'information pour chaque capteur indépendamment. 
