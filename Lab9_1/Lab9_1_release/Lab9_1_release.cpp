//Клиенты банка. Ф.И.О., тип счета (срочный, льготный и т. д.), номер счета, сумма на счете, дата последнего изменения. Выбор по номеру счета.



#include "List.h"
#include <iostream>
using namespace std;

struct BankClients
{
	string name;
	string accType;
	string accNumber;
	string sum;
	string date;

	BankClients* next;
};

void print(void* b)       //Функция используется при выводе 
{
	BankClients* a = (BankClients*)b;
	cout << a->name << " " << a->accType << " " << a->accNumber << " " << a->sum << " " << a->date << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	BankClients a1 = { "Александр", "льготный", "№42552371267", "$12837", "12.09.2019" };
	BankClients a2 = { "Дмитрий", "льготный", "№425519378472", "$1092", "10.11.2020" };
	BankClients a3 = { "Анастасия", "срочный", "№4255237127", "$945", "23.03.2021" };
	Object L1 = Create();
	L1.Insert(&a3);
	L1.Insert(&a2);
	L1.Insert(&a1);
	bool rc;
	int c, n;
	do {
		cout << "Выберите, что сделать:" << endl;
		cout << "1 - вывести список и кол-во элементов;" << endl;
		cout << "2 - найти элемент;" << endl;
		cout << "3 - удалить элемент;" << endl;
		cout << "4 - удаление списка;" << endl;
		cout << "5 - выход." << endl;
		cin >> c;
		switch (c)
		{
		case 1:
			L1.PrintList(print);
			break;
		case 2: {
			cout << "Сделайте выбор:" << endl;
			cout << "1 элемент:" << endl;
			cout << "2 элемент:" << endl;
			cout << "3 элемент:" << endl;
			cin >> n;
			switch (n) {
			case 1: {
				Element* e = L1.Search(&a1);
				BankClients* aa = (BankClients*)e->Data;
				cout << "Счёт клиента №1: " << aa->accNumber << endl; }
				  break;
			case 2: {
				Element* e = L1.Search(&a2);
				BankClients* aa = (BankClients*)e->Data;
				cout << "Счёт клиента №2: " << aa->accNumber << endl; }
				  break;
			case 3: {
				Element* e = L1.Search(&a3);
				BankClients* aa = (BankClients*)e->Data;
				cout << "Счёт клиента №3: " << aa->accNumber << endl; }break;
			}break;
		}
		case 3: {

			cout << "Сделайте выбор:" << endl;
			cout << "1 элемент:" << endl;
			cout << "2 элемент:" << endl;
			cout << "3 элемент:" << endl;
			int o;
			cin >> o;
			switch (o) {
			case 1: rc = L1.Delete(&a1);
				if (rc == true) cout << "Удален элемент №1." << endl;
				break;
			case 2:rc = L1.Delete(&a2);
				if (rc == true) cout << "Удален элемент №2." << endl;
				break;
			case 3: rc = L1.Delete(&a3);
				if (rc == true) cout << "Удален элемент №3." << endl;
				break;
			}break;
			cout << "Список:" << endl;
			L1.PrintList(print);
			return 0;
		}
		case 4:
			rc = L1.Delete(&a1);
			rc = L1.Delete(&a2);
			rc = L1.Delete(&a3);
			break;
		case 5: cout << "До свидания!"; exit(0);
		}
	} while (c != 5);
}