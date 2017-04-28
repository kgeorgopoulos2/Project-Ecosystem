#include "organism.h"

Organism::Organism(char species, float size, int age, bool gender, bool rep, float gps, int fn, int fr, bool tp, float ms) : species(species), age(age), size(size), gender(gender), rep(rep), gps(gps), fn(fn), fr(fr), tp(tp), ms(ms)
{
//empty                   
}

void Organism::setSize(float s) {
size=s/2;
}

void Organism::setGPSSize () {
size+=gps;
}

bool Organism::getTrwwPlakton() {
return tp;
}

int Organism::getAge() {
return age;
}

float Organism::getGps(){
return gps;
}

float Organism::setGps(float gps){
gps=-2*gps;
}
     
float Organism::getSize() {
return size;
}

char Organism::getSpecies() {
return species;
}

bool Organism::getRep() {
return rep;
}

bool Organism::getGender() {
return gender;
}
      

Organism::~Organism() //destructor
{

};




