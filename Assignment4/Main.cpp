#include <iostream>

#include "EvilCorp.h"


using namespace std;

int main(int argc, char *argv[]) {

    //Meet our hacker Eliot
    /*Eliot is a talented man so we have some options for calling him
     *      -i [input.txt] calls eliot in either -encode or -decode mode
     *      -s [char] calls eliot in char encoding mode that will print the encoding from the previous -i [input.txt] -encode operation
     *      -l is a way to kindly ask eliot to print the binary tree for the last encoding operation
     * */
    EvilCorp eliot;
    if (string(argv[1]) == "-i") {
        eliot.hack(argv[2], argv[3]);
    } else if (string(argv[1]) == "-s") {
        eliot.hack(argv[2][0]);
    } else if (string(argv[1]) == "-l") {
        eliot.hack();
    } else {
        cout << "ERROR CAUGHT: \n "
             << "Please Enter A Valid Command Mode When Running the Program. All Commands are listed below:\n"
             << "\t-i usage:\n"
             << "\t|\t -i <input_file_name.txt> -encode  --> to encode the file you specified\n"
             << "\t|\t -i <input_file_name.txt> -decode  --> to decode the file tou specified\n"
             << "\t-s usage:\n"
             << "\t|\t -s <character>  --> to get the binary encoding for a specific character \n"
                "\t|\t\t\tfrom your latest encode operation\n"
             << "\t|\t\t WARNING: Only the first character you entered is valid, \n"
                "\t|\t\t\tin case of multi character input rest of the string will be ignored!\n"
             << "\t-l usage:\n"
             << "\t|\t-l  --> to print the tree from your latest encode operation\n"
             << "WARNING: PLEASE ENTER ONE BLOCK OF COMMAND AT A TIME.\n"
             << "MULTI COMMANDS WILL BE IGNORED AFTER EXECUTING THE FIRST ONE\n";
    }
    return 0;
}
