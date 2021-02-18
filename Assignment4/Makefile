all: Main.o HuffmanHacker.o HuffmanEncoder.o EvilCorp.o
	g++ -std=c++11 *.o -o main

HuffmanHacker.o: HuffmanHacker.cpp
	g++ -c -std=c++11 HuffmanHacker.cpp

HuffmanEncoder.o: HuffmanEncoder.cpp
	g++ -c -std=c++11 HuffmanEncoder.cpp

EvilCorp.o: EvilCorp.cpp
	g++ -c -std=c++11 EvilCorp.cpp

Main.o: Main.cpp
	g++ -c -std=c++11 Main.cpp

clean:
	rm -rf *o huffman_tree.txt encoding_data.txt main