
#include "TableauArea.h"

TableauArea::TableauArea() = default;

TableauArea::TableauArea(array<Card, 28> tableauCards) {
    createPiles(tableauCards);
}

bool TableauArea::movePile(int srcPile, int srcIndex, int destPile) {
    int srcCount = piles[srcPile].getCount();
    if (!indexCheck(srcIndex, srcCount)) {
        return false;
    }
    Card checkCard = piles[srcPile].getCardAt(srcIndex);
    if (piles[destPile].isAccepting(checkCard)) {

        for (int i = srcIndex; i >= 0; i--) {
            Card tempCard = piles[srcPile].getCardAt(i);
            piles[destPile].addCards(tempCard);
        }
        piles[srcPile].removeCards(srcIndex);
        return true;
    }

    return false;
}

bool TableauArea::open(int pileNum) {
    return piles[pileNum].open() and pileNum < 7 and pileNum >= 0;
}

bool TableauArea::moveToTableau(Card src, int destPile) {
    if (indexCheck(destPile, 6)) {
        if (piles[destPile].isAccepting(src)) {
            piles[destPile].addCards(src);
            return true;
        }
    }
    return false;
}

//todo turn back to see if there's anything else to do here
// check for foundation acceptance will be made by the GameBoard
Card TableauArea::moveToFoundation(int pileNum) {
    if (indexCheck(pileNum, 6)) {
        Card keep = piles[pileNum].getTopCard();
        piles[pileNum].removeLast();
        return keep;
    }
    return Card();
}

string TableauArea::toString() {
    string out = "";
    int maxCard = 0;
    for (int i = 0; i < 7; i++) {
        maxCard = max(maxCard, piles[i].getCount());
    }
    for (int i = 0; i <= maxCard; i++) {
        for (int j = 0; j < 7; j++) {
            out.append( piles[j].getIndexCard(i).toString() + "   ");
        }
        out.append("\n");
    }

    return out;
}

void TableauArea::createPiles(array<Card, 28> tableauCards) {
    int idx = 27;

    for (int j = 0; j < 7; j++) {
        for (int i = j; i < 7; i++) {
            piles[i].addCards(tableauCards[idx]);
            idx--;
        }
        piles[j].open();
    }
}

bool TableauArea::isAccepting(Card card, int pileNum) {
    if(!indexCheck(pileNum, 6)){return false;}
    return piles[pileNum].isAccepting(card);
}

Card TableauArea::getTopCard(int pileNum) {
    return piles[pileNum].getTopCard();
}
