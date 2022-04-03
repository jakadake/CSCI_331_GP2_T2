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

	int getZip();

	int getOffset();

private:

	vector<indexElement> index;
	int recCount;

};

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

int primaryIndex::search(int target, int l, int r = index.size()) {
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