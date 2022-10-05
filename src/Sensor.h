/*
 * @author raphael_perrin
 * @file Sensor.h
 * @date 05/10/2022
 * @brief Superclasse des classes dérivées Humidity,Light,Pression & Temperature
 */

#ifndef SENSOR_H
#define SENSOR_H

#define LENGTH 2

class Light;
class Humidity;
class Pression;
class Temperature;

class Sensor
{
	
private:
	int m_data;
	const char** m_specs;

public:
// Définition de la forme canonique
	Sensor();
	virtual ~Sensor()
	{
		delete[] m_specs;
	}
	Sensor(const Sensor& sensor_p);
	Sensor& operator=(const Sensor& sensor_p);

	/*
    * @brief Getter récupérant la valeur de la variable privée data
    * @return int
    * @param none
    */
	int getData();

	/*
    * @brief Getter récupérant le char (caractérisant le type du sensor et son unité) présent à la ieme position du tableau
    * @return const char*
    * @param int i
    */
	const char* getSpec(int i_p)
	{
		return m_specs[i_p];
	}

	/*
    * @brief Méthode permettant de refresh les informations des sensors en leur attribuant une nouvelle valeur
    * @return void
    * @param none
    */
	void refreshData();

protected :
	/*
    * @brief Setter permettant d'indiquer le nom du sensor et son unité
    * @return void
    * @param const char* nom
	* @param const char* unité
    */
	void setSpecifications(const char* spec1_p, const char* spec2_p = "");

	/*
    * @brief Setter classique permettant de modifier la valeur de la variable data de la classe Sensor
    * @return void
    * @param int data
    */
	void setData(int data_p);

	/*
    * @brief Méthode abstraite implémentée par chaque fonction fille pour générer des nombres aléatoires caractéristiques de chaque sensor
    * @return int
    * @param none
    */
	virtual int aleaGenVal() = 0;
};

#endif // SENSOR_H