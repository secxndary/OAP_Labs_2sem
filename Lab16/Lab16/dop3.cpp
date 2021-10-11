#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

// ======================================  Д О П  3  ======================================

void dop3()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int size, i, sizeB = 0;
	int A[100], B[100], C[100];
	cout << "Введите количество элементов массива: ";
	cin >> size;

	cout << "\nМассив А: | ";
	for (i = 0; i < size; i++)
	{
		A[i] = 1 + rand() % 20;
		cout << A[i] << " | ";

		if (i % 2 == 0)
		{
			B[sizeB] = A[i];
			sizeB++;
		}
	}

	cout << "\nМассив B: | ";
	for (i = 0; i < sizeB; i++) cout << B[i] << " | ";

	bubbleSort(B, sizeB);
	cout << "\n\nСортировка пузырьком: | ";
	for (i = 0; i < sizeB; i++)
		cout << B[i] << " | ";

	insertSort(B, sizeB);
	cout << "\nСортировка вставкой:  | ";
	for (i = 0; i < sizeB; i++)
		cout << B[i] << " | ";

	cout << '\n';
}