#ifndef ARRAY_H
#define ARRAY_H
#include <string>
using namespace std;
#include "Animal.h"

#define MAX_ARR_SIZE  128

class Array{

  public:
    Array(){
      numAnimal = 0;
    }
    ~Array();
    void addAnimal(Animal *b);
    void deleteList();
    int getNumAnimal();
    string getAnimalName(int);
    string getAnimalGender(int);
    string getAnimalSpecies(int);
    string getAnimalBreed(int);
    string getAnimalHairType(int);
    string getAnimalHairColour(int);
    int getAnimalAge(int);


  private:
    Animal * array[MAX_ARR_SIZE];
    int numAnimal;

};
#endif
