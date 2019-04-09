#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Animal.h"

Animal::Animal(string n, string g, string s,string b, string hT, string hC,string aG,string hA,string sL,string nO ,string aP,string mA,string oU,string sP,string cH,string aH,string eQ,string eX, int a, int aId){
    name = n;
    gender = g;
    species = s;
    breed = b;
    hairType = hT;
    HairColour = hC;
    aggressiveness = aG;
    hyperactivity = hA;
    sleep = sL;
    noise = nO;
    appetite = aP;
    maintainance = mA;
    outside = oU;
    space = sP;
    child = cH;
    animal = aH;
    equipment = eQ;
    excitability = eX;
    age = a;
    id = aId;
}

int Animal::getId(){
    return id;
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

string Animal::getAggressiveness(){
    return aggressiveness;
}

string Animal::getHyperactivity(){
    return hyperactivity;
}

string Animal::getSleep(){
    return sleep;
}

string Animal::getNoise(){
    return noise;
}

string Animal::getAppetite(){
    return appetite;
}

string Animal::getMaintainance(){
    return maintainance;
}

string Animal::getOutside(){
    return outside;
}

string Animal::getSpace(){
    return space;
}

string Animal::getChild(){
    return child;
}

string Animal::getAnimal(){
    return animal;
}

string Animal::getEquipment(){
    return equipment;
}

string Animal::getExcitement(){
    return excitability;
}

int Animal::getAge(){
    return age;
}

