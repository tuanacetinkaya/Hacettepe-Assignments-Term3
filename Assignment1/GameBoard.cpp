
#include <fstream>
#include <iostream>
#include "GameBoard.h"


GameBoard::GameBoard() = default;

GameBoard::GameBoard(Stock stock, TableauArea tableau, string commandFileName, string outFileName) {
    gameStock = stock;
    tableauArea = tableau;

    performCommands(commandFileName, outFileName);
}

void GameBoard::performCommands(string commandFileName, string outFileName) {
    ifstream commandFile;
    ofstream outFile;

    commandFile.open(commandFileName);
    outFile.open(outFileName);

    string temp, cLine;

    if (commandFile.is_open()) {

        outFile << toString();
        while (getline(commandFile, cLine)) {
            if(isWin()){
                outFile << "You Win! \n\n";
                break;
            }
            temp = cLine;
            bool success = true;
            array<string, 5> parsed = parseString(temp);
            if(cLine == "exit"){
                break;
            }
            else if(parsed[1] == "from"){
                openFromStock();
            }//open from stock
            else if(parsed[0] == "open"){
                success = open(stoi(parsed[1]));
            }//open <pile_num>
            else if(parsed[0] == "move"){
                success = move(parsed);
            }//move to foundation command separates under move command
            outFile << cLine + "\n\n";
            if (!success) {
                outFile << "Invalid Move!\n\n";
            }
            outFile << "****************************************\n\n";
            outFile << toString();

        }
        outFile << "\nGame Over!\n";
        commandFile.close();
    } else cout << "Unable to open file";
}

bool GameBoard::isWin() {
    return foundationArea.isWin();
}

void GameBoard::openFromStock() {
    if (gameStock.getRemains() < 0) {
        gameStock.recycleCards(waste.getCardsBack(), waste.getTotalWaste());

    } else {
        waste.openStock(gameStock.openStock());
    }
}

bool GameBoard::move(array<string, 5> moveCommand) {
    string preCommand = moveCommand[1];
    if (preCommand == "to") { return moveToFoundation(moveCommand); }

    int pileNum = stoi(moveCommand[2]);
    if (preCommand == "pile") {
        int srcIdx, destPileNum;
        srcIdx = stoi(moveCommand[3]);
        destPileNum = stoi(moveCommand[4]);
        return tableauArea.movePile(pileNum, srcIdx, destPileNum);

    } else if (preCommand == "waste") {
        Card wasteCard = waste.getTopCard();
        if (wasteCard.getValue() == "   ") { return false; }
        if (!tableauArea.isAccepting(wasteCard, pileNum)) { return false; }
        waste.moveWaste();
        return tableauArea.moveToTableau(wasteCard, pileNum);

    } else if (preCommand == "foundation") {
        int destPile = stoi(moveCommand[3]);
        return tableauArea.moveToTableau(foundationArea.moveFoundation(pileNum), destPile);
    }
    return false;
}

bool GameBoard::moveToFoundation(array<string, 5> moveCommand) {
    if (moveCommand[3] == "pile") {
        int pileNum = stoi(moveCommand[4]);
        if (foundationArea.isAccepting(tableauArea.getTopCard(pileNum))) {
            return foundationArea.moveToFoundation(tableauArea.moveToFoundation(pileNum));
        }
    } else if (moveCommand[3] == "waste") {
        if (foundationArea.isAccepting(waste.getTopCard())) {
            return foundationArea.moveToFoundation(waste.moveWaste());
        }
    }
    return false;
}

bool GameBoard::open(int pileNum) {
    return tableauArea.open(pileNum);
}


string GameBoard::toString() {
    //empty line
    //stock waste         foundationArea
    //empty line
    //tableauArea
    //empty line
    //command
    //empty line
    //it it's invalid:"INVALID MOVE!" warning and
    // an empty line here
    //40 <*> symbol
    string boardOutput = "\n";
    boardOutput += gameStock.toString() + waste.toString() + "         " + foundationArea.toString() + "\n\n";
    boardOutput += tableauArea.toString() + "\n\n";

    return boardOutput;
}

array<string, 5> GameBoard::parseString(string input) {
    string delimiter = " ";
    array<string, 5> inText;
    string token;
    int len = 0;
    size_t pos = 0;
    //npos -> is a non position indicate
    while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        inText[len] = token;
        len++;
        input.erase(0, pos + delimiter.length());
    }
    inText[len] = input;
    return inText;
}

