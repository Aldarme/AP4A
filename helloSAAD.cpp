#include <iostream>

class Lampe
{
private:
    int puissance;
    bool estAllume;
public:
   
   void allumer()
   {this->estAllume=true;};
  
};

int main()
{
    Lampe l1;
    l1.allumer();
    cout<<l1.estAllume
}