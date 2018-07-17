/*
Author:Jason Stengel
Project: Final
Description:
Ask the user to enter the number of Prime Numbers he would like computed.
Be sure the number is 1 - 10000.
Build an unsigned int array; the size is the number of primes requested by
the user.
Call a function to fill the array with all the prime numbers from 2, up to
the number of primes requested. For example, if 10 primes were requested,
your array will contain: 2, 3, 5, 7, 11, 13, 17, 19, 23, and 29, Etc.
Remember that a prime number is a positive integer that cannot be divided
evenly by
any integer besides 1 and itself.
Write another function to display the primes in 10 columns of right-
justified numbers.
*/

#include <iostream>
#include <iomanip>
#include "ArraySizes.h"
using namespace std;


//prototypes
void FillArray(array_sizes *pArraySizes);
void PrintNumbers(array_sizes *pArraySizes);
void DifferenceBetween(array_sizes *pArraySizes);
void PrintDifference(array_sizes *pArraySizes);

int main()
{
	array_sizes SizeOf;
	array_sizes *pArraySizes;
	pArraySizes = &SizeOf;

	cout << "How many prime numbers would you like? ";
	cin >> pArraySizes->arr_size;
	//makes sure user enters a number between 1 and 10000
	while (pArraySizes->arr_size < 1 || pArraySizes->arr_size > 10000)
	{
		cout << "Please enter a number between 1 and 10000: " << endl;
		cin >> pArraySizes->arr_size;
	}

	//sets the pointers to point to dynamic arrays
	pArraySizes->arrDiff_size = (pArraySizes->arr_size - 1);
	pArraySizes->pArrayPrimes = new unsigned[pArraySizes->arr_size];
	pArraySizes->pArrayDiff = new unsigned[pArraySizes->arrDiff_size];

	//running functions
	FillArray(pArraySizes);
	PrintNumbers(pArraySizes);
	DifferenceBetween(pArraySizes);
	PrintDifference(pArraySizes);

	//delets the dynamic arrays that are being 
	//pointed to by the below pointers
	delete[] pArraySizes->pArrayDiff;
	delete[] pArraySizes->pArrayPrimes;

	cin.ignore();
	cin.get();

	return 0;
}

//fills the array with the number of prime numbers asked
//for by the user
void FillArray(array_sizes *pArraySizes)
{
	unsigned *pt;
	bool isPrime = true;
	int iCount2, iPrimeNumber, iTestNumbers;

	cout << endl;
	//gets the prime numbers within the range given by the user
	//filling the array with each prime found
	for (iPrimeNumber = 2, pt = pArraySizes->pArrayPrimes, iCount2 = 0; iCount2 < pArraySizes->arr_size; iPrimeNumber++)
	{
		iTestNumbers = 2;
		isPrime = true;
		while (iTestNumbers < iPrimeNumber && isPrime)
		{
			isPrime = true;
			if (iPrimeNumber % iTestNumbers == 0)
			{
				isPrime = false;
			}
			else
			{
				iTestNumbers++;
				isPrime = true;
			}
		}
		if (isPrime)
		{
			*pt = iPrimeNumber;
			pt++;
			iCount2++;
		}
	}
}
//prints the prime numbers
void PrintNumbers(array_sizes *pArraySizes)
{
	unsigned *pt;
	int iCount;

	for (pt = pArraySizes->pArrayPrimes, iCount = 1; iCount <= pArraySizes->arr_size; pt++, iCount++)
	{
		cout << setw(7) << right << *pt;

		if (iCount % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl << endl;
}

//gets the difference between each of the primes. 
//First and second, second and third etc.
void DifferenceBetween(array_sizes *pArraySizes)
{
	unsigned *pTemp;
	unsigned *pDiffTemp;
	int count;

	for (pTemp = pArraySizes->pArrayPrimes, pDiffTemp = pArraySizes->pArrayDiff, count = 0; count < pArraySizes->arrDiff_size; pDiffTemp++, pTemp++, count++)
	{
		*pDiffTemp = *(pTemp + 1) - *pTemp;
	}
}

//prints the difference between each prime number
void PrintDifference(array_sizes *pArraySizes)
{
	unsigned *pt;
	int iCount;
	cout << endl << endl;

	for (pt = pArraySizes->pArrayDiff, iCount = 1; iCount <= pArraySizes->arrDiff_size; pt++, iCount++)
	{
		cout << setw(7) << right << *pt;
		if (iCount % 10 == 0)
		{
			cout << endl;
		}
	}
}