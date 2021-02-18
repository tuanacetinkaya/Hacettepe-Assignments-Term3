

#include "LibrarySystem.h"

void LibrarySystem::runPC() {


    while (!commands.eof()) {
        auto command = fetchCommand();
        istringstream parser{command};
        string commandType;
        parser >> commandType;
        bool same = commandType == last;

        //add movie commands
        if (commandType == "addMovie") {
            if (!same) {
                outFile << "\n===addMovie() method test===\n";
            }
            //get the movie informations
            int movieId = -1, movieYear;
            size_t pos = 0;
            string s, movieTitle;
            int i = 0;
            while ((pos = command.find('\t')) != string::npos) {
                s = command.substr(0, pos);
                if (i == 1) {
                    movieId = stoi(s);
                } else if (i == 2) {
                    movieTitle = s;
                }
                command.erase(0, pos + 1);
                i++;
            }
            movieYear = std::stoi(command);
            addMovie(movieId, movieTitle, movieYear);

        }else if (commandType == "deleteMovie") {
            if (!same) {
                outFile << "\n===deleteMovie() method test===\n";
            }
            int movieId;
            parser >> movieId;
            deleteMovie(movieId);
        } else if (commandType == "addUser") {
            if (!same) {
                outFile << "\n===addUser() method test===\n";
            }
            int userId;
            string userName;
            parser >> userId;
            parser.ignore(1, '\t');
            std::getline(parser, userName);
            addUser(userId, userName);
        }else if (commandType == "deleteUser") {
            if (!same) {
                outFile << "\n===deleteUser() method test===\n";
            }
            int userId;
            parser >> userId;
            deleteUser(userId);
        } else if (commandType == "checkoutMovie") {
            if (!same) {
                outFile << "\n===checkoutMovie() method test===\n";
            }
            int movieId, userId;
            parser >> movieId >> userId;
            checkoutMovie(movieId, userId);
        }else if (commandType == "showUser") {
            if (!same) {
                outFile << "\n===showUser() method test===\n";
            }
            int userId;
            parser >> userId;
            showUser(userId);
        } else if (commandType == "showMovie") {
            if (!same) {
                outFile << "\n===showMovie() method test===\n";
            }
            int movieId;
            parser >> movieId;
            showMovie(movieId);
        } else if (commandType == "showAllMovie") {
            if (!same) {
                outFile << "\n===showAllMovie() method test===\n";
                outFile << "Movie id - Movie name - Year - Status\n";
            }
            showAllMovies();
        } else if (commandType == "returnMovie") {
            if (!same) {
                outFile << "\n===returnMovie() method test===\n";
            }
            int movieId;
            parser >> movieId;
            returnMovie(movieId);
        } else {
            outFile << "Not a valid command: " + command + '\n';
            break;
        }
        last = commandType;
    }
}


string LibrarySystem::fetchCommand() {
    string command;
    if (commands.good()) {
        std::getline(commands, command);
    }
    return command;
}

void LibrarySystem::addMovie(const int movieId, const string movieTitle, const int year) {
        pc->addMovie(movieId,movieTitle, year);
}

void LibrarySystem::deleteMovie(const int movieId) {
    pc->deleteMovie(movieId);
}

void LibrarySystem::addUser(const int userId, const string userName) {
    pc->addUser(userId, userName);
}

void LibrarySystem::deleteUser(const int userId) {
    pc->deleteUser(userId);
}

void LibrarySystem::checkoutMovie(int movieId, int userId) {
    pc->checkoutMovie(movieId, userId);
}

void LibrarySystem::returnMovie(const int movieId) {
    pc->returnMovie(movieId);
}

void LibrarySystem::showAllMovies() {
    pc->showAllMovie();
}

void LibrarySystem::showMovie(const int movieId) {
    pc->showMovie(movieId);
}

void LibrarySystem::showUser(const int userId) {
    pc->showUser(userId);
}
