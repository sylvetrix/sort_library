#include <iostream>
#include "src/BubbleSort.hpp"
#include "src/InsertionSort.hpp"
#include "src/MergeSort.hpp"
#include "src/QuickSort.hpp"
#include "src/SelectionSort.hpp"
#include "src/ShellSort.hpp"
#include "src/SortOrder.hpp"

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

const int sortsSize = 6;

// sorts to test
SortFunction sorts[sortsSize] = { Bubble, Insertion, Merge, Quick, Selection, Shell };

// set array functions
void setIntArray(int*, int*, int);

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

void setIntArray(int* newArray, int* initialArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		newArray[i] = initialArray[i];
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
	int _sortedArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int _reverseArray[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int _duplicateArray[10] = { 0, 4, 1, 3, 2, 2, 3, 1, 4, 0 };

	int sortedArray[10];
	int reverseArray[10];
	int duplicateArray[10];

	for (int i = 0; i < sortsSize; i++)
	{
		cout << "Testing ";
		switch (sorts[i])
		{
			case Bubble:
				cout << "Bubble";
				break;
			case Insertion:
				cout << "Insertion";
				break;
			case Merge:
				cout << "Merge";
				break;
			case Quick:
				cout << "Quick";
				break;
			case Selection:
				cout << "Selection";
				break;
			case Shell:
				cout << "Shell";
				break;
			default:
				cout << "Unknown";
				break;
		}
		cout << " sort:\n";

		setIntArray(sortedArray, _sortedArray, 10);
		setIntArray(reverseArray, _reverseArray, 10);
		setIntArray(duplicateArray, _duplicateArray, 10);

		runSorter(sortedArray, 10, LowToHigh, sorts[i]);
		runSorter(reverseArray, 10, LowToHigh, sorts[i]);
		runSorter(duplicateArray, 10, LowToHigh, sorts[i]);

		cout << "\tSorted array, low to high:    ";
		cout << (validateIntArray(sortedArray, 10, LowToHigh) ? "[PASSED]\n" : "[FAILED]\n");
		cout << "\tReversed array, low to high:  ";
		cout << (validateIntArray(reverseArray, 10, LowToHigh) ? "[PASSED]\n" : "[FAILED]\n");
		cout << "\tDuplicate array, low to high: ";
		cout << (validateIntArray(duplicateArray, 10, LowToHigh) ? "[PASSED]\n" : "[FAILED]\n");

		setIntArray(sortedArray, _sortedArray, 10);
		setIntArray(reverseArray, _reverseArray, 10);
		setIntArray(duplicateArray, _duplicateArray, 10);

		runSorter(sortedArray, 10, HighToLow, sorts[i]);
		runSorter(reverseArray, 10, HighToLow, sorts[i]);
		runSorter(duplicateArray, 10, HighToLow, sorts[i]);

		cout << "\tSorted array, low to high:    ";
		cout << (validateIntArray(sortedArray, 10, HighToLow) ? "[PASSED]\n" : "[FAILED]\n");
		cout << "\tReversed array, low to high:  ";
		cout << (validateIntArray(reverseArray, 10, HighToLow) ? "[PASSED]\n" : "[FAILED]\n");
		cout << "\tDuplicate array, low to high: ";
		cout << (validateIntArray(duplicateArray, 10, HighToLow) ? "[PASSED]\n" : "[FAILED]\n");
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

