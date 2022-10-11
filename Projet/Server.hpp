class Server
{
private:
    /* data */
    int serverNumber;
public:
    Server(/* args */);
    ~Server();
    void fileWrite();
    void consolWrite(Sensor data);
    void consolWrite(Packet data);
    void fileWrite(Packet data,int cas);
};
