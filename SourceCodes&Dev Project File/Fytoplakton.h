#ifndef FYTOPLAKTON_H
#define FYTOPLAKTON_H
#include "plakton.h"

class Fytoplakton : public Plakton {
      public:
      Fytoplakton(char , float , bool);
      
      private:
      char species;
      float size;
      bool rep;
};

#endif
