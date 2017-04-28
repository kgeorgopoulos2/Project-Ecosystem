#ifndef ORGANISM_H
#define ORGANISM_H

class Organism {
      public:
      Organism(char , float , int ,bool ,bool ,float  ,int , int , bool, float);
      Organism(char, float, int, int, bool, bool);
      float getSize();
      float setGps();
      float getGps();
      char getSpecies();
      bool getRep();
      bool getGender();
      bool getTrwwPlakton();
      void setSize(float );
      ~Organism();
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
