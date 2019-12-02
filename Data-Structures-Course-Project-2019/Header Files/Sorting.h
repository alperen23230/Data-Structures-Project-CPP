#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Student.h"
#include "Stack.h"

using std::string;

LinkedList list;
Stack stack;




struct Radix {
	int lenght;
	string* surnames;


	Radix(string list[], int listLenght) {
		surnames = list;
		lenght = listLenght;
	}

public:

	// Getting max sized string from array
	size_t getMax(string arr[], int lenght)
	{

		size_t max = arr[0].size();
		for (int i = 0; i < lenght; i++)
		{
			if (arr[i].size() > max)
				max = arr[i].size();
		}
		return max;
	}

	// Count sort
	void countSort(string arr[], int size, size_t s)
	{
		string *b = NULL;
		int *c = NULL;
		b = new string[size];
		c = new int[257];

		for (int i = 0; i < 257; i++)
		{
			c[i] = 0;
		}

		for (int j = 0; j < size; j++)
		{
			c[s < arr[j].size() ? (int)(unsigned char)arr[j][s] + 1 : 0]++;
		}

		for (int f = 1; f < 257; f++)
		{
			c[f] += c[f - 1];
		}

		for (int r = size - 1; r >= 0; r--)
		{
			b[c[s < arr[r].size() ? (int)(unsigned char)arr[r][s] + 1 : 0] - 1] = arr[r];
			c[s < arr[r].size() ? (int)(unsigned char)arr[r][s] + 1 : 0]--;
		}

		for (int l = 0; l < size; l++) {
			arr[l] = b[l];
		}

		delete[] b;
		delete[] c;
	}

	// Radix Sorting
	void radixSort(string b[], int r) {
		size_t max = getMax(b, r);
		for (size_t digit = max; digit > 0; digit--) // Looking for every digit and sorting in order 
		{
			countSort(b, r, digit - 1);
		}

	}

	// Display sorted list
	void sortWithRadix()
	{
		radixSort(surnames, lenght);
	}

};

struct Selection
{
	int lenght, minIndex;
	string* names;

	Selection(string list[], int listLenght) {
		names = list;
		lenght = listLenght;
	}

	void swap(string *xPointer, string *yPointer)
	{
		string temp = *xPointer;
		*xPointer = *yPointer;
		*yPointer = temp;
	}

	void sortWithSelection()
	{
		for (size_t i = 0; i < lenght - 1; i++)
		{
			minIndex = i;
			for (size_t j = i + 1; j < lenght; j++)
			{
				if (names[j] < names[minIndex])
				{
					minIndex = j;
				}
			}
			swap(&names[minIndex], &names[i]);
		}
	}

};

struct Quick
{
	int lenght;
	int* numbers;
	Stack stack1;

	Quick(int list[], int listLenght)
	{
		lenght = listLenght;
		numbers = list;
	}
	Quick(Stack stack, int stackLenght) {
		stack1 = stack;
		lenght = stackLenght;
	}


	void swap(int* x, int* y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	}

	int partition(int list[], int low, int high)
	{
		int pivot = list[high];
		int i = low - 1;

		for (int j = low; j < high; j++)
		{
			if (list[j] < pivot)
			{
				i++;
				swap(&list[j], &list[i]);
			}
		}
		swap(&list[i + 1], &list[high]);
		return i + 1;
	}

	int partitionStack(Stack* stack, int low, int high)
	{

		Student pivot = stack->FindNodewithIndex(high);
		int i = low - 1;

		for (int j = low; j < high; j++)
		{
			if (stack->FindNodewithIndex(j).studentNo < pivot.studentNo)
			{
				i++;
				if (i != j)stack->swap(i, j);
			}
		}
		if (i + 1 != high)stack->swap(i + 1, high);
		return i + 1;

	}


	void quickSort(int list[], int low, int high)
	{
		if (low < high)
		{
			int pivot = partition(list, low, high);

			quickSort(list, low, pivot - 1); // Sorting left pivot numbers
			quickSort(list, pivot + 1, high);  // Sorting right pivot numbers
		}
	}

	void quickSortStack(Stack* stack, int low, int high)
	{

		if (low < high)
		{
			int pivot = partitionStack(stack, low, high);

			quickSortStack(stack, low, pivot - 1); // Sorting left pivot numbers
			quickSortStack(stack, pivot + 1, high); // Sorting right pivot numbers

		}

	}


	void sortWithQuickSort()
	{

		quickSort(numbers, 0, lenght - 1);

	}

	Stack sortWithQuickSortStack()
	{
		quickSortStack(&stack1, 1, lenght);

		return stack1;
		//stack1.DisplayStack();
	}

};
