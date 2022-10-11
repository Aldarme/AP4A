class Sensor
{
private:
    /* data */
protected:
    float value;
public:
    Sensor(/* args */);
    Sensor(float value);
    ~Sensor();
    int getData();
    float aleaGenVal(int max);
    bool aleaGenvalBool(int max);
    void setter(float val);
    //int generateRandom();
    //void aleaGen();

    friend class Server;
    friend class Scheduler;
};

class Temperature : public Sensor {
    private:

    public:
    Temperature();
    Temperature(float temp);
    ~Temperature();
};

class Pressure : public Sensor {
    private:

    public:
    Pressure();
    //Pressure(float press);
    ~Pressure();
};

class Humidity : public Sensor {
    private:

    public:
    Humidity();
    ~Humidity();
    //Humidity(float humid);
};

class Light : public Sensor {
    private:

    public:
     bool lightPresent;
    Light();
    ~Light();
    int getData();
    void setter(bool state);
    //Light(bool lumiere);
};



