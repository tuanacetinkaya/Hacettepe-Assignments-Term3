
#ifndef ASSIGNMENT3_QUEUE_H
#define ASSIGNMENT3_QUEUE_H
/*Function templates are special functions that can operate
with generic types. This allows us to create a function
template whose functionality can be adapted to more than
one type or class without repeating the entire code for each type.*/

/*To use this function template we use the following format for the function call:

function_name <type> (parameters);
*/


template<typename T>
class Queue {
public:
    Queue() = default;
    ~Queue() = default;

    bool isEmpty() const;
    int size() const;
    //Enqueue: Items are added to the back of the queue
    void enqueue(const T& newItem);
    //Dequeue: Items are removed from the front of the queue
    void dequeue();
    //Get Front: Take a look at the first item
    void getFront(T& queueTop) const;

    string toString();
private:
    struct QueueNode {
        explicit QueueNode(T item){
            this->item = item;
            next = nullptr;
        }
        T item;
        QueueNode *next;
    };
    int _size = 0;
    QueueNode *_firstNode = nullptr;
    /* to avoid the traversal to the last node,
     an additional pointer to the last node is defined*/
    QueueNode *_lastNode = nullptr;
};

template<typename T>
//for queue we add from the last node
void Queue<T>::enqueue(const T &newItem) {
    QueueNode* newNode = new QueueNode(newItem);
//    newNode.item = newItem;
    if(_firstNode == nullptr){
        //list is empty
        _firstNode = newNode;
        newNode->next = _firstNode;
        _lastNode = _firstNode;
    }else{
        _lastNode->next = newNode;
        newNode->next = _firstNode;
        _lastNode = newNode;
    }
    _size += 1;
}

template<typename T>
//for queue we remove from the first node
void Queue<T>::dequeue() {
    if(!isEmpty()){
        QueueNode* temp = _firstNode;
        _lastNode->next = _firstNode->next;
        _firstNode = _firstNode->next;
        delete temp;
        _size -= 1;
    }
    if(_size == 0){
        //after deleting the values make sure they are set to nullptr
        _firstNode = nullptr;
        _lastNode = nullptr;
    }
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return _firstNode == nullptr;
}

template<typename T>
int Queue<T>::size() const {
    return _size;
}

template<typename T>
void Queue<T>::getFront(T &queueTop) const {
    if(_firstNode != nullptr){
        queueTop = _firstNode->item;
    }
}

#endif //ASSIGNMENT3_QUEUE_H
