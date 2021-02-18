#include <iostream>
#include "LinkedListMovie.h"
#include "LinkedListCustomers.h"
#include "LibraryPC.h"
#include "LibrarySystem.h"

//todo -> checkout movies command is not working
int main(int argc, char** argv) {

    LibrarySystem system("commands.txt", "output.txt");
    //LibrarySystem system(argv[1], argv[2]);
    system.runPC();
    return 0;
}
