#ifndef MHPLAKTON_H
#define MHPLAKTON_H  
#include "organism.h"

class Mhplakton : public Organism {
      public:
      Mhplakton(char , float , int , bool , bool , float , int , int , bool, float);
      
      private:
      char species;
      int age;
      float size;
      bool rep;
      bool gender;
      float gps;
      int fn;
      int fr;
      bool tp;
      float ms;
};      
#endif



