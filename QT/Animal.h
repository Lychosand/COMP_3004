#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
using std::string;

class Animal
{

  public:
    Animal(string,string,string,string,string,string,int);
    string getName();
    string getGender();
    string getSpecies();
    string getBreed();
    string getHairType();
    string getHairColour();
    int getAge();



  private:
    string name,gender,species,breed,hairType,HairColour;
    int age;





};

#endif
