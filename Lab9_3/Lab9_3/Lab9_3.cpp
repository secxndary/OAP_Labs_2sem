﻿#include <iostream>
using namespace std;

struct numbers
{
	char num[10];
	numbers* next;
};

char* circle(numbers*, int, int);
numbers* zapoln(int);

int main()
{
	setlocale(LC_ALL, "ru");
	int kolv;
	int k;
	cout << "Введите количество участников: ";
	cin >> kolv;
	numbers* g = zapoln(kolv);
	cout << "Введите k: ";
	cin >> k;
	cout << "Последним остался: " << circle(g, k, kolv) << endl;
	return 0;
}

numbers* zapoln(int kolv)
{
	numbers* first = nullptr;
	numbers* Head;
	numbers* nowiy;
	char a[10];
	if (kolv > 0)
	{
		nowiy = new numbers;
		Head = nowiy;
	}
	else
	{
		return first;
	}
	for (int i = 0; i < kolv; i++)
	{
		cout << "Введите порядковый номер: ";
		cin >> a;
		for (int y = 0; y < 10; y++)
		{
			if (a[y] == '\0')
			{
				nowiy->num[y] = '\0';
				break;
			}
			nowiy->num[y] = a[y];
		}
		first = nowiy;
		nowiy = new numbers;
		first->next = nowiy;
	}
	first->next = Head;
	return Head;
}

char* circle(numbers* g, int ocher, int kolv)
{
	int u = 0;
	numbers* buff;
	numbers* h = g;
	while (h->next != h)
	{
		for (int i = 0; i < ocher - 2; i++)
		{
			h = h->next;
		}
		buff = h->next;
		cout << "Удалён " << buff->num << endl;
		h->next = h->next->next;
		h = h->next;
		delete buff;
	}
	return h->num;
}