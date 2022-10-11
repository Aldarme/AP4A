/*!
 * @author  Cuenot Benoit  
 * @file    Sensor.hpp
 * @date    11/10/2022  
 * @brief   Cette classe est le Sensor.hpp. C'est la class Mère des différents capteurs où
 *          les attributs et méthodes vont pouvoir être instanciés. Les class Filles vont alors
 *          hériter des méthodes et attributs.
 *          On considère ici un avion étant entre 8000 mètres et 11 000 mètres d'altitudes pour les données de capteurs.      
 */


#ifndef SENSOR_HPP_INCLUDED
#define SENSOR_HPP_INCLUDED

class Sensor{   /*!< La classe Sensor est considéré comme une classe abstraite car cela n'a pas de sens de créer une classe Sensor sans spécifier quel type de capteur*/
  
    protected : /*!< Ces données sont mis en protected pour que les class filles puissent hériter*/

            int m_donneeCapteur;
            virtual int aleaGenVal() = 0; /*!< Le mot virtual est placé devant cette fonction car elle sera redéfinie pour chaque capteur.*/
      
    public :
        
            Sensor(int donneeCapteur_p = 0);
            Sensor(const Sensor& objSensor_p);
            ~Sensor();
            int ValeurData(); /*!< Permet uniquement de retourner la valeur de capteur, elle sera utile pour ensuite transmettre les données au Server*/ 
            int getData(); /*!< La méthode getData() d'attribuer une valeurs aléatoire à m_donneeCapteur*/
};

#endif // SENSOR_HPP_INCLUDED