

#include "DoublyLinkedList.h"

int DoublyLinkedList::find(string name) {
    Node *ptr = head;
    int count = -1;
    if (ptr != nullptr) {
        do {
            if (ptr->p.name == name) {
                count += 1;
                return count;
            }
            count += 1;
            ptr = ptr->next;
        } while (ptr != head);
    }
    return -1;
}

void DoublyLinkedList::find(int position, Package &aPackage) {
    if (position != -1) {
        //first element will be a truck, so we start from head.next
        Node *idx = head->next;
        bool outOfRange = false;
        for (int i = 0; i < position; i++) {
            if (idx != head) {
                //this finds the package at the given index
                idx = idx->next;
            } else {
                outOfRange = true;
                break;
            }
        }
        if (!outOfRange) {
            aPackage = idx->p;
        }
    }

}

void DoublyLinkedList::add(Package newPackage) {
//    if(find(newPackage.name) != -1){
//        //means it's already in the list
//        return false;
//    }else{
    Node *nodePackage = new Node();
    nodePackage->p = newPackage;
    if (head == nullptr) {
        head = nodePackage;
        nodePackage->next = head;
        nodePackage->prev = head;
        _size += 1;

    } else {
        Node *ptr = head->prev; //will be the last node

        nodePackage->next = head;
        ptr->next = nodePackage;
        head->prev = nodePackage;
        nodePackage->prev = ptr;
        _size += 1;
    }
    //so it's circular
    //return true;
//    }
}

bool DoublyLinkedList::remove(string name) {
    int deleteIndex = find(name);
    return remove(deleteIndex);
}

bool DoublyLinkedList::remove(int deleteIndex) {
    // this gives package index, -1 means it's the truck
    if (deleteIndex == -1) { return false; }//not in the list
    else {
        if (deleteIndex == 0) { //deleting head truck
            if (head->next == head) {
                delete head; //todo be sure this doesn't break anything
                head = nullptr; //now the list is empty
                _size = 0;
                return true;
            } else {
                Node *temp = head;
                //need to link the last element to the head's next
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next;
                head = head->next;
                _size -= 1;
                return true;
            }
        } else { //so it's not the first element in the list
            int count = 0;
            Node* temp = head;
            for(int i= 0; i < deleteIndex ; i++){
                temp = temp->next;
            }
            //we found our guy
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            _size -= 1;
            return true;


        }
    }
}




