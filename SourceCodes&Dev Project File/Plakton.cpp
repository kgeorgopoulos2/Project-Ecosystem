#include <iostream>  
#include "plakton.h"


Plakton::Plakton(char species, float size, int fn, int fr, bool tp, bool rep) : Organism(species, size, fn, fr, rep, tp)
{
//empty
}

void Organism::getAge() {
std::cout << "Plakton does not age!!!";
}
