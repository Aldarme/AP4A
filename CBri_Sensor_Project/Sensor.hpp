/**
 * @author BRICHET_Clement
 * @file Sensor.h
 * @date 23/09/2022
 * @brief This project's goal is to simulate a plane environment with its sensors and retrieve the randomly generated data from the sensors.
 * */

#ifndef SENSOR_H
#define SENSOR_H

#include <cstdlib>
#include <string>

template <class Type> class Sensor
{
    private:
    
    protected:

        /// @brief The value that is picked up by the sensor.
        Type m_value;
        /// @brief The type of data that is picked up by the sensor ("humidity", "light", etc.)
        std::string m_type;
        /// @brief The unit of the data that is picked up by the sensor ("%", "dB", etc.)
        std::string m_unit;

        /**
         * @brief Allows us to get a random value (type depending on the sensor calling it) in order to simulate what real captors could give us.
         * @return A random value, bounded according to the need of each type of sensor.
         * */
        virtual Type aleaGenVal()=0;

        //Setter
        virtual void setData()=0;

    public:

        //We define all the canonic functions here since Sensor is a template.

        //We don't define the default constructor since we have a template.s
        Sensor(){}

        Sensor(const Sensor& sourceSensor_p)
        {
            m_value = sourceSensor_p.m_value;
            m_type = sourceSensor_p.m_type;
            m_unit = sourceSensor_p.m_unit;
        }

        ~Sensor(){}

        Sensor& operator=(const Sensor& sourceSensor_p)
        {
            m_value = sourceSensor_p.m_value;
            m_type = sourceSensor_p.m_type;
            m_unit = sourceSensor_p.m_unit;
            return *this;
        }

        //Although we don't need getters to create Sensor objects, 
        //we need them for the scheduler.

        Type getData(void)
        {
            return this->m_value;
        }

        std::string getType(void)
        {
            return this->m_type;
        }

        std::string getUnit(void)
        {
            return this->m_unit;
        }
    


};

#endif //SENSOR_H