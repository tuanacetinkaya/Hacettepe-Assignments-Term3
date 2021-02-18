#ifndef ASSIGNMENT1_FOUNDATIONAREA_H
#define ASSIGNMENT1_FOUNDATIONAREA_H
#include <string>
#include <array>
#include "Card.h"
#include "Foundation.h"

using namespace std;

class FoundationArea {
public:
    FoundationArea() {
        foundations[0] = Foundation(Card::Suit::Heart);
        foundations[1] = Foundation(Card::Suit::Diamond);
        foundations[2] = Foundation(Card::Suit::Spade);
        foundations[3] = Foundation(Card::Suit::Club);
    };
    string toString();
    bool moveToFoundation(Card card);
    Card moveFoundation(int srcFoundation);
    bool isWin();
    bool isAccepting(Card card);

private:
    array<Foundation, 4> foundations;
};


#endif //ASSIGNMENT1_FOUNDATIONAREA_H
