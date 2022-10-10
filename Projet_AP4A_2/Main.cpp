#include <iostream>

#include "Server.cpp"
#include "Sensor.cpp"
#include "Temperature.cpp"
#include "Humidity.cpp"
#include "Light.cpp"
#include "Pression.cpp"
#include "Scheduler.cpp"

using namespace std;

int main()
{
    //déclaration des différents capteurs
    Temperature t;
    Humidity h;
    Light l;
    Pression p;

    //déclaration du Scheduler
    Scheduler boss;

    //déclaration du Server
    Server s;

    //variables de la durée de récolte des données et de l'intervalle de temps
    int m_temps_recolt = -1;
    int m_temps_intervalle = -1;

    //varaible de la réponse de l'utilisateur concernant l'affichage et loggage des données
    char m_activer;
    
    //permet de générer des nombres aléatoires différents à chaque exécution
    srand(time(NULL));

    //demande à l'utilisateur du temps de récolte des données
    while(m_temps_recolt < 0 || m_temps_recolt > 36000)
    {

        cout << "Veuillez saisir le temps durant lequel vous souhaitez récoltez les données en secondes :" << endl;
        cin >> m_temps_recolt;

    }

    //demande à l'utilisateur de l'intervalle de temps
    while(m_temps_intervalle < 0 || m_temps_intervalle > 600 || m_temps_intervalle > m_temps_recolt)
    {
        
        cout << "Veuillez saisir l'intervalle de temps où vous souhaitez récoltez les données en secondes :" << endl;
        cin >> m_temps_intervalle;

    }

    //demande à l'utilisateur si il souhaite afficher et logger les données
    while(m_activer != 'Y' && m_activer != 'N')
    {
        
        cout << "Souhaitez-vous activer l'affichage et le log des données ? (Y/N)" << endl;
        cin >> m_activer;

    }

    if(m_activer == 'Y'){

        for(int i=0;i<m_temps_recolt/m_temps_intervalle;i++)
        {

            boss.takeData(t, h, l, p, m_temps_intervalle);
            s.dataRCV(boss);
            s.consoleWrite();
            s.fileWrite();

        }
    }
    else
    {
        for(int i=0;i<m_temps_recolt/m_temps_intervalle;i++)
        {

            boss.takeData(t, h, l, p, m_temps_intervalle);
            s.dataRCV(boss);

        }
    }

    return 0;

}
