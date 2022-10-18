/*      author:TRABOULSI Rawan
        *PRESSURE
        *Créé le 24/09/2020          */
#include "Pressure.hpp"

Pressure::Pressure():m_Pmax(305000),m_Pmin(116358),m_Pvalue(20000){

}
Pressure::Pressure(const Pressure & autre){
    m_Pmax=autre.m_Pmax;
    m_Pmin=autre.m_Pmin;
    m_Pvalue=autre.m_Pvalue;
}

Pressure & Pressure::operator=(const Pressure & autre){
    m_Pmax=autre.m_Pmax;
    m_Pmin=autre.m_Pmin;
    m_Pvalue=autre.m_Pvalue;
    return *this;
}
//Les Fonctions
int Pressure::getPressuremax(){
return m_Pmax;
}
int Pressure::getPressuremin(){
    return m_Pmin;
}
int Pressure::getPvalue(){
    return m_Pvalue;
}

Pressure::~Pressure(){}

