#ifndef sensor_hpp
#define sensor_hpp
#include <iostream>

#include<string>


class Sensor{
    public : 
        Sensor();
        Sensor(std::string nom, std::string unite);
        ~Sensor();
        void Info();
    protected :
        std::string m_nom;
        std::string m_unite;
        int m_type;
};

#endif /* sensor_hpp */