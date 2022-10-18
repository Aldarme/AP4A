/**
* @author MOhana wael
* @file : Sensor.hpp
* @date 27/09/2022
* @Description Absrtact class Sensor
*/

#include <iostream>
#include <typeinfo> 
#ifndef Sensor_h
#define Sensor_h


template <typename T>
class Sensor{

//params
protected :  T val;
protected : char Type;
protected : std::string Unite;


/***************CONSTRUCTORS***************/
//Default constructor
public : Sensor():val(0){};
//Constructor parametre
public : Sensor(T a,char Type,std::string Unite ):val(a),Type(Type),Unite(Unite){};
//Constructor par recopie
Sensor(const Sensor<T>& autre){this->val = autre.val;};

/***************OPERATORS***************/
Sensor<T>& operator=(const Sensor<T>& autre){
        this->val = autre.val;
        return *this;
}

/***************METHODS***************/
//gen random val
private : virtual void aleaGenVal()= 0;

//Get Data
public : T getData(){ 
    aleaGenVal();
    return val;
    };
//Get Type
public : char getType(){return this->Type;}
//Get Unite
public : std::string getUnite(){return this->Unite;}

/***************DESTRUCTOR***************/
virtual ~Sensor(){};

};

#endif