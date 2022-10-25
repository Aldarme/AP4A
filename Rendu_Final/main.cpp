
#include <iostream>
#include "Sensor.cpp"
#include "Packet.cpp"
#include "Server.cpp"
#include "Scheduler.cpp"
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>



int main()
{
   
    int t,p,h,l,n,visualize,log;
    Server svr;

    std::cout<<"This program will give you the information about the temperature, pressure, humidity and light in this plane.\nIt will collect the data during T seconds. Each data will be collected in a different interval of time (in seconds), which you may choose.\n"<<std::endl;
    std::cout<<"During how many seconds do you want the data to be collected? (in seconds)"<<std::endl;std::cin>>n;
    std::cout<<"Please enter the time interval for temperature..."<<std::endl;std::cin>>t;
    std::cout<<"Please enter the time interval for pressure..."<<std::endl;std::cin>>p;
    std::cout<<"Please enter the time interval for humidity..."<<std::endl;std::cin>>h;
    std::cout<<"Please enter the time interval for light..."<<std::endl;std::cin>>l;

    std::cout<<"Do you want to see the result on console? (enter 1 for yes, 0 for no)"<<std::endl;std::cin>>visualize;
    while (visualize!=0 && visualize!=1)
    {
        std::cout<<"You entered the wrong input.\nDo you want to see the result on console? (enter 1 for yes, 0 for no)"<<std::endl;std::cin>>visualize;
    }
    std::cout<<"Do you want to create file to stock the data? (enter 1 for yes, 0 for no)"<<std::endl;std::cin>>log;
    while (log!=0 && log!=1)
    {
        std::cout<<"You entered the wrong input.\nDo you want to create file to stock the data? (enter 1 for yes, 0 for no)"<<std::endl;std::cin>>log;
    }
    
    //clear the data in the files from previous program.
    svr.clearDataInFile();

    //start collecting the data
    Scheduler sch1(t,p,h,l,n,visualize,log);
    sch1.theScheduler();
    
    if (log==1)
    {
        std::cout<<"The process is finished.\nYou can see the data in the file 'name.txt'."<<std::endl;
    }
    
}
    