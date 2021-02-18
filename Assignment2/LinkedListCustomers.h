
#ifndef ASSIGNMENT2_LINKEDLISTCUSTOMERS_H
#define ASSIGNMENT2_LINKEDLISTCUSTOMERS_H

#include <string>
#include "LinkedListMovie.h"
#include "UserNode.h"

using namespace std;

class LinkedListCustomers {
public:
    LinkedListCustomers() = default;
    //string toString(); //no need

    UserNode* findUser(int userId);

    bool addUser(UserNode* user);
    bool addUser(int userId, string name);

    bool deleteUser(int userId);
    bool isEmpty(){
        return headUser == nullptr;
    }

    //helpers for movie management
    bool checkOutMovie(MovieNode* movie, int userId);
    MovieNode* returnMovie(int movieId);
    MovieNode* findMovie(int movieId);
    string showMovies();


    //getters and setters
    UserNode* getHead(){ return headUser;}
    void setHead(UserNode* newHead){headUser = newHead;}

private:
    UserNode* headUser = nullptr;

};


#endif //ASSIGNMENT2_LINKEDLISTCUSTOMERS_H
