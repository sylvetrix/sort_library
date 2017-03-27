#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include <cstdlib>
#include "src/BaseSort.hpp"
#include "src/SortOrder.hpp"

using namespace std;

template <class T>
class BubbleSort : public BaseSort<T>
{
	public:
		BubbleSort(T*, int, SortOrder);
		bool sort();
};

template <class T>
BubbleSort<T>::BubbleSort(T* array = NULL, int size = 0, SortOrder order = LowToHigh)
	: BaseSort<T>(array, size, order)
{
}

template <class T>
bool BubbleSort<T>::sort()
{
	if (this->checkNullArray())
	{
		return true;
	}

	for (int i = 0; i < (this->getSize() - 1); i++)
	{
		bool swapped = false;

		for (int j = 0; j < (this->getSize() - 1 - i); j++)
		{
			if (this->compare(this->getIndex(j), this->getIndex(j + 1)))
			{
				this->swap(j, j + 1);
				swapped = true;
			}
		}

		if (!swapped)
		{
			break;
		}
	}
}

#endif

