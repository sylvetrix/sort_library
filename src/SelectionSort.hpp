#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include <cstdlib>
#include "src/BaseSort.hpp"
#include "src/SortOrder.hpp"

using namespace std;

template <class T>
class SelectionSort : public BaseSort<T>
{
	public:
		SelectionSort(T*, int, SortOrder);
		bool sort();
};

template <class T>
SelectionSort<T>::SelectionSort(T* array = NULL, int size = 0, SortOrder order = LowToHigh)
	: BaseSort<T>(array, size, order)
{
}

template <class T>
bool SelectionSort<T>::sort()
{
	if (this->checkNullArray())
	{
		return true;
	}

	for (int i = 0; i < (this->getSize() - 1); i++)
	{
		int indexMin = i;
		T min = this->getIndex(i);

		for (int j = i + 1; j < this->getSize(); j++)
		{
			if (this->compare(min, this->getIndex(j)))
			{
				indexMin = j;
				min = this->getIndex(j);
			}
		}

		if (indexMin != i)
		{
			this->swap(indexMin, i);
		}
	}
}

#endif

