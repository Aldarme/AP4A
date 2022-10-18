#ifndef classe.hpp
#define classe.hpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <list>

class Sensor {
    private:
    
    std::string type="sensor";
   
    public:
    Sensor();
    Sensor (const Sensor&);
    ~Sensor();
    Sensor &operator=(const Sensor&);
    void changeType (std::string new_type){
        this->type = new_type;
    };
    std::string getType (){
        return this->type;
    };
    template <class T> T aleaGenVal(){
        T r ;
        return r;

    };
    /**Demande de données getData*/
    template<class T> T getData (){
        
        T a = aleaGenVal();
        return a;
    };


};
class Scheduler {
    private:
    std::list <Sensor> c;
    Server s;
    public:
    Scheduler(Server s,std::list <Sensor> c){
        this->s = s;
        this->c = c;
    };
    Scheduler (const Scheduler&);
    ~Scheduler();
    Scheduler &operator=(const Scheduler&);
    
    
    
    void ecritureServeur(){
        for (Sensor elem : c){

            s.fileWrite(elem.getData(),elem);
            s.consoleWrite(elem.getData());
        };

    
    
    };
};

class Server {   
    public:
    Server();
    Server (const Server&);
    ~Server();
    Server &operator=(const Server&);
    template <class T> void consoleWrite(T a){

       cout << a  ;
    };

    template <class T> void fileWrite(T a, Sensor s){
        fstream fichier;
        std::string t = s.getType();
        if (t=="Temperature"){
            fichier.open("Temperature.txt", ios::out);
            fichier >> a;
            fichier.close();
            sleep(1);
 
        };

        elif (t=="Humidity"){
            fichier.open("Humidity.txt", ios::out);
            fichier >> a;
            fichier.close();
            sleep(3);
        };
        elif (t=="Light"){
            fichier.open("Light.txt", ios::out);
            fichier >> a;
            fichier.close();
            sleep(5);
 
        };

        else {
            fichier.open("Pression.txt", ios::out);
            fichier >> a;
            fichier.close();
            sleep(10);
        };
 
    };
};
#endif // classe.hpp 


