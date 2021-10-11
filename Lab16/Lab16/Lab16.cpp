#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

int main()
{
	short choose = 0;
	setlocale(LC_ALL, "ru");

	while (choose != 5)
	{
		cout << "\n========================================\n";
		cout << "\t   Выберите задание:\n\t1 — основа;\n\t2 — 1 доп (4 вариант);\n\t3 — 2 доп (5 вариант);"
			"\n\t4 — 3 доп (1 вариант);\n\t5 — выход из программы.";
		cout << "\n========================================\n";

		cin >> choose;
		switch (choose)
		{
			case 1: osnova(); break;
			case 2: dop1(); break;
			case 3: dop2(); break;
			case 4: dop3(); break;
			case 5: cout << "\nДо свидания!\n"; exit(0);
		}
	}
}