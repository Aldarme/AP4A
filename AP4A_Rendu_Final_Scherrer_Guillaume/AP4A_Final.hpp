/** 
 * @author SCHERRER Guillaume
 * @file AP4P_Intermediaire.hpp
 * @date 25/09/2022
 * @brief definiton de constantes et enums etc... 
*/

#ifndef AP4A_H
#define AP4A_H

#define T 0
#define H 1
#define P 2
#define L 3

struct ValeursCapteurs
{
    float m_measured_Temperature;
    float m_measured_Humidity;
    int m_measured_Pressure;
    int m_measured_Light;

};

#endif