/*author:TRABOULSI Rawan
        *TEMPERATURE
        *Créé le 24/09/2022
*/
#include"Temperature.hpp"
#include <iostream>


Temperature::Temperature():m_Tmax(80),m_Tmin(0),m_Temp(42){

}

Temperature::Temperature(const Temperature & autre){
    m_Tmax=autre.m_Tmax;
    m_Tmin=autre.m_Tmin;
    m_Temp=autre.m_Temp;
}

Temperature & Temperature::operator=(const Temperature & autre){
    m_Tmax=autre.m_Tmax;
    m_Tmin=autre.m_Tmin;
    m_Temp=autre.m_Temp;
    return *this;
}
//Les Fonctions
int Temperature::getTmax(){
    return m_Tmax;
}
int Temperature::getTmin(){
    return m_Tmin;
}
int Temperature::getTemp(){
    return m_Temp;
}

Temperature::~Temperature(){
    
}
