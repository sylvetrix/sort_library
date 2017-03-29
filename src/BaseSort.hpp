#ifndef BASESORT_HPP
#define BASESORT_HPP

#include <cstdlib>
#include "src/SortOrder.hpp"

using namespace std;

template <class T>
class BaseSort
{
	public:
		BaseSort(T*, int, SortOrder);
		virtual bool sort() = 0;

	protected:
		void bubbleDown(int);
		void bubbleUp(int);
		bool checkNullArray() { return (sortArray == NULL); }
		bool compare(T&, T&);
		bool compareEqual(T&, T&);
		bool compareOrEqual(T&, T&);
		T& getIndex(int);
		int getSize() { return arraySize; }
		void setIndex(int, T&);
		void swap(int, int);

	private:
		int arraySize;
		T* sortArray;
		SortOrder sortOrder;
		bool compareGreaterThan(T&, T&);
		bool compareLessThan(T&, T&);
};

template <class T>
BaseSort<T>::BaseSort(T* array = NULL, int size = 0, SortOrder order = LowToHigh)
{
	arraySize = size;
	sortArray = array;
	sortOrder = order;
}

template <class T>
void BaseSort<T>::bubbleDown(int pos)
{
	sortArray[pos + 1] = sortArray[pos];
}

template <class T>
void BaseSort<T>::bubbleUp(int pos)
{
	sortArray[pos - 1] = sortArray[pos];
}

template <class T>
T& BaseSort<T>::getIndex(int pos)
{
	return sortArray[pos];
}

template <class T>
void BaseSort<T>::setIndex(int pos, T& element)
{
	sortArray[pos] = element;
}

template <class T>
void BaseSort<T>::swap(int left, int right)
{
	T temp = sortArray[left];
	sortArray[left] = sortArray[right];
	sortArray[right] = temp;
}

template <class T>
bool BaseSort<T>::compare(T& left, T& right)
{
	if (sortOrder == HighToLow)
	{
		return compareLessThan(left, right);
	}
	else
	{
		return compareGreaterThan(left, right);
	}
}

template <class T>
bool BaseSort<T>::compareEqual(T& left, T& right)
{
	if (left == right)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool BaseSort<T>::compareOrEqual(T& left, T& right)
{
	return (compare(left, right) || compareEqual(left, right));
}

template <class T>
bool BaseSort<T>::compareGreaterThan(T& left, T& right)
{
	if (left > right)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool BaseSort<T>::compareLessThan(T& left, T& right)
{
	if (left < right)
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif

