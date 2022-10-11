#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <fstream>

using namespace std; 

template <class T>class Server{
    public:
        void consoleWrite( typeCapteur, type value,  typeVal); 
        void fileWrite( typeCapteur, type value,  typeVal);

        Server(){}; 
        ~Server(){} 
};

#endif;