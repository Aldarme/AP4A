
/**
 * @author BIN ABDUL SHUKOR Muhammad Ariff
 * @file Server.hpp\
 * @date 25/10/2022
 * @brief
 */

//Define guards
#ifndef PACKET_H
#define PACKET_H

class Packet
{
private:
    Temperature temperature;
    Pressure pressure;
    Humidity humidity;
    Light light;
    

public:
    // Definition de la forme canonique
    Packet();
    Packet(float temp, float press, float humid, bool lumiere);
    Packet(Temperature temp, Pressure press, Humidity humid, Light lumiere);
    ~Packet(){};
    void getInfo();
    void setPacket(Temperature temp,Pressure press, Humidity humid, Light lumiere);

    friend class Server;
};

#endif //PACKET_H
