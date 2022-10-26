/**
 * @author Erhart Eliott
 * @file Server.cpp
 * @date 03/10/2022
 * @brief 
 */

#include "Server.hpp"

Server Server::displayChoice()
{
        while (answerConsole != 'Y' && answerConsole != 'N' )
        {
                std::cout << "Do you want to display the values ​​in the terminal ? (Y/N)" << std::endl;
                std::cin >> answerConsole;
        }

        while (answerLogs != 'Y' && answerLogs != 'N' )
        {
                std::cout << "Do you want to display the values ​​in the dedicated files ? (Y/N)" << std::endl;
                std::cin >> answerLogs;
        }     

        return *this;
}

void Server::consoleWrite(int tps)
{
        if(answerConsole == 'Y'){
                std::cout << "\nDATAS (" << tps << " seconds from start)" << std::endl;
                std::cout << "Humidity: " << H << " g/m^3" << std::endl;

                if(tps%2 == 1)
                {
                        std::cout << "Light: " << L << "" << std::endl;
                        std::cout << "Pressure: " << P << " KPa" << std::endl;
                }

                if(tps%3 == 1)
                {
                        std::cout << "Temperature: " << T <<" °C " << std::endl;
                }
        }
}

void Server::fileWrite(int tps)
{
        if(answerLogs == 'Y')
        {
                std::ofstream myFluxH("Humidity.txt",std::ios::app);
                if(myFluxH)    
                {
                        myFluxH << "HUMIDITY SENSOR DATA ("<< tps << " seconds from start)\n" << std::endl;
                        myFluxH << "Humidity: " << H << " g/m^3\n" << std::endl;
                }
                else
                {
                        std::cerr << "ERROR: Unable to open file." << std::endl;
                }

                std::ofstream myFluxL("Light.txt",std::ios::app);
                if(myFluxL)    
                {
                        if(tps%2 == 1)
                        {
                                myFluxL << "LIGHT SENSOR DATA ("<< tps << " seconds from start)\n" << std::endl;
                                if(L == 1)
                                {
                                        myFluxL << "Light: On \n" << std::endl;
                                }
                                else
                                {
                                        myFluxL << "Light: Off \n" << std::endl;
                                }
                        }
                }
                else
                {
                        std::cerr << "ERROR: Unable to open file." << std::endl;
                }

                std::ofstream myFluxP("Pressure.txt",std::ios::app);
                if(myFluxP)    
                {
                        if(tps%2 == 1)
                        {
                                myFluxP << "PRESSURE SENSOR DATA ("<< tps << " seconds from start)\n" << std::endl;
                                myFluxP << "Pressure: " << P << " KPa\n" << std::endl;
                        }
                }
                else
                {
                        std::cerr << "ERROR: Unable to open file." << std::endl;
                }

                std::ofstream myFluxT("Temperature.txt",std::ios::app);
                if(myFluxT)    
                {
                        if(tps%3 == 1)
                        {
                                myFluxT << "TEMPERATURE SENSOR DATA ("<< tps << " seconds from start)\n" << std::endl;
                                myFluxT << "Temperature: " << T <<" °C \n\n" << std::endl;
                        }
                }
                else
                {
                        std::cerr << "ERROR: Unable to open file." << std::endl;
                }
        }
}

void Server::fileClear()
{
        if(answerLogs == 'Y')
        {
        std::ofstream myFluxH("Humidity.txt");
        std::ofstream myFluxL("Light.txt");
        std::ofstream myFluxP("Pressure.txt");
        std::ofstream myFluxT("Temperature.txt");
        }
}
