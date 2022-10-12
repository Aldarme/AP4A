#ifndef paquet_hpp
#define paquet_hpp
#include<string>

class Paquet{
    public:
        Paquet();
        Paquet(float val);
        Paquet(float val, std::string type, std::string unite);
        Paquet(const Paquet &Paquet);
        ~Paquet();
        Paquet& operator=(const Paquet &Paquet);    
        std::string data();    
        std::string Getunit();
    public:
        float m_val;
        std::string m_type;
        std::string m_unite;       
};


#endif /* paquet_hpp */