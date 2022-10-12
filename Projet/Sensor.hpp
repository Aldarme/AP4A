/**
 * @author Erhart Eliott
 * @file Sensor.hpp
 * @date 03/10/2022
 * @brief Définition de la classe Sensor
 */

//DEFINE GUARDS
#ifndef SENSOR_H
#define SENSOR_H

/** 
 * @class Sensor
 * @brief Implémentation classe Sensor 
 */

class Sensor
{
public:
        int aleaVal;

        /// @brief Déclaration de la forme canonique de Coplien
        Sensor ():aleaVal(){}; // Constructeur par défaut
        Sensor (const Sensor& a):aleaVal(a.aleaVal){}; // Constructeur par recopie
        ~Sensor (){}; // Destructeur

        /**
         * @brief Génère une valeur aléatoire comprise entre le minimum et le maximum
         * @return this
         * @param min, max
         */
        Sensor aleaGenVal(int min, int max);
};

/** 
 * @class Humidity
 * @brief Implémentation classe Humidity
 */
class Humidity: public Sensor
{
public: 
        /**
         * @brief Affecte une valeur grâce à la méthode aleaGenVal()
         * @return Sensor
         */
        Sensor getVal();
};

/** 
 * @class Light
 * @brief Implémentation classe Light
 */
class Light: public Sensor
{
public: 
        Sensor getVal();
};

/** 
 * @class Pressure
 * @brief Implémentation classe Pressure
 */
class Pressure: public Sensor
{
public: 
        Sensor getVal();
};

/** 
 * @class Temperature
 * @brief Implémentation classe Temperature
 */
class Temperature: public Sensor
{
public: 
        Sensor getVal();
};

#endif // SENSOR_H