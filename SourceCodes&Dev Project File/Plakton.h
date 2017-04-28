#ifndef PLAKTON_H
#define PLAKTON_H
#include "organism.h"

class Plakton : public Organism {
      public:
      Plakton(char , float , int , int, bool, bool);
      Plakton(char , float, bool);
      void getAge();
      
      private:
      char species;
      float size;
      int fn;
      int fr;
      bool rep;
      bool tp;
}; 
     
#endif
