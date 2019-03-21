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

string Array::getAnimalAggressiveness(int a){
    return array[a]->getAggressiveness();
}

string Array::getAnimalHyperactivity(int a){
    return array[a]->getHyperactivity();
}
string Array::getAnimalSleep(int a){
    return array[a]->getSleep();
}
string Array::getAnimalNoise(int a){
    return array[a]->getNoise();
}
string Array::getAnimalAppetite(int a){
    return array[a]->getAppetite();
}
string Array::getAnimalMaintainance(int a){
    return array[a]->getMaintainance();
}
string Array::getAnimalOutside(int a){
    return array[a]->getOutside();
}
string Array::getAnimalSpace(int a){
    return array[a]->getSpace();
}
string Array::getAnimalChild(int a){
    return array[a]->getChild();
}
string Array::getAnimalAnimalFriendly(int a){
    return array[a]->getAnimal();
}
string Array::getAnimalEquipment(int a){
    return array[a]->getEquipment();
}
string Array::getAnimalExcitability(int a){
    return array[a]->getExcitement();
}

int Array::getAnimalAge(int a){
    return array[a]->getAge();
}






