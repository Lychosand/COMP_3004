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
<<<<<<< HEAD
=======
    void setAggressionScore(float);
    void setHyperScore(float);
    void setSleepScore(float);
    void setNoiseScore(float);
    void setFoodScore(float);
    void setMaintenanceScore(float);
    void setLivingScore(float);
    void setEquipmentScore(float);
    void setStimuliScore(float);
    void setAgeScore(float);
    void setGenderScore(float);
>>>>>>> master
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
<<<<<<< HEAD
    float maintainanceScore;
=======
    float maintenanceScore;
>>>>>>> master
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
