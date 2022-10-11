
//  ∗ @author Xiyu LUO
//  ∗ @file Server . h
//  ∗ @date 11/10/2022

// Define guards
#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ∗ @class Server
// ∗ @brief Description de la classe 

template <class T>
class Server{
private:
    bool consolActivation;
    bool logActivation;
    void fileWrite(T t);
    void consolWrite(T t);
public:
    Server(){};
    Server(const Server s): Server(s){};
    ~Server(){};
    Server& operator=(const Server s);
    void operator>>(T t);
    void dataRcv(T t);
};

#endif // SERVER_H