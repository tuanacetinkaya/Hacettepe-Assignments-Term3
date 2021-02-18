
#include "LibraryPC.h"

bool LibraryPC::addMovie(const int movieId, const string movieTitle, const int year) {

    if(customerList.findMovie(movieId)->getId() != -1){
        output << "Movie " << movieId << " already exists\n";
        return false;
    }
    if(uncheckedMovies.addMovie(movieId, movieTitle, year)){
        output << "Movie " << movieId << " has been added\n";
        return true;
    }
    output << "Movie " << movieId << " already exists\n";
    return false;
}

bool LibraryPC::deleteMovie(const int movieId) {
    bool isDeleted = false;
    //first check if a user has that movie
    if(customerList.returnMovie(movieId)->getId() != -1 )//means a user had it and now it's removed from that list
    {
        isDeleted = true;
        output << "Movie " << movieId << " has been checked out\n";
    }
    if(uncheckedMovies.deleteMovie(movieId)){
        isDeleted = true;
        output << "Movie " << movieId << " has not been checked out\n";
    }
    if(isDeleted){
        output << "Movie "<< movieId <<  " has been deleted\n";
        return true;
    }
    output << "Movie " << movieId << " does not exists\n";
    return false;
}

bool LibraryPC::addUser(const int userId, const string userName) {
    if(customerList.addUser(userId, userName)){
        output << "User " << userId << " has been added\n";
        return true;
    }
    output << "User " << userId << " already exists\n";
    return false;
}

bool LibraryPC::deleteUser(const int userId) {
    if(customerList.deleteUser(userId)){
        output << "User " << userId << " has been deleted\n";
        return true;
    }
    output << "User " << userId << " does not exist\n";
    return false;
}

bool LibraryPC::checkoutMovie(int movieId, int userId) {
    MovieNode* ret = uncheckedMovies.findMovie(movieId);
    MovieNode* addThis = new MovieNode(ret->getId(),ret->getName(),ret->getYear());
    UserNode* demandUser = customerList.findUser(userId);
    if(ret->getId() == -1){
        output <<  "Movie " << movieId << " does not exist for checkout\n";
        return false;
    }
    else if(demandUser->getId() == -1){
        output << "User " << userId << " does not exist for checkout\n";
        return false; //no user exists
    }
    else if(customerList.checkOutMovie(addThis, userId)){
        uncheckedMovies.deleteMovie(movieId);
        output << "Movie " << movieId << " has been checked out by User " << userId << "\n";
        return true;
    }
    output << "Movie " << movieId << " does not exist for checkout\n";
    return false;
}


bool LibraryPC::returnMovie(const int movieId) {
    if(uncheckedMovies.findMovie(movieId)->getId() != -1){
        output << "Movie " << movieId << " has not been checked out\n";
        return false;
    }

    MovieNode* movie = customerList.returnMovie(movieId);

    if(movie->getId() != -1){
        uncheckedMovies.addMovie(movie);
        output << "Movie " <<movieId << " has been returned\n";
        return true;
    }

    output << "Movie " << movieId << " not exist in the library\n";
    return false;
}

bool LibraryPC::showAllMovie() {
    string out = uncheckedMovies.toString();
    out += customerList.showMovies();
    output << out;
    return true;
}

bool LibraryPC::showMovie(const int movieId) {
    MovieNode* target = uncheckedMovies.findMovie(movieId);
    if(target->getId() == -1){
        target = customerList.findMovie(movieId);
        if(target->getId() == -1){
            output << "Movie with the id " << movieId << " does not exist\n";
            return false;
        }
    }
    output << target->toString();
    return true;
}

bool LibraryPC::showUser(const int userId) {
    UserNode* target = customerList.findUser(userId);
    if(target->getId() == -1){
        output << "User " << userId << " does not exist\n";
        return false;
    }
    output << target->toString();
    return true;
}
