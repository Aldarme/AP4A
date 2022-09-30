//
// Created by rayan on 26/09/2022.
//

#ifndef UNTITLED72_SERVER_H
#define UNTITLED72_SERVER_H
#include <iostream>

class Server {

private:
    bool m_consolActivation;
    bool m_logActivation;

public:

    void consolWrite(float temperature, float humidite, float lumiere, float pression);
    void fileWrite(const std::string& sensor, float valeur);
    Server();
    Server(Server const& server);
    ~Server();
    Server& operator=(const Server& server);


};
#endif //UNTITLED72_SERVER_H
