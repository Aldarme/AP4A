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
   //C'est pour tester les differentess constructeurs:

  // Server MYFIRSTSERVER2=MYFIRSTSERVER;    
   //Server MYFIRSTSERVER3;
   //MYFIRSTSERVER3=MYFIRSTSERVER2;

   int choix2;//pour savoir ou on doit afficher les resultats
   cout<<"\n\n";
   printf("Choisissez :\n1-Afficher les Data sur le console\n2-Enregistrer les Data dans un file txt \n3-Lire les data stockees dans le file\nReponse:");
   scanf("%i",&choix2);
   if (choix2>3 || choix2<1)
   {
      cout<<"Erreur!Choisissez un bon choix";
      return 0;
   }

//les unitées des capteurs sont par defaut :celsius,%,dB,Hpa.



   Temperature temp("C");//constructeur avec parametres l'unitée est C
   Humidity humid;//constructeur par defaut
   Light light;
   
   Pression Pression;
   Pression.setUnite("hPa");//encapsulation
   
 
   //light.unite="GDB";Interdit (attribut privé)
   //cout<<"HI\n"<<temp.getUnite()<<" \n";//pour afficher l'unite choisit
   Scheduler Sched(temp,humid,light,Pression);//sched e a pour attribut les differents capteurs
  //je teste les constructeurs
   Scheduler Sched2=Sched;//je teste le constructeur par recopie
   Scheduler Sched3;
   Sched3=Sched2;
   //je teste l'operateure d'affectation de sched
   //cout<<Sched.getTemp().type;Encapsulation des attributs de sched

   //je suis entrain de tester l'encapsulation des attribus du scheduler
   Temperature temp3;
   temp3=Sched.getTemp();//je suis entrain de tester l'encapsulation des attribus du scheduler
   temp3.setUnite("Celsius");
   Sched.setTemp(temp3);
   //cout<<"VERSION"<<temp3.version;
   cout<<"\nLoading information...\n\n\n\n";
   if(choix2==2)
   {
      cout<<"les informations recupere de l'avion sont stockees dans le log file\n(chaque 1 seconde il y a une information recu)\nVous pouvez ouvrir le log.txt pour consulter les informations avec le temps correspondant a chaque requete\n ";
   }
   Sched.Scheduler_in_and_out(MYFIRSTSERVER,choix2);//va lancer l'execution
}
