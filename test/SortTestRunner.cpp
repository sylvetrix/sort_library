#include <ctime>
#include <iostream>
#include "src/BubbleSort.hpp"
#include "src/InsertionSort.hpp"
#include "src/MergeSort.hpp"
#include "src/QuickSort.hpp"
#include "src/SelectionSort.hpp"
#include "src/ShellSort.hpp"
#include "src/SortOrder.hpp"

#define INT_TEST_SIZE 10000
#define SORTS_SIZE 6
#define GEN_TYPE_SIZE 4
#define ORDERS_SIZE 2

using namespace std;

// enum for sort to use
enum SortFunction
{
	Bubble,
	Insertion,
	Merge,
	Quick,
	Selection,
	Shell
};

enum ArrayGenType
{
	Ascending,
	Descending,
	Interlaced,
	Random
};

// sorts to test
SortFunction sorts[SORTS_SIZE] = { Bubble, Insertion, Merge, Quick, Selection, Shell };
string sortName(SortFunction);

// ways to generate the array
ArrayGenType genTypes[GEN_TYPE_SIZE] = { Ascending, Descending, Interlaced, Random };
string genTypeName(ArrayGenType);

// sort orders
SortOrder sortOrders[ORDERS_SIZE] = { LowToHigh, HighToLow };
string orderName(SortOrder);

// set array functions
void setIntArray(int*, int, ArrayGenType);

// type testing functions
bool testChar();
bool testClass();
bool testInt();

// validation functions
bool validateCharArray(char*, int, SortOrder);
template <class T>
bool validateClassArray(T*, int, SortOrder);
bool validateIntArray(int*, int, SortOrder);

// templated class runners
template <class T>
void runSorter(T*, int, SortOrder, SortFunction);

int main(int argc, char** argv)
{
	testInt();
}

string sortName(SortFunction function)
{
	switch(function)
	{
		case Bubble:
			return "Bubble";
		case Insertion:
			return "Insertion";
		case Merge:
			return "Merge";
		case Quick:
			return "Quick";
		case Selection:
			return "Selection";
		case Shell:
			return "Shell";
		default:
			return "Unknown";
	}
}

string genTypeName(ArrayGenType genType)
{
	switch (genType)
	{
		case Ascending:
			return "Ascending";
		case Descending:
			return "Descending";
		case Interlaced:
			return "Interlaced";
		case Random:
			return "Random";
		default:
			return "Unknown";
	}
}

string orderName(SortOrder order)
{
	switch (order)
	{
		case LowToHigh:
			return "Low to High";
		case HighToLow:
			return "High to Low";
		default:
			return "Unknown Order";
	}
}

void setIntArray(int* testArray, int arraySize, ArrayGenType genType)
{
	switch (genType)
	{
		case Ascending:
			for (int i = 0; i < arraySize; i++)
			{
				testArray[i] = i;
			}
			break;
		case Descending:
			for (int i = arraySize - 1; i >= 0; i--)
			{
				testArray[i] = i;
			}
			break;
		case Interlaced:
			{
				int maxNum = (int)(arraySize / 2) - 1;
				for (int i = 0; i < arraySize; i += 2)
				{
					testArray[i] = i / 2;
					testArray[i + 1] = maxNum - (i / 2);
				}
			}
			break;
		case Random:
			srand((int) time(0));
			for (int i = 0; i < arraySize; i++)
			{
				testArray[i] = rand();
			}
			break;
		default:
			break;
	}
}

bool testChar()
{
	return false;
}

bool testClass()
{
	return false;
}

bool testInt()
{
	int testArray[INT_TEST_SIZE];

	for (int s = 0; s < SORTS_SIZE; s++)
	{
		cout << "Testing " << sortName(sorts[s]) << " sort:\n";

		for (int o = 0; o < ORDERS_SIZE; o++)
		{
			for (int gt = 0; gt < GEN_TYPE_SIZE; gt++)
			{
				setIntArray(testArray, INT_TEST_SIZE, genTypes[gt]);
				runSorter(testArray, INT_TEST_SIZE, sortOrders[o], sorts[s]);
				cout << "\tType: " << genTypeName(genTypes[gt]) << ",\tOrder: " << orderName(sortOrders[o]) << ": ";
				cout << (validateIntArray(testArray, INT_TEST_SIZE, sortOrders[o]) ? "[PASSED]\n" : "[FAILED]\n");
			}
		}
	}
}

bool validateCharArray(char* array, int size, SortOrder order)
{
	return false;
}

template <class T>
bool validateClassArray(T* array, int size, SortOrder order)
{
	return false;
}

bool validateIntArray(int* array, int size, SortOrder order)
{
	for (int i = 1; i < size; i++)
	{
		if (((order == LowToHigh) && (array[i - 1] > array[i]))
			|| ((order == HighToLow) && (array[i - 1] < array[i])))
		{
			return false;
		}
	}

	return true;
}

template <class T>
void runSorter(T* array, int size, SortOrder order, SortFunction function)
{
	BaseSort<T> * sorter;

	switch (function)
	{
		case Bubble:
			sorter = new BubbleSort<T>(array, size, order);
			break;
		case Insertion:
			sorter = new InsertionSort<T>(array, size, order);
			break;
		case Merge:
			sorter = new MergeSort<T>(array, size, order);
			break;
		case Quick:
			sorter = new QuickSort<T>(array, size, order);
			break;
		case Selection:
			sorter = new SelectionSort<T>(array, size, order);
			break;
		case Shell:
			sorter = new ShellSort<T>(array, size, order);
			break;
		default:
			return;
	}
	if (sorter != NULL)
	{
		sorter->sort();
		delete sorter;
	}
}

