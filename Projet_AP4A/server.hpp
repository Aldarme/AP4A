//
// Created by Jules Ferlin on 24/09/2022.
//

#ifndef PROJET_AP4A_SERVER_HPP
#define PROJET_AP4A_SERVER_HPP
#include <ostream>


class server
{
private:
    bool consolActivation;
    bool logActivation;
public:
    server();
    server(const server& s);
    ~server();
    server& operator=(const server& v);
    template<typename T>
    void fileWrite(T type);
    template<typename T>
    void consolWrite(T type);
};

server::server() {}

#endif //PROJET_AP4A_SERVER_HPP
