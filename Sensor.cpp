#include <iostream>
#include"Sensor.hpp"

using namespace std;

template <class T> T Sensor<T>::getData(){
    return this->value;
}
template <class T> T Sensor<T>::aleaGenVal(){
  srand(time(0));
  
   return rand() % (max - min) + min;
};