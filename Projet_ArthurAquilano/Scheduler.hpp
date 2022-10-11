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

#include "Data.hpp"
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
    * @brief Récupère les valeurs générées par les sensors et les placent dans l'objet DataPacket
    * @return this
    * @param Aucun
    */
    Scheduler getData();

    /** 
    * @brief Transfère les données à la classe Server en copiant les données de Scheduler.dataValue vers Server.data
    * @return Rien
    * @param Référence à la classe Server
    */
    void sendDataToServer(Server& server);

    /** 
    * @brief Met en pause le programme pendant un certains temps (configuré par l'entier time)
    * @return Rien
    * @param Aucun
    */
    void wait();
};

#endif //SCHEDULER.H