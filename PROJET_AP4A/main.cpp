#include <iostream>
#include "Scheduler.cpp"

int main(){
    Temperature<float> T;
    Humidity<float> H;
    Light<bool> L;
    Pression<int> P;
    Server Ser;
    int m_time=0;
    int m_time_temperature;
    int m_time_pression;
    int m_time_light;
    int m_time_humidity;
    
    //Choix de l'interval de temps de chaque mesure
    cout<<"Choisissez l'interval de temps entre les détections de données pour la température (Interval en millisecondes)"<<endl;
    cin>>m_time_temperature;
    cout<<"Choisissez l'interval de temps entre les détections de données pour la pression (Interval en millisecondes)"<<endl;
    cin>>m_time_pression;
    cout<<"Choisissez l'interval de temps entre les détections de données pour la lumière (Interval en millisecondes)"<<endl;
    cin>>m_time_light;
    cout<<"Choisissez l'interval de temps entre les détections de données pour l'humidité (Interval en millisecondes)"<<endl;
    cin>>m_time_humidity;

    //Choix de la période d'étude des mesures en secondes
    while(m_time*1000<m_time_humidity || m_time*1000<m_time_humidity || m_time*1000<m_time_light || m_time*1000<m_time_pression){
        cout<<"Choisissez sur combien de temps la détection doit se faire (Donnée en secondes)"<<endl;
        cin>>m_time;
    }
    cout<<endl;

    //Initialisation du scheduler avec l'interval choisis
    Scheduler Sch(Ser,T,H,L,P);

    srand(time(NULL)); //Fonction permettant d'avoir des vraies valeurs différentes entre les programmes
    
    //Boucle de temps symbolisant la période d'étude choisis par l'utilisateur
    for(int i=1;i<=m_time*1000;i++){
        Sch.sendServer(i,m_time_temperature,m_time_pression,m_time_light,m_time_humidity);
    }
    return 0;
}