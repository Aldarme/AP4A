#include "Server.hpp"
#include "Light.hpp"

int main(){
    Light light;
    Package pacman(light.getData(), "light", "lux");

    Server serv;
    serv.consolWrite(pacman);
}