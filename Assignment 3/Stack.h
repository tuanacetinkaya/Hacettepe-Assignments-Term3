

#ifndef ASSIGNMENT3_STACK_H
#define ASSIGNMENT3_STACK_H

/*Function templates are special functions that can operate
with generic types. This allows us to create a function
template whose functionality can be adapted to more than
one type or class without repeating the entire code for each type.*/

/*To use this function template we use the following format for the function call:

function_name <type> (parameters);

*/

template <typename T>
class Stack {
public:
    Stack() = default;
    ~Stack() = default;
    bool isEmpty() const;
    int size() const;

    //Push: Place item on top of the stack
    void push(const T& newItem);
    //Top: Take a look at the topmost item without removing it
    void getTop(T& stackTop) const;
    //Pop: Remove item from the top of the stack
    void pop();
private:
    struct ListNode {
        explicit ListNode(T newItem){
            item = newItem;
        }
        T item;
        ListNode* next = nullptr;
    };
    ListNode* _head = nullptr;
    ListNode* _tail = nullptr;
    int _size = 0;
};

template<typename T>
bool Stack<T>::isEmpty() const {
    return _head == nullptr;
}

template<typename T>
int Stack<T>::size() const {
    return _size;
}

template<typename T>
void Stack<T>::push(const T &newItem) {
    ListNode* n = new ListNode(newItem);
    if(_head == nullptr){
        //list is empty
        _head = n;
        n->next = _head;
        _tail = _head;
    }else{
        _tail->next = n;
        n->next = _head;
        _tail = n;
    }
    _size += 1;
}

template<typename T>
void Stack<T>::getTop(T &stackTop) const {
    if(_head != nullptr){
        stackTop = _tail->item;
    }
}

//pop the last one
template<typename T>
void Stack<T>::pop() {
    //only one element in the list or the list is empty stack will be flushed
    if(_size <= 1){
        //deleting the head will also delete the tail
        delete _head;
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
    }else{
        ListNode* temp = _head;
        while(temp->next != _tail){
            temp = temp->next;
        }
        //now temp keeps the node before the last one
        temp->next = _tail->next;
        delete _tail;
        _tail = temp;
        _size -= 1;
    }
}


#endif //ASSIGNMENT3_STACK_H
