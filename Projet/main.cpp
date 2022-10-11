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
    /*std::ofstream TemperatureFile("temperature.txt");
    std::ofstream PressureFile("pressure.txt");
    std::ofstream HumidityFile("humidity.txt");
    std::ofstream LightFile("light.txt");*/
    
    int t,p,h;
    bool l,created=false;
    Server svr;

    Temperature temp1;
    Pressure press1;
    Humidity humid1;
    Light lumiere1;

    Packet pck(temp1,press1,humid1,lumiere1);

    int dataTemp,dataPress,dataHumid;
    bool dataLight;
    srand(time(0));
    int n;

std::cout<<"This program will give you the information about the temperature, pressure, humidity and light in this plane"<<std::endl;
std::cout<<"It will collect the data every N seconds."<<std::endl;
std::cout<<"Please enter N..."<<std::endl;
std::cin>>n;

for (int i = 0; i < 10; i++)
{
    //generate random number for the capteur
    t = aleaGenVal(50);
    p = aleaGenVal(100);
    h = aleaGenVal(100);
    l = aleaGenValBool(2);
    
    //set new value for each object(temperature,pressure,humidity and light)
    temp1.setter(t);
    press1.setter(p);
    humid1.setter(h);
    lumiere1.setter(l);

    //get the value for each object 
    dataTemp=temp1.getData();
    dataHumid=humid1.getData();
    dataPress=press1.getData();
    dataLight=lumiere1.getData();

    //set a packet to send to the server
    pck.setPacket(temp1,press1,humid1,lumiere1);

    // affichage "Packet 1, Packet 2, Packet 3......"
    std::cout<<"Packet "<<i+1<<":"<<std::endl;

    //display on console the result
    svr.consolWrite(pck);
    
    //check if Files .txt have been created or not
    if (i>0)
    {
        created=true;
    }
    
    //write in file
    svr.fileWrite(pck,1);
    svr.fileWrite(pck,2);
    svr.fileWrite(pck,3);
    svr.fileWrite(pck,4);

    //delay how many seconds
    scheduler(n);
    
}
    
    


    /*std::cout<<"temperature: "<<dataTemp<<std::endl;
    std::cout<<"humidity: "<<dataHumid<<std::endl;
    std::cout<<"pressure: "<<dataPress<<std::endl;
    std::cout<<"light: "<<dataLight<<std::endl;*/

    /*std::cout<<"temperature : "<<dataTemp<<std::endl;
    std::cout<<"pressure : "<<dataPress<<std::endl;
    std::cout<<"humidity :" <<dataHumid<<std::endl;*/
   
    //svr.consolWrite(pck);
    //Packet myPac=new Packet();
    
    /*std::cout<<rand()<<std::endl;
    std::cout<<rand()<<std::endl;
    std::cout<<rand()<<std::endl;*/
   
    //Sensor scr(t,p,h,l);
    
    //change parameter for Packet constructor to type Temperature,Pressure,Humidity and Light
    /*Packet packet1(temperature1,press1,humid1,lumiere1);
    Server svr;
    svr.consolWrite(packet1);
    */   
    //svr.consolWrite(scr);
    
    //Packet pck;


    //Packet pck(t,p,h,l);
    //pck.getInfo();
 //Temperature temp1 = new Temperature(3);

    //int ran;
    //ran = generateRandom();
    //std::cout<<ran<<std::endl;
    //getData();


    float cuba,cuka;
    //cuba=aleaGenVal();
    //cuka=aleaGenVal();
    //std::cout<<cuba<<std::endl;
    //std::cout<<cuba<<std::endl;

}