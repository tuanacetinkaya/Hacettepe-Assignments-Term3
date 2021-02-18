

#ifndef ASSIGNMENT2_LIBRARYSYSTEM_H
#define ASSIGNMENT2_LIBRARYSYSTEM_H
#include <string>
#include <iostream>
#include <sstream>
#include "LibraryPC.h"

using namespace std;

class LibrarySystem {
public:
    //constructors
    LibrarySystem() = default;
    LibrarySystem(string commandFile, string outputFile){
        inName = commandFile;
        outName = outputFile;
        outFile.open(outName, fstream::app );
        outFile << "===Movie Library System===\n";


        outFileRef = &outFile;
        commands.open(commandFile);
        pc = new LibraryPC(outFile);
    }
    ~LibrarySystem(){
        outFile.close();
        commands.close();
        delete pc;
    }
    void runPC();
    void addMovie(const int movieId, const string movieTitle, const int year);
    void deleteMovie(const int movieId);
    void addUser(const int userId, const string userName);
    void deleteUser(const int userId) ;
    void checkoutMovie(int movieId, int userId);
    void returnMovie(const int movieId);
    void showAllMovies();
    void showMovie(const int movieId);
    void showUser(const int userId);

private:
    string outName;
    string inName;
    string last;
    ifstream commands;
    ofstream outFile;
    ofstream *outFileRef;
    LibraryPC* pc;
    string fetchCommand();



};


#endif //ASSIGNMENT2_LIBRARYSYSTEM_H
