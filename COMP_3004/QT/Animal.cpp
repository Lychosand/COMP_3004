#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Animal.h"

Animal::Animal(string n, string g, string s,string b, string hT, string hC, int a){
    name = n;
    gender = g;
    species = s;
    breed = b;
    hairType = hT;
    HairColour = hC;
    age = a;
}
string Animal::getName(){
    return name;
}

string Animal::getGender(){
    return gender;
}

string Animal::getBreed(){
    return breed;
}

string Animal::getSpecies(){
    return species;
}

string Animal::getHairType(){
    return hairType;
}

string Animal::getHairColour(){
    return HairColour;
}

int Animal::getAge(){
    return age;
}


/*void Animal::createAnimal(string n, string g, string s,string b, string hT, string hC, int a){
  name = n;
  gender = g;
  species = s;
  breed = b;
  hairType = hT;
  HairColour = hC;
  age = a;
}*/
