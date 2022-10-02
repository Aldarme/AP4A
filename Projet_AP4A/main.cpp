#include <iostream>
#include "sensor.hpp"
#include "server.hpp"

int main() {
    Temperature t;
    Humidite h;
    Pression p;
    Light l;
    Server s;
    s.fileWrite(t.getName(), t.getData(), t.getUnite());
    s.consolWrite(t.getName(), t.getData(), t.getUnite());
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
