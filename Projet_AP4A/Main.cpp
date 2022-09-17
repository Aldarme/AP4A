#include <iostream>
#include "Server.cpp"

using namespace std;

int main(){

    cout << "\nPremier Test\n" << endl;

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    Server s(a, b, c, d);

    Server sp;

    s.consoleWrite();

    sp.consoleWrite();

    s.fileWrite("C:/Users/hugoc/OneDrive/Bureau/Projet_AP4A/Capteurs.txt");

    return 0;
}