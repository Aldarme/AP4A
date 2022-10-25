/**
 * @author Arthur
 * @file Scheduler.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe Scheduler
 */

//DEFINE_GUARDS
#ifndef SCHEDULER_H
#define SCHEDULER_H

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "DataPacket.hpp"
#include "Server.hpp"

/**
* @class Scheduler
* @brief Déclaration de la classe Scheduler
*/
class Scheduler
{
public:
    DataPacket dataValue;

    /** 
    * @brief Déclaration de la forme canonique de coplien
    * @return Rien
    * @param Ceux par défaut
    */
    Scheduler(): dataValue(){};
    Scheduler(const Scheduler& s): dataValue(s.dataValue){};
    ~Scheduler(){};

    /** 
    * @brief Récupère les valeurs générées par les sensors et les placent dans l'objet DataPacket à différent intervales 
    * @return this
    * @param Entier temps 
    */
    Scheduler getData(int time);

    /** 
    * @brief Transfère les données à la classe Server en copiant les données de Scheduler.dataValue vers Server.data
    * @return Rien
    * @param Référence à la classe Server et un entier temps
    */
    void sendDataToServer(int time, Server& server);

};

#endif //SCHEDULER.H