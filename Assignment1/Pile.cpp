#include "Pile.h"

#include <utility>
//for all piles, bottom open card is at the last index that is -> cardsHere[count]
//!call of piles has to start from 7 to the left-most pile 1 to keep the deck in order

Pile::Pile() {
    //easter egg here in case I do something wrong
    //cout << "Empty Constructor Called for Pile class. BUM! All Cards are Joker's now HAHAHAHAHA"<< endl;
}

bool Pile::open() {
    //if it is closed
    if( !cardsHere[count].getState()){
        cardsHere[count].setState(true);
        return true;
    }
    //if it's already open
    return false;
}

//todo some case might be missing here, check again later
bool Pile::isAccepting(Card card) {
    if(count == -1 and card.getDegree() == 13){
        return true;
    }
    //will not accept if the card is closed
    return isAlternating(card) and isCountable(card) and card.getState();
}

//remove all cards after some index
bool Pile::removeCards(int index) {
    if(index <= count){
        for(int i = 0; i <= index; i++){
            removeLast();
        }
        return true;
    }
    return false;
}
void Pile::removeLast() {
    cardsHere[count] = Card("   ");
    count --;
}

pair<Card *, int> Pile::getPile() {
    return make_pair(cardsHere, count);
}

Card *Pile::getCards() {
    return cardsHere;
}

int Pile::getCount() {
    return count;
}

bool Pile::isAlternating(Card card) {
    //simple but effective :) check suit enum
    return cardsHere[count].getSuit() % 2 != card.getSuit() % 2;
}

bool Pile::isCountable(Card newCard) {
    return cardsHere[count].getDegree() - 1 == newCard.getDegree();
}

string Pile::toString() {
    string str;
    for(int i = 0; i<= count; i++){
        str += "-> " + cardsHere[i].toString();
    }
    return str;
}

void Pile::addCards(Card cards) {
    count ++;
    cardsHere[count] = move(cards);
}

Card Pile::getCardAt(int index) {
    //index check is being done by TableauArea so it is safe to return
    return cardsHere[count - index];
}
