#include <iostream>
#include <fstream>
#include <windows.h>
#include "serveur.hpp"
#include "scheduler.hpp"
#include "sensor.hpp"
#include "light.hpp"
#include "humidity.hpp"
#include "sound.hpp"
#include "temperature.hpp"




int main() {
	char rep='O';

	light lum;
	humidity hum;
	sound soun;
	temperature temp;

	scheduler sche(lum,soun,hum,temp);

	//serveur serv(sche);          //Le main en utilisant la methode datarecovery
	//sche.datarecovery(serv);

	while (rep == 'O') {
		cout << endl;
		sche.datarecove();
		serveur serv(sche);
		serv.fileWrite();
		cout << endl;
		cout << " Voulez vous des nouvelles valeurs (Repondre O (oui) ou N (non))" << endl;
		cin >> rep;
	}
	
   return 0;
}