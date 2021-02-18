cmake_minimum_required(VERSION 3.17)
project(Assignment1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment1 Main.cpp Croupier.cpp Croupier.h Card.cpp Card.h TableauArea.cpp TableauArea.h Pile.cpp Pile.h Stock.cpp Stock.h GameBoard.cpp GameBoard.h Waste.cpp Waste.h Foundation.cpp Foundation.h FoundationArea.cpp FoundationArea.h)
