#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Student.h"

using std::string;


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
	void displayRadixSorted()
	{
		radixSort(surnames, lenght);
		for (size_t i = 0; i < lenght; i++)
		{
			std::cout << surnames[i] << std::endl;
		}
	}

};
