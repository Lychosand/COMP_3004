#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>
#include <QMessageBox>

using namespace std;

#include "ACM.h"

ACM::ACM(){
}

ACM::~ACM(){
}

void ACM::compute(Array animalList, ClientArray clientList, vector<Match> &set){
    sortedSet.clear();

    time_t start = time(0);

    initSet(set, animalList, clientList);

    //dealBreakers(set); //the two functions you need to implement
    //scoring(set);

    testVals(set);//insert testing values, not necessary once you implement the scoring

    sortSet(set, sortedSet);//sorts set from highest to lowest, not working right now, maybe just do this as you get the overall scores?
    cutOff(sortedSet);// gets rid of any match with overall score < 70


    optimalSet(sortedSet);//computes optimal set, also not working perfectly just comment this out and use qDebug to test youre parts

    set.clear();
    for(int i = 0; i < (int)(sortedSet.size()); i++){
        set.push_back(sortedSet.at(i));
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
        if(set.at(i).getAnimal()->getId() == 10 && set.at(i).getClient()->getDatabaseId() == 11){
            set.at(i).setOverallScore(99.0);
        }else if(set.at(i).getAnimal()->getId() == 11 && set.at(i).getClient()->getDatabaseId() == 12){
            set.at(i).setOverallScore(97.0);
        }else if(set.at(i).getAnimal()->getId() == 10 && set.at(i).getClient()->getDatabaseId() == 13){
            set.at(i).setOverallScore(95.0);
        }else if(set.at(i).getAnimal()->getId() == 12 && set.at(i).getClient()->getDatabaseId() == 13){
            set.at(i).setOverallScore(92.0);
        }else if(set.at(i).getAnimal()->getId() == 13 && set.at(i).getClient()->getDatabaseId() == 14){
            set.at(i).setOverallScore(87.0);
        }else if(set.at(i).getAnimal()->getId() == 11 && set.at(i).getClient()->getDatabaseId() == 15){
            set.at(i).setOverallScore(84.0);
        }else if(set.at(i).getAnimal()->getId() == 14 && set.at(i).getClient()->getDatabaseId() == 16){
            set.at(i).setOverallScore(81.0);
        }else if(set.at(i).getAnimal()->getId() == 11 && set.at(i).getClient()->getDatabaseId() == 13){
            set.at(i).setOverallScore(62.0);
        }else{
            set.at(i).setOverallScore(4.0);
        }
    }
}

void ACM::sortSet(vector<Match> inSet, vector<Match> &outSet){//not working correctly as of right now, I will fix this
    /*outSet.clear();
    bool flag = true;
    for(int i = 0; i < (int)(inSet.size()); i++){
        if(i == 0){
            outSet.push_back(inSet.at(i));
        }else if(inSet.at(i).getOverallScore() > outSet.at(0).getOverallScore()){
            outSet.insert(outSet.begin() + i, inSet.at(i));
        }else{
            for(int j = 0; j < (int)(outSet.size()); j++){
                if(inSet.at(i).getOverallScore() > outSet.at(j).getOverallScore()){
                    outSet.insert(outSet.begin() + j, inSet.at(i));
                    flag = false;
                    break;
                }
            }
            if(flag){
                outSet.push_back(inSet.at(i));
            }
        }
    }*/
    outSet.clear();
    for(int i = 0; i < (int)(inSet.size()); i++){
        outSet.push_back(inSet.at(i));
    }
}

void ACM::cutOff(vector<Match> &set){
    for(int i = 0; i < (int)(set.size());i++){
        if(set.at(i).getOverallScore() < 70){
            set.erase(set.begin()+i);
        }
    }
}

void ACM::optimalSet(vector<Match> &set){
    int finalIndex = 0;
    int k = 0;
    int dIndex = 0;
    vector<Match> assocVec, dVec;
    scoringThreshold = 75;
    for(int i = 0; i < (int)(set.size()); i++){
        if(set.at(i).getOverallScore() > scoringThreshold){
            if(i == 0){
                finalSet.push_back(set.at(i));
                finalIndex++;
            }else if(checkFinal(set.at(i), finalSet)){
                finalSet.at(finalIndex) = set.at(i);
                finalIndex++;
            }else {
                checkNumFinal(set.at(i), finalSet, assocVec);
                if(assocVec.size() == 1){
                    if(compareAssociations(set.at(i), assocVec.at(0), set)){
                        findById(assocVec.at(0).getId(), finalSet, k);
                        checkDiscarded(assocVec.at(0), discarded, finalSet, dVec);
                        discarded.at(dIndex) = finalSet.at(k);
                        finalSet.at(k) = set.at(i);
                        for(int p = 0; p<(int)(dVec.size()); p++){
                            finalSet.at(finalIndex) = dVec.at(p);
                            finalIndex++;
                        }

                    }
                }else{
                    discarded.at(dIndex) = set.at(i);
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
    int j = 0;
    for(int i = 0; i < (int)(vec.size()); i++){
        if(checkAssociation(m, vec.at(i)) == false && m.getId() != vec.at(i).getId()){
            outVec.at(j) = vec.at(i);
            j++;
        }
    }
}

bool ACM::compareAssociations(Match m1, Match m2, vector<Match> all){//returns true if m1 has less associations, returns false if m2 has less associations
    vector<Match> v1, v2;
    checkNumFinal(m1, all, v1);
    checkNumFinal(m2, all, v2);
    if( v1.size() < v2.size()){
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
    int j = 0;
    checkNumFinal(m, vec, temp);
    for(int i = 0; i <(int)(temp.size());i++){
        checkNumFinal(temp.at(i), lockedInVec, temp2);
        if((int)(temp2.size()) == 1){
            final.at(j) = temp.at(i);
            j++;
        }
    }
}










