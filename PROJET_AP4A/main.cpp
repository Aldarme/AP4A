#include <iostream>
#include "Scheduler.cpp"

int main(){
    Temperature T;
    Humidity H;
    Light L;
    Pression P;
    Server Ser;
    int m_interval;
    int m_time=0;
    
    //Choix de l'interval de temps des mesures des valeurs en secondes
    cout<<"Choisissez l'interval de temps entre les détections de données (Interval en secondes)"<<endl;
    cin>>m_interval;
    //Choix de la période d'étude des mesures en secondes
    while(m_time<m_interval){
        cout<<"Choisissez sur combien de temps la détection doit se faire (Donnée en secondes)"<<endl;
        cin>>m_time;
    }
    cout<<endl;

    //Initialisation du scheduler avec l'interval choisis
    Scheduler Sch(Ser,T,H,L,P,m_interval);

    srand(time(NULL)); //Fonction permettant d'avoir des vraies valeurs différentes entre les programmes
    
    //Boucle de temps symbolisant la période d'étude choisis par l'utilisateur
    for(int i=0;i<m_time/m_interval;i++){
        Sch.setValue();
    }
    return 0;
}