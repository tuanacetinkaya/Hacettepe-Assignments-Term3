//
// It's not a decoder
// It's THE DECODER
//

#ifndef ASSIGNMENT4_HUFFMANHACKER_H
#define ASSIGNMENT4_HUFFMANHACKER_H

#include<string>
#include<iostream>
#include <utility>

#include "HuffmanEncoder.h"

using namespace std;

class HuffmanHacker {
public:
    HuffmanHacker() = default;

    explicit HuffmanHacker(string fileName) {
        inputFileName = std::move(fileName);
        readEncodedMessageFromFile();

        rebuildTreeByEncodingData();

    }

   /* PRECONDITION:
    *      input file is binary encoded. And there's a encodingData_input.txt as dictionary
    * POST-CONDITION:
    *      input file is back in it's original shape. encodingData_input.txt is now empty.
    *
    *   code name: decodeFile()
    *       Mission is to decode the input file back to it's original form and flush the encoding data.
    *       Crucial to prevent cyber bad guys to steal it and use it to trick us */
    void decodeFile();

    //print the tree using the encoder's method, cheater? nah! just a decent hacker.
    void printHuffmanTree();

    string getEncodingFor(char c);

private:
    string inputFileName;
    string encodedMessage;

    // in order to hack them, we need a mole inside. That's it.
    // He'll help us rebuild it and tell us all about printing the tree
    HuffmanEncoder::HuffNode rootMole;

    //methods
    //reads the input file and saves the data to a string to decode later on
    void readEncodedMessageFromFile();

    //while reading the encodingData_inputFile.txt rebuilds the tree by saving nodes to root mole
    /* this method is responsible to report back if the given input file is not encoded properly
     *          ie. given encoding data has non-leaf coded data
     *          THAT MEANS OUR MOLE IS A TRAITOR
     *          ABORT MISSION
     * */
    void rebuildTreeByEncodingData();

    void placeToTree(string character, const string& binaryCode, HuffmanEncoder::HuffNode* parent);


};


#endif //ASSIGNMENT4_HUFFMANHACKER_H
