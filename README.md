# AP4A
UTBM_UV_C++

Rendu Final

(J'ai utilisé des threads dans mon projet, or MinGW compile mal les threads, j'ai donc utiliser le compilateur de visual studio
pour compiler mais l'entièrtée du code fut coder sous Visual Studio Code) -> Fichier exe du projet dans Debug/SimulationAvion

Mon rendu final est quelque peut différent de rendu intèrmédiaire, j'expliquerai cela dans se fichier. Voici la
structure de mon projet.

Main :

  Main se charge de demander le temps de simulation ainsi que l'affichage ou non des logs et de la console. La fonction initialise les objets
  server et les 4 sensors ainsi que le scheduler avant d'appeler sa fonction simulation avec en paramètre le temps en secondes de simulation ainsi que
  les 4 sensors et le server

Scheduler :

  Le scheduler créer 5 threads, dans chaqun de ses threads la fonction simulation des sensors et server tournent en boucle. J'ai fait cela car dans le
  monde réel, les sensors récupèrent en permanence des données, pas uniquement quand on leurs demande de les envoyer. De même pour le serveur, dans le
  monde réel les serveurs tournent en boucle, pas uniquement lorsque l'ont modifie ou appel une de leurs données.
  Le Scheduler se contente de récupérer les données des sensor avec un getData et les envoies au serveur avec un update.
  Pour récupérer ses données à intervale de temps différents entre les sensor j'ai utilisé un simple modulo : Dans une boucle for(j ...)
  j'ai utiliser la fonction sleep_for(chrono::milliseconds(1000)) pour que chaqune des boucles dure une seconde, ainsi pour récupérer la valeur de la lumière toutes les 3 secondes j'ai symplement ajouter un if(j%3 == 0){...}

Sensor:

  Contrairement au rendu intermédiaire, on modifie les valeurs en ajoutant symplement un nombre aléatoire entre -n et n, n étant différent pour chaqun des sensors
  en focntion de se qui semble cohérent.
  La classe mère sensor est codée uniquement dans la fichier .hpp car elle posède des templates
  
  Deux fonction sont ajoutées dans Sensor : intRand() et floatRand() qui créent des valeurs aléatoires. La raison de cet ajout est que la fonction Rand() sort des valeurs identique entre les threads, j'ai donc recréer des fonctions random avec : uniform_int_distribution<int> pour créer un nombre entier aléatoire et uniform_real_distribution<float> pour créer un nombre flotant aléatoire.

Server :

    Le serveur écrit toutes les secondes les valeurs des sensors qu'il a enregistré et 
    qui sont parfois modifiés par le Scheduler.



--------------------------------------------------------------------------------------------------------------------------------
Rendu Intermédiaire projet AP4A

Dans ce rendu intermédiaire, l'utilisateur commence en recevant trois messages : il doit renseigner le temps de la simulation,
s'il affiche dans la console les valeurs, et s'il active l'écriture des valeurs dans les logs. En cas de valeur entrée incorrect,
le temps de simulation ne pourra pas exceder 10 minutes et des messages d'erreurs sont affichés pour les deux dernières entrées.

Le Scheduler est le point central de ce projet. Il initialise les 4 sensors ainsi que le server. Les fonctions simulation de ses 
5 objets tournent en boucle pour modifier à intervalle régulier leurs valeurs ( et afficher à intervale régulier pour le serveur ). 
Pour faire cela j'ai divisé le tread principal en 5 sous-threads.

J'ai rencontré un léger problème dans les thread des sensor avec la fonction random. Le problème étant que la fonction random utilise
l'horloge interne de la machine pour créer des valeurs aléatoires, mais dans les threads la fonction rand utilisais "l'horloge du thread".
En bref, tous les thread renvoyaient la même valeur. Pour régler ce problème, j'ai re créer une fonction Rand (intRand) dans Sensor pour que
celle-ci fasse appel à l'horloge globale et non local au thread.

J'ai aussi modifié la fonction aleaGenVal pour que le simulateur renvoie des valeurs plus cohérentes. En effet en utilisant simplement la
fonction random pour affecter des valeurs, on se retrouve avec par exemple une température qui passe de 15 à 30 °C en une seconde. J'ai donc
fait en sorte que la fonction aleaGenVal renvoie une petite valeur (aléatoire dans un écart de 10% de l'écart entre le max et le min) qui
sera ensuite ajouté ou soustrait (ajout de valeur négatif) à la valeur du sensor. De plus, je me suis inspiré de la figure ci-dessous pour
faire en sorte que, plus la valeur du sensor est supérieur à la "moyenne", plus la valeur aléatoire ajoutée à la valeur es de chance d'être négatif (et inversement)

[Capture](https://user-images.githubusercontent.com/113534586/194127988-ca5dc5df-073d-4656-813a-846f596969cd.PNG)

Pour faire cella de manière à simplifier, j'ai simplement séparé l'écart entre le min et le max en 6 parties ( Premier tiers supérieur, deuxième  
tiers inférieur à la moyenne, ...) et modifier le min et le max de la fonction random.

Enfin, dernièrement, j'ai pris la liberté d'écrire les logs dans un fichier csv pour une facilitée de lecture. Mon projet comporte donc un seul fichier log
et non 1 par Sensor comme demandé, mais je trouve cela plus pratique à lire.
