#include <iostream>

int main()
{
    
}

template<class T>;
class Server {
    ~Server();
    Server();
    
    Server<T>::Server{
        void fileWrite() {}

        void consolWrite() {}    

    }
        Server<T>::~Server{
            Server & operator=(const Server & autre);
    }
};

class Scheduler {
    Scheduler() {
        void scheduler();
    }
    ~Scheduler() {};
};

class Sensor {
    public:Sensor() {
        
    }

};

class Temperature :public Sensor{
    public:
        float tem;
};

class Humidity :public Sensor {
    public:
        float hum;

};

class Light :public Sensor {
    public:
        bool lig;
};

class Pression :public Sensor {
    public:
        int pre;
};