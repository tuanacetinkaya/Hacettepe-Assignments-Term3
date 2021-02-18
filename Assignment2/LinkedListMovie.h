
#ifndef ASSIGNMENT2_LINKEDLISTMOVIE_H
#define ASSIGNMENT2_LINKEDLISTMOVIE_H


#include <utility>

using namespace std;

class MovieNode{
public:
    MovieNode() = default;

    MovieNode(int id, const string& title, int year){
        movieId = id;
        movieName = title;
        movieYear = year;
    }
    //copy constructor
    MovieNode(MovieNode const &other){
        if(&other == NULL){

        }
        movieId= other.movieId;
        movieName = other.movieName;
        movieYear = other.movieYear;
        //we do not copy the next since we only want to copy one movie
    }

    //getter setter
//methods

    string toStringUser(){
        return to_string(movieId) + " " + movieName + " " + to_string(movieYear) + "\n";
    }
    string toString(){
        string currStat = " Not checked out";
        if(status){
            currStat = " Checked out by User " + to_string(ownerId);
        }
        return to_string(movieId) + " " + movieName + " " + to_string(movieYear) + currStat + "\n";
    }
    int getId() const{return movieId;}
    string getName(){return movieName;}
    int getYear() const{return movieYear;}
    bool getStatus() const{return status;}

    void setStatus(bool stat){status = stat;}

    MovieNode* getNext(){return next;}
    void setNext(MovieNode* nxt){next = nxt;}

    int getOwnerId(){return ownerId;}
    void setOwnerId(int id){ownerId = id;}

private:
    int movieId = -1;
    string movieName;
    int movieYear = -1;

    int ownerId = -1;
    bool status = false;

    MovieNode* next = nullptr;

};


class LinkedListMovie{
public:
    LinkedListMovie() = default;
    MovieNode* findMovie(int movieId);
    bool addMovie(int id, string title, int year);
    bool addMovie(MovieNode* newMovie);
    bool deleteMovie(int movieID);
    bool isEmpty();
    string toString();
    string toStringUser();
    string toStringAll();

    //getters setters
    MovieNode* getHead(){return head;}
    void setHead(MovieNode* newHead){head = newHead;}

private:
    MovieNode* head = nullptr;
};
















//
//class NodeMovie {
//public:
//    NodeMovie() = default;
//
//    explicit NodeMovie(Movie *m) {
//        movie = m;
//    }
//
//    NodeMovie(const int id, const string title, const int year) {
//        Movie init(id, title, year);
//        movie = &init;
//    }
//
//    ~NodeMovie() {}
//
//    //setters getters
//    void setMovie(Movie *m) {
//        movie = m;
//    }
//
//    Movie *getMovie() { return movie; }
//
//    void setNextNode(NodeMovie *next) {
//        nextNode = next;
//    }
//
//    NodeMovie *getNextNode() {
//        return nextNode;
//    }
//
//private:
//    Movie *movie = NULL;
//    NodeMovie *nextNode = NULL;
//};
//
//class LinkedListMovie {
//public:
//    //constructors
//    LinkedListMovie() = default;
//    ~LinkedListMovie() = default;
//
//
//    explicit LinkedListMovie(NodeMovie *headMovie) {
//        head = headMovie;
//        total = 1;
//    }
//
//    LinkedListMovie(int movieId, string title, int year) {
//        NodeMovie temp(movieId, title, year);
//        head = &temp;
//    }
//
//    //getters setters
//    NodeMovie *getHead() { return head; }
//
//    void setHead(NodeMovie *nodePtr) { head = nodePtr; }
//
//    int getTotal() const { return total; }
//
//    //methods
//    string toString();
//
//    bool add(int id, string title, int year);
//
//    bool add(NodeMovie *movie);
//    bool add(Movie *movie);
//
//    bool deleteMovie(int id);
//
//    bool isEmpty() const { return total == 0; }
//
//    NodeMovie *getMovie(int movieId);
//
//private:
//    NodeMovie *head = nullptr;
//    int total = 0;
//
//};


#endif //ASSIGNMENT2_LINKEDLISTMOVIE_H
