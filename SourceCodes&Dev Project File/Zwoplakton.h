#ifndef ZWOPLAKTON_H
#define ZWOPLAKTON_H
#include "plakton.h"
#include <iostream>

class Zwoplakton : public Plakton {
      public:
      Zwoplakton(char , float , int , int , bool, bool);
      
      private:
      char species;
      float size;
      int fn;
      int fr;
      bool tp;
      bool rep;
}; 

#endif
