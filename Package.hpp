#ifndef PACKAGE_H
#define PACKAGE_H

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
    std::string getName()
    {
        return m_sensor_name;
    }

    friend std::ostream& operator<<( std::ostream &p_output, const Package &p_package)
    {
        p_output << p_package.m_sensor_name << ": " << p_package.m_data << " " << p_package.m_sensor_unit;          
        return p_output;
    }

    friend std::ofstream& operator<<( std::ofstream &p_output_f, Package &p_package)
    {
        p_output_f << p_package.m_data << ";";
        return p_output_f;
    }
};

#endif // PACKAGE_H