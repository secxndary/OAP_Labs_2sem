#include <iostream>
using namespace std;

const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};

void insert(Address* e, Address** phead, Address** plast);
Address* setElement();
void outputList(Address** phead, Address** plast);
void delet(char name[NAME_SIZE], Address** phead, Address** plast);
void find(char name[NAME_SIZE], Address** phead);
void writeToFile(Address** phead);
void readFromFile(Address** phead, Address** plast);
void deleteM(Address** phead, Address** plast);

int main()
{
	setlocale(LC_CTYPE, "Rus");
	Address* head = NULL;
	Address* last = NULL;
	short choose = 0;
	while (choose != 5)
	{
		char s[80];  int c;
		cout << "Выберите действие:\n1 — ввод элемента;\n2 — вывод списка;\n3 — удаление элемента;\n4 — поиск элемента;"
			"\n5 — запись в файл;\n6 — вывод из файла;\n7 — удаление каждого m-го элемента;\n8 — выход из программы.\n";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);

		switch (c)
		{
		case 1: 
			insert(setElement(), &head, &last);
			break;
		case 2:
			outputList(&head, &last);
			break;
		case 3:
			char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
			break;
		case 4:
			char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
			break;
		case 5:
			writeToFile(&head);
			break;
		case 6: 
			readFromFile(&head, &last);
			break;
		case 7: 
			deleteM(&head, &last);
			break;
		case 8: 
			cout << "До свидания!\n";
			exit(0);
		}
	}
}

void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти.\n";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}

void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени 
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено.\n" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален.\n" << endl;
	}
}

void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено.\n" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}

void writeToFile(Address** phead)       //Запись в файл
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}

void readFromFile(Address** phead, Address** plast)          //Считывание из фай-ла
{
	struct Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "Ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}

void deleteM(Address** phead, Address** plast)
{
	Address* t = *phead;
	short m, i = 0;
	cout << "Введите m:\n";
	cin >> m;

	while (t)
	{
		for (i = 0; i < m - 1; i++)
		{
			if (t->next == NULL) break;
			else
			{
				if (t->prev != *phead && t->prev != nullptr)
				{
					t->prev->next = t;
				}
				if (t->next != *plast && t->next != nullptr)
				{
					t->next->prev = t;
				}
				t = t->next;

				/*t->prev->next = t;
				t->next->prev = t;*/
			}
				
		}

		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast && t != nullptr)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}

		if (t->next == nullptr) break;
	}
}