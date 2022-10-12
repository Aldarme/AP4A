#ifndef sensor_hpp
#define sensor_hpp
//class Temperature;
#include <iostream>

#include<string>


class Sensor{
    public : 
        Sensor();
        Sensor(std::string nom, std::string unite);
        ~Sensor();
        //float getvalue(Temperature t);
        void Info();
    protected :
        std::string m_nom;
        std::string m_unite;
};

#endif /* sensor_hpp */