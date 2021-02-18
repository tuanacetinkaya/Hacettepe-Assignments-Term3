#include "HuffmanEncoder.h"

/* Input: a message to encode
 * Output: Updates the $root of the class as the root of the huffman tree
 * Post-condition: if the input is empty root = nullptr
 *                  if we have only one letter the letter will be given the code 0 assigned to left child of root
 *                  else the tree will be formed by a priority queue that is a hash/map order
 * */
void HuffmanEncoder::buildTree(const string& message) {
    buildFrequencies(message);

    //build the tree now

    //start by adding the known chars as nodes to a vector
    // data.first = character
    // data.second = frequency
    for (auto const& data : frequencies){
         auto addNode = new HuffNode(data.first, data.second);
        encoderVector.push_back(addNode);
    }

    // now merge the nodes until there's only one root left
    if(encoderVector.size() == 1){
        auto* rNode = new HuffNode();
        rNode->left = encoderVector[0];
        encoderVector.erase(encoderVector.begin());
        encoderVector.push_back(rNode);
    }

    while(encoderVector.size() > 1){
        //sort the array by their frequencies
        sort(encoderVector.begin(), encoderVector.end(), huffNodeComparator);
        auto* mergeRoot = new HuffNode(encoderVector[0]->freq + encoderVector[1]->freq);
        mergeRoot->left = encoderVector[0];
        mergeRoot->right = encoderVector[1];
        //remove first two elements since we have the root of them
        encoderVector.erase(encoderVector.begin(), encoderVector.begin() + 2);
        encoderVector.push_back(mergeRoot);
    }
    //now the encoder vector has only one element inside which is our root
    // we check in case we're given an empty input for sure
    if(encoderVector.size() > 0){
        root = encoderVector[0];
    }


//    print the frequencies
//    for (auto const& x : frequencies)
//    {
//        std::cout << x.first  // string (key)
//                  << ':'
//                  << x.second // string's value
//                  << std::endl;
//    }
}

void HuffmanEncoder::buildFrequencies(const string& message) {
    for(char c: message){
        frequencies[tolower(c)] += 1;
    }
}

int HuffmanEncoder::charPositionInFrequencies(char c) {
    int pos = -1;
    for(auto const& p : frequencies){
        pos ++;
        if(p.first == c){
            return pos;
        }
    }
    return -1;
}
/*recursively traverses the tree -using DFS- and saves the found
 * */
void HuffmanEncoder::buildEncodingMap(HuffNode* node, const string& path) {
    if(node == nullptr){
        return;
    }

    if(node->value != '\0'){
        encodingMap[node->value] = path;
        return;
    }
    if(node->left != nullptr){
        buildEncodingMap(node->left, path + "0");
    }
    if(node->right != nullptr){
        buildEncodingMap(node->right, path + "1");
    }
}

//post-condition: fileData is assigned to lowercase version of the input file data
void HuffmanEncoder::fileToString() {
    string line;

    ifstream ifStream;
    ifStream.open(fileName);
    //if it's a one line input avoid adding \n
    getline(ifStream, line);
    fileData += line;

    while(getline(ifStream, line)){
        fileData += "\\n";
        fileData += line;
    }
    ifStream.close();
    transform(fileData.begin(), fileData.end(), fileData.begin(),
              [](unsigned char c){return tolower(c);});

}

void HuffmanEncoder::encodeFile() {
    ofstream outFile;
    outFile.open(fileName);

    string coded;
    for(char c: fileData){
        coded += getEncodingFor(c) ;
    }
    cout << "Encoded Message: " <<endl;
    cout << coded << endl;
    outFile << coded;
    outFile.close();
}
/* WARNING:
 *    '\n' is excluded from the method since it change form while encoding and stored as '\\' and 'n'
 *      any search for '\n' will be result by "-1"
 * */
string HuffmanEncoder::getEncodingFor(char c) {
    for(auto ch: encodingMap){
        if(ch.first == c){
            return ch.second;
        }
    }
    return "-1";
}

void HuffmanEncoder::fileEncodingMap() {
    string fileToSaveMap =   encodingDataFileName;
    ofstream fileMap(fileToSaveMap);

    for(auto codes: encodingMap){
        fileMap << codes.first << DELIMITER << codes.second << "\n";
    }
    fileMap.close();
}

void HuffmanEncoder::printHuffmanTree(const std::string& prefix, const HuffNode* node, bool isLeft, ofstream& treeFile) {

    if( node != nullptr )
    {
        treeFile << prefix;

        treeFile << (isLeft ? "|---" : "|___" );

        // print the value of the node
        /* WARNING:
         *      for 'space' console prints ' '
         *      for empty tree there will be no output
        */
        if(node->value == '\0'){
            treeFile << node->freq <<endl;
        }else if(node->value == ' '){
            treeFile << "' '" <<endl;
        }else{
            treeFile << node->value << endl;
        }

        // enter the next tree level - left and right branch
        printHuffmanTree( prefix + (isLeft ? "|   " : "    "), node->left, true, treeFile);
        printHuffmanTree( prefix + (isLeft ? "|   " : "    "), node->right, false, treeFile);
    }
}

void HuffmanEncoder::printHuffmanTree(const HuffNode* node)
{
    if(node == nullptr){
        cout << "<empty tree>" <<endl;
    }else{
        //save the tree to file
        ofstream treeFileStream(treeFileName);
        printHuffmanTree("", node, false, treeFileStream);
        treeFileStream.close();

        //print to console
        string read;
        ifstream treeReader(treeFileName);
        while(getline(treeReader, read)){
            cout << read <<endl;
        }
        treeReader.close();
    }
}
