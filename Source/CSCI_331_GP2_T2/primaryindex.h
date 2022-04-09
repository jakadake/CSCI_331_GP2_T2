/**
*
*
*
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>


struct indexElement {
	indexElement() {
		zip = offset = -1;
	}

	indexElement(int x, int y) {
		zip = x;
		offset = y;
	}

	int zip;
	int offset;
};

class primaryIndex {
public:
	primaryIndex() { recCount = 0; }

	primaryIndex(ofstream& oFile) { readFromFile(oFile); }

	void add(int z, int o);

	int search(int target, int l, int r);

	int getZip() { return index.zip; }

	int getOffset() { return index.offset; }

	void writeToFile(ofstream& oFile);

	void readFromFile(ifstream& iFile);

private:

	vector<indexElement> index;
	int recCount;

};