//
// Created by rayan on 26/09/2022.
//

#ifndef UNTITLED72_SERVER_H
#define UNTITLED72_SERVER_H
#include <iostream>
#include "../Enum.h"


class Server {

private:
    bool m_consolActivation;
    bool m_logActivation;
    void consolWrite(const SensorData& data);
    void fileWrite(const SensorData& data);
public:
    Server();
    Server(Server const& server);
    ~Server();
    void dataRcv(const SensorData& data);
};

void operator<<(Server& server, const SensorData& data);
#endif //UNTITLED72_SERVER_H
