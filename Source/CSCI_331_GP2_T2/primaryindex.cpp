/**
*
*
*
*/

#include "primaryindex.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

/*
* @brief
*
*
*/

void primaryIndex::add(int z, int o) {
	int i = 0;
	while (i < recCount && index[i] < z) i++;
	if (i == recCount) i--;
	index.insert(i, indexElement(z, o));
	recCount++;
}

/*
* @brief simple binary search algorithm
* @pre target value must be specified as first argument
* @post -1 return means value not in list
* @param target value, left-most index, right-most index
*/

int primaryIndex::search(int target, int l = 0, int r = index.size()) {
	if (r >= l)
		int mid = l + (r-1) / 2;
	if (index[mid].getZip() == target)
		return index[mid].getOffset();
	else if (index[mid].getZip() > target)
		search(target, mid - 1);
	else   //index[mid].getZip() < target
		search(target, mid + 1);
	return -1;

}

void primaryIndex::writeToFile( ofstream& oFile){
	
	oFile << recCount << "\n";

	for (int i = 0; i < index.size(); i++) {
		oFile << index[i].zip << "," << index[i].offset << "\n";
	}
}


void primaryIndex::readFromFile(ifstream& iFile) {
	if (!iFile.eof()) {
		iFile >> recCount;

		string temp;
		int z, o;
		char temp;

		while (!iFile.eof()) {
			temp = "";
			temp = iFile.getline();
			
			iFile >> z >> temp >> o;

			index.add(z, o);

		}
	}
}

