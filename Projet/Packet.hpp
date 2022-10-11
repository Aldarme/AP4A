class Packet
{
private:
    /* data */
    Temperature temperature;
    Pressure pressure;
    Humidity humidity;
    Light light;
    

public:
    
    float temp;
    float press;
    float humid;
    bool lumiere;

    Packet(/* args */);
    Packet(float temp, float press, float humid, bool lumiere);
    Packet(Temperature temp, Pressure press, Humidity humid, Light lumiere);
    ~Packet();
    void getInfo();
    void setPacket(Temperature temp,Pressure press, Humidity humid, Light lumiere);

    friend class Server;
};


