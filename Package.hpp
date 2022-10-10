#ifndef PACKAGE_H
#define PACKAGE_H

/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Package
*/

#include <string>
#include <fstream>

class Package
{
private:
    
    float m_data;
    std::string m_sensor_name;
    std::string m_sensor_unit;

public:
    Package(float p_data, std::string p_sensor_name, std::string p_sensor_unit);

    std::string getName();

    friend std::ostream& operator<<( std::ostream &p_output, const Package &p_package);

    friend std::ofstream& operator<<( std::ofstream &p_output_f, Package &p_package);
};

#endif // PACKAGE_H