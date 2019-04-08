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
    maintenanceScore = 0.0;
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
void Match::setAggressionScore(float s) {
    aggressionScore = s;
}
void Match::setHyperScore(float s) {
    hyperScore = s;
}
void Match::setSleepScore(float s) {
    sleepScore = s;
}
void Match::setNoiseScore(float s) {
    noiseScore = s;
}
void Match::setFoodScore(float s) {
    foodScore = s;
}
void Match::setMaintenanceScore(float s) {
    maintenanceScore = s;
}
void Match::setLivingScore(float s) {
    livingCondScore = s;
}
void Match::setEquipmentScore(float s) {
    equipmentScore = s;
}
void Match::setStimuliScore(float s) {
    stimuliScore = s;
}
void Match::setAgeScore(float s) {
    ageScore = s;
}
void Match::setGenderScore(float s) {
    genderScore = s;
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
    return maintenanceScore;
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
