#include <iostream>

#include "SimpleVector.h"
#include "SearchVect.h"
#include "SortableVector.h"
using namespace std; 

int main()
{
	const int SIZE = 5; 
	SearchableVector<int> iTable(SIZE);
	SortableVector<int> iTable2(SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		iTable[i] = (i * 2);
	}

	cout << "iTable:\n";
	iTable.print();
	int result;
	cout << "Searching for the number 6 in iTable.\n";
	result = iTable.findItem(6);
	if (result == -1)
	{
		cout << "6 not found\n";
	}
	else
	{
		cout << "Six is at: " << result << endl;
	}

	cout << endl << endl;
	cout << "Removing the end of the Vector" << endl;
	iTable.pop_back();
	cout << endl << endl;
	cout << "Adding 10 to the end" << endl;
	iTable.push_back(10);
	iTable.print();
	cout << endl << endl << endl;
	cout << "Making new vector out of order..." << endl;
	iTable2[0] = 4;
	iTable2[1] = 9;
	iTable2[2] = 1;
	iTable2[3] = 10;
	iTable2[4] = 7;
	iTable2.print();
	cout << "Ordering said vector..." << endl;
	iTable2.sortItem();
	iTable2.print();
	return 0;
}