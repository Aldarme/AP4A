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

ostream& operator<<(ostream& os, Scheduler& s)
{
    os<<"SERVER :"<<endl<<s.m_server<<endl<<"TEMPERATURE SENSOR : "<<endl<<s.m_temperature<<endl;
    os<<"HUMIDITY SENSOR : "<<endl<<s.m_humidity<<endl<<"PRESSION SENSOR : "<<endl<<s.m_pression;
    os<<endl<<"LIGHT SENSOR : "<<endl<<s.m_light;
    return os;
}
Server& Scheduler::getServer()
{
    return m_server;
}

Sensor& Scheduler::getTemperatureSensor()
{
    return m_temperature;
}

Sensor& Scheduler::getHumiditySensor()
{
    return m_humidity;
}

Sensor& Scheduler::getPressionSensor()
{
    return m_pression;
}

Sensor& Scheduler::getLightSensor()
{
    return m_light;
}

void Scheduler::setRandDataAllSensor()
{
        getTemperatureSensor().setRandData();     // On affecte à l'attribut m_data de chaque objet de classe mère Sensor une valeur aléatoire
        getHumiditySensor().setRandData();
        getPressionSensor().setRandData();        // --> simulation d'un prélèvement de donnée par chacun des capteurs
        getLightSensor().setRandData();
}

void Scheduler::sendDataToServer(int time)
{
    float temperature, humidity, pression, light;

    for(int i=0;i<time;i++)
    {
        setRandDataAllSensor();

        temperature=getTemperatureSensor().getData();            // On récupère les données aléatoires engendrées que l'on stocke dans des variables
        humidity=getHumiditySensor().getData();
        pression=getPressionSensor().getData();

        if(getLightSensor().getData()<0.5)                       // Le système de génération de valeur étant adapté aux flottants, la valeur de m_data de
        {                                                        // l'objet de classe LightSensor se situe entre 0 et 1. Afin qu'elle soit égale soit à 0,
            light=0;                                             //soit à 1, on réalise un test découpant en deux l'écart entre 0 et 1, affectant ensuite
        }
        else                                                    // 0 à light si la valeur de m_data est inférieure à 0.5, ou 1 si elle est supérieure
        {
            light=1;
        }

        if(getServer().getConsolActivation())        // On teste la valeur de l'attribut m_consolActivation de l'attribut 'objet de classe Server' de
        {                                                // l'objet de classe Scheduler, afin d'afficher ou non les données dans la console
            getServer().consoleWrite(UNITE_TEMP,temperature);
            cout<<"\t";
            getServer().consoleWrite(UNITE_HUM,humidity);
            cout<<"\t";
            getServer().consoleWrite(UNITE_PRE, pression);
            cout<<"\t";
            getServer().consoleWrite(UNITE_LI,light);
            cout<<endl;
        }

        if(getServer().getLogActivation())     // On teste la valeur de l'attribut m_logActivation de l'attribut 'objet de classe Server' de
        {                                                // l'objet de classe Scheduler, afin d'afficher ou non les données dans les fichiers correspondants
            getServer().fileWrite(FICHIER_TEMP,temperature);
            getServer().fileWrite(FICHIER_HUM,humidity);
            getServer().fileWrite(FICHIER_PRE,pression);
            getServer().fileWrite(FICHIER_LI,light);
        }

        sleep(1);  // On impose un délai d'une seconde avant de relever et d'afficher et/ou écrire à nouveau les données
    }
}