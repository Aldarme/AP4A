/**
 * @file Server.hpp
 * @author Flavian THEUREL
 * @brief The server receives datas from captors and displays/saves them
 * @version 0.1
 * @date 2022-09-28
 */


#ifndef SERVER_H
#define SERVER_H

/**
 * @class EType
 * @brief Enumeration of the data type that are provided by the sensors 
 */
enum EType
{
  e_temperature,
  e_humidity,
  e_pressure,
  e_light
};

/**
 * @class Server
 * @brief Server receives datas from captors and displays/saves them
 */
class Server
{
private:
  int m_temperatureBuffer, m_humidityBuffer, m_pressureBuffer, m_lightBuffer; // Attribute used to stock the data from the sensor until a new data is sent
  bool m_settingLog = true, m_settingDisplay = true; // Status of the diplaying / logging methods

   /**
   * @brief Write in a file the data provided by the sensor
   * 
   * @param type Data type
   * @param data_p Data from the sensor
   */
  void fileWriter(EType type_p);

  /**
   * @brief Write in the console the data provided by a sensor
   * 
   * @param type Data type
   * @param data_p Data from the sensor
   */
  void consolWrite(EType type_p);

public:
  Server();
  Server(const Server& serv_p);
  ~Server();
  Server& operator=(const Server& serv_p);

  /**
   * @brief Do the display / log of the data corresponding to its type (take in account the settings)
   * 
   * @param type Data type
   */
  void operator>>(EType type);

  /**
   * @brief Get the data from a sensor
   * 
   * @param type_p Data type
   * @param data_p Data from the sensor
   * @return true if the data has been correctly sent
   */
  void receiveData(EType type_p, int data_p);
};

#endif