/*      author:TRABOULSI Rawan
        BRIGHTNESS
        Créé le 19/09/2020 */


#ifndef BRIGHTNESS_HPP
#define BRIGHTNESS_HPP
#include "Sensor.hpp"
#include <string>

class Brightness: public Sensor{
    //FORME CANONIQUE
    public:
    Brightness();
    Brightness(const Brightness & autre);
    Brightness &operator=(const Brightness &);
    virtual~Brightness();
    //Les Méthodes
    int getBrightness();
    int getBrightnessmax();
    int getBrightnessmin();

    //Les Attributs
    private:
    int m_Brightnessmax;
    int m_Brightnessmin;
    int m_Brightnessvalue;


};

#endif //BRIGHTNESS_H