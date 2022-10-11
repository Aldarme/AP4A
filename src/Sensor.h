/*
 * @author raphael_perrin
 * @file Sensor.h
 * @date 05/10/2022
 * @brief Superclasse des classes dérivées Humidity,Light,Pression & Temperature
 */

#ifndef SENSOR_H
#define SENSOR_H

#define LENGTH 2
template <class T>
class Sensor
{
	
private:
	T m_data;
	const char** m_specs;

public:
// Définition de la forme canonique
	Sensor(){
		this->m_data = 0;
    	m_specs = new const char*[LENGTH];
	}
	virtual ~Sensor()
	{
		delete[] m_specs;
	}
	Sensor(const Sensor& sensor_p){
		this->m_data = sensor_p.m_data;
   		m_specs = new const char*[LENGTH];
    	if(m_specs)
    	{
        	for(int i = 0; i < LENGTH; i++)
			{
            	this->m_specs[i] = sensor_p.m_specs[i];
        	}
    	}
	}
	Sensor& operator=(const Sensor& sensor_p){
		this->m_data = sensor_p.m_data;
    	if(m_specs)
    	{
        	for(int i = 0; i < LENGTH; i++)
			{
           		this->m_specs[i] = sensor_p.m_specs[i];
        	}
    	}
    	return *this;
	}

	/*
    * @brief Getter récupérant la valeur de la variable privée data
    * @return int
    * @param none
    */
	T getData(){
		return m_data;
	}

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
	void refreshData()
	{
		m_data = aleaGenVal();
	}

protected :
	/*
    * @brief Setter permettant d'indiquer le nom du sensor et son unité
    * @return void
    * @param const char* nom
	* @param const char* unité
    */
	void setSpecifications(const char* spec1_p, const char* spec2_p = ""){
		this->m_specs[0] = spec1_p;
    	this->m_specs[1] = spec2_p;
	}

	/*
    * @brief Setter classique permettant de modifier la valeur de la variable data de la classe Sensor
    * @return void
    * @param int data
    */
	void setData(T data_p){
		 this->m_data = data_p;
	}

	/*
    * @brief Méthode abstraite implémentée par chaque fonction fille pour générer des nombres aléatoires caractéristiques de chaque sensor
    * @return int
    * @param none
    */
	virtual T aleaGenVal() = 0;
};

#endif // SENSOR_H