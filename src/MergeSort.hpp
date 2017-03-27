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
		void merge(
};

template <class T>
MergeSort<T>::MergeSort(T* array = NULL, int size = 0, SortOrder order = LowToHigh)
	: BaseSort<T>(array, size, order)
{
}

template <class T>
bool MergeSort<T>::sort()
{
	if (this->checkNullArray() || (this.getSize() <= 1))
	{
		return true;
	}

	tempArray = T[this->getSize()];
}

#endif

