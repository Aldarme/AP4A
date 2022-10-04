/*           author:TRABOULSI Rawan
        *HUMIDITY
        *Créé le 24/09/2022          */

#include"Humidity.hpp"
//je créé un nouveau objet Humidity avec le costructeur par defaut et j'affecte à ses attributs des valeurs
Humidity::Humidity():m_humiditymax(60),m_humiditymin(30),m_humidityvalue(45){}

//Par le constructeur de recopie 
Humidity::Humidity(const Humidity & autre){
m_humiditymax=autre.m_humiditymax;
m_humiditymin=autre.m_humiditymin;
m_humidityvalue=autre.m_humidityvalue;
}

Humidity & Humidity:: operator=(const Humidity & autre){
m_humiditymax=autre.m_humiditymax;
m_humiditymin=autre.m_humiditymin;
m_humidityvalue=autre.m_humidityvalue;
return *this;
}

//Les Fonctions 
int Humidity::getHumidity(){
    return m_humidityvalue;
}

int Humidity::getHumiditymax(){
    return m_humiditymax;
}

int Humidity::getHumiditymin(){
    return m_humiditymin;
}

Humidity::~Humidity(){
    //ne fait rien 
}

