
#ifndef ASSIGNMENT1_FOUNDATION_H
#define ASSIGNMENT1_FOUNDATION_H

#include "Card.h"

class Foundation {
public:
    //constructors
    Foundation()= default;
    explicit Foundation(Card::Suit suit){ foundSuit = suit;}
    //methods
    string toString();
    bool acceptCard(Card card);
    Card removeCard();

    //helper
    bool isAccepting(Card card);

    Card getTopCard(){
        return topCard;
    }
private:
    //attributes
    Card::Suit foundSuit;
    Card topCard = Card("000");
};


#endif //ASSIGNMENT1_FOUNDATION_H
