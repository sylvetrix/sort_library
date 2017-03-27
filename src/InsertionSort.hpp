#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include <cstdlib>
#include "src/BaseSort.hpp"
#include "src/SortOrder.hpp"

template <class T>
class InsertionSort : public BaseSort<T>
{
	public:
		InsertionSort(T*, int, SortOrder);
		bool sort();
};

template <class T>
InsertionSort<T>::InsertionSort(T* array = NULL, int size = 0, SortOrder order = LowToHigh)
	: BaseSort<T>(array, size, order)
{
}

template <class T>
bool InsertionSort<T>::sort()
{
	if (this->checkNullArray())
	{
		return true;
	}

	int holePos;
	T element;

	for (int i = 1; i < this->getSize(); i++)
	{
		element = this->getIndex(i);
		holePos = i;

		while ((holePos > 0) && (this->compare(this->getIndex(holePos - 1), element)))
		{
			this->bubbleDown(holePos - 1);
			holePos--;
		}

		this->setIndex(holePos, element);
	}
}

#endif

