
class Server {
public :
    Server();
    ~Server();
    Server(const Server& s);
    Server& operator=(const Server& s);
    void consoleWrite();
    void fileWrite();
};