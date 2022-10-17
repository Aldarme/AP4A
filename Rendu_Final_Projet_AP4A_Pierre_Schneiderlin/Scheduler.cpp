/**
 * @author Pierre Schneiderlin
 * @file Scheduler.cpp
 * @date 22/09/2022
 * @brief fichier source contenant l'implémentation des méthodes de la classe Scheduler (voir "Scheduler.hpp")
 */

#include "Scheduler.hpp"

using namespace std;

Scheduler::Scheduler(const Scheduler& s){
    this->m_server=s.m_server;
    this->m_temperature=s.m_temperature;
    this->m_humidity=s.m_humidity;
    this->m_light=s.m_light;
    this->m_pression=s.m_pression;
}

Scheduler& Scheduler::operator=(const Scheduler& s)
{
    this->m_server=s.m_server;
    this->m_temperature=s.m_temperature;
    this->m_humidity=s.m_humidity;
    this->m_light=s.m_light;
    this->m_pression=s.m_pression;

    return (*this);
}

Server& Scheduler::getServer()
{
    return m_server;
}

TemperatureSensor& Scheduler::getTemperatureSensor()
{
    return m_temperature;
}

HumiditySensor& Scheduler::getHumiditySensor()
{
    return m_humidity;
}

PressionSensor& Scheduler::getPressionSensor()
{
    return m_pression;
}

LightSensor& Scheduler::getLightSensor()
{
    return m_light;
}

void Scheduler::setRandDataAllSensor()
{
        getTemperatureSensor().setRandData();     // On affecte à l'attribut m_data de chaque objet de classe mère Sensor une valeur aléatoire
        getHumiditySensor().setRandData();
        getPressionSensor().setRandData();        // --> simulation d'un prélèvement de donnée par chacun des capteurs
        getLightSensor().setRandData();           // Méthode qui n'est pas utilisée dans la version finale du projet, car le prélèvement ne se fait
}                                                 // plus en même temp

int Scheduler::setPeriod(const string& type){
    cout<<endl<<"Veuillez choisir la periode de prelevement des donnees du capteur de type \""<<type<<"\" > ";
    return intInputControl(1,10000);
}

bool Scheduler::beginSimulation(int time)
{
    float temperature, humidity;
    int pression, period_t, period_h, period_p, period_l;
    bool light, sampling_test;

    cout<<endl<<"Demarrer la simulation (Oui ("<<YES<<"), ou Quitter le programme ("<<QUIT<<")) > ";    // On offre le choix à l'utilisateur de continuer
    if(!yesNoAnswerControl(YES,QUIT))                                                     // ou de quitter la simulation
    {
        return false;
    }

    period_t=setPeriod(TEMP);   // On offre à l'utilisateur la possibilité de saisir les périodes de prélèvement des différents capteurs
    period_h=setPeriod(HUM);
    period_p=setPeriod(PRE);
    period_l=setPeriod(LI);

    cout<<endl<<"Lancement de la simulation"<<endl;
    sleep(1);

    for(int i=1;i<(time*1000)+1;i++)    // On réalise autant de tours de boucle que de périodes choisies dans le main par l'utilisateur
    {                                   // (multipliées par 1000 car on lui demandait le nombre de périodes en milliers)
        sampling_test=false;
        if(i%period_t==0)                               // Pour chaque capteur :
        {
            getTemperatureSensor().setRandData();                  // Le Sensor correspondant crée une valeur aléatoire
            temperature = getTemperatureSensor().getData();            // On la récupère en l'affectant à une variable portant le nom du sensor
            getServer().consoleWrite<float>(TEMP, temperature);   // On l'écrit (ou non) dans la console, puis (ou non) dans les fichiers de log
            getServer().fileWrite<float>(FICHIER_TEMP, temperature); //(en fonctions des choix de l'utilisateur, contrôlés directement dans ces méthodes)
            sampling_test=true;
        }

        if(i%period_h==0)                     // On réalise un prélèvement des données de chaque Sensor en fonction de sa période (saisie
        {                                          // par l'utilisateur) : utilisation du modulo (%) sur l'entier itérateur i
            getHumiditySensor().setRandData();
            humidity=getHumiditySensor().getData();
            getServer().consoleWrite<float>(HUM,humidity);
            getServer().fileWrite<float>(FICHIER_HUM,humidity);
            sampling_test=true;
        }

        if(i%period_p==0)
        {
            getPressionSensor().setRandData();
            pression=getPressionSensor().getData();
            getServer().consoleWrite<int>(PRE, pression);
            getServer().fileWrite<int>(FICHIER_PRE,pression);
            sampling_test=true;
        }

        if(i%period_l==0)
        {
            getLightSensor().setRandData();
            light=getLightSensor().getData();
            getServer().consoleWrite<bool>(LI,light);
            getServer().fileWrite<bool>(FICHIER_LI,light);
            sampling_test=true;
        }

        if(sampling_test&&getServer().getConsolActivation())     // Si au moins une valeur a été écrite dans la console dans ce tour de boucle
        {                                                    // et si l'écriture dans la console est activée, on réalise un saut de ligne
            cout<<endl;                                // dans la console (pour pouvoir séparer les différents tours de boucle entre eux
        }

        //this_thread::sleep_for(chrono::milliseconds(1));
        // --> Imposer un délai dans la boucle : inutile


    }
    return true;
}
