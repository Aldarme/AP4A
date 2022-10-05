//
// Created by rayan on 05/10/2022.
//
#ifndef PROJET_SERVER_H
#define PROJET_SERVER_H
#include "../enum.h"

class Server
{
private:
    bool m_consolActivation;
    bool m_logActivation;
    void fileWrite(const SensorData& data);
    void consolWrite(const SensorData& data);

public:
    Server();
    Server(bool, bool);
    virtual ~Server(){};
    void dataRcv(const SensorData& data);
    void affichageConsole();
    void ecritureLog();

};

void operator<<(Server& server, const SensorData& data);
#endif //PROJET_SERVER_H
