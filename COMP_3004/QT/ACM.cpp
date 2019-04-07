#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include <QMessageBox>

using namespace std;

#include "ACM.h"

ACM::ACM(){
}

ACM::~ACM(){
}

bool sortFn(Match &m1, Match &m2){
    return m1.getOverallScore() > m2.getOverallScore();
}

void ACM::compute(Array animalList, ClientArray clientList, vector<Match> &set){
    sortedSet.clear();
    set.clear();
    finalSet.clear();
    time_t start = time(0);

    initSet(set, animalList, clientList);

    //dealBreakers(set); //the two functions you need to implement
    //scoring(set);

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

void ACM::dealBreakers(vector<Match> &set){
    /*Input:set of all matches
     *if a mtach breaks a dealbreaker rule do something like set.erase(set.begin()+i);
     *Output: reduced set of matches
     */
}
void ACM::scoring(vector<Match> &set){
    /*Input: reduced set of matches
     *set score for each rule of each match and total the scores par match(there is attributes for a match object to hold
     * all this info
     *Output: set of matches with score attributes set
     */
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










