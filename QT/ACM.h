#ifndef ACM_H
#define ACM_H
#include "Match.h"
#include "Array.h"
#include "ClientArray.h"
#include <vector>
#include <QtDebug>
#include <chrono>

typedef std::vector<int> V1D;
typedef std::vector<V1D> V2D;

class ACM{

public:
    ACM();
    ~ACM();
    void compute(Array, ClientArray, vector<Match>&);

private:
    void initSet(vector<Match>&, Array, ClientArray);
    bool dealBreakers(vector<Match>&, int, int*);
    void scoring(vector<Match>&, V2D&);
    void testVals(vector<Match>&);
    void sortSet(vector<Match>, vector<Match>&);
    void cutOff(vector<Match>&);
    void optimalSet(vector<Match>&);
    bool checkAssociation(Match, Match);
    bool checkFinal(Match, vector<Match>);
    void checkNumFinal(Match, vector<Match>,vector<Match>&);
    bool compareAssociations(Match, Match, vector<Match>);
    void findById(int, vector<Match>, int&);
    void checkDiscarded(Match, vector<Match>, vector<Match>, vector<Match>&);
    float aggressionRule(vector<Match>&, int, int*);
    float hyperactivityRule(vector<Match>&, int, int*);
    float sleepRule(vector<Match>&, int, int*);
    float noiseRule(vector<Match>&, int, int*);
    float foodRule(vector<Match>&, int, int*);
    float attentionRule(vector<Match>&, int, int*);
    float houseRule(vector<Match>&, int, int*);
    float equipmentRule(vector<Match>&, int, int*);
    float stimuliRule(vector<Match>&, int, int*);
    float ageRule(vector<Match>&, int, int*);
    float genderRule(vector<Match>&, int, int*);
    void NRooks(V2D&, V1D&, V1D&, V2D&);
    void PrintVector(const V2D&, int);
    void CreateMatrix(V2D&, V2D&, V1D&, V1D&);
    void DestroyRows(V2D&, V2D&, V1D&, V1D&);
    void DestroyColumns(V2D&, V2D&, V1D&, V1D&);
    bool RecursiveNRooks(V2D&, V2D&, V2D&, V2D&, int, int, chrono::time_point<chrono::high_resolution_clock>);
    void CheckOptimal(V2D&, V2D&, int);
    bool NonAttacking(V2D&, V2D&, int, int);
    void ShrinkMatrix(V2D&, V2D&, V2D&, V2D&, V1D&, V1D&);


    float scoringThreshold;
    vector<Match> finalSet;
    vector<Match> discarded;
    vector<Match> sortedSet;

    V2D matches;
};

#endif // ACM_H
