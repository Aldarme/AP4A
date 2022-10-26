/**
 * @author lois ROGER
 * @file Sensor.hpp
 * @date 05/09/2022
 * @brief les capteurs permettent de créer différentes données et de les récupérer
*/
#ifndef SENSOR_H
#define SENSOR_H

template <class T>
class Sensor
{
    public:
    Sensor<T>();
    Sensor<T>(const Sensor<T>& s);
    ~Sensor<T>();
    virtual T getData(T mini, T maxi); // fonction qui récupère une donnée aléatoire
    virtual T aleaGenVal(T mini, T maxi); // fonction qui génère une valeur aléatoire entre 2 valeur
    
    
    
};

#endif