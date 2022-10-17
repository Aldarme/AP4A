#include <iostream>
#include "Server.hpp"
#include "Server.cpp"
#include "Sensor.cpp"
#include "Sensor.hpp"
#include "Scheduler.cpp"
#include "Scheduler.hpp"
#include "Temperature.cpp"
#include "Temperature.hpp"
#include "Humidity.cpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Light.cpp"
#include "Pression.hpp"
#include "Pression.cpp"

////pour la fonction sleep
//#include <cstdlib>//pour le random
using namespace std;


int main()
{
   
   

   Server MYFIRSTSERVER;
   int option;//pour savoir l'option de l'affichage des resultats
   cout<<"\n\n";
   printf("Choisissez :\n1:Afficher les Data sur le console\n2:Enregistrer les Data dans des files txt \n3:Lire les data stockees dans les files txt\n4:Write on the console and in files (en meme temps)\nReponse:");
   scanf("%i",&option);
   if (option>4 || option<1)
   {
      cout<<"Erreur!Choisissez un bon choix";
      return 0;
   }


   Temperature temp("Celsius");//constructeur avec parametres l'unitée est Celsius
   Humidity humid;//constructeur par defaut
   Light light;
   Pression pression;
 
   
 
  

   int choix_du_fichier_a_lire=-1;
   if (option==3)//si l'option etait de lire un fichier seulement
   {
   cout<<"Choisissez quel fichier:\n1-Temperature.txt\n2-Humidity.txt \n3-Light.txt\n4-Presion.txt\nReponse:";
   cin>>choix_du_fichier_a_lire;
   }
   else//ici pour choisir les unites 
   {
      int choixtypetemp;
      int choixtypehumid;
      int choixtypePression;
      
      cout<<"\n\nChoisissez l'unite de la temperature(les donnees seront compatibles avec l'unite :)) :\n1:Celsius\n2:Fahrenheit\n";
      cin>>choixtypetemp;
      if (choixtypetemp==1){temp.setUnite("Celsius");}//bien sur L'encapsulation existe :)
      else{temp.setUnite("Fahrenheit");};
      cout<<"\nChoisissez l'unite de la Pression:\n1:hPa\n2:Bar\n";
      cin>>choixtypePression;
      if (choixtypePression==1){pression.setUnite("hPa");}
      else{pression.setUnite("Bar");};

      
   }
   cout<<"\nLoading informations...\n\n\n\n";
   if(option==2)
   {
      cout<<"les informations recupere de l'avion sont stockees dans des txt files\n(chaque instant il y a une information recu)\nVous pouvez ouvrir les fichiers pour consulter les informations en temps reels (avec le temps correspondant a chaque requete)\n ";
   }
   
   Scheduler Sched(temp,humid,light,pression);
   Sched.Scheduler_in_and_out(MYFIRSTSERVER,option,choix_du_fichier_a_lire);//va lancer l'execution

}
