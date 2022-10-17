 /*
 @author Saad Sbat
 @file Sensor.hpp
 @date 24/9/2022
 @C'est la classe Sensor qui est la classe mere des capteur et qui génére les data des capteurs(qui sont des dérivées de cette classe)
 */
#ifndef SENSOR_HPP
#define SENSOR_HPP
#include <string>
#include <iostream>

using std::string;
class Sensor
{

public: 
   float version;
   //char typesensor[12]; 
   Sensor(/* args */);
   Sensor(const Sensor & autre);
   ~Sensor(){};
   Sensor&  operator=(const Sensor &p);
   template<class T> T getData(char type[],char unite[]);
   template<class T> T aleaGenVal(char typeofsensor[],char unite[] );

};
#endif