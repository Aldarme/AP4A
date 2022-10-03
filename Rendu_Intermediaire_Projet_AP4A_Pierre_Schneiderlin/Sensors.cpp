/**
 * @author Pierre Schneiderlin
 * @file Sensor.cpp
 * @date 22/09/2022
 * @brief fichier source contenant l'implémentation des méthodes de la classe Sensor (voir "Sensor.hpp")
 */

#include "Sensors.hpp"
using namespace std;

float Sensor::aleaGenVal() const
{

    float temp;
    int signe;
    float dif;

    signe=rand()%2;
    if(signe==0)
    {                            // On affecte 1 ou -1 à l'entier signe, qui servira ensuite à définir si la valeur à ajouter sera positive ou négative
        signe=-1;
    }

    dif=float(rand()%int(((m_dataMax-m_dataMin)*10)))/100;  // On affecte à temp une valeur aléatoire entre 0 et un dixième de la différence entre
    // la valeur maximale et la valeur minimale (simulation d'un léger changement, adapté à toute plage de valeurs)

    dif*=float(signe);   // Multiplication par 1 ou -1 : valeur positive ou négative

    temp=m_data+dif;   // On affecte à temp la valeur de m_data plus la valeur d'ajout contnue dans la variable dif

    if(temp<m_dataMin)                 // On vérifie ensuite si la nouvelle valeur obtenue de dépasse pas de la plage de valeurs autorisées
    {                                  // Si c'est le cas, on fixe cette valeur à un moins ou plus la valeur de dif de l'extrémité dépassée,
        temp=m_dataMin+dif;
    }
    if(temp>m_dataMax)
    {
        temp=m_dataMax-dif;
    }
    return temp;
}

Sensor::Sensor(const Sensor& s){
    this->m_dataMin=s.m_dataMin;
    this->m_dataMax=s.m_dataMax;
    this->m_data=s.m_data;
}

Sensor& Sensor::operator=(const Sensor& s)
{
    this->m_dataMin=s.m_dataMin;
    this->m_dataMax=s.m_dataMax;
    this->m_data=s.m_data;
    return (*this);
}

ostream& operator<<(ostream& os, Sensor& s)
{
    os<<"\tdata : "<<s.m_data<<endl<<"\tdataMin : "<<s.m_dataMin<<endl<<"\tdataMax : "<<s.m_dataMax;
    return os;
}

float Sensor::getData() const
{
    return m_data;
}

float Sensor::getDataMin() const
{
    return m_dataMin;
}

float Sensor::getDataMax() const
{
    return m_dataMax;
}

void Sensor::setRandData()
{                                           // On ne peut pas donner directement une valeur à m_data comme avec les autres attributs de la classe Sensor,
    m_data=aleaGenVal();                    // car on souhaite qu'elle soit générée aléatoirement, ici via la méthode aleGenVal;
}

void Sensor::setDataMin(float dataMin)
{
    m_dataMin=dataMin;
}

void Sensor::setDataMax(float dataMax)
{
    m_dataMax=dataMax;
}

void Sensor::setAllData(float dataMin, float dataMax)        // Méthode permettant de condenser l'affectation de valeurs aux attributs de la classe Sensor
{
    setDataMin(dataMin);
    setDataMax(dataMax);
    m_data=m_dataMin+float(rand()%100*((m_dataMax-m_dataMin)+1))/100; // On affecte à m_data une valeur aléatoire dans la plage de données autorisées
}                                                                     // Sert d'initialisation à m_data avant d'être modifiée en fonction de son
// ancienne valeur par aleaGenVal
