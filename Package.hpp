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

template <typename T>
class Package
{
private:
    
    T m_data;
    std::string m_sensor_name;
    std::string m_sensor_unit;

public:
    /**
     * @brief Construct a new Package:: Package object
     * 
     * @param p_data 
     * @param p_sensor_name 
     * @param p_sensor_unit 
     */
    Package(T p_data, std::string p_sensor_name, std::string p_sensor_unit){
        m_data = p_data;
        m_sensor_name = p_sensor_name;
        m_sensor_unit = p_sensor_unit;
    }

    /**
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    std::string getName(){
        return m_sensor_name;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& p_output, const Package<U>& p_package);

    template <typename U>
    friend std::ofstream& operator<<(std::ofstream& p_output_f, Package<U>& p_package);
};

/**
 * @brief overide << operator for cout use
 * 
 * @param p_output 
 * @param p_package 
 * @return std::ostream& 
 */
template <typename U>
std::ostream& operator<<(std::ostream& p_output, const Package<U>& p_package)
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
template <typename U>
std::ofstream& operator<<(std::ofstream& p_output_f, Package<U>& p_package)
{
    p_output_f << p_package.m_data << ";";
    return p_output_f;
}

#endif // PACKAGE_H