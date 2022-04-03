/**
* delimBuffer.CPP
* Member function definitions for the delimBuffer class.  
*/
#include "delimBuffer.h"
#include <iostream>
#include <string> 

// Default Constructor
delimBuffer::delimBuffer() {

	delim = ',';
	index = 0;
	buf = "";
	size = 0;
	maxsize = 1000;

}

//Specified Constructor w/ Defaults
delimBuffer::delimBuffer(char delim = ',', int maxsize = 1000) {

	index = 0;
	buf = "";
	size = 0;
}

//Read from delimBuffer
bool delimBuffer::read(ifstream& inFile){
	index = 0;
	buf = "";
	if (inFile.is_open() && !inFile.eof()) {				// execute only when the file is open and not at the end of the file
		getline(inFile,buf);								// pull everything up to the next newline
		size = stoi(buf[0]) * 10 + stoi(buf[1]);			// first two chars of string are length indicators
		return true;
	}
	else
		return false;

}

bool delimBuffer::write(ofstream& outFile) {

	outFile << buf;

}

bool delimBuffer::unpack(string& field){
	if (index != size && size != 0) { // execute only when delimBuffer is not empty

		while (index < size && buf[index] != delim) { // 
			field.push_back(buf[index++]);
		}
		if (buf[index] == delim)
			index++;
		return true;

	}
	return false;
}

bool delimBuffer::pack(string field) {
	buf = field;
}