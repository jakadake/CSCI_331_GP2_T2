/**
* primaryindex.h
* Class containing the primary index and the byte offset of the data file
* for the corresponding primary key.     
*
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "LIBuffer.h"
#include "zip.h"
#include "delimBuffer.h"


struct indexElement {
	
	int zip;
	unsigned long int offset;
};

class primaryIndex {
public:
	primaryIndex();	

	primaryIndex(fstream& ifile, fstream& dfile) { readIndex(); }

	primaryIndex(ifstream& infile) { readCSV(infile); }

	void add(int z, int o);

	unsigned long search(int target);

	void writeToFile();

	void readIndex();

	void readCSV(ifstream&);

private:

	string printTable(vector<vector<zip>>&); // output data table

	short stateChooser(string x);	// return index of state with given 2 letter code

	short mostNorth(vector<zip>); // searches a given state to find the most northern zipcode

	short mostSouth(vector<zip>); // searches a given state to find the most southern zipcode

	short mostEast(vector<zip>); // searches a given state to find the most eastern zipcode //moost steeast

	short mostWest(vector<zip>); // searches a given state to find the most western zipcode

	string readIn(ifstream& inFile, vector<vector<zip>>& states);
	
	unsigned long binSearch(int target, int l, int r);

	void transfer(vector<vector<zip>>&, string);

	string buildHeader(string);

	vector<indexElement> index;
	int recCount;
	fstream dFile, iFile;

};