#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <classe.hpp>



/** fonction sleep() */ 

class Temperature : public Sensor {
    public:
    Temperature(){
        std::string new_type ="Temperature" ;
        changeType (new_type);

    };
    float aleaGenVal(){
        float r = 23 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(25-23)));
    };
    float getData();
};
class Humidity : public Sensor {
    public:
     Humidity(){
        std::string new_type ="Humidity" ;
        changeType (new_type);

    };
    float aleaGenVal(){
        
        float r = 0.06 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.1-0.06)));
        return r;
    };   
    float getData();
};
class Light : public Sensor {
    public:
    Light(){
         std::string new_type ="Light" ;
        changeType (new_type);

    };
    bool aleaGenVal(){
        int r= rand() % 2;
        if (r==0){
            return true;
        };
        else{
            return false;
        };
    bool getData();
};
class Pression : public Sensor {
    public:
    Pression(){
         std::string new_type ="Pression" ;
        changeType (new_type);

    };
    int aleaGenVal(){
        int r = rand() % 450 + 50;
        return r;
    };
    int getData() ;
};



int main() {
    Server serveur1;
    Temperature t1;
    Pression p1;
    Light l1;
    Humidity h1;
    std::list<Sensor> listecapteur = { l1, p1, h1, t1 };
    Scheduler sched(serveur1,listecapteur);
    while(true){
        sched.ecritureServeur();
    };
    return 0;
    };

