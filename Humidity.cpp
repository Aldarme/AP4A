#include "Humidity.hpp"
#include <stdio.h> 
#include <stdlib.h>

/*on ajoute un min et un max différent pour chaque capteur, qui seront utilisés pour créer un une valeur cohérente avec la réalité*/

 
Humidity::Humidity()
{
    min = 0;        
    max = 100;
} //constructeur par défaut

Humidity::~Humidity()
{

} //Destructeur
