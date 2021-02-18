//
// Circular Singly LinkedList
//

#include <iostream>
#include "LinkedListMovie.h"

//worst solution ever, but again, i can't assign nullptr if i can't find the movie,
//so empty movie is an OK solution for this particular problem
MovieNode *LinkedListMovie::findMovie(int movieId) {
    MovieNode *temp = new MovieNode(); //empty movie
    MovieNode *ptr = head;
    //if the list is not empty
    if (ptr != nullptr) {
        do {
            if (ptr->getId() == movieId) {
                temp = ptr;
                break;
            }
            ptr = ptr->getNext();
        } while (ptr != head);
    }
    return temp;
}

bool LinkedListMovie::addMovie(int id, string title, int year) {
    MovieNode *temp = new MovieNode(id, title, year);
    return addMovie(temp);
}

bool LinkedListMovie::addMovie(MovieNode *newMovie) {
    MovieNode* tempMovie = findMovie(newMovie->getId());
    if (tempMovie->getId() != -1) {
        //means it's already in the list
        return false;
    } else {
        if (head == nullptr) {
            head = newMovie;
            newMovie->setNext(head);
        } else {
            MovieNode *ptr = head;
            while (ptr->getNext() != head) {
                ptr = ptr->getNext();
            }
            ptr->setNext(newMovie);
            newMovie->setNext(head);
        }
        //so it's circular
        return true;
    }
}

bool LinkedListMovie::deleteMovie(int movieID) {
    MovieNode *deleteDis = findMovie(movieID);
    if (deleteDis->getId() == -1 ) { return false; }//not in the list
    else {
        if (deleteDis == head) {
            if (head->getNext() == head) {
                head = nullptr; //now the list is empty
                return true;
            } else {
                MovieNode *temp = head;
                //need to link the last element to the head's next
                while (temp->getNext() != head) {
                    temp = temp->getNext();
                }
                temp->setNext(head->getNext());
                head = head->getNext();
                return true;
            }
        } else { //so it's not the first element in the list
            MovieNode *temp;
            MovieNode *prevNode = head;
            MovieNode *current = head->getNext();
            while (current != nullptr) {
                if (current->getId() == movieID) {
                    temp = current;
                    current = nullptr;
                } else {
                    prevNode = prevNode->getNext();
                    current = current->getNext();
                }
            }
            prevNode->setNext(temp->getNext());
            delete deleteDis; //todo if something breaks check this mofo
            return true;
        }
    }
}

bool LinkedListMovie::isEmpty() {
    return head == nullptr;
}

string LinkedListMovie::toString() {
    string out = "";
    if (head == nullptr) {
        return out;
    }

    MovieNode *idx = head;
    do {
        out.append(idx->toString());
        idx = idx->getNext();
    } while (idx != head);

    return out;
}

string LinkedListMovie::toStringUser() {
    string out = "Movie id - Movie name - Year\n";
    if (head == nullptr) {
        return out;
    }

    MovieNode *idx = head;
    do {
        out.append(idx->toStringUser());
        idx = idx->getNext();
    } while (idx != head);

    return out;
}

string LinkedListMovie::toStringAll() {
    string out = "";
    if (head == nullptr) {
        return out;
    }

    MovieNode *idx = head;
    do {
        out.append(idx->toString());
        idx = idx->getNext();
    } while (idx != head);

    return out;
}
