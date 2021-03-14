#pragma once
#include "SimpleVector.h"

template <class T>
class SortableVector : public SimpleVector<T>
{
public:
	// constructor
	SortableVector(int s) : SimpleVector<T>(s) { }
	SortableVector(SortableVector& obj) : SimpleVector<T>(obj) { }
	SortableVector(SimpleVector<T>& obj) : SimpleVector<T>(obj) { }
	void sortItem();

};

template <class T>
void SortableVector<T>::sortItem()
{
	int temp;
	bool swap;

	do 
	{
		swap = false;
			for (unsigned count = 0; count < this->size() - 1; count++)
			{
				if (this->operator[](count) > this->operator[](count + 1))
				{
					temp = this->operator[](count);
					this->operator[](count) = this->operator[](count + 1);
					this->operator[](count + 1) = temp;
					swap = true;
				}
			}
	} while (swap);
	
}