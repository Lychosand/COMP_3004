#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Match.h"

Match::Match(Animal *a, Client *c, int i){
    animal = a;
    client = c;
    m_id = i;
    overallScore = 0.0;
    aggressionScore = 0.0;
    hyperScore = 0.0;
    sleepScore = 0.0;
    noiseScore = 0.0;
    foodScore = 0.0;
    maintainanceScore = 0.0;
    livingCondScore = 0.0;
    equipmentScore = 0.0;
    stimuliScore = 0.0;
    ageScore = 0.0;
    genderScore = 0.0;
    breedScore = 0.0;
    hairTypeScore = 0.0;
    hairColourScore = 0.0;
}

Match::~Match(){
}

int Match::getId(){
    return m_id;
}

void Match::setOverallScore(float s){
    overallScore = s;
}

Animal* Match::getAnimal(){
    return animal;
}

Client* Match::getClient(){
    return client;
}

float Match::getOverallScore(){
    return overallScore;
}

float Match::getAggressionScore(){
    return aggressionScore;
}

float Match::getHyperScore(){
    return hyperScore;
}

float Match::getSleepScore(){
    return sleepScore;
}

float Match::getNoiseScore(){
    return noiseScore;
}

float Match::getFoodScore(){
    return foodScore;
}

float Match::getMaintainanceScore(){
    return maintainanceScore;
}

float Match::getLivingCondScore(){
    return livingCondScore;
}

float Match::getEquipmentScore(){
    return equipmentScore;
}

float Match::getStimuliScore(){
    return stimuliScore;
}

float Match::getAgeScore(){
    return ageScore;
}

float Match::getGenderScore(){
    return genderScore;
}

float Match::getBreedScore(){
    return breedScore;
}

float Match::getHairTypeScore(){
    return hairTypeScore;
}

float Match::getHairColourScore(){
    return hairColourScore;
}
