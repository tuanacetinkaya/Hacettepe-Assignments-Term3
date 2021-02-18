//$remains and all other counters inside classes will be in
// index form to simplify the operations

#include "Stock.h"

Stock::Stock() = default;

Stock::Stock(array<Card, 24> stockCards) {
    setCards(stockCards, 23);
}

string Stock::toString() {
    if (remains >= 0) {
        return "@@@";
    }
    return "___";
}

void Stock::setCards(array<Card, 24 > cardList, int remainSize) {
    remains = remainSize;
    for (int i = 0; i < remainSize + 1; i++) {
        cards[i] = cardList[i];
    }
}

void Stock::addCard(Card newCard) {
    remains++;
    cards[remains] = newCard;
}

array<Card, 3> Stock::openStock() {
    array<Card, 3> package{};
    if (remains >= 2) {
        package = {cards[remains], cards[remains - 1], cards[remains - 2]};
        removeCard(3);
    } else if (remains == 1) {
        package = {cards[remains], cards[remains - 1], Card("   ")};
        removeCard(2);

    } else if (remains == 0) {
        package = {cards[remains], Card(), Card()};
        removeCard(1);
    }
    return package;
}

void Stock::removeCard(int num) {

    for (int i = 0; i < num; i++) {
        cards[remains] = Card();
        remains--;
    }
}

//todo check if it's working
void Stock::recycleCards(array<Card, 24> remaining, int index) {
    //that sets the cards from end to bottom to keep the initial order
    for(int i = 0; i <= index; i++){
        addCard(remaining[index - i]);
//        cout << cards[i].getValue();
    }
}
