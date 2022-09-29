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

    Temperature t;
    Humidity h;
    Light l;
    Pression p;

    Scheduler boss;

    Server s;

    int m_temps_recolt = -1;

    int m_temps_intervalle = -1;
    
    srand(time(NULL));

    while(m_temps_recolt < 0 || m_temps_recolt > 36000){

        cout << "Veuillez saisir le temps durant lequel vous souhaitez récoltez les données en secondes :" << endl;
        cin >> m_temps_recolt;
    }

    while(m_temps_intervalle < 0 || m_temps_intervalle > 600 || m_temps_intervalle > m_temps_recolt){
        
        cout << "Veuillez saisir l'intervalle de temps où vous souhaitez récoltez les données en secondes :" << endl;
        cin >> m_temps_intervalle;
    }

    for(int i=0;i<m_temps_recolt/m_temps_intervalle;i++){
        boss.sendData(t, h, l, p, s, m_temps_intervalle);
        s.dataRCV(boss);
        s.consoleWrite();
        s.fileWrite("C:/Users/hugoc/OneDrive/Bureau/Projet_AP4A_1/Capteurs.csv");
    }

    return 0;
}