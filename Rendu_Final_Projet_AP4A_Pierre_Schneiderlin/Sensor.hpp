/**
 * @author Pierre Schneiderlin
 * @file Sensor.hpp
 * @date 22/09/2022
 * @brief header contenant la déclaration de la classe Sensor (qui permet de générer des données pour simuler les relevés réalisés par un capteur),
 * ainsi que toutes les implémentations de ces méthodes, l'utilisation de templates empêchant de les réaliser dans un .cpp
 */

#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "main.hpp"

/**
 * @class Sensor
 * @brief Permet de générer des données pour simuler un capteur
 */
template <class T>
class Sensor {                // Cette classe est une classe template, afin de permettre à ses classes filles d'être de types différents et
                              // de néanmoins pouvoir utiliser les méthodes de leur classe mère
private:

    T m_data; ///< Contient la donnée générée par l'objet
    T m_dataMin; ///< Contient la valeur minimale que peux prendre l'attribut m_data
    T m_dataMax; ///< Contient la valeur maximale que peux prendre l'attribut m_data

    /**
     * Méthode permettant de générer une valeur aléatoire proche de celle actuelle de m_data tout en contrôlant
     * que la nouvelle valeur générée ne sorte pas de l'amplitude des valeurs autorisées
     */
    T aleaGenVal() const;

public:

    //////////////////////////////////// FORME CANONIQUE ////////////////////////////////////

    /**
     * Constructeur par défaut
     */
    Sensor<T>() : m_dataMin(), m_data(), m_dataMax() {}

    /**
     * Constructeur par recopie (par affectation d'attributs)
     * @param min - la valeur que l'on souhaite attribuer à l'attribut m_dataMin
     * @param max - la valeur que l'on souhaite attribuer à l'attribut m_dataMax
     */
    Sensor<T>(T min, T max) {setAllData(min, max);}

    /**
     * Constructeur par recopie
     * @param p - l'objet de classe Sensor à recopier
     */
    Sensor<T>(const Sensor<T>& p);

    /**
     * Destructeur
     */
    virtual ~Sensor<T>()= default;;

     /**
     * Opérateur d'affectation "="
     * @param s - l'objet de classe Sensor dont on souhaite copier les attributs dans l'objet appelé
     * @return l'objet appelé modifié
     */
    virtual Sensor<T>& operator=(const Sensor<T>& s);

    /////////////////////////////////////////////////////////////////////////////////////////

    /**
     * Méthode définissant la surcharge de l'opérateur de sortie <<
     * @param os - le flux de sortie par lequel on souhaite diriger l'objet s
     * @param s - l'objet de classe Sensor que l'on souhaite diriger vers le flux de sortie os
     * @return le flux de sortie dans lequel se trouve l'objet de classe Sensor tel qu'on souhaite qu'il soit affiché
     */
    template <typename N>
    friend std::ostream& operator<<(std::ostream& os, Sensor<N>& s);

    /**
     * Méthode permettant d'accéder à l'attribut m_data de l'objet de classe Sensor
     * @return la valeur de l'attribut m_data
     */
    T getData() const;

    /**
     * Méthode permettant d'accéder à l'attribut m_dataMin de l'objet de classe Sensor
     * @return la valeur de l'attribut m_dataMin
     */
    T getDataMin() const;

    /**
     * Méthode permettant d'accéder à l'attribut m_dataMax de l'objet de classe Sensor
     * @return la valeur de l'attribut m_dataMax
     */
    T getDataMax() const;

    /**
     * Méthode permettant d'affecter à l'attribut m_data de l'objet de classe Sensor une valeur aléatoire via
     * l'utilisation de la méthode aleaGenVal();
     */
    void setRandData();

    /**
     * Méthode permettant de modifier l'attribut m_dataMin de l'objet de classe Sensor
     * @param dataMin - la valeur à affecter à l'attribut m_dataMin
     */
    void setDataMin(T dataMin);

    /**
     * Méthode permettant de modifier l'attribut m_dataMax de l'objet de classe Sensor
     * @param dataMax - la valeur à affecter à l'attribut m_dataMax
     */
    void setDataMax(T dataMax);

    /**
     * Méthode permettant de modifier les attributs m_dataMin et m_dataMax de l'objet de classe Sensor
     * @param dataMin - la valeur à affecter à l'attribut m_dataMin
     * @param dataMax - la valeur à affecter à l'attribut m_dataMax
     */
    void setAllData(T dataMin, T dataMax);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                            ///IMPLÉMENTATION DES MÉTHODES TEMPLATES DE LA CLASSE SENSOR///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T Sensor<T>::aleaGenVal() const
{

    T temp;
    int signe;
    T dif;

    signe=rand()%2;
    if(signe==0)
    {                // On affecte 1 ou -1 à l'entier signe, qui servira ensuite à définir si la valeur à ajouter sera positive ou négative
        signe=-1;
    }

    dif=T(rand()%int(((m_dataMax-m_dataMin)*10)))/100;  // On affecte à temp une valeur aléatoire entre 0 et un dixième de la différence entre
    // la valeur maximale et la valeur minimale (simulation d'un léger changement, adapté à toute plage de valeurs)

    dif*=T(signe);   // Multiplication par 1 ou -1 : valeur positive ou négative

    temp=m_data+dif;   // On affecte à temp la valeur de m_data plus la valeur d'ajout contnue dans la variable dif

    if(temp<m_dataMin)                 // On vérifie ensuite si la nouvelle valeur obtenue de dépasse pas de la plage de valeurs autorisées
    {                                  // Si c'est le cas, on fixe cette valeur à un moins ou plus la valeur de dif de l'extrémité dépassée,
        temp=m_dataMin+dif;
    }
    if(temp>m_dataMax)
    {
        temp=m_dataMax-dif;
    }

    if(m_data==0)                     // Dans le cas où l'on doit retourner un booléen : si m_data vaut 0, on renvoie 0 (3/4 chances) ou un (1/4)
    {                                 // Cela simule une coupure de la lumière, généralement allumée dans l'avion, qui peut durer mais assez
        if(rand()%4==0){              // rapidement rétablie (retour à 1)
            return 1;
        }
        return 0;
    }

    if(m_data==1)                    // Si m_data vaut 1, la lumière est allumée, elle a beaucoup plus de chance de rester allumée (7/8) que de
    {                                // s'éteindre (1/8)
        if(rand()%8==0){
            return 0;               // (Le choix des probabilités ne suit aucun calcul, elles ont été choisies seulement parce qu'elles proposent
        }                           // une simulation à peu près correcte tout en permettant d'afficher les deux valeurs possibles dans un intervalle
        return 1;                   // de temps plutôt court
    }

    return temp;
}

template <class T>
Sensor<T>::Sensor(const Sensor<T>& s){
    this->m_dataMin=s.m_dataMin;
    this->m_dataMax=s.m_dataMax;
    this->m_data=s.m_data;
}

template <class T>
Sensor<T>& Sensor<T>::operator=(const Sensor<T>& s)
{
    this->m_dataMin=s.m_dataMin;
    this->m_dataMax=s.m_dataMax;
    this->m_data=s.m_data;
    return (*this);
}

template <class T>
std::ostream& operator<<(std::ostream& os, Sensor<T>& s)
{
    os<<"\tdata : "<<s.m_data<<std::endl<<"\tdataMin : "<<s.m_dataMin<<std::endl<<"\tdataMax : "<<s.m_dataMax;
    return os;
}

template <class T>
T Sensor<T>::getData() const
{
    return m_data;
}

template <class T>
T Sensor<T>::getDataMin() const
{
    return m_dataMin;
}

template <class T>
T Sensor<T>::getDataMax() const
{
    return m_dataMax;
}

template <class T>
void Sensor<T>::setRandData()
{                                     // On ne peut pas donner directement une valeur à m_data comme avec les autres attributs de la classe Sensor,
    m_data=aleaGenVal();              // car on souhaite qu'elle soit générée aléatoirement, ici via la méthode aleGenVal;
}

template <class T>
void Sensor<T>::setDataMin(T dataMin)
{
    m_dataMin=dataMin;
}

template <class T>
void Sensor<T>::setDataMax(T dataMax)
{
    m_dataMax=dataMax;
}

template <class T>
void Sensor<T>::setAllData(T dataMin, T dataMax)    // Méthode permettant de condenser l'affectation de valeurs aux attributs de la classe Sensor
{
    setDataMin(dataMin);
    setDataMax(dataMax);
    m_data=m_dataMin+T(rand()%100*((m_dataMax-m_dataMin)+1))/100; // On affecte à m_data une valeur aléatoire dans la plage de données autorisées
}                                                                     // Sert d'initialisation à m_data avant d'être modifiée en fonction de son
                                                                      // ancienne valeur par aleaGenVal

#endif //SENSOR_HPP
