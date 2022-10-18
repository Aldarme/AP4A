/*AUTHOR: TRABOULSI Rawan
créé le 09/10/2022*/

#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include <random>
#include <cstdlib>
#include <time.h>
#include <string>

template<class T>
class Sensor {

private:
    T m_Smaxi;
    T m_Smini;
    T m_Svalue;
    
    //FORME CANONIQUE DE COPLIEN
    public:
    Sensor(){
    m_Smaxi=0;
    m_Smini=0;
    m_Svalue=0;
    }

    Sensor(const Sensor & autre){
        m_Smaxi=autre.m_Smaxi;
        m_Smini=autre.m_Smini;
        m_Svalue=autre.m_Svalue;
    }
    Sensor &operator=(const Sensor & autre){
        m_Smaxi=autre.m_Smaxi;
        m_Smini=autre.m_Smini;
        m_Svalue=autre.m_Svalue;
        return *this;
    }

    virtual ~Sensor();//destructeur 

/**************************Les Méthodes**********************************************************/
    T getMaxi(){
        return m_Smaxi;
    }
    T getMini(){
        return m_Smini;
    }
    T getValue(){
        return m_Svalue;
    }

    
    /***********************************************************************/
    /*Ces trois fonctions pour pouvoir modifier les valeurs maxi et mini */
    void setMax(T max_p){
        m_Smaxi=max_p;
    }

    void setMin(T min_p){
        m_Smini=min_p;
    }
    void setValue(T value_p){
        m_Svalue=value_p;
    }

    T getData(){
        return aleaGenVal();
    }//fct qui nous permet d'accéder à la fct aleaGenVal de type T
    

protected:
// une fct template qui génère un nombre aléatoire de type int ou float ou bool retourne un int ou float ou bool 
    T aleaGenVal(){

        if(std::is_same<T,int>::value){
            m_Svalue=rand()%(static_cast<int>(m_Smaxi)-static_cast<int>(m_Smini)+1) + static_cast<int>(m_Smini);
            return m_Svalue;
        }
        if(std::is_same<T,bool>::value){
            m_Svalue=rand()%(static_cast<bool>(m_Smaxi)-static_cast<bool>(m_Smini)+1) + static_cast<bool>(m_Smini);
            if(m_Svalue==1){
                m_Svalue==true;
            }
            if(m_Svalue==0){
                m_Svalue=false;
            }
            return m_Svalue;
        }

        if(std::is_same<T,float>::value){
            m_Svalue=(m_Smini + static_cast<float> (rand()) / (static_cast<float> (RAND_MAX/(m_Smaxi-m_Smini))));
            return m_Svalue;
        }

    }



};
#endif //SENSOR_H

