#ifndef MATCH_H
#define MATCH_H

#include "Animal.h"
#include "Client.h"

class Match{
public:
    Match(Animal*, Client*, int);
    ~Match();
    int getId();
    Animal* getAnimal();
    Client* getClient();
    float getOverallScore();
    float getAggressionScore();
    float getHyperScore();
    float getSleepScore();
    float getNoiseScore();
    float getFoodScore();
    float getMaintainanceScore();
    float getLivingCondScore();
    float getEquipmentScore();
    float getStimuliScore();
    float getAgeScore();
    float getGenderScore();
    float getBreedScore();
    float getHairTypeScore();
    float getHairColourScore();
    void setOverallScore(float);
private:
    int m_id;
    Animal* animal;
    Client* client;
    string reasoning;
    float overallScore;
    float aggressionScore;
    float hyperScore;
    float sleepScore;
    float noiseScore;
    float foodScore;
    float maintainanceScore;
    float livingCondScore;
    float equipmentScore;
    float stimuliScore;
    float ageScore;
    float genderScore;
    float breedScore;
    float hairTypeScore;
    float hairColourScore;
};

#endif // MATCH_H
