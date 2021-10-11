#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

// ======================================  Д О П  2  ======================================

void dop2()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int size, i, j = 0;
	int A[100], B[100], C[100];
	cout << "Введите количество элементов массивов: ";
	cin >> size;

	cout << "\nМассив А: | ";
	for (i = 0; i < size; i++)
	{
		A[i] = 1 + rand() % 20;
		cout << A[i] << " | ";

		if (A[i] % 2 == 0)
		{
			C[j] = A[i];
			j++;
		}
	}

	cout << "\nМассив B: | ";
	for (i = 0; i < size; i++)
	{
		B[i] = 1 + rand() % 20;
		cout << B[i] << " | ";
		if (B[i] % 2 != 0)
		{
			C[j] = B[i];
			j++;
		}
	}

	cout << "\nМассив C: | ";
	for (i = 0; i < j; i++) cout << C[i] << " | ";

	bubbleSortUp(C, j);
	cout << "\n\nСортировка пузырьком: | ";
	for (i = 0; i < j; i++) cout << C[i] << " | ";

	selectSort(C, j);
	cout << "\nСортировка выбором:   | ";
	for (i = 0; i < j; i++) cout << C[i] << " | ";
	cout << '\n';
}