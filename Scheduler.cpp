/*author:TRABOULSI Rawan
        *SCHEDULER
        *Créé le 09/10/2022
*/ 

#include "Scheduler.hpp"
#include <unistd.h>
#include <time.h>
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Brightness.hpp"
#include "Pressure.hpp"
#include "Server.hpp"
#include "Sensor.hpp"

Scheduler::Scheduler(){

}

Scheduler :: Scheduler(const Scheduler & autre){
    m_Temp=autre.m_Temp;
    m_Humidity=autre.m_Humidity;
    m_Brightness=autre.m_Brightness;
    m_Pressure=autre.m_Pressure;

}
 Scheduler & Scheduler::operator=(const Scheduler & autre){
    m_Temp=autre.m_Temp;
    m_Humidity=autre.m_Humidity;
    m_Brightness=autre.m_Brightness;
    m_Pressure=autre.m_Pressure;
    return *this;
 }
 void Scheduler::transmetDATA(Server serverfinal_p,int temps_p,int temps_temperature_p,int temps_pressure_p,int temps_humidity_p,int temps_brightness_p){
srand(time(0));
int var_temperature,var_pressure,var_humidity,var_brightness,var_time=time(0);
 m_Temp.setMax(m_Temp.getTmax());
 m_Temp.setMin(m_Temp.getTmin());

 m_Humidity.setMax(m_Humidity.getHumiditymax());
 m_Humidity.setMin(m_Humidity.getHumiditymin());

 m_Brightness.setMax(m_Brightness.getBrightnessmax());
 m_Brightness.setMin(m_Brightness.getBrightnessmin());

 m_Pressure.setMax(m_Pressure.getPressuremax());
 m_Pressure.setMin(m_Pressure.getPressuremin());
  
  while(time(0)-var_time<=temps_p){

   if((time(0)-var_temperature)>=temps_temperature_p){
    serverfinal_p.dataRcv(m_Temp.getData(),serverfinal_p,1);
    m_Temp.setMax(m_Temp.getValue()+0.4);	
    m_Temp.setMin(m_Temp.getValue()-0.4);
    var_temperature=time(0);
   }

   if((time(0)-var_pressure)>=temps_pressure_p){
    serverfinal_p.dataRcv(m_Pressure.getData(),serverfinal_p,0);
    m_Pressure.setMax(m_Pressure.getValue()+20);
    m_Pressure.setMin(m_Pressure.getValue()-20);
    var_pressure=time(0);
   }

   if((time(0)-var_humidity)>=temps_humidity_p){
    serverfinal_p.dataRcv(m_Humidity.getData(),serverfinal_p,4);
    m_Humidity.setMax(m_Humidity.getValue()+1);
    m_Humidity.setMin(m_Humidity.getData()-1);
    var_humidity=time(0);
   }

   if((time(0)-var_brightness)>=temps_brightness_p){
    serverfinal_p.dataRcv(m_Brightness.getData(),serverfinal_p,0);
    m_Brightness.setMax(m_Brightness.getValue());
    m_Brightness.setMin(m_Brightness.getValue());
    var_brightness=time(0);
   }

  }
  }
 Scheduler::~Scheduler() 
  {
    //vide rien à faire
  }
  

