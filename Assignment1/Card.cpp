#include "Card.h"

string Card::toString() {
    return (getState()) ? getValue(): "@@@" ;
}

bool Card::openCard() {
    if (!Card::getState()){
        Card::state = true;
        return true;
    }
    return false;
}

//Card x = Card y
Card::Card(const Card &old){
    value = old.value;
    state = old.state;
    degree = old.degree;
    suit = old.suit;
}

Card::Card(string value) {
    setValue(value);
    setState(true);
}

Card::Card(string value, bool isOpen) {
    setValue(value);
    setState(isOpen);
}

Card::Card() {
    setValue("   ");
    setState(true); //cards are open initially but the stack will look like they're closed just for simplicity
}

void Card::setValue(string cardVal) {
    value = cardVal;
    char suitID = cardVal.at(0);

    switch (suitID) {
        case 'D':
            suit = Suit::Diamond;
            break;
        case 'S':
            suit = Suit::Spade;
            break;
        case 'C':
            suit = Suit::Club;
            break;
        case 'H':
            suit = Suit::Heart;
            break;
    }
    if(cardVal != "   "){
        degree = stoi(cardVal.substr(1));
    }
}
