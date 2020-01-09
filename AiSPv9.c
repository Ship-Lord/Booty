#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>


int GenerateNiz(int[], int);
int CopyNiz(int* A, int* B, int n);
int ExchangeSort(int[], int);
int SelectionSort(int[], int);
int InsertionSort(int[], int);
int BubbleSort(int[], int);
void ShellSort(int* niz, int n);
void QuickSort(int* niz, int top, int bottom);

int main()
{
	srand(time(NULL));

	printf("\r\n\t\t*************************");
	printf("\r\n\t\t***      VJEZBA 9.    ***");
	printf("\r\n\t\t*       Sortiranje      *");
	printf("\r\n\t\t*************************");
	printf("\r\n");
	printf("\r\n");

	Sortiranje(100);


	system("pause");
	return 0;
}

int GenerateNiz(int A[], int n)
{

	for (int i = 0; i < n; i++) {
		A[i] = rand() % n;
		//printf("%d",i);
		//printf("%d\n", A[i]);
	}
	return 0;
}

int CopyNiz(int* A, int* B, int n)
{
	for (int i = 0; i < n; i++)
	{
		B[i] = A[i];
	}
	return 0;
}

int ExchangeSort(int niz[], int length)
{
	int i = 0, j = 0;
	int temp = 0;   // holding variable
	for (i = 0; i < length - 1; i++)    // element to be compared
	{
		for (j = (i + 1); j < length; j++)   // rest of the elements
		{
			if (niz[i] < niz[j])          // descending order
			{
				temp = niz[i];          // swap
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
	}
	return 0;
}

int SelectionSort(int niz[], int length)
{
	int i, j, first, temp;
	for (i = length - 1; i > 0; i--)
	{
		first = 0;                 // initialize to subscript of first element
		for (j = 1; j <= i; j++)   // locate smallest between positions 1 and i.
		{
			if (niz[j] < niz[first])
				first = j;
		}
		temp = niz[first];   // Swap smallest found with element in position i.
		niz[first] = niz[i];
		niz[i] = temp;

		
	}
	return 0;
}

	int InsertionSort(int niz[], int length)
	{
		int i, j, key;
		for (j = 1; j < length; j++)    // Start with 1 (not 0)
		{
			key = niz[j];
			for (i = j - 1; (i >= 0) && (niz[i] < key); i--)   // Smaller values move up
			{
				niz[i + 1] = niz[i];
			}
			niz[i + 1] = key;    //Put key into its proper location
		}
		return 0;
	}

	int BubbleSort(int niz[], int length)
	{
		int i, j, flag = 1;    // set flag to 1 to start first pass
		int temp;             // holding variable
		for (i = 1; (i <= length) && flag; i++)
		{
			flag = 0;
			for (j = 0; j < (length - 1); j++)
			{
				if (niz[j + 1] > niz[j])      // ascending order simply changes to <
				{
					temp = niz[j];             // swap elements
					niz[j] = niz[j + 1];
					niz[j + 1] = temp;
					flag = 1;               // indicates that a swap occurred.
				}
			}
		}
		return 0;   //arrays are passed to functions by address; nothing is returned
	}

	void ShellSort(int* niz, int n)
	{
		int i, temp, flag = 1;
		int d = n;
		while (flag || (d > 1))      // boolean flag (true when not equal to 0)
		{
			flag = 0;           // reset flag to 0 to check for future swaps
			d = (d + 1) / 2;
			for (i = 0; i < (n - d); i++)
			{
				if (niz[i + d] > niz[i])
				{
					temp = niz[i + d];      // swap positions i+d and i
					niz[i + d] = niz[i];
					niz[i] = temp;
					flag = 1;                  // tells swap has occurred
				}
			}
		}
		return;
	}

	void QuickSort(int* niz, int top, int bottom)
	{
		// top = subscript of beginning of array
		// bottom = subscript of end of array

		int middle;
		if (top < bottom)
		{
			middle = partition(niz, top, bottom);
			QuickSort(niz, top, middle);   // sort first section
			QuickSort(niz, middle + 1, bottom);    // sort second section
		}
		return;
	}
	//Function to determine the partitions
// partitions the array and returns the middle subscript
	int partition(int* niz, int top, int bottom)
	{
		int x = niz[top];
		int i = top - 1;
		int j = bottom + 1;
		int temp;

		do
		{
			do
			{
				j--;
			} while (x > niz[j]);

			do
			{
				i++;
			} while (x < niz[i]);

			if (i < j)
			{
				temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		} while (i < j);
		return j;           // returns middle subscript 
	}

	void MergeSort(int* arrayA, int* arrayB, int* arrayC)
	{
		int indexA = 0;     // initialize variables for the subscripts
		int indexB = 0;
		int indexC = 0;

		while ((indexA < arrayA.length()) && (indexB < arrayB.length())
		{
			if (arrayA[indexA] < arrayB[indexB])
			{
				arrayC[indexC] = arrayA[indexA];
				indexA++;    //increase the subscript
			}
			else
			{
				arrayC[indexC] = arrayB[indexB];
				indexB++;      //increase the subscript
			}
			indexC++;      //move to the next position in the new array
		}
		// Move remaining elements to end of new array when one merging array is empty
		while (indexA < arrayA.length())
		{
			arrayC[indexC] = arrayA[indexA];
			indexA++;
			indexC++;
		}
		while (indexB < arrayB.length())
		{
			arrayC[indexC] = arrayB[indexB];
			indexB++;
			indexC++;
		}
		return;
	}

	int Sortiranje(int n)
	{
		unsigned long Start = 0;
		unsigned long End = 0;
		int arrayA[] = 0;
		int arrayB[] = 0;

		int* ParrayA = arrayA;
		int* ParrayB = arrayB;

		printf("Niz od %d elemenata : ", n);
		arrayA = (int*)malloc(sizeof(int) * n);
		if (arrayA == 0)
		{
			printf("Greska pri alokaciji memorije za arrayA!!\n");
			return 0;
		}
		else
		{
			GenerateNiz(arrayA, n);
		}
		
		arrayB = (int*)malloc(sizeof(int) * n);
		if (arrayB == 0)
		{
			printf("Greska pri alokaciji memorije za arrayB!!\n");
			return 0;
		}
		else
		{
			CopyNiz(arrayA, arrayB, n);
			Start = GetTickCount64();
			ExchangeSort(arrayB, n);
			End = GetTickCount64();
			printf("\r\nExchangeSort\t\t%d", (int)(End - Start));
			free(arrayB);
		}
	
		return 0;
	}