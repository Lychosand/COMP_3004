#include <iostream>
#include <iomanip>
using namespace std;
#include "Array.h"

void Array::addAnimal(Animal *b)
{
  array[numAnimal] = b;
  numAnimal += 1;

}

void Array::deleteList(){
    for (int i = 0; i < numAnimal; i++)
       {
           delete array[i];
       }
    numAnimal = 0;
}
Array::~Array(){
  for (int i = 0; i < numAnimal; i++)
     {
         delete array[i];
     }
}

int Array::getNumAnimal(){
    return numAnimal;
}

string Array::getAnimalName(int a){
    return array[a]->getName();
}

string Array::getAnimalGender(int a){
    return array[a]->getGender();
}

string Array::getAnimalBreed(int a){
    return array[a]->getBreed();
}

string Array::getAnimalSpecies(int a){
    return array[a]->getSpecies();
}

string Array::getAnimalHairType(int a){
    return array[a]->getHairType();
}

string Array::getAnimalHairColour(int a){
    return array[a]->getHairColour();
}
int Array::getAnimalAge(int a){
    return array[a]->getAge();
}






