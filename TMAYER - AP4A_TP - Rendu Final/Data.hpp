/*
 * @author Thibault MAYER
 * @file Data.hpp
 * @date 20/10/2021
 * @brief cette classe sert de template pour les valeurs des capteurs
 */

#ifndef DATA_HPP_
#define DATA_HPP_

#include <ctime>
#include <string>
#include <iostream>
#include <sstream>


template <typename T> class Data
{
public:
    //constructeur par défault
    Data();

    //constructeur par recopie
    Data(const Data<T>& data_p);

    //constructeur avec la valeur et le nom du capteur
    Data(const T value_p, const std::string& nomCapteur_p);

    //destructeur
    virtual ~Data();
    Data<T>& operator=(const Data<T>& data_p);
    std::string& getName();
    std::string toString() const;
    T getValue() const;

    private :
        T m_value;
        time_t m_dateMesure;
        std::string m_nomCapteur;
};

template <typename T>
Data<T>::Data()
{
    m_value = 0;
    m_dateMesure = time(0);
    m_nomCapteur = "default";
}

template<typename T>
Data<T>::Data(const Data<T>& data_p) : m_value(data_p.m_value), m_dateMesure(data_p.m_dateMesure), m_nomCapteur(data_p.m_nomCapteur)
{

}

template <typename T>
Data<T>::Data(const T value_p, const std::string& name_p)
{
    m_value = value_p;
    m_dateMesure = time(0);
    m_nomCapteur = name_p;
}

template <typename T>
Data<T>::~Data() 
{

}

template <typename T>
std::string& Data<T>::getName()
{
    return this->m_nomCapteur;
}

template <typename T>
Data<T>& Data<T>::operator=(const Data<T>& data_p)
{
    this->m_value = data_p.m_value;
    this->m_dateMesure = data_p.m_dateMesure;
    this->m_nomCapteur = data_p.m_nomCapteur;
    return *this;
}

template<typename T>
std::string Data<T>::toString() const{

	//On retourne un string de la date affichée de manière lisible
	std::stringstream date;
	tm* time = std::localtime(&this->m_dateMesure);
	date 	<< "Time :\t"
			<< (time->tm_year + 1900) << '-'
	        << (time->tm_mon + 1) << '-'
	        <<  time->tm_mday << " at "
			<< time->tm_hour << ":"
			<< time->tm_min << ":"
			<< time->tm_sec << "\t"
            << " | "
			<< this->m_nomCapteur << "\t"
            << " | "
			<< this->m_dateMesure;

	return date.str();
}

template<typename T>
T Data<T>::getValue() const{
    return this->m_value;
}

#endif