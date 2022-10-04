/*      author:TRABOULSI Rawan
        *LIGHT
        *Créé le 24/09/2020 */

#include "Brightness.hpp" //inclure la classe Brightness pour affecter des valeures aux attributs 


Brightness::Brightness():m_Brightnessmax(100),m_Brightnessmin(5),m_Brightnessvalue(75){}//constructeur par defaut

Brightness::Brightness(const Brightness & autre){ //constructeur par recopie
    m_Brightnessmax=autre.m_Brightnessmax;
    m_Brightnessmin=autre.m_Brightnessmin;
    m_Brightnessvalue=autre.m_Brightnessvalue;
}
Brightness & Brightness::operator=(const Brightness & autre){ //operateur =
    m_Brightnessmax=autre.m_Brightnessmax;
    m_Brightnessmin=autre.m_Brightnessmin;
 return  *this;
}
//Les Fonctions
int Brightness::getBrightness(){
    return  m_Brightnessvalue;
}
int Brightness::getBrightnessmax(){
    return  m_Brightnessmax;
}
int Brightness::getBrightnessmin(){
    return m_Brightnessvalue;
}
Brightness::~Brightness(){

}

