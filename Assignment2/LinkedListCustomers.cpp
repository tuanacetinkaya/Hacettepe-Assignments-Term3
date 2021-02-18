#include "LinkedListCustomers.h"

#include <utility>

bool LinkedListCustomers::addUser(UserNode *newUser) {
    if(findUser(newUser->getId())->getId()!= -1){
        //means it's already in the list
        return false;
    }else{
        if(headUser == nullptr){
            headUser = newUser;
            newUser->setNext(headUser);
            newUser->setPrev(headUser);

        }else{
            UserNode* ptr = headUser->getPrevious() ; //will be the last node
//            newUser->setNext(ptr->getNext());
//            ptr->setNext(newUser);
//            ptr->getNext()->setPrev(newUser);
//            newUser->setPrev(ptr);

//            //now the last node is new added node
            newUser->setNext(headUser);
            ptr->setNext(newUser);
            headUser->setPrev(newUser);
            newUser->setPrev(ptr);
        }
        //so it's circular
        return true;
    }
}

bool LinkedListCustomers::addUser(int userId, string name) {
    UserNode *temp = new UserNode(userId, std::move(name));
    return addUser(temp);
}

bool LinkedListCustomers::deleteUser(int userId) {
    UserNode* deleteDis = findUser(userId);
    if(deleteDis == nullptr){ return false;}//not in the list
    else{
        if(deleteDis == headUser){
            if(headUser->getNext() == headUser){
                headUser = nullptr; //now the list is empty
                return true;
            }else{
                UserNode* temp = headUser;
                //need to link the last element to the head's next
                while(temp->getNext()!= headUser){
                    temp = temp->getNext();
                }
                temp->setNext(headUser->getNext());
                headUser = headUser->getNext();
                return true;
            }
        }else{ //so it's not the first element in the list
            UserNode* temp;
            UserNode* prevNode = headUser;
            UserNode* current = headUser->getNext();
            while (current != nullptr){
                if(current->getId() == userId){
                    temp = current;
                    current = nullptr;
                }else{
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

UserNode *LinkedListCustomers::findUser(int userId) {
    UserNode* temp = new UserNode();
    UserNode* ptr = headUser;

    if(ptr == nullptr){
        return temp;
    }else{
        do{
            if(ptr->getId() == userId){
                temp = ptr;
            }
            ptr = ptr->getNext();
        }while (ptr != headUser);
        return temp;
    }}

bool LinkedListCustomers::checkOutMovie(MovieNode* movie, int userId) {
    UserNode* demanded = findUser(userId);
    if(demanded->getId() != -1){
        return demanded->checkOut(movie);
    }
    return false;
}

// if movie is not in checkedout's list we return movie with id -1 -> keep in mind
MovieNode* LinkedListCustomers::returnMovie(int movieId) {
    UserNode* curr = headUser;
    if(curr == nullptr){
        return new MovieNode();
    }
    do{
        if(curr->getCheckouts()->findMovie(movieId)->getId() != -1){
            //means that user has that movie
            return curr->returnMovie(movieId);
        }
        curr = curr->getNext();
    }while (curr != headUser);
    return new MovieNode(); //if doesn't exists returns empty movie
}

MovieNode *LinkedListCustomers::findMovie(int movieId) {
    UserNode* curr = headUser;
    if(curr == nullptr){
        return new MovieNode();
    }
    do{
        MovieNode* wanted = curr->getCheckouts()->findMovie(movieId);
        if(wanted->getId() != -1){
            //means that user has that movie
            return wanted;
        }
        curr = curr->getNext();
    }while (curr != headUser);
    return new MovieNode(); //if doesn't exists returns empty movie
}

string LinkedListCustomers::showMovies() {
    string output = "";
    UserNode* ptr = headUser;
    if(ptr == nullptr){
        return output;
    }
    do{
        output += ptr->getCheckouts()->toStringAll();
        ptr = ptr->getNext();
    }while (ptr != headUser);
    return output;
}





