/**
* @author MOhana wael
* @file : Server.cpp
* @date 27/09/2022
* @Description Definition classe Server
*/

#include <iostream>
#include "./Server.hpp"
#include "./Sensor.hpp"
#include "./Temperature.hpp"
#include "./Light.hpp"
#include "./Humidity.hpp"
#include "./Pressure.hpp"
#include <fstream>
#include <ctime>


/***************CONSTRUCTORS***************/
//Definition default constructor
Server::Server():consolActivation(true),logActivation(false){}
//Definition constructor par recopie
Server::Server(const Server& autre){
    this->consolActivation = autre.consolActivation;
    this->logActivation = autre.logActivation;
 }

/***************OPERATORS***************/
 //Definition Operator =
 Server& Server::operator=(const Server& autre){
     this->consolActivation = autre.consolActivation;
        this->logActivation = autre.logActivation;
        return *this;
}

/***************METHODS***************/
//Definition method fileWrite 
//Path is determined based on incoming sensor's type 
template <typename T>
void Server::Server::fileWrite(Sensor<T>& s){ 
    time_t currtime;
    time(&currtime);
    char str[26];
    ctime_s(str, sizeof str, &currtime);

    std::fstream inoutstream;

    switch(s.getType()){

      case 'T':{
         inoutstream.open("./Data/Temperature_log.txt",std::fstream::app);
         try{
    
    if(inoutstream.fail()){ throw -1 ;}
    else{
        inoutstream << "\nTime:"<< str << s.getType() << ": " << std::to_string(s.getData()) << " " << s.getUnite();
    }
    } catch(int err){
    std::cout << "error opening file, exiting...";  
    exit(1);
   }  
         break;}
        case 'L':{
         try{
       inoutstream.open("./Data/Light_log.txt",std::fstream::app);
    if(inoutstream.fail()){ throw -1 ;}
    else{
        std::string state="";
        if(s.getData() == false) state = "False";
        else state = "True"; 
        inoutstream << "\nTime:"<< str << " " << s.getType() <<"-state: " << state << " " << s.getUnite();
    }
    } catch(int err){
    std::cout << "error opening file, exiting...";  
    exit(1);
   }
         break;}
          case 'P':{
             try{
    inoutstream.open("./Data/Pressure_log.txt",std::fstream::app);
    if(inoutstream.fail()){ throw -1 ;}
    else{
        inoutstream << "\nTime:"<< str << " " << s.getType() << ": " << std::to_string(s.getData()) << " " <<s.getUnite();
    }
    } catch(int err){
    std::cout << "error opening file, exiting...";  
    exit(1);
   }
            break;}
            case 'H':{
                try{
    inoutstream.open("./Data/Humidity_log.txt",std::fstream::app);
    if(inoutstream.fail()){ throw -1 ;}
    else{
        inoutstream << "\nTime:"<< str << " " << s.getType() << ": " <<  std::to_string(s.getData()) << " " << s.getUnite();
        inoutstream.close();
    }
    } catch(int err){
    std::cout << "error opening file, exiting...";  
    exit(1);
   }
               break;}
    }

     inoutstream.close();
        if(!inoutstream.is_open()) std::cout << "\nFile closed";
        else{ std::cout << "\nCannot close file,exiting..."; exit(1);}
};



//Definition Method Console Write
template<typename T>
void Server::consoleWrite(Sensor<T>& s){
   time_t currtime;
    time(&currtime);
    char str[26];
    ctime_s(str, sizeof str, &currtime);
    switch(s.getType()){
      case 'T':{
         std::cout << "\nTime:"<< str << s.getType() << ": " << std::to_string(s.getData()) << " " << s.getUnite();
         break;}
       case 'L':{
         std::string state="";
        if(s.getData() == false) state = "False";
        else state = "True"; 
         std::cout << "\nTime:"<< str << " " << s.getType() <<"-state: " << state << " " << s.getUnite();
         break;}
         case 'P':{
            std::cout << "\nTime:"<< str << " " << s.getType() << ": " << std::to_string(s.getData()) << " " <<s.getUnite();
            break;}
            case 'H':{
               std::cout << "\nTime:"<< str << " " << s.getType() << ": " <<  std::to_string(s.getData()) << " " << s.getUnite();
               break;}
    }

};

//Definition Methode Receive Signal from server
template <typename T>
void Server::receiveSignal(Sensor<T>& s){
     if(consolActivation) consoleWrite(s);
        else if(logActivation) fileWrite(s);
        else std::cout << "\n" <<"Config Erreur" ;
};


/***************DESTRUCTOR***************/
Server::~Server(){}