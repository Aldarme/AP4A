 /*
  Server.h
 
  Created on: 2022/10/4
 Author: Z1ppo
 */

#ifndef SERVER_H_
#define SERVER_H_
#include <iostream>
#include <fstream>
#include "Sensor.h"

enum sensorType{
	temperature,
	humidity,
	pressure,
	light,
};


class Server
{
private:
	float t;
	float h;
	int p;
	bool l;
	bool consolActivation;
	bool logActivation;

public:
	Server();

	~Server();

	void dataUpdate(enum sensorType sT, float data);

	void dataUpdate(enum sensorType sT, int data);

	void dataUpdate(enum sensorType sT, bool data);

	void consolWrite(enum sensorType sT);

	void fileWrite(enum sensorType sT);

	void setConsolActivation(bool act);

	void setLogActivation(bool act);

	bool canConsol();

	bool canLog();


};




#endif /* SERVER_H_ */
