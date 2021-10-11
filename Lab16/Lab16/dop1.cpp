#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

// ======================================  Д О П  1  ======================================

void dop1()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int size, i, min = 21, j, sizeC = 0;
	int A[100], B[100], C[100];
	cout << "Введите количество элементов массивов: ";
	cin >> size;

	cout << "\nМассив А: | ";
	for (i = 0; i < size; i++)
	{
		A[i] = 1 + rand() % 20;
		cout << A[i] << " | ";
	}

	cout << "\nМассив B: | ";
	for (i = 0; i < size; i++)
	{
		B[i] = 1 + rand() % 20;
		cout << B[i] << " | ";
		if (B[i] < min) min = B[i];
	}

	cout << "\nМинимальное значение: " << min;

	cout << "\nМассив С: | ";
	for (i = 0; i < size; i++)
	{
		if (A[i] > min)
		{
			C[i] = A[i];
			sizeC++;
			cout << C[i] << " | ";
		}
	}

	cout << "\n\nСортировка шейкером: | ";
	shakerSort(C, sizeC);
	for (i = 0; i < sizeC; i++)
	{
		if (C[i] > 0) cout << C[i] << " | ";
	}

	cout << "\nСортировка Шелла:    | ";
	Shell(C, sizeC);
	for (i = 0; i < sizeC; i++)
	{
		if (C[i] > 0) cout << C[i] << " | ";
	}
	cout << '\n';
}