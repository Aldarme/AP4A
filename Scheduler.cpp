/*author:TRABOULSI Rawan
        *SCHEDULER
        *Créé le 29/09/2022
*/ 

#include "Scheduler.hpp"
#include <iostream>
#include <unistd.h>
#include <time.h>
#include <Windows.h> //pour la fct sleep 

Scheduler::Scheduler(){

}

Scheduler :: Scheduler(const Scheduler & autre){
    m_Temp=autre.m_Temp;
    m_Humidity=autre.m_Humidity;
    m_Brightness=autre.m_Brightness;
    m_Pressure=autre.m_Pressure;
    m_Stemperature=autre.m_Stemperature;
    m_Shumidity=autre.m_Shumidity;
    m_Slight=autre.m_Slight;
    m_Spressure=autre.m_Spressure;
}
 Scheduler & Scheduler::operator=(const Scheduler & autre){
    m_Temp=autre.m_Temp;
    m_Humidity=autre.m_Humidity;
    m_Brightness=autre.m_Brightness;
    m_Pressure=autre.m_Pressure;
    m_Stemperature=autre.m_Stemperature;
    m_Shumidity=autre.m_Shumidity;
    m_Slight=autre.m_Slight;
    m_Spressure=autre.m_Spressure;
    return *this;
 }
 void Scheduler::transmetData1(Server server_p,int frequency_p,int temps_p){
//attributsensor.fctsensor(attributscheduler.fctclasse);
 m_Stemperature.setMax(m_Temp.getTmax());
 m_Stemperature.setMin(m_Temp.getTmin());

 m_Shumidity.setMax(m_Humidity.getHumiditymax());
 m_Shumidity.setMin(m_Humidity.getHumiditymin());

 m_Slight.setMax(m_Brightness.getBrightnessmax());
 m_Slight.setMin(m_Brightness.getBrightnessmin());

 m_Spressure.setMax(m_Pressure.getPressuremax());
 m_Spressure.setMin(m_Pressure.getPressuremin());
  int j=0;
  while((temps_p/frequency_p)>j){
     if(j==0){
        m_Server.dataRcv(m_Spressure.getData(),m_Shumidity.getData(),m_Slight.getData(),m_Stemperature.getData(),server_p);
     }
     else{
        m_Spressure.setMax(m_Spressure.getValue()+1);
        m_Spressure.setMin(m_Spressure.getValue()-1);

        m_Shumidity.setMax(m_Shumidity.getValue()+3);
        m_Shumidity.setMin(m_Shumidity.getValue()-3);

        m_Slight.setMax(m_Slight.getValue()+2);
        m_Slight.setMin(m_Slight.getValue()-2);

        m_Stemperature.setMax(m_Stemperature.getValue()+1);
        m_Stemperature.setMin(m_Stemperature.getValue()-1);

        m_Server.dataRcv(m_Spressure.getData(),m_Shumidity.getData(),m_Slight.getData(),m_Stemperature.getData(),server_p);

     }
     Sleep(frequency_p*1000);
     ++j;
  }

 }
 Scheduler::~Scheduler() 
  {
    //vide rien à faire
  }
  

