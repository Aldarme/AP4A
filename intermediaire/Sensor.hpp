/**
 * @author Céliane ALLAIRE
 * @file Sensor.hpp
 * @date 28/09/2022
 * @brief 
 * */

//
//Define guards
#ifndef SENSOR_H
#define SENSOR_H


/**
 * @class Sensor
 * @brief classe sensor. Classe mère des différents sensors (ils sont dérivés de cette classe). On y génère les différentes données sur l'avion
 */
class Sensor
{
private:
    float m_data; //la donnée aléatoire à fournir
    float m_minData;
    float m_maxData;
public:
// Definition de la forme canonique
    Sensor():m_data(), m_minData(), m_maxData(){}; //Constructeur pas défaut
    Sensor(const Sensor& param_s):m_data(param_s.m_data), m_minData(param_s.m_minData), m_maxData(param_s.m_maxData){}; //Constructeur par recopie
    Sensor& operator=(const Sensor& param_s); //Opérateur d'affectation
    ~Sensor(); //Destructeur

    float aleaGenVal(); //Nous pouvons déclarer le type dans la classe sensor pour le rendu intermédiaire
    float getData();
};


#endif  // SENSOR_H