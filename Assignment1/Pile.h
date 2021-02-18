
#ifndef ASSIGNMENT1_PILE_H
#define ASSIGNMENT1_PILE_H


#include "Card.h"

class Pile {
public:
    //constructors
    Pile();
    //todo no need for now, but keep in mind this constructor
    //Pile(Card cardList[], int size);

    //functions
    void removeLast();
    string toString();

    bool open();
    //opens the first card, if it's open returns false

    bool isAccepting(Card card);
    //check if the new card is appropriate for the pile

    bool removeCards(int index);
    //remove cards after some index, returns false if it's not possible

    void addCards(Card cards);
    //no need to return. TableauArea checks isAccepting before addCards so it's safe
    //string toString(); //toString method belongs to TableauArea for board to print correctly

    //getters and setters
    pair<Card*, int> getPile(); //return the cards and number of cards in pile
    Card* getCards();
    int getCount();
    Card getCardAt(int index);
    Card getIndexCard(int literalIndex){
        return cardsHere[literalIndex];
    }
    Card getTopCard(){
        if(count < 0){return Card();}
        return cardsHere[count];
    }

//    void setPile(Card*, int);
    //setting cards and count separately is DANGEROUS so setters for them does not exist here


private:
    //attributes
    Card cardsHere[20];
    int count = -1;

    //helper methods
    //to help isAccepting the first card to be add has to be controlled by these two criteria:
    //since all other cards already placed by this criteria, comparing first card with our last would be sufficient
    bool isAlternating(Card card);
    bool isCountable(Card);


};


#endif //ASSIGNMENT1_PILE_H
