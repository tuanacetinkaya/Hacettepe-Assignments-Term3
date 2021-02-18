
#ifndef ASSIGNMENT1_STOCK_H
#define ASSIGNMENT1_STOCK_H

#include "Card.h"

#include <array>

class Stock {
public:
    //constructors
    Stock();
    explicit Stock(array<Card, 24> stockCards);

    string toString();
    array<Card, 3> openStock();

    //getters setters
    int getRemains(){
        return remains;
    }
    array<Card, 24> getCards() {return cards;}
    void recycleCards(array <Card, 24> remaining, int index);

private:

    //attributes
    array<Card, 24> cards{};
    int remains = 23;

    //helper methods
    void addCard(Card newCard);
    void removeCard(int num);
    void setCards(array<Card, 24> cardList, int remainSize);
};


#endif //ASSIGNMENT1_STOCK_H
