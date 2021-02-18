
#ifndef ASSIGNMENT2_USERNODE_H
#define ASSIGNMENT2_USERNODE_H

#include <string>
#include <utility>
#include "LinkedListMovie.h"

using namespace std;


class UserNode {
public:
    UserNode() {}

    UserNode(int id, string name) {
        userId = id;
        userName = std::move(name);
    }

    bool checkOut(MovieNode *newMovie) {
        if (checkedouts.addMovie(newMovie)) {
            newMovie->setStatus(true);
            newMovie->setOwnerId(userId);
            return true;
        }
        return false;
    }

    MovieNode* returnMovie(int movieId) {
        MovieNode* keep = checkedouts.findMovie(movieId);
        if(keep->getId() != -1){
            keep->setOwnerId(-1);
            keep->setStatus(false);
            checkedouts.deleteMovie(movieId);
        }
        return keep;
    }


    //getters/setters
    int getId() const { return userId; }

    string getName() { return userName; }

    UserNode *getNext() { return nextNode; }

    void setNext(UserNode *newNext) { nextNode = newNext; }

    UserNode *getPrevious() { return prevNode; }

    void setPrev(UserNode *newPrev) { prevNode = newPrev; }

    LinkedListMovie *getCheckouts() { return &checkedouts; }


//    User id: 7 User name: Emma Ashley
//    User 7 checked out the following Movies:
    string toString() {
        string out = "User id: " + to_string(userId) + " User name: " + userName + "\n";
        out += "User " + to_string(userId) + " checked out the following Movies:\n";
        if (!checkedouts.isEmpty()) {
            out += checkedouts.toStringUser();
        }
        //todo when printing user, traverse through the $checkedouts and print their result from the checkedoutMovies linkedlist
        return out;
    }


private:
    int userId = -1;
    string userName;
    LinkedListMovie checkedouts;
    UserNode *nextNode;
    UserNode *prevNode;
};


#endif //ASSIGNMENT2_USERNODE_H
