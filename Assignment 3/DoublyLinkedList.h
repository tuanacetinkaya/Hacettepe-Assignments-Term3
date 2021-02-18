//
// Created by Tuana on 14/12/2020.
//

#ifndef ASSIGNMENT3_DOUBLYLINKEDLIST_H
#define ASSIGNMENT3_DOUBLYLINKEDLIST_H
#include <string>
#include "Package.h"

using namespace std;

class DoublyLinkedList {
public:
    DoublyLinkedList() = default;
    //string toString(); //no need

    //returns the index of the given package
    int find(string name);
    void find(int position, Package & aPackage);

//    bool add(Package newPackage);
    void add(Package newPackage);

    bool remove(string name);
    bool remove(int index);

    string getHead(){
        if(!isEmpty()){
            return head->p.name;
        }
        return "";
    }

    bool isEmpty(){
        return head == nullptr;
    }
    int size() const{
        return _size;
    }


private:
    struct Node{
        Package p;
        Node* next = nullptr;
        Node* prev = nullptr;
    };
    Node* head = nullptr;
    int _size = 0;
};


#endif //ASSIGNMENT3_DOUBLYLINKEDLIST_H
