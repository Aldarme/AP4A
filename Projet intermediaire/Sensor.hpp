/**
 * @author Tontsa apala frank
 * @file Sensor.hpp
 * @date 25/09/2022
 * @brief Sensor
 */

#ifndef SENSOR_H
#define SENSOR_H
class Sensor{
    
    protected :  int m_val;



    public : Sensor();  //constructeur par defaut

    Sensor(const Sensor& S); //constructeur de recopie
 
    Sensor& operator=(const Sensor& S);


    private : void aleaGenVal();

    public : int getData();

~Sensor();




};

#endif   //SENSOR_H
