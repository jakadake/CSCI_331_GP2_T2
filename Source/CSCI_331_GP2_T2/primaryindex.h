/**
*
*
*
*/

#include <vector>


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
	primaryIndex();

	void add(int, int);

	int search(int target, int l, int r);

	int getZip() { return index.zip; }

	int getOffset() { return index.offset; }

private:

	vector<indexElement> index;
	int recCount;

};