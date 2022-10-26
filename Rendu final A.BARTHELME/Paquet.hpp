#ifndef paquet_hpp
#define paquet_hpp
#include<string>
#include<iostream>
/**
 * @author A.BARTHELME
 * @file paquet.hpp
 * @date 26/10/2022
 * @brief Fichier de la classe paquet, cette classe permet de transformer les données en paquet
 * @version finale
 * @details La classe est définie comme template, en fonction du type de données que l'on veut traiter
**/


template <typename T> class Paquet{
    public:
        Paquet<T>(){
            m_val =42;
            m_type = "Capteur/nom par defaut";
            m_unite = "Unite par defaut";
            m_i = 0;
        }
        Paquet<T>(T val){
            m_val = val;
            m_type = "Capteur/nom par defaut";
            m_unite = "Unite par defaut";
            m_i = 0;
        }
        Paquet<T>(T val,std::string type, std::string unite,int i){
            m_val = val;
            m_type = type;
            m_unite = unite;
            m_i = i;
        }
        Paquet<T>(const Paquet<T> &Paquet){
            m_val = Paquet.m_val;
            m_type = Paquet.m_type;
            m_unite = Paquet.m_unite;
            m_i = Paquet.m_i;
        }
        ~Paquet<T>(){
            std::cout << "Destruction du paquet" << std::endl;
        }
        Paquet<T>& operator=(const Paquet<T> &Paquet){
            m_val = Paquet.m_val;
            m_type = Paquet.m_type;
            m_unite = Paquet.m_unite;
            m_i = Paquet.m_i;
            return *this;
        }
        T data(){
            //std::cout << "val dans paquet : "<< m_val << std::endl;
            return m_val;
            
        }
        void info(){
            std::cout << "Data : parametres du capteur" << std::endl;
            std::cout << "Type : "<< m_type << std::endl;
            std::cout << "Valeur : " <<  m_val << std::endl;
            std::cout << "Unite : " << m_unite << std::endl;
        }
        std::string Getunit(){
            return m_unite;
        }
        int GetId(){
            return m_i;
        }
        std::string GetType(){
            return m_type;
        }

      
    private :
        T m_val;
        std::string m_fichier;
        std::string m_type;
        std::string m_unite;
        int m_i;       
};


#endif /* paquet_hpp */