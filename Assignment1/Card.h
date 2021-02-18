
#ifndef ASSIGNMENT1_CARD_H
#define ASSIGNMENT1_CARD_H
#include <string>
#include <utility>
#include <iostream>

using namespace std;

class Card {
public:
    //Hearts and Diamonds are Red
    // Spade and Clubs are black
    //comparison: Suit % 2 will be the same colors
    enum Suit{ Heart, Spade, Diamond, Club};

    //constructors
    Card();
    explicit Card(string value);
    Card(string value, bool isOpen);
    Card(const Card &old); //copy constructor

    //getters and setters
    void setValue(string cardVal);

    string getValue(){
        return value;
    }
    bool getState() const{
        return state;
    }
    void setState(bool cardState){
        state = cardState;
    }
    int getSuit(){
        return suit;
    }

    int getDegree(){
        return degree;
    }

    //functions
    string toString();
    bool openCard();

private:
    //attributes
    bool state;
    string value;
    Suit suit;
    int degree;

};


#endif //ASSIGNMENT1_CARD_H
