Les valeurs aléatoire des capteurs sont créées en prenant en compte la dernière valeur aléatoire créée pour avoir des valeurs qui ont un sens. l'attribut m_data de sensor ne sert qu'à ça.

Mes méthodes aleaGenValue et aleaInitValue peuvent paraître inutilement compliquées mais je les ai construites ainsi pour que l'aléatoire soit plus efficace (car les fonctions srand et rand ne sont pas réellement aléatoires).

Mes méthodes fileWrite et fileReset ne sont pas très optimisées, je pense que j'aurais pû utiliser un for each pour éviter d'écrire manuellement les actions pour les 4 fichiers textes mais j'ai du mal a manipuler des fichiers.

J'ai fais le choix d'afficher toutes les données à chaque seconde même si elles ne changent pas toutes, c'est pourquoi certaines données ont la même valeurs pendant plusieurs secondes d'affilées.