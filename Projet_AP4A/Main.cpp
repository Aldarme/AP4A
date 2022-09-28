#include <iostream>
#include "Server.cpp"
#include "Sensor.cpp"
#include "Scheduler.cpp"

using namespace std;

int main(){

    //cout << "\nPremier Test\n" << endl;

    //int a, b, c, d;

    //cin >> a >> b >> c >> d;

    //Server s(a, b, c, d);

    //Server sp;

    //Server p(1,2,3,4);

    //s.consoleWrite();

    //sp.consoleWrite();

    //s.fileWrite("C:/Users/hugoc/OneDrive/Bureau/Projet_AP4A/Capteurs.csv");

    //p.fileWrite("C:/Users/hugoc/OneDrive/Bureau/Projet_AP4A/Capteurs.csv");

    //Temperature t;
    //Humidity h;
    //Light l;
    //Pression p;

    Scheduler boss;

    //Server s;

    srand(time(NULL));
    
    for(int i = 0;i<5;i++){
        boss.sendData();
    }

    return 0;
}