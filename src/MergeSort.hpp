#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <cstdlib>
#include "src/BaseSort.hpp"
#include "src/SortOrder.hpp"

using namespace std;

template <class T>
class MergeSort : public BaseSort<T>
{
	public:
		MergeSort(T*, int, SortOrder);
		bool sort();

	private:
		T* tempArray;
		void merge(int, int, int);
		void mergeSort(int, int);
};

template <class T>
MergeSort<T>::MergeSort(T* array = NULL, int size = 0, SortOrder order = LowToHigh)
	: BaseSort<T>(array, size, order)
{
}

template <class T>
void MergeSort<T>::merge(int low, int mid, int high)
{
	int left = low, right = mid + 1, i = low;

	for ( ; (left <= mid) && (right <= high); i++)
	{
		if (this->compare(this->getIndex(left), this->getIndex(right)))
		{
			tempArray[i] = this->getIndex(right);
			right++;
		}
		else
		{
			tempArray[i] = this->getIndex(left);
			left++;
		}
	}

	while (left <= mid)
	{
		tempArray[i] = this->getIndex(left);
		i++;
		left++;
	}

	while (right <= high)
	{
		tempArray[i] = this->getIndex(right);
		i++;
		right++;
	}

	for (i = low; i <= high; i++)
	{
		this->setIndex(i, tempArray[i]);
	}
}

template <class T>
void MergeSort<T>::mergeSort(int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergeSort(low, mid);
		mergeSort(mid + 1, high);
		merge(low, mid, high);
	}
}

template <class T>
bool MergeSort<T>::sort()
{
	if (this->checkNullArray() || (this->getSize() <= 1))
	{
		return true;
	}

	T array[this->getSize()];
	tempArray = array;
	mergeSort(0, this->getSize() - 1);

	return true;
}

#endif

