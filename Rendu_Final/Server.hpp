/**
 * @author BIN ABDUL SHUKOR Muhammad Ariff
 * @file Server.hpp
 * @date 25/10/2022
 * @brief
 */
 
//Define guards
#ifndef SERVER_H
#define SERVER_H
class Server
{
private:
    int serverNumber;
public:
    // Definition de la forme canonique
    Server();
    Server(int i):serverNumber(i){};
    ~Server(){};
    void fileWrite(Temperature tmp);
    void fileWrite(Pressure tmp);
    void fileWrite(Humidity tmp);
    void fileWrite(Light tmp);
    void clearDataInFile();
    void consolWrite(Temperature tp);
    void consolWrite(Pressure prs);
    void consolWrite(Humidity hmd);
    void consolWrite(Light lgt);
};

#endif //SERVER_H 