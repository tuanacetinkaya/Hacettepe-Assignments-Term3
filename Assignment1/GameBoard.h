
#ifndef ASSIGNMENT1_GAMEBOARD_H
#define ASSIGNMENT1_GAMEBOARD_H

#include <array>

#include "Stock.h"
#include "TableauArea.h"
#include "Waste.h"
#include "Foundation.h"
#include "FoundationArea.h"

using namespace std;

class GameBoard {
public:
    //constructors
    GameBoard();
//    GameBoard(Stock stock, TableauArea tableauArea, string* commandList, int commandListSize);
    GameBoard(Stock stock, TableauArea tableauArea, string commandFileName, string outFile);

    //methods
    //returns true when we win the game, false otherwise
    void performCommands(string commandFileName, string outputFile);
    string toString();

private:
    Waste waste;
    FoundationArea foundationArea;
    Stock gameStock;
    TableauArea tableauArea;

    bool isWin();

    //command helpers
    void openFromStock();
    bool move(array<string,5> moveCommand);
    bool moveToFoundation(array<string,5> moveCommand);
    bool open(int pileNum);
    array<string, 5> parseString(string input);

};


#endif //ASSIGNMENT1_GAMEBOARD_H
