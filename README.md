# AP4A
UTBM_UV_C++

Rendu intermédiaire projet AP4A

Dans ce rendu intermédiaire, l'utilisateur commence en recevant trois messages : il doit renseigner le temps de la simulation,
s'il affiche dans la console les valeurs, et s'il active l'écriture des valeurs dans les logs. En cas de valeur entrée incorect,
le temps de simulation ne pourra pas exeder 10 minutes et des messages d'erreurs sont affichés pour les deux dernières entrées.

Le Scheduler est le point centrale de ce projet. Il initialise les 4 sensors ainsi que le server. Les fonctions simulation de ses 
5 objets tournent en boucle pour modifier à interval régulier leurs valeurs ( et afficher à intervale régulier pour le serveur ). 
Pour faire cella j'ai diviser le tread principal en 5 sous-threads.

J'ai rencontrer un léger problème dans les thread des sensor avec la fonction random. Le problème étant que la fonction random utilise
l'horloge interne de la machine pour créer des valeurs aléatoire mais dans les threads la fonction rand utilisais "l'horloge du thread".
En bref tout les thread renvoyaient la même valeur. Pour régler ce problème j'ai re créer une fonction Rand (intRand) dans Sensor pour que
celle-ci fasse appel à l'horloge global et non local au thread.

J'ai aussi modifier la fonction aleaGenVal pour que le simulateur renvoient des valeurs plus cohérentes. En effet en utilisant symplement la
fonction random pour affecter des valeurs on se retrouve avec par exemple une température qui passe de 15 à 30 °C en une seconde. J'ai donc
fait en sorte que la fonction aleaGenVal renvoie une petite valeur (aléatoire dans un équart de 10% de l'équart entre le max et le min) qui
sera ensuite ajouté ou soustrait (ajout de valeur négatif) à la valeur du sensor. De plus je me suis inspiré de la figure ci-dessous pour
faire en sorte que, plus la valeur du sensor est supérieur à la "moyenne", plus la valeur aléatoire es de chance d'être négatif (et inversement)

[Capture](https://user-images.githubusercontent.com/113534586/194127988-ca5dc5df-073d-4656-813a-846f596969cd.PNG)

Pour faire cella de manière symplifier j'ai simplement séparer l'équart entre le min et le max en 6 parties ( premier tière superieur, deuxième  
tière inferieur (à la moyenne) et modifier le min et le max de la fonction random.

Enfin, dernièrement, j'ai pris la libertée d'écrire les logs dans un fichier csv pour une facilitée de lecture. Mon projet comporte donc un seul fichier log
et non 1 par Sensor comme demandais, mais je trouve cella plus pratique à lire.
