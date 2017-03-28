#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <cstdlib>
#include "src/BaseSort.hpp"
#include "src/SortOrder.hpp"

using namespace std;

template <class T>
class QuickSort : public BaseSort<T>
{
	public:
		QuickSort(T*, int, SortOrder);
		bool sort();

	private:
		int partition(int, int, T);
		void quickSort(int, int);
};

template <class T>
QuickSort<T>::QuickSort(T* array = NULL, int size = 0, SortOrder order = LowToHigh)
	: BaseSort<T>(array, size, order)
{
}

template <class T>
int QuickSort<T>::partition(int left, int right, T pivot)
{
	int tempLeft = left - 1, tempRight = right;
	
	while (true)
	{
		while (this->compare(pivot, this->getIndex(++tempLeft))) { }
		while ((tempRight > 0) && this->compare(this->getIndex(--tempRight), pivot)) { }

		if (tempLeft >= tempRight)
		{
			break;
		}
		else
		{
			this->swap(tempLeft, tempRight);
		}
	}

	this->swap(tempLeft, right);
	return tempLeft;
}

template <class T>
void QuickSort<T>::quickSort(int left, int right)
{
	if (left >= right)
	{
		return;
	}

	T pivot = this->getIndex(right);
	int part = partition(left, right, pivot);
	quickSort(left, part - 1);
	quickSort(part + 1, right);
}

template <class T>
bool QuickSort<T>::sort()
{
	if (this->checkNullArray() || (this->getSize() <= 1))
	{
		return true;
	}

	quickSort(0, this->getSize() - 1);
}

#endif

