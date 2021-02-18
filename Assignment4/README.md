# Huffman Encoding and Decoding Project
This is a school assignment given by Data Structures lecture at Hacettepe.

It compresses and decompresses the given text file by implementing huffman algorithm.

When you have your non-encoded file (assuming named as input.txt) in the same directory as this project you can call the below commands to perform:

First you need to compile the program by hand
*       g++ -std=c++11 *.o -o main
or by calling makefile if working on cmd
*       make

After compiling the program below instructions can be called:
* This encodes the input file and creates the huffman tree inside a text file
*      ./main -i input.txt -encode
* This decodes the file using previously created tree file
*      ./main -i input.txt -decode
* This prints the encoding for a given char from your latest encode operation
WARNING: Only the first character you entered is valid, in case of multi character input rest of the string will be ignored!
*      ./main -s [char]
* This is to print the tree from your latest encode operation
*      ./main -l 

WARNING: PLEASE ENTER ONE BLOCK OF COMMAND AT A TIME. MULTI COMMANDS WILL BE IGNORED AFTER EXECUTING THE FIRST ONE

## Report and Details
Assignment details and report also exists in this file. Please check those when required further information or use cases.