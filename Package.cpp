#include "Package.hpp"
#include <iostream>

Package::Package(float p_data, std::string p_sensor_name, std::string p_sensor_unit)
    {
        m_data = p_data;
        m_sensor_name = p_sensor_name;
        m_sensor_unit = p_sensor_unit;
    }