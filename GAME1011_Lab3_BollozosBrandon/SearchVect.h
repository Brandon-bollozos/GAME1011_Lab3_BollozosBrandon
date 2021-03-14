#pragma once
#include "SimpleVector.h"

template <class T> 
class SearchableVector : public SimpleVector<T>
{
public: 
	// constructor
	SearchableVector(int s) : SimpleVector<T>(s) { }
	SearchableVector(SearchableVector& obj) : SimpleVector<T>(obj) { }
	SearchableVector(SimpleVector<T>& obj) : SimpleVector<T>(obj) { }
	int findItem(T);

};

template <class T>
int SearchableVector<T>::findItem (T item)
{
	int first, last, middle , position;
	first = 0;
	last = this->size() - 1;
	position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (this->operator[](middle) == item)
		{
			found = true;
			position = middle;
		}
		else if (this->operator[](middle) > item)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}	
	}
	return position;
}