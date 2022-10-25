#include <iostream>
#include "Pression.hpp"


int Pression::getData()
{
    return Pression::randomValue(950,1050); //Generating a random number between 950 and 1050 (hPa)
}; //Returning the pression value

int Pression::randomValue(int param_minor, int param_major)
{
    return (rand()%param_major - param_minor)+param_minor;
}; //Generating a random int between param_minor and param_major

std::ostream &operator<<(std::ostream &os, const Pression &pression) {
    return os;
}
