#ifndef ACM_H
#define ACM_H
#include "Match.h"
#include "Array.h"
#include "ClientArray.h"
#include <vector>
#include <QtDebug>

class ACM{

public:
    ACM();
    ~ACM();
    void compute(Array, ClientArray, vector<Match>&);

private:
    void initSet(vector<Match>&, Array, ClientArray);
    void dealBreakers(vector<Match>&);
    void scoring(vector<Match>&);
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


    float scoringThreshold;
    vector<Match> finalSet;
    vector<Match> discarded;
    vector<Match> sortedSet;
};

#endif // ACM_H
