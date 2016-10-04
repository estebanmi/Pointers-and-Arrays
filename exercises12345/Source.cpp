#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

void sum(int val1, int val2, int* result);	//EX2
void reverse(int* array2, int sizeArray); //EX3
void absSwap(int* arr1, int sizeArr1, int* arr2, int sizeArr2); //EX4

void printCharPtr(char* myString); //EX5
int sizeWord(char* word); //EX5
void concat(char* word1, char* word2, char* resultEX5); //EX5

int main()
{

	/////// EX 1 ///////

	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* arrayP;
	arrayP = array;

	cout << "Exercise 1:" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << arrayP[i] << "\t" << &array[i] << endl;
	}
	system("pause");

	/////// EX 2 ///////

	system("CLS");
	cout << "Exercise 2:" << endl;
	int val1;
	int val2;
	int result;

	cout << "Enter val1: " << endl;
	cin >> val1;
	cout << "Enter val2: " << endl;
	cin >> val2;

	sum(val1, val2, &result);

	system("pause");

	/////// EX 3 ///////   

	system("CLS");
	cout << "Exercise 3:" << endl;

	int array2[10];

	for (int i = 0; i < 10; ++i)
	{
		cout << "Enter val" << i << ": ";
		cin >> array2[i];
	}

	reverse(array2, 10);

	system("pause");

	/////// EX 4 ///////   

	system("CLS");
	cout << "Exercise 4:" << endl;
	srand(time(NULL));


	int* arr1 = (int*)calloc(20, sizeof(int));    //IS NOT PRODUCT(*) IS COLON ','
	int* arr2 = (int*)malloc(20 * sizeof(int));
	for (int i = 0; i < 20; ++i)
	{
		arr2[i] = rand() % 1001;
	}

	cout << "\n***Before***\n\nArray 1:\tArray 2:" << endl;
	for (int i = 0; i<20; ++i)
	{
		cout << arr1[i] << "\t\t" << arr2[i] << endl;
	}

	cout << "Press to apply the function Abs" << endl << endl;
	system("pause");
	absSwap(arr1, 20, arr2, 20);

	system("CLS");
	cout << "Exercise 4:" << endl;
	cout << "\n***Before***\n\nArray 1:\tArray 2:" << endl;
	for (int i = 0; i<20; ++i)
	{
		cout << arr1[i] << "\t\t" << arr2[i] << endl;
	}
	free(arr1);
	free(arr2);

	system("pause");

	/////// EX 5 ///////   

	system("CLS");

	char word1[10];
	char word2[10];

	cout << "Exercise 5:\n\nEnter first word(10 chars max): " <<endl;

	cin >> word1;

	cout << "\nEnter second word(10 chars max): " << endl;

	cin >> word2;

	int totalSize = (sizeWord(word1) + sizeWord(word2) + 1);   // word1 size + word2 size + 1(NULL) = TOTAL

	char* resultEX5 = (char*)malloc(totalSize * sizeof(char));   

	concat(word1,word2,resultEX5);

	printCharPtr(resultEX5);

	free(resultEX5);
	
	system("pause");
	return 0;
}

void sum(int val1, int val2, int* result) // EX2
{
	*result = val1 + val2;
	cout << "val1 + val2 = " << *result << endl;
}

void reverse(int* array2, int sizeArray)  // EX3
{
	for (int i = 1; i<sizeArray + 1; ++i)
	{
		cout << *(array2 + (sizeArray - i)) << endl;;
	}

}

void absSwap(int* arr1, int sizeArr1, int* arr2, int sizeArr2)// EX4
{
	if (sizeArr1 == sizeArr2)
	{
		for (int i = 0; i<sizeArr1; ++i)
		{
			arr1[i] = arr2[i];
		}
	}
	else
	{
		cout << "The arrays must have the same size." << endl;
	}

}

void printCharPtr(char* myString) // EX5
{
	int i = 0;

	cout << "\nThe new word is: " << endl;

	while (myString[i] != NULL)
	{
		cout << myString[i];
		i++;
	}

	cout << endl << endl;
}
int sizeWord(char* word) // EX5
{
	int i = 0;

	while (word[i] != NULL)
	{
		i++;
	}
	return i;
}
void concat(char* word1, char* word2, char* result) // EX5
{
	int i = 0;
	int j = 0;

	while (word1[i] != NULL)
	{
		result[i] = word1[i];
		i++;
	}

	while (word2[j] != NULL)
	{
		result[i] = word2[j];
		i++;
		j++;
	}

	result[i] = NULL;
}