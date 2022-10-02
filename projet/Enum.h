//
// Created by rayan on 30/09/2022.
//

#ifndef UNTITLED72_ENUM_H
#define UNTITLED72_ENUM_H
#include <string>
enum DataType
{
    e_unknown_data,
    e_float,
    e_int,
    e_bool
};

enum SensorType
{
    e_unknown_type,
    temperature,
    humidity,
    light,
    pressure
};

typedef struct s_SensorData
{
    SensorType sensorType;
    DataType dataType;
    std::string value;
} SensorData;

#endif //UNTITLED72_ENUM_H
