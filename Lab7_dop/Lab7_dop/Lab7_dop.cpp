#include <iostream>
#include <fstream>
#include <string>
#include "myStack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;

	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента	

	Stack1* myStk1 = new Stack1; //выделение памяти для стека
	myStk1->head = NULL;

	Stack2* myStk2 = new Stack2; //выделение памяти для стека
	myStk2->head = NULL;

	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Очистка стека" << endl;
		cout << "5 - Удаление первого положительного элемента" << endl;
		cout << "6 - Запись в файл" << endl;
		cout << "7 - Чтение из файла" << endl;
		cout << "8 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "Извлеченный элемент: " << choice << endl;
			break;
		case 3: cout << "Весь стек: " << endl;
			show(myStk);
			break;
		case 4: clear(myStk);
			break;
		case 5: task(myStk);
			break;
		case 6: ofile(myStk);
			break;
		case 7: ifile(myStk);
			break;
		case 8: return 0;
			break;
		}
	}
	return 0;
}

void push(int x, Stack* myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}
int pop(Stack* myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
		int a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}
void show(Stack* myStk)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

void clear(Stack* myStk)
{
	Stack* e = myStk->head;
	while (e != NULL)
	{
		e->data = NULL;
		e = e->next;
	}
}

void task(Stack* myStk)
{
	Stack* e = myStk->head;
	bool stop = true;
	while (stop)
	{
		if (e->data < 0)
		{
			e = e->next;
		}
		if (e->data > 0)
		{
			e->data = NULL;
			e = e->next;
			stop = false;
		}
		else cout << "Положительных элементов нет.\n";
	}
	cout << "Первый положительный элемент удалён.\n";
}

void ifile(Stack* myStk)
{
	ifstream file1("data.txt");
	Stack* e = myStk->head;
	string line;
	while (getline(file1, line))
	{
		cout << line << endl;
	}
	file1.close();
}

void ofile(Stack* myStk)
{
	ofstream file1("data.txt");
	Stack* e = myStk->head;
	while (e)
	{
		int data = e->data;
		if (data != 0)
		{
			file1 << data << " ";
			e = e->next;
		}
	}
	file1.close();
	cout << "Стек записан в файл data.txt\n";
}
