

#include "FoundationArea.h"

//Heart Diamond Spade Club
string FoundationArea::toString() {
    string fArea;
    for (int i = 0; i < 4; i++) {
        fArea += foundations[i].toString() + " ";
    }
    return fArea;
}

bool FoundationArea::moveToFoundation(Card card) {
    switch (card.getSuit()) {
        case Card::Suit::Heart:
            foundations[0].acceptCard(card);
            break;
        case Card::Suit::Diamond:
            foundations[1].acceptCard(card);
            break;
        case Card::Suit::Spade:
            foundations[2].acceptCard(card);
            break;
        case Card::Suit::Club:
            foundations[3].acceptCard(card);
            break;
    }
    return false;
}

Card FoundationArea::moveFoundation(int srcFoundation) {
    if (srcFoundation > 3 || srcFoundation < 0) { return Card(); }
    return foundations[srcFoundation].removeCard();
}

bool FoundationArea::isWin() {
    for (int i = 0; i < 4; i++) {
        if (foundations[i].getTopCard().getDegree() != 13) { return false; }
    }
    return true;
}

bool FoundationArea::isAccepting(Card card) {
    switch (card.getSuit()) {
        case Card::Suit::Heart:
            return foundations[0].isAccepting(card);
        case Card::Suit::Diamond:
            return foundations[1].isAccepting(card);
        case Card::Suit::Spade:
            return foundations[2].isAccepting(card);
        case Card::Suit::Club:
            return foundations[3].isAccepting(card);
    }
    return false;
}
