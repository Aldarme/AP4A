#ifndef PACKAGE_H
#define PACKAGE_H

#include "string"

template <typename TYPE>
class Package
{
private:
    
    TYPE m_data;
    std::string m_sensor_name;
    std::string m_sensor_unit;

public:
    Package(TYPE p_data, std::string p_sensor_name, std::string p_sensor_unit)
    {
        m_data = p_data;
        m_sensor_name = p_sensor_name;
        m_sensor_unit = p_sensor_unit;
    };

    friend std::ostream &operator<<( std::ostream &output, const Package &p_package ) 
    { 
         output << p_package.m_sensor_name << ": " << p_package.m_data << p_package.m_sensor_unit;
         return output;            
    }

    friend std::istream &operator>>( std::istream  &input, Package &p_package )
    { 
        input >> p_package.m_data << ";";
        return input;            
    }
};

#endif // PACKAGE_H