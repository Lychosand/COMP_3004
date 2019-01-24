#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>

class Animal {
public:
    Animal(QString animal_name, QString animal_gender, int animal_age, QString animal_species, QString animal_breed, QString animal_hair_type, QString animal_hair_colour);
    QString name;
    QString gender;
    int     age;
    QString species;
    QString breed;
    QString hair_type;
    QString hair_colour;

private:
    /*
    QString name;
    QString gender;
    int     age;
    QString species;
    QString breed;
    QString hair_type;
    QString hair_colour;
    */
};

#endif // ANIMAL_H
