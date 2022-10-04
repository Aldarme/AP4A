/**
 * @author DURUPT Corentin
 * @file Server.cpp
 * @date 20/09/2022
 * @brief This is the implementation of the different methods of the class Server.
*/

#include "Server.hpp"
#include "Sensor.hpp"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

Server::Server(){
}

Server::Server(const Server& s){
    this->m_data_sensor_temperature = s.m_data_sensor_temperature;
    this->m_data_sensor_humidity = s.m_data_sensor_humidity;
    this->m_data_sensor_light = s.m_data_sensor_light;
    this->m_data_sensor_pressure = s.m_data_sensor_pressure;
}

Server& Server::operator=(const Server& s){
    this->m_data_sensor_temperature = s.m_data_sensor_temperature;
    this->m_data_sensor_humidity = s.m_data_sensor_humidity;
    this->m_data_sensor_light = s.m_data_sensor_light;
    this->m_data_sensor_pressure = s.m_data_sensor_pressure;

    return *this;
}

Server::~Server(){  
}

Server::Server(const Temperature& t, const Humidity& h, const Light& l, const Pressure& p){
    this->m_data_sensor_temperature = t;
    this->m_data_sensor_humidity = h;
    this->m_data_sensor_light = l;
    this->m_data_sensor_pressure = p;
}

string Server::data_sensor_contents(const Sensor& t){
    string line_contents, t1, t2;
    t1 = t.m_sensor_name;
    t2 = to_string(t.m_data);

    line_contents = t1 + " " + t2;
    return line_contents;
}

void Server::fileWrite(const Server& ser){
    string const File_name1("Temperature.txt");
    string const File_name2("Humidity.txt");
    string const File_name3("Light.txt");
    string const File_name4("Pressure.txt");

    ofstream myFile_temperature(File_name1.c_str(), ios::app);
    ofstream myFile_humidity(File_name2.c_str(), ios::app);
    ofstream myFile_light(File_name3.c_str(), ios::app);
    ofstream myFile_pressure(File_name4.c_str(), ios::app);

    if(myFile_temperature){
        string line = data_sensor_contents(ser.m_data_sensor_temperature);
        myFile_temperature << line << endl;
    } else {
        cerr << "Problem on the file !" << endl;
    }

    if(myFile_humidity){
        string line = data_sensor_contents(ser.m_data_sensor_humidity);
        myFile_humidity << line << endl;
    } else {
        cerr << "Problem on the file !" << endl;
    }

    if(myFile_light){
        string line = data_sensor_contents(ser.m_data_sensor_light);
        myFile_light << line << endl;
    } else {
        cerr << "Problem on the file !" << endl;
    }

    if(myFile_pressure){
        string line = data_sensor_contents(ser.m_data_sensor_pressure);
        myFile_pressure << line << endl;
    } else {
        cerr << "Problem on the file !" << endl;
    }
}

void Server::consolWrite(const Server& ser){
    cout << "[Server]" << endl;
    cout << ser.m_data_sensor_temperature << endl; 
    cout << ser.m_data_sensor_humidity << endl; 
    cout << ser.m_data_sensor_light << endl; 
    cout << ser.m_data_sensor_pressure << endl << endl; 
}
