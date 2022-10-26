/** 
 * @author SCHERRER Guillaume
 * @file Scheduler.cpp
 * @date 25/09/2022
 * @brief definiton ds corps des méthodes de Schedule.hpp
 *  
*/
// génériques
#include <iostream>
#include <time.h>
//#include <ncurses.h> /*for detecting keypress on unix(Mac & Linux) */
//#include <conio.h>      /*for detecting keypress on Windows */

#include "AP4A_Final.hpp"


// classes:
#include "Server.hpp"
#include "Scheduler.hpp"
#include "Sensor.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Pressure.hpp"
#include "Light.hpp"

// instancier les capteurs:
Temperature Temp_sensor(23.0f, 25.0f); //23 to 25 °C --> température moyenne dans une cabine d'avion
Humidity Humidity_sensor(10.0f, 20.0f);  // 10 to 20% rel. humidity   --> humidité moyenne
Pressure Pressure_sensor(60000.0f, 70000.0f); // 60000 to 70000 Pa (0,6 to 0,7 bars)
Light Light_sensor; 

// instancier le Serveur:
Server SensorServer;

Scheduler::Scheduler(int periode, int* PeriodeCapt) // constructor
{
    for(int i=0;i<4;i++){m_PeriodeCapt[i]=PeriodeCapt[i];} // période de chaque capteur
    m_period_in_seconds = periode; // période de base
    m_MasterCount=0;
    std::cout << "\n Relevé de Températures toutes les  " << m_PeriodeCapt[T] << " secondes \n";
    std::cout << " Relevé d'Humidité relative toutes les  " << m_PeriodeCapt[H] << " secondes \n";
    std::cout << " Relevé de Pression toutes les  " << m_PeriodeCapt[P] << " secondes \n";
    std::cout << " Relevé de Lumière toutes les  " << m_PeriodeCapt[L] << " secondes \n\n";
} 

Scheduler::~Scheduler() 
{

} // destructor


void Scheduler::ProcessScheduler() 
{
    
    ValeursCapteurs measures; // on instancie la structure de données  

    GetChoice(); // récupérer le choix d'affichage/stockage des valeurs

    std::cout << "Relevé des mesures en cours...!  \n\n";

    while ( 1 )
    {
        Delay();// attendre 1 période de base
       
        MeasureAndProcess(measures);  //"measures" est la structure des valeurs capteurs
        
        m_MasterCount++;
        
        // On demande à l'utilisateur s'il veut continuer après une aquisition complète des 4 capteurs
        int AskUser= m_PeriodeCapt[T]+m_PeriodeCapt[H]+m_PeriodeCapt[P]+m_PeriodeCapt[L];
        if((m_MasterCount%AskUser)==0 && (!Keypress()))
        {
          break;
        }

    } // fin boucle infinie

    Stop(); // on arrête le programme
}


void Scheduler::TransferDataToServer(ValeursCapteurs &valeurs)
{
    SensorServer.UpdateValues(valeurs,m_choix_save);
}

void Scheduler::Stop()
{
    SensorServer.CloseAll();
}

int Scheduler::GetChoice()
{

    std::cout <<"Comment souhaitez-vous sauvegarder les valeurs ? \n";
    std::cout <<"1) Uniquement dans le terminal \n";
    std::cout <<"2) Uniquement dans les fichiers de log de chaque capteur\n";
    std::cout <<"3) Dans le terminal et dans les fichiers de log\n";

    //scan du choix de l'utilisateur

    std::cin >> m_choix_save; //global var 
    
    std::cout <<"Votre choix:"<<  m_choix_save <<"\n";


    return m_choix_save;
}


void Scheduler::Delay()
{
    int delay_in_clocks = m_period_in_seconds * CLOCKS_PER_SEC;

    // attendre  m_period_in_seconds:
    clock_t Start_tick = clock();
    
    while ( (clock() - Start_tick) < delay_in_clocks)   // tant que le nombre de ticks est inférieur au délai programmé "CapturePeriod"    
    {
        //attendre
    }
}

void Scheduler::MeasureAndProcess(ValeursCapteurs &vals_caps) 
{
    //générer les valeurs et les récupérer:
    if(m_MasterCount%m_PeriodeCapt[T]==0)
    { 
        vals_caps.m_measured_Temperature = Temp_sensor.aleaSensorVal(); 
    }
    if(m_MasterCount%m_PeriodeCapt[H]==0)
    { 
        vals_caps.m_measured_Humidity = Humidity_sensor.aleaSensorVal();
    }
    if(m_MasterCount%m_PeriodeCapt[P]==0)
    { 
        vals_caps.m_measured_Pressure = Pressure_sensor.aleaSensorVal(); 
    }
    if(m_MasterCount%m_PeriodeCapt[L]==0)
    { 
        vals_caps.m_measured_Light = Light_sensor.aleaSensorVal(); 
    }
    
    if(m_MasterCount%m_PeriodeCapt[T]==0 || m_MasterCount%m_PeriodeCapt[H]==0 || m_MasterCount%m_PeriodeCapt[P]==0 || m_MasterCount%m_PeriodeCapt[L]==0)
    {
      TransferDataToServer(vals_caps); // on tranfert les 4 mesures ( même si certaines sont inchangées)
    }
          
}

bool Scheduler::Keypress()
{

    char refaire_mesure;

    std::cout<< "\nvoulez-vous continuer de mesurer? \n";
    std::cout<< "\nTapez 'o' si vous souhaitez continuer les mesures \n";
    std::cout<< "Tapez 'n' si vous souhaitez arrêter les mesures \n\n";
    
    std::cin>> refaire_mesure;

    
    while( (refaire_mesure!= 'o') && (refaire_mesure!= 'O') && (refaire_mesure!= 'n') && (refaire_mesure!= 'N') )
    {
        std::cout<< "\nLettre saisie incorrecte \n";
        std::cin>> refaire_mesure;
    }
 
    std::cout<< "votre choix: "<< refaire_mesure <<"  \n\n";

    if(refaire_mesure== 'o' || refaire_mesure== 'O' )  // choix = YES
    {
        return true;
    }
    else // choix = 'n' ou 'N' pour dire NO
    {
        return false;
    }

}
