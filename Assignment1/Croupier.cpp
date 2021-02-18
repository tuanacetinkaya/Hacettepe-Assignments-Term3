
#include <iostream>
#include <fstream>
#include "Croupier.h"
#include "Card.h"
#include "TableauArea.h"
#include "Pile.h"
#include "Stock.h"
#include "GameBoard.h"

using namespace std;

Croupier::Croupier(string deckFile, string commandFile, string outFile) {
    deckFileName = deckFile;
    //todo delete this variable if GameBoard succeed to read the commands

    //Handle the piles first
    array<Card, 28> tableauCards;
    array<Card, 24> stockCards;

    auto dividedDeck = dealCards(deckFileName);
    tableauCards = dividedDeck.second;
    stockCards = dividedDeck.first;

    TableauArea baseArea(tableauCards);
    Stock cardStock(stockCards);

    GameBoard letTheGameBegin(cardStock, baseArea, commandFile, outFile);

}

pair<array<Card, 24>, array<Card, 28>> Croupier::dealCards(string fileName) {
    ifstream deckText;
    deckText.open(fileName);

//    Card stock[24]; //will be size 23 always
//    Card tableau[28];
    array<Card, 24> stock;
    array<Card, 28> tableau;

    string cardText;
    string temp;
    int count = 0;

    if (deckText.is_open()) {
        while (getline(deckText, cardText)) {
            //if there's an empty line below or an invalid file format we close the file and execute with the rest
            if (cardText.empty()) {
                deckText.close();
                break;
            }
            temp = cardText;
            Card newCard(temp);
            if (count < 24) {
                stock[count] = newCard;
                count++;
            } else {
                newCard.setState(false);
                //for the ones going to pile initial state will be closed
                tableau[count - 24] = newCard;
                count++;
            }
        }
        deckText.close();
    } else cout << "Unable to open file";

    //now the cards are divided correctly
    return make_pair(stock, tableau);

}
