
#ifndef ASSIGNMENT2_LIBRARYPC_H
#define ASSIGNMENT2_LIBRARYPC_H

#include <string>
#include <fstream>
#include <iostream>

#include "LinkedListCustomers.h"

using namespace std;

class LibraryPC {
public:
    LibraryPC(ofstream & output):output(output){}

    bool addMovie(const int movieId, const string movieTitle, const int year);
    bool deleteMovie(const int movieId);
    bool addUser(const int userId, const string userName);
    bool deleteUser(const int userId) ;
    bool checkoutMovie(int movieId, int userId);
    bool returnMovie(const int movieId);
    bool showAllMovie();
    bool showMovie(const int movieId);
    bool showUser(const int userId);

    //getters and setters
    LinkedListCustomers* getCustomerList(){ return &customerList;}
    LinkedListMovie* getUncheckedMovies(){ return &uncheckedMovies;}


private:
    LinkedListCustomers customerList;
    LinkedListMovie uncheckedMovies;
    ofstream & output;

};


#endif //ASSIGNMENT2_LIBRARYPC_H
