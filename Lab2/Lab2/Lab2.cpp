#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <clocale>
#define LEN 100

using namespace std;

// Основа 1

//int main()
//{
//    setlocale(LC_ALL, "");
//    int a; errno_t err, columns = 4;
//    FILE* f;
//    err = fopen_s(&f, "matrix.txt", "w");
//    if (err != 0)
//    {
//        perror("Невозможно создать файл\n");
//        return EXIT_FAILURE;
//    }
//    int Matrix[16] = { 2,7,12,-4,
//                     6,-45,0,13,
//                     96,43,-2,8,
//                     33,-5,63,-11 };
//    // вывод первой матрицы
//    fprintf(f, "В матрице %d столбца.\n============================\n", columns);
//    for (int j = 0; j < 16; j += 4)
//    {
//        for (int i = j; i < j + 4; i++)
//        {
//            fprintf(f, "%d\t", Matrix[i]);
//        }
//        fprintf(f, "\n", "\n");
//    }
//    fprintf(f, "============================\n");
//    // вывод второй матрицы
//    err = fopen_s(&f, "matrixT.txt", "w");
//    if (err != 0)
//    {
//        perror("Невозможно создать файл\n");
//        return EXIT_FAILURE;
//    }
//    fprintf(f, "В матрице %d столбца.\n============================\n", columns);
//    for (int j = 0; j < 4; j++)
//    {
//        for (int i = j; i <= j + 12; i += 4)
//        {
//            fprintf(f, "%d\t", Matrix[i]);
//        }
//        fprintf(f, "\n", "\n");
//    }
//    fprintf(f, "============================\n");
//
//    printf("Данные записаны в файл matrixT.txt\n");
//    fclose(f);
//    return 0;
//}

// Основа 2

//int main()
//{
//	setlocale(LC_ALL, "");
//	const int len = 4;
//	char line1[len], line2[len], line3[len];
//	FILE* f1;
//	fopen_s(&f1, "NameA.txt", "r");
//	FILE* f2;
//	fopen_s(&f2, "NameB.txt", "r");
//	FILE* f3;
//	fopen_s(&f3, "NameC.txt", "r");
//	FILE* f4;
//	fopen_s(&f4, "NameD.txt", "w");
//
//	for (int i = 1; i <= 4; i++)
//	{
//		fgets(line1, len, f1);
//		fputs(line1, f4);
//		fgets(line2, len, f2);
//		fputs(line2, f4);
//		fgets(line3, len, f3);
//		fputs(line3, f4);
//	}
//	cout << "Данные записаны в файл NameD.txt" << endl;
//}

// Доп 1.1 (Вариант 11)

//int main()
//{
//	setlocale(LC_ALL, "");
//	int* a;
//	int size, counter = 0;
//	errno_t err;
//	FILE* f;
//	FILE* g;
//	err = fopen_s(&f, "fileA11.txt", "r");
//	if (err != 0)
//	{
//		perror("Невозможно создать файл");
//		return EXIT_FAILURE;
//	}
//	err = fopen_s(&g, "fileB11.txt", "w");
//	if (err != 0)
//	{
//		perror("Невозможно создать файл\n");
//		return EXIT_FAILURE;
//	}
//	fseek(f, 0L, SEEK_END);
//	size = ftell(f);
//	fseek(f, 0L, SEEK_SET);
//	a = (int*)calloc(size, sizeof(int));
//	for (int i = 0; i < size; i++)
//	{
//		fscanf_s(f, "%d ", &a[i]);
//	}
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++) 
//		{
//			if (a[i] == a[j] && i != j)
//			{
//				counter++;
//			}
//
//		}
//		if (counter == 1)
//		{
//			fprintf_s(g, "%d ", a[i]);
//		}
//	}
//	fclose(f);
//	fclose(g);
//}

// Доп 1.2 (Вариант 11)

//int main()
//{
//	setlocale(LC_ALL, "ru");
//	FILE* F1;
//	FILE* F2;
//	char str[255];
//	errno_t err;
//	err = fopen_s(&F1, "f1.txt", "w");
//	for (int i = 0; i < 7; i++)
//	{
//		fflush(stdin);
//		printf("Строка  %d: \n", i + 1);
//		gets_s(str);
//		fputs(str, F1);
//		fputs("\n", F1);
//	}
//	fclose(F1);
//	err = fopen_s(&F1, "f1.txt", "r");
//	err = fopen_s(&F2, "f2.txt", "w");
//	while (fgets(str, 255, F1) != NULL)
//	{
//		if (str[strlen(str) - 2] == 'A' || str[strlen(str) - 2] == 'a')
//		{
//			fputs(str, F2);
//		}
//	}
//	fclose(F1);
//	fclose(F2);
//}

// Доп 2.1 (Вариант 15)

//int main()
//{
//	setlocale(LC_ALL, "ru");
//	FILE* f1;
//	FILE* f2;
//	char str[255];
//	fopen_s(&f1, "matrix13_1.txt", "r");
//	fopen_s(&f2, "matrix13_2.txt", "w");
//	int column;
//	cout << "Введите столбец матрицы:\n";
//	cin >> column;
//	while (fgets(str, sizeof(str), f1))
//	{
//		int counter = 0;
//		char word[255];
//		stringstream x;
//		x << str;
//		while (x >> word)
//		{
//			if (counter + 1 == column)
//			{
//				fputs(word, f2);
//				fputs("\n", f2);
//			}
//			counter++;
//		}
//		cin.get();
//	}
//	fclose(f2);
//}

// Доп 2.2 (Вариант 15)

//void StrCut(FILE* f1, FILE* f2, int row1, int row2)
//{
//	int sum = 0;
//	char str[LEN];
//	row1--;
//	row2--;
//	while (fgets(str, LEN, f1))
//	{
//		if (sum < row1)
//		{
//		}
//		else
//		{
//			if (row1 <= row2)
//			{
//				fputs(str, f2);
//			}
//			else
//			{
//			}
//			row1++;
//		}
//		sum++;
//	}
//}
//
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	int row1, row2;
//	FILE* f1;
//	FILE* f2;
//	errno_t err1, err2;
//	err1 = fopen_s(&f1, "t1.txt", "r");
//	if (err1 != NULL)
//	{
//		printf("Ошибка открытия файла\n"); return -1;
//	}
//	err2 = fopen_s(&f2, "t2.txt", "w");
//	if (err2 != NULL)
//	{
//		printf("Ошибка открытия файла\n"); return -1;
//	}
//	fclose(f1);
//	fclose(f2);
//	cout << "Введите необходимую строку:\n";
//	cin >> row1;
//	row2 = row1 + 3;
//	fopen_s(&f1, "t1.txt", "r");
//	fopen_s(&f2, "t2.txt", "w");
//	StrCut(f1, f2, row1, row2);
//}

// Доп 3.1 (Вариант 14)

//int main()
//{
//	setlocale(LC_ALL, "ru");
//	FILE* f1;
//	FILE* f2;
//	char str[255];
//	fopen_s(&f1, "matrix14_1.txt", "r");
//	fopen_s(&f2, "matrix14_2.txt", "w");
//	int column;
//	cout << "Введите столбец матрицы:\n";
//	cin >> column;
//	while (fgets(str, sizeof(str), f1))
//	{
//		int counter = 0;
//		char word[255];
//		stringstream x;
//		x << str;
//		while (x >> word)
//		{
//			if (counter + 1 == column)
//			{
//				fputs(word, f2);
//				fputs("\n", f2);
//			}
//			counter++;
//		}
//		cin.get();
//	}
//	fclose(f2);
//}

// Доп 3.2 (Вариант 14)

//int main()
//{
//	using namespace std;
//	setlocale(LC_ALL, "Russian");
//	FILE* F1;
//	FILE* F2;
//	char str[255];
//	errno_t err;
//	err = fopen_s(&F1, "f1_14.txt", "w");
//	for (int i = 0; i < 6; i++)
//	{
//		fflush(stdin);
//		printf("Строка  %d: \n", i + 1);
//		gets_s(str);
//		fputs(str, F1);
//		fputs("\n", F1);
//	} 
//	fclose(F1);
//	err = fopen_s(&F1, "f1_14.txt", "r");
//	err = fopen_s(&F2, "f2_14.txt", "w");
//
//	while (fgets(str, 255, F1) != 0)
//	{
//		if (str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5'
//			|| str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' || str[0] == '0')
//		{
//			fputs(str, F2);
//		}
//	}
//	fclose(F1);
//	fclose(F2);
//}