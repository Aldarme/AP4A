/*author:TRABOULSI Rawan 
        *SENSOR
        *Créé le 19/09/2022
        *Fichier Header dont on déclare la classe Sensor avec ses attributs et ses déclarations de méthodes*/

#ifndef SENSOR_HPP
#define SENSOR_HPP
#include <string>

class Sensor{

    protected:
    int aleaGenVal();// une fct qui génère un nombre aléatoire 


    //La FORME CANONIQUE 
    //les contructeur,operateur d'affectation et destructeur
    public:
    Sensor();//un constructeur par defaut
    Sensor(const Sensor & autre);//un constructeur de recopie
    Sensor &operator=(const Sensor &);//operateur d'affectation
    virtual ~Sensor();//destructeur 
    Sensor(int max_p, int min_p, int value_p);//constructeur parametres

    //Les Méthodes
    int getMaxi();
    int getMini();
    int getValue();

    
    /***********************************************************************/
    /*Ces trois fonctions pour pouvoir modifier les valeurs maxi et mini */
    void setMax(int max_p);
    void setMin(int min_p);
    void setValue(int value_p);

    int getData();//fct qui nous permet d'accéder à la fct aleaGenVal d'auprès les classes filles de la classe mère Sensor


    //Les Attributs (m_nomattribut le m_ pour indiquer qu'il est membre d'un objet d'une classe )
    private:
    int m_Smaxi;
    int m_Smini;
    int m_Svalue;

};
#endif //SENSOR_H

