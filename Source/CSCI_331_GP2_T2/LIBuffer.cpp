/**
* LIBuffer.CPP
* Member function definitions for the LIBuffer class.
*/
#include "LIBuffer.h"
#include "zip.h"
#include <iostream>
#include <string> 

using namespace std;
// Default Constructor
LIBuffer::LIBuffer() {

	delim = ',';
	index = 0;
	buf = "";
	size = 0;
	maxsize = 1000;

}

//Specified Constructor w/ Defaults
LIBuffer::LIBuffer(char delim = ',', int maxsize = 1000) {

	index = 0;
	buf = "";
	size = 0;
}

//Read from LIBuffer
bool LIBuffer::read(ifstream& inFile) {
	index = 0;
	buf = "";
	if (inFile.is_open() && !inFile.eof()) {				// execute only when the file is open and not at the end of the file
		getline(inFile, buf);								// pull everything up to the next newline
		size = stoi(buf[0]) * 10 + stoi(buf[1]);			// first two chars of string are length indicators
		return true;
	}
	else
		return false;

}

bool LIBuffer::write(ofstream& outFile, zip record) {
	buf.insert(0, itos(buf.size()));
	outFile << buf;

}

bool LIBuffer::unpack(string& field) {
	if (index != size && size != 0) { // execute only when LIBuffer is not empty

		while (index < size && buf[index] != delim) { // 
			field.push_back(buf[index++]);
		}
		if (buf[index] == delim)
			index++;
		return true;

	}
	return false;
}

bool LIBuffer::pack(string& field) {
	buf.append(field);
}