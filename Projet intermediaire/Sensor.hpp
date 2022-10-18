/**
 * @author Tontsa apala frank
 * @file Sensor.hpp
 * @date 25/09/2022
 * @brief Sensor
 */

#ifndef SENSOR_H_
#define SENSOR_H_

template <class T>
class Sensor {
public:
	Sensor();
	virtual ~Sensor();
	Sensor(const Sensor &other);

	// Declaration de la premiere methode virtuel pure
	virtual T getData() = 0;

protected:
	T m_data; //Variable o� est stockk� les donn�es gener� du capteur
	// Declaration de la deuxieme methode virtuel pure
	//Elle est crée pour permettre l'acces au valeur du capteur
	//� toutes les classes et fonctions
	virtual T aleaGenVal() = 0;
};

#endif /* SENSOR_H_ */
