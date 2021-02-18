//
// The ultimate corporate to handle the commands
//

#ifndef ASSIGNMENT4_EVILCORP_H
#define ASSIGNMENT4_EVILCORP_H

#include "HuffmanHacker.h" //everything included in here

using namespace std;

class EvilCorp {
public:
    EvilCorp() = default;

    //All commands are reviewed and executed here. Business is good.
    //encode or decode operations are held here
    void hack(string fileName, string mode);

    // get the code for a character
    void hack(char character);

    //print the binary tree
    void hack();

private:
    string commandMode; //encode; decode; list; show
    string inputFileName;


};


#endif //ASSIGNMENT4_EVILCORP_H
