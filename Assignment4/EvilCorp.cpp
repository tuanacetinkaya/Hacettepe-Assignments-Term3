
#include "EvilCorp.h"

void EvilCorp::hack(string fileName, string mode) {
    if(mode == "-encode"){
        HuffmanEncoder tyrellWellick(fileName);
        tyrellWellick.encodeFile();

    }else if(mode == "-decode"){
        HuffmanHacker darlene(fileName);
        darlene.decodeFile();

    }else{
        cout << "Please Enter A Valid Command Mode with -i\n"
                << "\tYou can use this command formatted as below:\n"
                << "\t\t -i <input_file_name.txt> -encode  --> to encode the file you specified\n"
                << "\t\t -i <input_file_name.txt> -decode  --> to decode the file tou specified\n";
    }
}

void EvilCorp::hack(char character) {
    HuffmanHacker mrRobot;
    cout << mrRobot.getEncodingFor(character);
}

void EvilCorp::hack() {
    HuffmanHacker leslieRomero;
    leslieRomero.printHuffmanTree();
}
