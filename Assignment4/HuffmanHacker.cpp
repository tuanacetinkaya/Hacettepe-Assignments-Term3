
#include "HuffmanHacker.h"

void HuffmanHacker::readEncodedMessageFromFile() {
    ifstream inFile(inputFileName);
    stringstream sstream;
    sstream << inFile.rdbuf();
    encodedMessage = sstream.str();
    inFile.close();
}

void HuffmanHacker::rebuildTreeByEncodingData() {
    ifstream encodeFile(encodingDataFileName);
    if(encodeFile.good()){
        string line, data, ch;
        string binaryCode;
        while(getline(encodeFile, line)){
            stringstream sstream(line);
            getline(sstream, ch, DELIMITER);
            sstream >> binaryCode;
            //now place the char in the correct place
            placeToTree(ch, binaryCode, &rootMole);
        }
    }else{
        cout << "Please encode a file to decode" << endl;
    }
    encodeFile.close();
}

void HuffmanHacker::placeToTree(string character, const string& binaryCode, HuffmanEncoder::HuffNode* parent) {
    HuffmanEncoder::HuffNode* child = parent;
    char val = character[0];
    for(char bit: binaryCode){
        if(bit == '0'){
            if(child->left == nullptr){
                child->left = new HuffmanEncoder::HuffNode();
            }
            child = child->left;
        }else if(bit == '1'){
            if(child->right == nullptr){
                child->right = new HuffmanEncoder::HuffNode();
            }
            child = child->right;
        }
    }
    child->value = val;
}

void HuffmanHacker::decodeFile() {
    ofstream file(inputFileName);

    string message;
    HuffmanEncoder::HuffNode* currentNode = &rootMole;
    for(char bit: encodedMessage){
        if(bit == '0'){
            currentNode = currentNode->left;
        }else if(bit == '1'){
            currentNode = currentNode->right;
        }else{
            cout << "Warning: File format for encoded file is not in binary form!" <<endl;
            break;
        }
        if(currentNode->value != '\0'){
            message += currentNode->value;
            currentNode = &rootMole;
        }
    }
    cout << "\nDecoded Message: \n" << message <<endl;
    file << message <<endl;
    file.close();
}

void HuffmanHacker::printHuffmanTree() {
    //print to console
    string read;
    ifstream treeReader(treeFileName);
    if(treeReader.peek() == ifstream::traits_type::eof()){
        cout << "Tree is Empty!\nPlease encode a file to build the tree\n";
    }

    while(getline(treeReader, read)){
        cout << read <<endl;
    }
    treeReader.close();
}

string HuffmanHacker::getEncodingFor(char c) {
    ifstream encodeData(encodingDataFileName);
    string output, line, chr, chrBinaryCode ;

    if(!encodeData){
        return "Unable to open Encoding Data File! Make Sure You Encode the File Before Trying to Reach a Char Encoding\n";
    }

    //check if the file is empty
    encodeData.seekg(0, ios::end);
    int lengthOfFile = encodeData.tellg();
    encodeData.close();

    //reopening the file to reset the cursor
    encodeData.open(encodingDataFileName);

    //TODO NOTE: another way to tell the file is empty is below, however it did not worked for me I'll get back to this later:
    //encodeData.peek() == ifstream::traits_type::eof()

    if(lengthOfFile != 0){

        while(getline(encodeData,line)){

            stringstream stringParser(line);
            getline(stringParser, chr, DELIMITER);
            stringParser >> chrBinaryCode ;
            if(chr[0] == c){
                output = "Binary encoding for char '";
                output += c;
                output += "' is:  " + chrBinaryCode + "\n";
                encodeData.close();
                return output;
            }
        }
        // for C++20 and above -so it won't work on DEV
        // but I leave this here because I like to catch up with the versions and use their perks unlike our server
        // = format("'{}' is not a char included in the encoded file.", string(1,c));
        output = "\n'";
        output += c;
        output += "' is not a char included in the encoded file.\n";
    }else{
        output = "\nPlease encode a file to get the encoding for '" ;
        output += c;
        output += "'\n";
    }
    encodeData.close();
    return output;
}
