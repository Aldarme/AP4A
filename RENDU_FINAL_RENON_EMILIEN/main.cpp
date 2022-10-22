#include "Scheduler.cpp"

int main(){
    Temperature<float> m_SensorT;
    Humidity<float> m_SensorH;
    Light<bool> m_SensorL;
    Pression<int> m_SensorP;
    Server m_Ser;
    int m_time=0; //m_time est la variable de temps totale de notre programme
    int m_time_temperature; //m_time_temperature est l'interval de temps spécifique au capteur de température
    int m_time_pression; //m_time_pression est l'interval de temps spécifique au capteur de pression
    int m_time_light; //m_time_light est l'interval de temps spécifique au capteur de lumière
    int m_time_humidity; //m_time_humidity est l'interval de temps spécifique au capteur d'humidité
    
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

    //Initialisation du scheduler 
    Scheduler m_Sch(m_Ser,m_SensorT,m_SensorH,m_SensorL,m_SensorP);

    srand(time(NULL)); //Fonction permettant d'avoir des vraies valeurs différentes entre les programmes
    
    //Boucle de temps symbolisant la période d'étude choisie par l'utilisateur
    for(int m_actual_time=1;m_actual_time<=m_time*1000;m_actual_time++){
        m_Sch.sendServer(m_actual_time,m_time_temperature,m_time_pression,m_time_light,m_time_humidity);
    }
    return 0;
}