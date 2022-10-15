#include "../hpp/Scheduler.hpp"
#include "../hpp/Temperature.hpp"
#include "../hpp/Light.hpp"
#include "../hpp/Humidity.hpp"
#include "../hpp/Pression.hpp"

#include<cstdio>
#include<iostream>



int main()

{
    Scheduler sch; //création d'un objet Scheduleur
    sch.getSensorData(); //Lancement de la fonction permettant de run tout le programme en recuperant les données envoyées des sensors et les envoyant au Server pour l'affichage et le stockage
    return 0;


    // int a=clock();//this gets the time in sec.
    // std::cout<<a;

    
        // while(true)
        // {
        //    while(clock()/CLOCKS_PER_SEC-a<1);
        //    std::cout<<"test"<<" ";
        //    a=clock()/CLOCKS_PER_SEC;
        // }

    // Temperature *temperature;
    // temperature = new Temperature;

    // Light *light;
    // light = new Light;

    // Humidity *humidity;
    // humidity = new Humidity;

    // Pression *pression;
    // pression = new Pression;

    
    // std::cout << temperature->getData() << std::endl;
    // std::cout << light->getData() << std::endl;
    // std::cout << humidity->getData() << std::endl;
    // std::cout << pression->getData() << std::endl;

    
}

// #include <iostream>
// #include <thread>

// void thread_function()
// {
//     std::cout << "thread function\n";
// }

// void thread_function2()
// {
//     std::cout << "thread function2\n";
// }

// int main()
// {
//     std::thread t(&thread_function);
//     std::thread t2(&thread_function2);   // t starts running
//     std::cout << "main thread\n";
//     t.join();
//     t2.join();   // main thread waits for the thread t to finish
//     return 0;
// }

