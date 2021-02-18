
#ifndef ASSIGNMENT1_TABLEAUAREA_H
#define ASSIGNMENT1_TABLEAUAREA_H


#include "Card.h"
#include "Pile.h"

#include <array>

class TableauArea {
public:
    //constructors
    TableauArea();
    TableauArea(array<Card, 28> tableauCards);

    bool movePile(int srcPile, int srcIndex, int destPile);
    bool open(int pileNum);
    bool moveToTableau(Card src, int destPile);
    Card moveToFoundation(int pileNum);
    //methods
    bool isAccepting(Card card, int pileNum);
    string toString();

    //getters and setters
    Pile* getPiles(){
        return piles;
    }
    Card getTopCard(int pileNum);

private:
    Pile piles[7];
    //helpers
    void createPiles(array<Card, 28> tableauCards);
    bool indexCheck(int srcIndex, int limitIndex){
        return srcIndex <= limitIndex and srcIndex >=0;
    }

};


#endif //ASSIGNMENT1_TABLEAUAREA_H
