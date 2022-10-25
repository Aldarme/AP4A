
//  ∗ @author Xiyu LUO
//  ∗ @file Server . cpp
//  ∗ @date 25/10/2022

#include "Server.h"

// ∗ @class Server
// ∗ @Class Sensor is used to abstract the real server connected to sensors
//    It provides a member function dataRcv for receiving data from the sensor
//    It provides two pritave member functions consolWrite and fileWrite
//    The first one is used to display the received data and the second one is used to write the data to the log file
//    Both of these functions can be disabled or enabled under certain conditions

template <class T>
void Server<T> :: consolWrite(T t)//Display the received data
{
    if(consolActivation==1)//If it is allowed to display the data
    {
       cout << "Receive a data from a sensor" <<endl;
       if(this_thread::get_id()==Th_t.get_id())
       //Use the ID of the thread to know if this function is called in the thread that control the corresponding sensor
       {
            cout << "Temperature : " << t <<endl;
       }
       if(this_thread::get_id()==Th_h.get_id()){
            cout << "Humidity : " << t <<endl;
       }
       if(this_thread::get_id()==Th_l.get_id()){
            cout << "Light : " << t <<endl;
       }
       if(this_thread::get_id()==Th_p.get_id()){
            cout << "Pression : " << t <<endl;
       }
    }
    else{
        cout << "Error! Can not display the data" <<endl;
    }
}

template <class T>
void Server<T> :: fileWrite(T t)//Write the data to the log file
{
    if(logActivation==1)//If it is allowed to write the data
    {
        ofstream LogFile;
        if(this_thread::get_id()==Th_t.get_id())
        //Use the ID of the thread to know if this function is called in the thread that control the corresponding sensor
        {
            LogFile.open("T_logfile.txt",ofstream::app);//Open the corresponding log file
            LogFile << "----" << t << "----" <<"\n";//Write the data
            LogFile.close();//Close the file
            cout << "Write temperature data to log file" <<endl;
        }
        if(this_thread::get_id()==Th_h.get_id()){
            LogFile.open("H_logfile.txt",ofstream::app);
            LogFile << "----" << t << "----" <<"\n";
            LogFile.close();
            cout << "Write humidity data to log file" <<endl;
        }
        if(this_thread::get_id()==Th_l.get_id()){
            LogFile.open("L_logfile.txt",ofstream::app);
            LogFile << "----" << t << "----" <<"\n";
            LogFile.close();
            cout << "Write light data to log file" <<endl;
        }
        if(this_thread::get_id()==Th_p.get_id()){
            LogFile.open("P_logfile.txt",ofstream::app);
            LogFile << "----" << t << "----" <<"\n";
            LogFile.close();
            cout << "Write data pression to log file" <<endl;
        }
    }
    else{
        cout << "Error! Can not log the data" <<endl;
    }
}

template <class T>
void Server<T> :: dataRcv(T t){
    consolActivation=1; //Allow to display the data
    consolWrite(t); //Call consolWrite to diaplay the data "t"
    logActivation=1;    //Allow to write the data to the log file
    fileWrite(t);   //Call fileWrite to write the data "t"
    consolActivation=0; //Disabling of functions
    logActivation=0;    //Disabling of functions
}
