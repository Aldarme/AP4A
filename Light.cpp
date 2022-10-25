#include <iostream>
#include "Light.hpp"


bool Light::getData() {
    return Light::randomValue(0, 1); //Generating a random number between 0 and 1 (0 = false, 1 = true)
}; //Returning the light value

bool Light::randomValue(int param_minor, int param_major) {
    return (rand() % param_major - param_minor) + param_minor;
}

std::ostream &operator<<(std::ostream &os, const Light &light) {
    return os;
}; //Generating a random bool between param_minor and param_major