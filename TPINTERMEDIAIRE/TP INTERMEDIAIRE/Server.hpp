//Server Hpp 

#include <iostream> 



class Server{

private:
    bool m_consolActivation; // Permet d'indiquer si l'utilisateur veut visualiser les données arrivantes dans la console
    bool m_logActivation; // Permet d'indiquer si l'utilisateur veut stocker les donnees des capteurs dans des fchiers de logs



public:
  

    // Forme canonique de Coplien de la classe server
    Server(); // Constructeur par défaut
    Server(const Server& server); // Constructeur par recopie
    ~Server(); // Destructeur
    Server& operator=(const Server& server); // Opérateur d'affectation

    void consolWrite(const float temperature_p, const float humidity_p, const float light_p, const float sound_p);


    void fileWrite(const float temperature_p, const float humidity_p, const float light_p, const float sound_p);

    bool getConsolActivation();
    bool getLogActivation();

    void setConsolActivation(bool ans_p);
    void setLogActivation(int ans_p);
};