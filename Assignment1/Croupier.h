
#ifndef ASSIGNMENT1_CROUPIER_H
#define ASSIGNMENT1_CROUPIER_H
#include <string>
#include "Card.h"
#include <array>

using namespace std;

class Croupier {
public:
    Croupier(string deckFile, string commandFile, string outFile);

    //split the cards between tableau area and deck
    pair<array<Card, 24>, array<Card, 28>> dealCards(string fileName);

private:
    string deckFileName;
};


#endif //ASSIGNMENT1_CROUPIER_H
