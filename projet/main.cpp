#include <iostream>
using namespace std;
#include "Server/Server.h"

int main() {
    cout << "Hello, World!" << std::endl;
    Server server;
    float temp, hum, lum, pre;
    temp = 52;
    hum = 30;
    lum = 35.68;
    pre = 50.3;
    server.consolWrite(temp, hum, lum, pre);
    server.fileWrite("temp",temp);
    return 0;
}
