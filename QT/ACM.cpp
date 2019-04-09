#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <cmath>

using namespace std;

//QSqlDatabase animal_db=QSqlDatabase::addDatabase("QSQLITE");

#include "ACM.h"
int highestSum = 0;

ACM::ACM(){
}

ACM::~ACM(){
}

bool sortFn(Match &m1, Match &m2){
    return m1.getOverallScore() > m2.getOverallScore();
}

void ACM::compute(Array animalList, ClientArray clientList, vector<Match> &set){
    V2D temp(clientList.getNumClients(), V1D(animalList.getNumAnimal()));
    V2D matrix(0, V1D(0));

    V1D clients(0);
    V1D animals(0);

    sortedSet.clear();
    set.clear();
    finalSet.clear();

    initSet(set, animalList, clientList);

    scoring(set, temp); //function call to run through routines producing all grade weights
    NRooks(temp, clients, animals, matrix);

    for(int i = 0; i < (int)temp.size(); i++) {
        for(int j = 0; j < (int)temp[i].size(); j++) {
            if(matrix[i][j] == 1) {
                cout << "Client " << clients[i] << " Matches With Animal " << animals[j] << " With Score of: " << temp[i][j] << endl;
            }
        }
    }

    /*
    testVals(set);//insert testing values, not necessary once you implement the scoring

    sort(set.begin(), set.end(), sortFn);

    //sortSet(set, sortedSetOrig);//sorts set from highest to lowest, not working right now, maybe just do this as you get the overall scores?

    cutOff(set);// gets rid of any match with overall score < 70

    optimalSet(sortedSet);//computes optimal set

    set.clear();
    for(int i = 0; i < (int)(finalSet.size()); i++){
        set.push_back(finalSet.at(i));
    }

    time_t end = time(0);
    double timeSpent = difftime(end, start);
    qDebug() << "Time Spent: " << timeSpent;
    */
}

void ACM::initSet(vector<Match> &matchVec, Array aList, ClientArray cList){
    QString s, s2;
    int k = 0;
    for(int i = 0; i < aList.getNumAnimal(); i++){
        for(int j = 0; j < cList.getNumClients(); j++){
            Match m(aList.getAnimalAt(i), cList.getClientAt(j), k);
            matchVec.push_back(m);
            k++;
        }
    }
}

bool ACM::dealBreakers(vector<Match> &set, int i, int* pref){
    /*Input:set of all matches
     *if a mtach breaks a dealbreaker rule do something like set.erase(set.begin()+i);
     *Output: reduced set of matches
     */
    //Switch statement handles checking if the client is looking for a specific animal
    switch(pref[0]){
        case 0: //cout << "Any" <<  " vs " << set.at(i).getAnimal()->getSpecies() << endl;
                break;
        case 1: //cout << "Dog" <<  " vs " << set.at(i).getAnimal()->getSpecies() << endl;
                if(set.at(i).getAnimal()->getSpecies() != "Dog")
                    return true;
                    //cout << "We Got A Problem!" << endl;
                break;
        case 2: //cout << "Cat" <<  " vs " << set.at(i).getAnimal()->getSpecies() << endl;
                if(set.at(i).getAnimal()->getSpecies() != "Cat")
                    return true;
                    //cout << "We Got A Problem!" << endl;
                break;
        case 3: //cout << "Rabbit" <<  " vs " << set.at(i).getAnimal()->getSpecies() << endl;
                if(set.at(i).getAnimal()->getSpecies() != "Rabbit")
                    return true;
                    //cout << "We Got A Problem!" << endl;
                break;
        case 4: //cout << "Bird" <<  " vs " << set.at(i).getAnimal()->getSpecies() << endl;
                if(set.at(i).getAnimal()->getSpecies() != "Bird")
                    return true;
                    //cout << "We Got A Problem!" << endl;
                break;
        case 5: //cout << "Hamster" <<  " vs " << set.at(i).getAnimal()->getSpecies() << endl;
                if(set.at(i).getAnimal()->getSpecies() != "Hamster")
                    return true;
                    //cout << "We Got A Problem!" << endl;
                break;
        case 6: //cout << "Guinea Pig" <<  " vs " << set.at(i).getAnimal()->getSpecies() << endl;
                if(set.at(i).getAnimal()->getSpecies() != "Guinea Pig")
                    return true;
                    //cout << "We Got A Problem!" << endl;
                break;
        case 7: //cout << "Chinchilla" <<  " vs " << set.at(i).getAnimal()->getSpecies() << endl;
                if(set.at(i).getAnimal()->getSpecies() != "Chinchilla")
                    return true;
                    //cout << "We Got A Problem!" << endl;
                break;
    }

    //If the client has children and the animal is not good with children
    switch(pref[8]) {
        case 1:
            if(set.at(i).getAnimal()->getChild() == "No Children")
                return true;
            break;
    }

    //If the client has animals and the animal is not friendly with other animals
    switch(pref[10]) {
        case 0: break;
        default:
            if(set.at(i).getAnimal()->getAnimal() == "Not Animal Friendly")
                return true;
            break;
    }

    return false;
}

//Routine handling aggression
float ACM::aggressionRule(vector<Match> &set, int i, int* pref) {

    float difference = 0;
    float client_score = (pref[1] + 1) * 0.25;

    if(set.at(i).getAnimal()->getAggressiveness() == "Submissive") {
        difference = client_score - 0.25;
    }else if(set.at(i).getAnimal()->getAggressiveness() == "Slightly Submissive") {
        difference = client_score - 0.50;
    }else if(set.at(i).getAnimal()->getAggressiveness() == "Slightly Aggressive") {
        difference = client_score - 0.75;
    }else if(set.at(i).getAnimal()->getAggressiveness() == "Aggressive") {
        difference = client_score - 1;
    }

    if(difference < 0) {
        return (0.12 + (0.12 * difference));
    }else {
        return 0.12;
    }
}

//Routine handling hyperactivity
float ACM::hyperactivityRule(vector<Match> &set, int i, int* pref) {
    float hyper_diff = 0;
    float maintenance_diff = 0;
    float living_diff = 0;
    float client_hyper = (pref[2] + 1) * 0.25;
    float client_living = pref[7] * 0.2;
    float client_maintenance = pref[6] * 0.25;

    if(set.at(i).getAnimal()->getHyperactivity() == "Calm") {
        hyper_diff = client_hyper - 0.25;
        living_diff = client_living - 0.25;
    }else if (set.at(i).getAnimal()->getHyperactivity() == "Slightly Calm") {
        hyper_diff = client_hyper - 0.50;
        living_diff = client_living - 0.50;
    }else if(set.at(i).getAnimal()->getHyperactivity() == "Slightly Hyper") {
        hyper_diff = client_hyper - 0.75;
        living_diff = client_living - 0.75;
    }else if(set.at(i).getAnimal()->getHyperactivity() == "Hyper") {
        hyper_diff = client_hyper - 1;
        living_diff = client_living - 1;
    }

    if(set.at(i).getAnimal()->getMaintainance() == "Minimal") {
        maintenance_diff = client_maintenance - 0.25;
    }else if(set.at(i).getAnimal()->getMaintainance() == "Below Average") {
        maintenance_diff = client_maintenance - 0.50;
    }else if(set.at(i).getAnimal()->getMaintainance() == "Above Average") {
        maintenance_diff = client_maintenance - 0.75;
    }else if(set.at(i).getAnimal()->getMaintainance() == "Special Care Needed") {
        maintenance_diff = client_maintenance - 1;
    }

    if(hyper_diff < 0) {
        hyper_diff = (0.05 + (hyper_diff * 0.05));
    }else {
        hyper_diff = 0.05;
    }

    if(maintenance_diff < 0) {
        maintenance_diff = (0.025 + (maintenance_diff * 0.025));
    }else {
        maintenance_diff = 0.025;
    }

    if(living_diff < 0) {
        living_diff = (0.025 + (living_diff * 0.025));
    }else {
        living_diff = 0.025;
    }

    return hyper_diff + maintenance_diff + living_diff;
}


//Routine handling sleep schedule
float ACM::sleepRule(vector<Match> &set, int i, int* pref) {
    float sleep_diff = 0;
    float maintenance_diff = 0;
    float client_sleep = pref[3] * 0.25;
    float client_maintenance = pref[6] * 0.25;

    if(set.at(i).getAnimal()->getMaintainance() == "Minimal") {
        maintenance_diff = client_maintenance - 0.25;
    }else if(set.at(i).getAnimal()->getMaintainance() == "Below Average") {
        maintenance_diff = client_maintenance - 0.50;
    }else if(set.at(i).getAnimal()->getMaintainance() == "Above Average") {
        maintenance_diff = client_maintenance - 0.75;
    }else if(set.at(i).getAnimal()->getMaintainance() == "Special Care Needed") {
        maintenance_diff = client_maintenance - 1;
    }

    if(set.at(i).getAnimal()->getSleep() == "Nocturnal") {
        sleep_diff = client_sleep - 0.33;
    }else if(set.at(i).getAnimal()->getSleep() == "Flexible") {
        sleep_diff = client_sleep - 0.66;
    }else if(set.at(i).getAnimal()->getSleep() == "Normal") {
        sleep_diff = client_sleep - 1;
    }

    if(sleep_diff < 0) {
        sleep_diff = (0.045 + (sleep_diff * 0.045));
    }else {
        sleep_diff = 0.045;
    }

    if(maintenance_diff < 0) {
        maintenance_diff = (0.045 + (sleep_diff * 0.045));
    }else {
        maintenance_diff = 0.045;
    }

    return sleep_diff + maintenance_diff;
}


//Routine handling noise tolerance
float ACM::noiseRule(vector<Match> &set, int i, int* pref) {
    float hyper_diff = 0;
    float noise_diff = 0;
    float client_noise = pref[4] * 0.2;

    if(set.at(i).getAnimal()->getHyperactivity() == "Calm") {
        hyper_diff = client_noise - 0.25;
    }else if (set.at(i).getAnimal()->getHyperactivity() == "Slightly Calm") {
        hyper_diff = client_noise - 0.50;
    }else if(set.at(i).getAnimal()->getHyperactivity() == "Slightly Hyper") {
        hyper_diff = client_noise - 0.75;
    }else if(set.at(i).getAnimal()->getHyperactivity() == "Hyper") {
        hyper_diff = client_noise - 1;
    }

    switch(std::stoi(set.at(i).getAnimal()->getNoise())) {
        case 1: noise_diff = client_noise - 0.1;
            break;
        case 2: noise_diff = client_noise - 0.2;
            break;
        case 3: noise_diff = client_noise - 0.3;
            break;
        case 4: noise_diff = client_noise - 0.4;
            break;
        case 5: noise_diff = client_noise - 0.5;
            break;
        case 6: noise_diff = client_noise - 0.6;
            break;
        case 7: noise_diff = client_noise - 0.7;
            break;
        case 8: noise_diff = client_noise - 0.8;
            break;
        case 9: noise_diff = client_noise - 0.9;
            break;
        case 10: noise_diff = client_noise - 1;
            break;
    }

    if(hyper_diff < 0) {
        hyper_diff = 0.045 + (0.045 * noise_diff);
    }else {
        hyper_diff = 0.045;
    }

    if(noise_diff < 0) {
        noise_diff = 0.045 + (0.045 * noise_diff);
    }else {
        noise_diff = 0.045;
    }

    return hyper_diff + noise_diff;
}

//Routine handling food budget
float ACM::foodRule(vector<Match> &set, int i, int* pref) {
    float food_diff = 0;
    float client_food = pref[5] * 0.33;

    if(set.at(i).getAnimal()->getAppetite() == "Minimal") {
        food_diff = client_food - 0.33;
    }else if(set.at(i).getAnimal()->getAppetite() == "Average") {
        food_diff = client_food - 0.66;
    }else if(set.at(i).getAnimal()->getAppetite() == "Above Average") {
        food_diff = client_food - 0.99;
    }

    if(food_diff < 0) {
        food_diff = (0.09 + (0.09 * food_diff));
    }else {
        food_diff = 0.09;
    }

    return food_diff;
}


//Routine handling time for attention
float ACM::attentionRule(vector<Match> &set, int i, int* pref) {
    float maintenance_diff = 0;
    float client_maintenance = pref[6] * 0.25;

    if(set.at(i).getAnimal()->getMaintainance() == "Minimal") {
        maintenance_diff = client_maintenance - 0.25;
    }else if(set.at(i).getAnimal()->getMaintainance() == "Below Average") {
        maintenance_diff = client_maintenance - 0.50;
    }else if(set.at(i).getAnimal()->getMaintainance() == "Above Average") {
        maintenance_diff = client_maintenance - 0.75;
    }else if(set.at(i).getAnimal()->getMaintainance() == "Special Care Needed") {
        maintenance_diff = client_maintenance - 1;
    }

    if(maintenance_diff < 0) {
        maintenance_diff = 0.09 + (maintenance_diff * 0.09);
    }else {
        maintenance_diff = 0.09;
    }

    return maintenance_diff;
}


//Routine handling living conditions
float ACM::houseRule(vector<Match> &set, int i, int* pref) {
    float outside_diff = 0;
    float space_diff =0;

    float client_maintenance = pref[6] * 0.25;
    float client_living = pref[7] * 0.2;

    if(set.at(i).getAnimal()->getOutside() == "Rarely") {
        outside_diff = client_maintenance - 0.25;
    }else if(set.at(i).getAnimal()->getOutside() == "Sometimes") {
        outside_diff = client_maintenance - 0.50;
    }else if(set.at(i).getAnimal()->getOutside() == "Daily") {
        outside_diff = client_maintenance - 0.75;
    }else if(set.at(i).getAnimal()->getOutside() == "Multiple Times Daily") {
        outside_diff = client_maintenance - 1;
    }

    if(set.at(i).getAnimal()->getOutside() == "Minimal") {
        space_diff = client_living - 0.33;
    }else if(set.at(i).getAnimal()->getOutside() == "Moderate") {
        space_diff = client_living - 0.66;
    }else if(set.at(i).getAnimal()->getOutside() == "Above Average") {
        space_diff = client_living - 1;
    }

    if(space_diff < 0) {
        space_diff = 0.045 + (0.045 * space_diff);
    }else {
        space_diff = 0.045;
    }

    if(outside_diff < 0) {
        outside_diff = 0.045 + (0.045 * outside_diff);
    }else {
        outside_diff = 0.045;
    }

    return space_diff + outside_diff;
}


//Routine handling equipment for animal
float ACM::equipmentRule(vector<Match> &set, int i, int* pref) {
    float equipment_diff = 0;
    float client_equipment = pref[9] * 0.2;

    if(set.at(i).getAnimal()->getEquipment() == "Minimal") {
        equipment_diff = client_equipment - 0.25;
    }else if(set.at(i).getAnimal()->getEquipment() == "Some Equipment") {
        equipment_diff = client_equipment - 0.50;
    }else if(set.at(i).getAnimal()->getEquipment() == "More Than Average Equipment") {
        equipment_diff = client_equipment - 0.75;
    }else if(set.at(i).getAnimal()->getEquipment() == "Above Average") {
        equipment_diff = client_equipment - 1;
    }

    if(equipment_diff < 0) {
        equipment_diff = (0.09 + (0.09 * equipment_diff));
    }else {
        equipment_diff = 0.09;
    }

    return equipment_diff;
}

//Routine handling external stimuli
float ACM::stimuliRule(vector<Match> &set, int i, int* pref) {
    float stimuli_diff = 0;
    float client_stimuli = pref[11] * 0.25;

    if(set.at(i).getAnimal()->getExcitement() == "Easily Excited") {
        stimuli_diff = client_stimuli - 0.33;
    }else if(set.at(i).getAnimal()->getExcitement() == "Moderate") {
        stimuli_diff = client_stimuli - 0.66;
    }else if(set.at(i).getAnimal()->getExcitement() == "Not Easily Excited") {
        stimuli_diff = client_stimuli - 1;
    }

    if(stimuli_diff < 0) {
        stimuli_diff = (0.0825 + (0.0825 * stimuli_diff));
    }else {
        stimuli_diff = 0.0825;
    }

    return stimuli_diff;
}

//Routine handling age rule
float ACM::ageRule(vector<Match> &set, int i, int* pref) {

    if(set.at(i).getAnimal()->getAge() <= 3 && pref[12] == 1) {
        return 0.0825;
    }else if((set.at(i).getAnimal()->getAge() > 3) && (set.at(i).getAnimal()->getAge() < 7) && (pref[12] == 2)) {
        return 0.0825;
    }else if(set.at(i).getAnimal()->getAge() > 7 && pref[12] == 3) {
        return 0.0825;
    }

    return 0;
}

//Routine handling gender rule
float ACM::genderRule(vector<Match> &set, int i, int* pref) {
    float client_gender = pref[13];

    if(client_gender == 0)
        return 0.0825;

    if(client_gender == 1 && set.at(i).getAnimal()->getGender() == "Male") {
        return 0.066;
    }else if(client_gender == 2 && set.at(i).getAnimal()->getGender() == "Female") {
        return 0.0825;
    }

    return 0;
}

void ACM::scoring(vector<Match> &set, V2D &matrix){
    /*Input: reduced set of matches
     *set score for each rule of each match and total the scores par match(there is attributes for a match object to hold
     * all this info
     *Output: set of matches with score attributes set
     */
    int *pref;

    int client_inc = 0;
    int animal_inc = 0;
    int currentAnimal = set.at(0).getAnimal()->getId();

    float running_sum = 0;
    float current_score = 0;

    for(int i = 0; i < (int)set.size(); i++) {
        pref = set.at(i).getClient()->getPreferences();

        running_sum = 0;

        if(currentAnimal != set.at(i).getAnimal()->getId()) {
            currentAnimal = set.at(i).getAnimal()->getId();
            animal_inc = 0;
            client_inc++;
        }

        if(dealBreakers(set, i, pref)) {
            set.at(i).setOverallScore(running_sum);
            matrix[animal_inc++][client_inc] = running_sum;
        }else {
            current_score = aggressionRule(set, i, pref);
            set.at(i).setAggressionScore(current_score);
            running_sum += current_score;

            current_score = hyperactivityRule(set, i, pref);
            set.at(i).setHyperScore(current_score);
            running_sum += current_score;

            current_score = sleepRule(set, i, pref);
            set.at(i).setSleepScore(current_score);
            running_sum += current_score;

            current_score = noiseRule(set, i, pref);
            set.at(i).setNoiseScore(current_score);
            running_sum += current_score;

            current_score = foodRule(set, i, pref);
            set.at(i).setFoodScore(current_score);
            running_sum += current_score;

            current_score = attentionRule(set, i, pref);
            set.at(i).setMaintenanceScore(current_score);
            running_sum += current_score;

            current_score = houseRule(set, i, pref);
            set.at(i).setLivingScore(current_score);
            running_sum += current_score;

            current_score = equipmentRule(set, i, pref);
            set.at(i).setEquipmentScore(current_score);
            running_sum += current_score;

            current_score = stimuliRule(set, i, pref);
            set.at(i).setStimuliScore(current_score);
            running_sum += current_score;

            current_score = ageRule(set, i, pref);
            set.at(i).setAgeScore(current_score);
            running_sum += current_score;

            current_score = genderRule(set, i, pref);
            set.at(i).setGenderScore(current_score);
            running_sum += current_score;

            double total = (running_sum * 100) + 0.5;
            if(total > 100)
                total = 100;

            total = round(total);
            set.at(i).setOverallScore(total);
            matrix[animal_inc++][client_inc] = total;
        }
    }
}

void ACM::testVals(vector<Match> &set){

    for(int i = 0; i < (int)(set.size()); i++){
        /*float f = (float)(rand()%100 + 1);
        set.at(i).setOverallScore(f);*/
        if(set.at(i).getAnimal()->getId() == 10 && set.at(i).getClient()->getDatabaseId() == 11 ){
            set.at(i).setOverallScore(80);
        }else if(set.at(i).getAnimal()->getId() == 10 && set.at(i).getClient()->getDatabaseId() == 12 ){
            set.at(i).setOverallScore(0);
        }else if(set.at(i).getAnimal()->getId() == 10 && set.at(i).getClient()->getDatabaseId() == 13 ){
            set.at(i).setOverallScore(100);
        }else if(set.at(i).getAnimal()->getId() == 11 && set.at(i).getClient()->getDatabaseId() == 11 ){
            set.at(i).setOverallScore(90);
        }else if(set.at(i).getAnimal()->getId() == 11 && set.at(i).getClient()->getDatabaseId() == 12 ){
            set.at(i).setOverallScore(75);
        }else if(set.at(i).getAnimal()->getId() == 11 && set.at(i).getClient()->getDatabaseId() == 13 ){
            set.at(i).setOverallScore(83);
        }else if(set.at(i).getAnimal()->getId() == 12 && set.at(i).getClient()->getDatabaseId() == 11 ){
            set.at(i).setOverallScore(92);
        }else if(set.at(i).getAnimal()->getId() == 12 && set.at(i).getClient()->getDatabaseId() == 12 ){
            set.at(i).setOverallScore(86);
        }else if(set.at(i).getAnimal()->getId() == 12 && set.at(i).getClient()->getDatabaseId() == 13 ){
            set.at(i).setOverallScore(76);
        }
    }
}

void ACM::sortSet(vector<Match> inSet, vector<Match> &outSet){//not working correctly as of right now, I will fix this
    outSet.clear();
    bool flag = true;
    for(int i = 0; i < (int)(inSet.size()); i++){
        if(i == 0){
            outSet.push_back(inSet.at(i));
        }else{
            flag = true;
            qDebug() << i;
            for(int j = 0; j < (int)(outSet.size()); j++){
                qDebug() << "here";
                if(inSet.at(i).getOverallScore() > outSet.at(j).getOverallScore()){
                    qDebug() << "here2";
                    outSet.insert(outSet.begin()+j, inSet.at(i));
                    break;
                    qDebug() << "here3";
                    flag = false;
                }
            }
            if(flag){
                outSet.push_back(inSet.at(i));
            }
        }
    }
}

void ACM::cutOff(vector<Match> &set){
    sortedSet.clear();
    for(int i = 0; i < (int)(set.size());i++){
        //qDebug() << set.at(i).getOverallScore();
        if(set.at(i).getOverallScore() > 70){
            sortedSet.push_back(set.at(i));
        }
    }
}

void ACM::optimalSet(vector<Match> &set){
    int k = 0;
    int dIndex = 0;
    vector<Match> assocVec, dVec;
    scoringThreshold = 75;
    for(int i = 0; i < (int)(set.size()); i++){
        if(set.at(i).getOverallScore() >= scoringThreshold){
            if(i == 0){
                finalSet.push_back(set.at(i));
            }else if(checkFinal(set.at(i), finalSet)){
                finalSet.push_back(set.at(i));
            }else {
                checkNumFinal(set.at(i), finalSet, assocVec);
                //if(assocVec.size() == 1){
                    if(compareAssociations(set.at(i), assocVec.at(0), set)){
                        findById(assocVec.at(0).getId(), finalSet, k);
                        checkDiscarded(assocVec.at(0), discarded, finalSet, dVec);
                        discarded.push_back(finalSet.at(k));
                        finalSet.at(k) = set.at(i);
                        for(int p = 0; p<(int)(dVec.size()); p++){
                            if(checkFinal(dVec.at(p),finalSet)){
                                finalSet.push_back(dVec.at(p));
                            }
                        }

                    //}
                }else{
                    discarded.push_back(set.at(i));
                    dIndex++;
                }
                assocVec.clear();
            }
        }
    }
}

bool ACM::checkAssociation(Match m1, Match m2){//returns true if the two matches in question dont share their animals or clients
    if(m1.getAnimal()->getId() != m2.getAnimal()->getId() && m1.getClient()->getDatabaseId() != m2.getClient()->getDatabaseId() ){
        return true;
    }else{
        return false;
    }
}

bool ACM::checkFinal(Match m, vector<Match> vec){//returns true if the match in question doesnt share an animal or client with any of the already locked in matches
    for(int i = 0; i < (int)(vec.size()); i++){
        if(checkAssociation(m, vec.at(i)) == false && m.getId() != vec.at(i).getId()){
            return false;
        }
    }
    return true;
}

void ACM::checkNumFinal(Match m, vector<Match> vec, vector<Match> &outVec){//returns all associations the match in question shares with any of the other matches in the vector in question
    for(int i = 0; i < (int)(vec.size()); i++){
        if(checkAssociation(m, vec.at(i)) == false && m.getId() != vec.at(i).getId()){
            outVec.push_back(vec.at(i));
        }
    }
}

bool ACM::compareAssociations(Match m1, Match m2, vector<Match> all){//returns true if m1 has less associations, returns false if m2 has less associations
    vector<Match> v1, v2;
    checkNumFinal(m1, all, v1);
    checkNumFinal(m2, all, v2);
    if( v1.size() <= v2.size()){
        return true;
    }else{
        return false;
    }
}

void ACM::findById(int id, vector<Match> vec, int &index){
    for(int i = 0; i < (int)(vec.size()); i++){
        if(id == vec.at(i).getId()){
            index = i;
        }
    }
}

void ACM::checkDiscarded(Match m, vector<Match> vec, vector<Match> lockedInVec, vector<Match>& final){
    vector<Match> temp, temp2;
    checkNumFinal(m, vec, temp);
    for(int i = 0; i <(int)(temp.size());i++){
        checkNumFinal(temp.at(i), lockedInVec, temp2);
        if((int)(temp2.size()) == 1){
            final.push_back(temp.at(i));
        }
    }
}

//Function to print out solutions
void ACM::PrintVector(const V2D &v, int sum) {

    vector< vector<int> >::iterator row;
    vector<int>::iterator col;

    for(auto & vec: v) {
        for(auto & i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl << "Sum of above set = " << sum << endl;
}

/* Function is called when checking if Roosolutionk can be
placed in our 2D vector matrix.  Left side of matrix
is checked by seeing if col Rooks already exist between
columns 0 <-> (col-1). */

bool ACM::NonAttacking(V2D &binary, V2D &solution, int row, int col) {
    /* Pass over restricted cells in our matrix,
    otherwise check if Rook has already been placed in
    row. */
    if(binary[row][col] == 0) {
        return false;
    }else {
        for (int i = 0; i < col; i++)
            if (solution[row][i])
                return false;
    }

    return true;
}

//Function saves the current most optimal solution
void ACM::CheckOptimal(V2D &optimal, V2D &currentSolution, int sum) {
    cout << "Current highest sum: " << highestSum << " New Sum: " << sum << endl;
    if(sum > highestSum) {
        highestSum = sum;
        for(unsigned i=0; i < currentSolution.size(); i++) {
            for(unsigned j=0; j < currentSolution[i].size(); j++) {
                optimal[i][j] = currentSolution[i][j];
            }
        }
    }
}

//Recursive Function solving the N Rooks problem
bool ACM::RecursiveNRooks(V2D &binary, V2D &solution, V2D &weights, V2D &optimal, int sum, int col, chrono::time_point<chrono::high_resolution_clock> before) {
    using ms = chrono::milliseconds;
    using clock = chrono::system_clock;

    auto duration = chrono::duration_cast<ms>(clock::now() - before);

    if(duration.count()/1000.0 > 45) {
        return false;
    }
    if(col == (int)binary.size()) {
        CheckOptimal(optimal, solution, sum);
        PrintVector(solution, sum);
        sum = 0;
        return true;
    }

    //If all Rooks have been placed then print solution

    //Place Rook in specific column in all rows
    bool reset = false;


    //Move through rows
    for (int i = 0; i < (int)solution.size(); i++) {
        /* Check index of binary matrix to see if it's
        safe to write to our solution matrix */
        if (NonAttacking(binary, solution, i, col) ) {
            solution[i][col] = 1;

            //True if placement is possible
            reset = RecursiveNRooks(binary, solution, weights, optimal, (sum += weights[i][col]), (col + 1), before) || reset;

            //If Rook cannot be placed in cell, remove and backtrack
            solution[i][col] = 0;
            sum -= weights[i][col];
        }
    }


    //If Rook cannot be placed in any row for specific column return false
    return reset;
}

//Function to convert matrix into an NxN board
void ACM::DestroyColumns(V2D &v, V2D &target, V1D &clients, V1D &animals) {

    V1D sums(v[0].size());

    for(unsigned i = 0; i < v[0].size(); i++) {
        int currentSum = 0;
        for(unsigned j = 0; j < v.size(); j++) {
            if(target[j][i] == 1)
                currentSum += v[j][i];
        }
        sums[i] = currentSum;
        currentSum = 0;
    }

    int toDestroy = ((int)v[0].size() - (int)v.size());

    int iterator = 0;
    std::vector<int> indices;

    std::generate_n(std::back_inserter(indices), sums.size(), [&iterator]() {return iterator++;});
    std::partial_sort(indices.begin(), indices.begin() + toDestroy, indices.end(), [&sums](int ind1, int ind2) { return sums[ind1] < sums[ind2];});
    indices.erase(indices.begin() + toDestroy, indices.end());

    sort(begin(indices), end(indices));

    for(int i = 0; i < toDestroy; i++) {
        for(int j = 0; j < (int)v.size(); j++) {
            v[j].erase(v[j].begin() + (indices[i] - i));
            target[j].erase(target[j].begin() + (indices[i] - i));
        }

        animals.erase(animals.begin() + (indices[i] - i));
    }

}

//Shrink Matrix is called when the algorithm hangs too long
//Making it an NxN => (N - 1)x(N - 1)
void ACM::ShrinkMatrix(V2D &matrix, V2D &solutions, V2D &weights, V2D &optimalSet, V1D &clients, V1D &animals) {
    cout << "SHRINKING MATRIX" << endl;
    int current_lowest_row_sum = 50000;
    int current_lowest_col_sum = 50000;
    int row_sum;
    int col_sum;
    int lowest_col = 0;
    int lowest_row = 0;
    bool check_row = false;
    bool check_col = false;

    for(int i = 0; i < (int)weights.size(); i++){
        row_sum = 0;
        check_row = false;
        for(int j = 0; j < (int)weights[i].size(); j++) {
            if(matrix[i][j] == 1) {
                row_sum += weights[i][j];
                check_row = true;
            }
        }


        if(current_lowest_row_sum > row_sum || check_row == false) {
            current_lowest_row_sum = row_sum;
            lowest_row = i;
        }
    }

    cout << "LOWEST ROW: " << lowest_row << " SUM: " << current_lowest_row_sum << endl;
    cout << "REMOVING ROW: " << lowest_row << endl;
    clients.erase(clients.begin() + lowest_row);
    matrix.erase(matrix.begin() + lowest_row);
    solutions.erase(solutions.begin() + lowest_row);
    weights.erase(weights.begin() + lowest_row);
    optimalSet.erase(optimalSet.begin() + lowest_row);

    for(int i = 0; i < (int)weights[0].size(); i++) {
        col_sum = 0;
        check_col = false;

        for(int j = 0; j < (int)weights.size(); j++) {
            if(matrix[j][i] == 1) {
                col_sum += weights[j][i];
                check_col = true;
            }
        }

        if(current_lowest_col_sum < col_sum || check_col == false) {
            current_lowest_col_sum = col_sum;
            lowest_col = i;
        }
    }

    cout << "LOWEST COLUMN: " << lowest_col << " SUM: " << current_lowest_row_sum << endl;
    cout << "REMOVING COLUMN: " << lowest_col << endl;

    for(int i = 0; i < (int)weights.size(); i++) {
        matrix[i].erase(matrix[i].begin() + lowest_col);
        solutions[i].erase(solutions[i].begin() + lowest_col);
        weights[i].erase(weights[i].begin() + lowest_col);
        optimalSet[i].erase(optimalSet[i].begin() + lowest_col);
    }

    animals.erase(animals.begin() + lowest_col);

    for(int i = 0; i < (int)optimalSet.size(); i++)
        for(int j = 0; j < (int)optimalSet[i].size(); j++)
            optimalSet[i][j] = 0;

    highestSum = 0;
}

//Function removes rows that fall below the threshold across all animals
void ACM::DestroyRows(V2D &v, V2D &target, V1D &clients, V1D &animals) {
    bool allowedCounter = false;

    for(unsigned i=0; i < target.size(); i++) {
        allowedCounter = false;

        for(unsigned j=0; j < target[i].size(); j++) {
            if(target[i][j] == 1) {
                allowedCounter = true;
            }
        }

        if(allowedCounter == false) {
            cout << "Destroy Row: " << i << endl;
            target.erase(target.begin() + i);
            v.erase(v.begin() + i);
            clients.erase(clients.begin() + i);
            i = 0;
        }
    }


    DestroyColumns(v, target, clients, animals);

}

/*Function Fills our binary matrix dependent on the values
of our weighted matches.  Spots in the matrix that are
allotted 1s are allowable cells for a rook to be placed.
When the algorithm is running 0s will be seen as
restricted placements */
void ACM::CreateMatrix(V2D &v, V2D &target, V1D &clients, V1D &animals) {
    for(unsigned i=0; i < v.size(); i++) {
        for(unsigned j=0; j < v[i].size(); j++) {
            if(v[i][j] < 87) {
                target[i][j] = 0;
            }else {
                target[i][j] = 1;
            }
        }
    }

    DestroyRows(v, target, clients, animals);
}

/* This function is our main function in solving
our N Rooks problem aided with backtracking.  If
Rooks are unable to be placed, then it will return
false.  Otherwise returns true and prints the solutions */
void ACM::NRooks(V2D& matches, V1D& clients, V1D& animals, V2D& binary)
{
    cout << "Starting N Rooks" << endl;
    using ms = chrono::milliseconds;
    using clock = chrono::system_clock;

    int N;
    int sum = 0;
    V2D weights(matches.size(), V1D(matches[0].size()));

    for(unsigned i = 0; i < matches.size(); i++)
        for(unsigned j = 0; j < matches[0].size(); j++)
            weights[i][j] = matches[i][j];

    //Populate all current clienst (need to track which are removed)
    for(unsigned i = 0; i < matches.size(); i++)
        clients.push_back(i);

    //Populate all current animals (need to track which are removed)
    for(unsigned i = 0; i < matches[0].size(); i++)
        animals.push_back(i);

    V2D matrix(matches.size(), V1D(matches[0].size()));     //2D Vector that represents our matches as a binary matrix

    CreateMatrix(weights, matrix, clients, animals);

    V2D solutions(matrix.size(), V1D(matrix[0].size()));  //2D Vector that will have solutions write to it
    V2D optimalSet(matrix.size(), V1D(matrix[0].size())); //Matrix that will change based on sums of the sets

    N = (int)matrix[0].size();
    cout << "---------Solutions--------" << endl;

    while(N > 0) {
        auto before = clock::now();

        if(RecursiveNRooks(matrix, solutions, weights, optimalSet, sum, 0, before) == false) {
            cout << "Shrinking Matrix" << endl;
            ShrinkMatrix(matrix, solutions, weights, optimalSet, clients, animals);
            N = (int)matrix[0].size();
        }else {
            cout << "------HERE------" << endl;
            auto duration = chrono::duration_cast<ms>(clock::now() - before);

            if(duration.count() / 1000.0 > 25) {
                cout << "Shrinking Matrix" << endl;
                ShrinkMatrix(matrix, solutions, weights, optimalSet, clients, animals);
                N = (int)matrix[0].size();
            }else {
                N = 0;
            }
        }
    }

    cout << "-----Final Grade Weights-----" << endl;
    PrintVector(weights, 0);
    cout << "-----Final Binary Matrix-----" << endl;
    PrintVector(matrix, 0);
    cout << "------Most Optimal Set------" << endl;
    PrintVector(optimalSet, highestSum);

    cout << "TOTAL PAIRS MADE: " << optimalSet.size() << endl;

    matches = weights;
    binary = optimalSet;

    return;
}







