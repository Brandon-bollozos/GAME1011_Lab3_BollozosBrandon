#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
// we are creating a vector
template <class T>
class SimpleVector
{
private:
	T* aptr;
	int arraySize;
	void subError() const;

public:
	SimpleVector(int);
	SimpleVector(const SimpleVector&);
	~SimpleVector();
	int size() const
	{
		return arraySize;
	}
	T& operator[](int);
	void print() const;
	void pop_back();
	void push_back(int);
};

//sets size
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
	arraySize = s;
	aptr = new T[s];
	for (int i = 0; i < arraySize; i++)
	{
		aptr[i] = T(); // assuming the data type has a default contructor 
	}
}

//copy constructor
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj)
{
	arraySize = obj.arraySize;
	aptr = new T[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		aptr[i] = obj.aptr[i];
	}
}

template <class T>
SimpleVector<T>::~SimpleVector()
{
	if (arraySize > 0)
	{
		delete[] aptr;
	}
}

// error message when subscrpit is out of range 
template <class T>
void SimpleVector<T>::subError() const
{
	cout << "ERROR: OUT OF RANGE. \n";
	exit(0);
}

//orverlaod the [] operator. take in subscript then return something from array
template <class T>
T& SimpleVector<T>::operator[](int sub)
{
	if (sub < 0 || sub >= arraySize)
	{
		subError();
	}
	return aptr[sub];
}

template <class T>
void SimpleVector<T>::print() const
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << aptr[i] << " ";
	}
	cout << endl;
}

template <class T>
void SimpleVector<T>::pop_back()
{
	for (int i = 0; i < arraySize - 1; i++)
	{
		cout << aptr[i] << " ";
	}
	cout << endl;
}

template <class T>
void SimpleVector<T>::push_back(int item)
{
	for (int i = 0; i < arraySize; i++)
	{
		aptr[i] = aptr[i + 1];
	}
	aptr[arraySize - 1] = item;
}
