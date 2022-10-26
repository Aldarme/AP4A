/** 
 * @author SCHERRER Guillaume
 * @file Sensor.hpp
 * @date 25/09/2022
 * @brief Cette classe a pour but de contenir toutes les méthodes nécéssaires pour que 
 * les capteurs héritant de cette classe puissent faire leur mesures.
 *  
*/

#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>

template <class Type_of_value>
class Sensor
{
private:

    Type_of_value m_data; // mesure fournie par le capteur ( valeur aléatoire générée par aleaGenval() )

public: 


    Sensor<Type_of_value>();   // constructeur par défaut
    ~Sensor<Type_of_value>();  // destructeur
    Sensor<Type_of_value> (Sensor<Type_of_value>& sensor); // constructeur de recopie
    Sensor<Type_of_value>& operator=(const Sensor<Type_of_value>& sensor); //opérateur d'affectation


    /** 
     * @brief Cette fonciton a pour but de "récupérer" les mesures générées en FLOAT pour le rendu intermédiaire
     * @return le type de la valeur mesurée est retourné 
     * @param //
    */
    
    Type_of_value getData();

    /** 
     * @brief Cette fonciton a pour but de "générer" les mesures du capteur en FLOAT/INT pour le rendu final
     * @return le type de la valeur mesurée est retourné 
     * @param dépend du type assigné lors de l'héritage
    */
    
    Type_of_value aleaGenVal(Type_of_value, Type_of_value);// ----> maybe la faire en "virtual" car besoin en bool pour la lumière

     /** 
     * @brief Cette fonciton a pour but de "générer" la mesure du capteur de lumière en BOOL 
     * @return le type de la valeur mesurée est retourné 
     * @param dépend du type assigné lors de l'héritage
    */

    Type_of_value aleaGenValBool(); // fct spéciale pour le type bool
                         
};// fin de définition de la classe


//définition du corps des méthodes en utilisant le système de templates 

template <typename Type_of_value>
Sensor<Type_of_value>::Sensor() 
{
     m_data=0.0;
}     // default constructor


template <typename Type_of_value>
Sensor<Type_of_value>::Sensor(Sensor<Type_of_value>& sensor) 
{
     m_data = 0.0;
}       // constructeur de recopie 


template <typename Type_of_value>
Sensor<Type_of_value>::~Sensor() 
{

}    // destructor


template <typename Type_of_value>
Type_of_value Sensor<Type_of_value>::aleaGenVal(Type_of_value min, Type_of_value max)
{
    float generated_value;
    generated_value = (float)rand() / (float)RAND_MAX ;  // valeur entre 0.0 et 1.0
    m_data =  (max - min) * generated_value + min; // m_data entre min et max
  
    return m_data; // return generated sensor value
}

template <typename Type_of_value>
Type_of_value Sensor<Type_of_value>::aleaGenValBool()
{
    m_data = rand() % 2;

    return m_data;
}

template <typename Type_of_value>
Type_of_value Sensor<Type_of_value>::getData()
{
    return m_data; 
}

#endif
