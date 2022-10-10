/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Package
*/

#include "Package.hpp"
#include <iostream>

/**
 * @brief Construct a new Package:: Package object
 * 
 * @param p_data 
 * @param p_sensor_name 
 * @param p_sensor_unit 
 */
Package::Package(float p_data, std::string p_sensor_name, std::string p_sensor_unit)
    {
        m_data = p_data;
        m_sensor_name = p_sensor_name;
        m_sensor_unit = p_sensor_unit;
    }

/**
 * @brief Get the Name object
 * 
 * @return std::string 
 */
std::string Package::getName()
{
    return m_sensor_name;
}

/**
 * @brief overide << operator for cout use
 * 
 * @param p_output 
 * @param p_package 
 * @return std::ostream& 
 */
std::ostream& operator<<( std::ostream &p_output, const Package &p_package)
{
    p_output << p_package.m_sensor_name << ": " << p_package.m_data << " " << p_package.m_sensor_unit;          
    return p_output;
}

/**
 * @brief overide << operator for file use
 * 
 * @param p_output_f 
 * @param p_package 
 * @return std::ofstream& 
 */
 std::ofstream& operator<<( std::ofstream &p_output_f, Package &p_package)
{
    p_output_f << p_package.m_data << ";";
    return p_output_f;
}