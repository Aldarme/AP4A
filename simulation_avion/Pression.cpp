#include "Pression.hpp"
#include <stdlib.h>

Pression::Pression() {
    this->value = 0;  
}
Pression::Pression(const Pression& p) {
    this->value = p.value; 
}
Pression& Pression::operator=(const Pression& p) {
    this->value = p.value; 
    return *this; 
}
Pression& Pression::operator=(float p) {
    this->value = p; 
    return *this; 
}
Pression::~Pression() {
}

int Pression::aleaGenValue(){
    return (rand()%450 + 50); //pression between 50 and 500
}

