#ifndef classe.hpp
#define classe.hpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
class sensor {
    public:
    sensor();
    sensor (const sensor);
    ~sensor();
    sensor &operator=(const sensor&);
    /** générer des valeurs aléatoires aleaGenVal*/
    int aleaGenVal(){
        std::defaut_random_engine re;
        std::uniform_int_distribution<int> distrib{1,6};
    }
    /**Demande de données getData*/
    template <class T> T getData (){
        
        T a = aleaGenVal()
        return a
    }
class sensor::humidity{
    aleagenval .... 
    float getData()
    

}

}

class scheduler {
    public:
    scheduler();
    scheduler (const scheduler);
    ~scheduler();
    scheduler &operator=(const scheduler&);
    /** Notion de delai pour envoyer les données à la classe server */
   
    server.fileWrite(sensor.getData())
    server.consoleWrite(sensor.getData())
}

class server {
    public:
    server();
    server (const server);
    ~server();
    server &operator=(const server&);
    void consoleWrite(a){

       cout << a  ;
        }

    template <class T> void fileWrite(T a){
        fstream fichier;
        fichier.open("capteur.txt", ios::out);
        fichier >> a;
        fichier.close();
 
    }
}
#endif // classe.hpp 


