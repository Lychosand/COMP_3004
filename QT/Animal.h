#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
using std::string;

class Animal
{

  public:
    Animal(string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,int,int);
    string getName();
    string getGender();
    string getSpecies();
    string getBreed();
    string getHairType();
    string getHairColour();
    string getAggressiveness();
    string getHyperactivity();
    string getSleep();
    string getNoise();
    string getAppetite();
    string getMaintainance();
    string getOutside();
    string getSpace();
    string getChild();
    string getAnimal();
    string getEquipment();
    string getExcitement();
    int getId();
    int getAge();

  private:
    string name,gender,species,breed,hairType,HairColour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space,child,animal,equipment,excitability;
    int age, id;
};

#endif
