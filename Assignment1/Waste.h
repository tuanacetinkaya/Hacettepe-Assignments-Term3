#ifndef ASSIGNMENT1_WASTE_H
#define ASSIGNMENT1_WASTE_H
#include <string>
#include <array>
#include "Card.h"

using namespace std;

class Waste {
public:
    Waste();

    //methods
    string toString();
    Card moveWaste(); //return empty card if there's no waste
    void openStock(array<Card, 3> stockCards);

    array<Card, 24> getCardsBack();
    int getTotalWaste(){return totalWaste;}
    Card getTopCard(){return wasted[totalWaste];}

private:
    int topCards = 0;
    int totalWaste = -1;
    array<Card, 24> wasted;

};


#endif //ASSIGNMENT1_WASTE_H
