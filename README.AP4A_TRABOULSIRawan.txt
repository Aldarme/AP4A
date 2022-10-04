****************************************Bonjour,Bienvenuer sur le ReadMe de mon projet Ecosystème avion.*****************************************
*Merci de créer un fichier support pour écrire les fichiers.txt avant de compiler ou bien de changer le chemin .
**J'ai confronté beaucoup de problème avec mon compilateur j'étais obligée d'ajouter des fonctions nouvelles pour que ça compile comme "#define WIN32_LEAN_AND_MEAN" 
dans le tête de mon fichier main1.cpp
***Si vous utilisez Windows la fonction qui va renvoyer les données à des intervalles de temps précises est SSleep(ligne 80) avec l'entête windows.h; 
si vous utiliser linux il faut la remplacer par sleep(ligne 81) avec l'entête unistd.h{dans le fichier Scheduler.cpp}
****La pression est en pascal (int), l'humidité en pourcentage(int), la luminosité en lumen (int) et la temperature en degré Celsius (int) pour le rendu intérmediaire.
