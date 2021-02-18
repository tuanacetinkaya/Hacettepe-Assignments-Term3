
#ifndef ASSIGNMENT4_HUFFMANENCODER_H
#define ASSIGNMENT4_HUFFMANENCODER_H

#include<iostream>
#include <utility>
#include<vector>
#include<map>
#include <algorithm>
#include <fstream>
#include <sstream>

#define DELIMITER '-'
#define encodingDataFileName "encoding_data.txt"
#define treeFileName "huffman_tree.txt"

using namespace std;

class HuffmanEncoder {

public:
    HuffmanEncoder() = default;

    explicit HuffmanEncoder(const string &inputFileName) {
        fileName = inputFileName;
        //loads the file data to fileData string
        fileToString();

        //builds the tree with respect to given file data
        buildTree(fileData);

        //maps the built tree and records the char pats on $encodingMap
        buildEncodingMap(root, "");

        //file the paths for chars to use it later
        fileEncodingMap();

        //save the tree to file
        ofstream treeFileStream(treeFileName);
        printHuffmanTree("", root, false, treeFileStream);
        treeFileStream.close();

        //below line was just for test purposes
        //printHuffmanTree(root);
    }

    struct HuffNode {
        HuffNode() = default;

        HuffNode(char val, int fq) {
            freq = fq;
            value = val;
        }

        explicit HuffNode(int fq) {
            freq = fq;
        }

        int freq = 0;
        char value = '\0';
        HuffNode *left = nullptr;
        HuffNode *right = nullptr;
    };

    string getEncodingFor(char c);

    void printHuffmanTree(){
        printHuffmanTree(root);
    }

    static void printHuffmanTree(const HuffNode *node);

    //encode the $fileData and output the result
    void encodeFile();


private:
    //methods and structs
    static void printHuffmanTree(const std::string &prefix, const HuffNode *node, bool isLeft, ofstream& treeFile);

    static bool huffNodeComparator(HuffNode *hn1, HuffNode *hn2) {
        if (hn1 != nullptr || hn2 != nullptr) {
            return hn1->freq < hn2->freq;
        }
        return false;
    }

    void buildTree(const string &message);

    void buildFrequencies(const string &message);

    int charPositionInFrequencies(char c);

    void buildEncodingMap(HuffNode *node, const string &path);

    void fileEncodingMap();

    void fileToString();



    //Attributes
    string fileName;
    string fileData;
    HuffNode *root = nullptr;
    map<char, int> frequencies;
    vector<HuffNode *> encoderVector;
    map<char, string> encodingMap;


};


#endif //ASSIGNMENT4_HUFFMANENCODER_H
