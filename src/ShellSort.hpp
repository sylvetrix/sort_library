#ifndef SHELLSORT_HPP
#define SHELLSORT_HPP

#include <cstdlib>
#include "src/BaseSort.hpp"
#include "src/SortOrder.hpp"

using namespace std;

template <class T>
class ShellSort : public BaseSort<T>
{
	public:
		ShellSort(T*, int, SortOrder);
		bool sort();
};

template <class T>
ShellSort<T>::ShellSort(T* array = NULL, int size = 0, SortOrder order = LowToHigh)
	: BaseSort<T>(array, size, order)
{
}

template <class T>
bool ShellSort<T>::sort()
{
	if (this->checkNullArray() || (this->getSize() <= 1))
	{
		return true;
	}

	int interval = 1;

	while (interval < (this->getSize() / 3))
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		for (int outer = interval; outer < this->getSize(); outer++)
		{
			T element = this->getIndex(outer);
			int inner = outer;

			while ((inner > (interval - 1))
				&& this->compareOrEqual(this->getIndex(inner - interval), element))
			{
				this->setIndex(inner, this->getIndex(inner - interval));
				inner -= interval;
			}

			this->setIndex(inner, element);
		}

		interval = (interval - 1) / 3;
	}
}

#endif

