
#include "Waste.h"

Waste::Waste() {}

string Waste::toString() {

    // -> else display the stock
    string wasteString = "";

    if (topCards == 0) {
        // if there are cards in the pile: only top card
        if (totalWaste >= 0) {
            wasteString += " " + wasted[totalWaste].toString();
            wasteString += " ___ ___";
            return wasteString;
        }
        // if there's no prev card: ___ ___ ___
        return " ___ ___ ___";
    }
    for (int i = topCards; i > 0; i--) {
        wasteString += " " + wasted[totalWaste - i + 1].toString();
    }
    for (int j = 0; j < 3 - topCards; j++) {
        wasteString += " ___";
    }
    return wasteString;
}

Card Waste::moveWaste() {
    if (totalWaste >= 0) {
        Card keep = wasted[totalWaste];
        wasted[totalWaste] = Card();
        totalWaste--;
        topCards--;
        return keep;
    }
    return Card();
}


void Waste::openStock(array<Card, 3> stockCards) {
// [D13, S03, D04]
    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (stockCards[i].getValue() == "   ") { break; }
        count++;
        totalWaste++;
        wasted[totalWaste] = stockCards[i];
    }
    topCards = count;
}

array<Card, 24> Waste::getCardsBack() {
    return wasted;
}
