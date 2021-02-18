

#include "Foundation.h"

string Foundation::toString() {
    return (topCard.getDegree() == 0) ? "___": topCard.toString();
}

bool Foundation::acceptCard(Card card) {
    if (isAccepting(card)){
        topCard = Card(card.getValue());
        return true;
    }
    return false;
}

//todo returning an empty card will be resulted with return false command in GameBoard
Card Foundation::removeCard() {
    if(topCard.getDegree() < 1){
        return Card();
    }

    Card willRemove = topCard;
    //to remove the card we only need to decrease the value by one
    int tempDeg = topCard.getDegree() - 1;
    string tempVal = topCard.getValue();

    if(tempDeg == 0 ){
        topCard = Card("000");
        return willRemove;
    }

    //we will overwrite the value
    tempVal.replace(2,1, to_string(tempDeg % 10));
    tempVal.replace(1,1, to_string(((int) tempDeg / 10)));
    topCard = Card(tempVal);
    return willRemove;
}

bool Foundation::isAccepting(Card card) {
    //has to be open
    if(!card.getState()){ return false;}
    //has to have the same suit
    if(card.getSuit() != foundSuit){return false;}
    //degree has to be larger by one
    if((topCard.getDegree() + 1) != card.getDegree()){return false;}

    return true;
}
