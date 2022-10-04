/**
* @author Alan HERVE
* @file Server.hpp
* @date 01/10/2022
* @brief Is in charge of writing values received from the captors in files and in the console
**/


#ifndef SERVER_H
#define SERVER_H
#pragma once
#include <iostream>



class Server {

    private:

        bool consolActivation;
        bool logActivation;
        
    
    public: 

    Server(){

        consolActivation= false;
        logActivation = false;
        this->initiateFile();
        


    }

    Server(const Server& copy){
        this->consolActivation = copy.consolActivation;
        this->logActivation = copy.logActivation;
    }
    
    void activateConsole();

    void activateLog();

    void deActivateConsole();
    void deActivateLog();
    void activateAll();
    void deActivateAll();

    virtual ~Server(){
        
    }


//other function

    //void fileWrite(type Type);

    //void writeConsol(type Type);

   
    void initiateFile();

    template <class Type> void fileWrite(Type classparam);
    
    template <class Type> void consoleWrite(Type classparam);

};




#endif