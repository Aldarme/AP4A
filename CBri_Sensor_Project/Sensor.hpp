/**
 * @author BRICHET_Clement
 * @file Sensor.h
 * @date 23/09/2022
 * @brief 
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
        std::string m_filename;

        /**
         * @brief Allows us to get a random value (type depending on the sensor calling it) in order to simulate what real captors could give us.
         * @return A random value, bounded according to the need of each type of sensor.
         * */
        virtual Type aleaGenVal()=0;

        virtual void setData()=0;

    public:
        //canonic functions
        Sensor();
        Sensor(const Sensor&);
        Sensor& operator=(const Sensor&);
        virtual ~Sensor();

        /**
         * @brief A function that returns the m_value of a sensor.
         * @return The attribute m_value of a sensor.
         * @param
         * */
        Type getData(void);
};

#endif //SENSOR_H