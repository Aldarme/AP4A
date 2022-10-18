/*      author:TRABOULSI Rawan
        *LIGHT
        *Créé le 09/10/2020 */

#include "Brightness.hpp" 


Brightness::Brightness():m_Brightnessmax(1),m_Brightnessmin(0){}//constructeur par defaut

Brightness::Brightness(const Brightness & autre){ //constructeur par recopie
    m_Brightnessmax=autre.m_Brightnessmax;
    m_Brightnessmin=autre.m_Brightnessmin;
    
}
Brightness & Brightness::operator=(const Brightness & autre){ //operateur =
    m_Brightnessmax=autre.m_Brightnessmax;
    m_Brightnessmin=autre.m_Brightnessmin;
 return  *this;
}
//Les Fonctions
/*int Brightness::getBrightness(){
    return  m_Brightnessvalue;
}*/
int Brightness::getBrightnessmax(){
    return  m_Brightnessmax;
}
int Brightness::getBrightnessmin(){
    return m_Brightnessmin;
}
Brightness::~Brightness(){

}

