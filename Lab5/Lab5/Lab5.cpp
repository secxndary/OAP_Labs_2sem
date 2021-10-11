#include <iostream>
#include <string>
using namespace std;

// =====================================  О С Н О В А   1  =====================================

int main();
int osn1Cin();
void osn1Cout(int &kolvo);
void osn1Delete();
void osn1Search();

const int SIZE = 30;

struct Klass
{
	unsigned num : 4;
	unsigned letter : 32;
} klass;

enum Subject
{
	MATHS = 0,
	PHYSICS,
	OAP,
	ENGLISH
} subjects;

struct Pupils
{
	string surname;
	string name;
	Klass klass;
	int marks[4];
	float average;
} pupils[SIZE];

Pupils clear;

void osnova1()
{
	int kolvo;
	short choose;
	do {
		cout << "Выберите, что сделать:\n1 — ввод информации;\n2 — вывод информации;\n3 — удаление информации;\n4 — поиск информации;\n5 — выход.\n";
		cin >> choose;
		switch (choose)
		{
		case 1: kolvo = osn1Cin(); break;
		case 2: osn1Cout(kolvo); break;
		case 3: osn1Delete(); break;
		case 4: osn1Search(); break;
		case 5: main(); break;
		}
	} while (choose != 5);
}

int osn1Cin()
{
	int kolvo;
	do {
		cout << "Введите кол-во учеников (от 1 до " << SIZE << "):\n";
		cin >> kolvo;
	} while (kolvo < 1 || kolvo > SIZE);
	for (int i = 0; i < kolvo; i++)
	{
		cout << "Ученик №" << i + 1 << '\n';
		cout << "Введите фамилию:\n";
		cin >> pupils[i].surname;
		cout << "Введите имя:\n";
		cin >> pupils[i].name;
		cout << "Введите класс:\nВведите цифру класса:\n";
		int klassNum;
		cin >> klassNum;
		pupils[i].klass.num = klassNum;
		cout << "Введите букву класса:\n";
		char klassLetter;
		cin >> klassLetter;
		pupils[i].klass.letter = klassLetter;
		cout << "Введите оценки:\n";
		for (int j = 0; j < 4; j++)
		{
			cin >> pupils[i].marks[j];
		}
		pupils[i].average = (((float)pupils[i].marks[MATHS] + (float)pupils[i].marks[PHYSICS] + (float)pupils[i].marks[OAP] + (float)pupils[i].marks[ENGLISH]) / 4);
		cout << "===============================\n";
	}
	return kolvo;
}

void osn1Cout(int &kolvo)
{
	for (int i = 0; i < kolvo; i++)
	{
		cout << "Ученик №" << i + 1 << '\n';
		cout << "Фамилия: " << pupils[i].surname << '\n';
		cout << "Имя: " << pupils[i].name << '\n';
		cout << "Класс: " << pupils[i].klass.num << (char)pupils[i].klass.letter <<'\n';
		cout << "Оценки:\n";
		cout << "Математика: " << pupils[i].marks[MATHS] << '\n';
		cout << "Физика: " << pupils[i].marks[PHYSICS] << '\n';
		cout << "ОАиП: " << pupils[i].marks[OAP] << '\n';
		cout << "Английский: " << pupils[i].marks[ENGLISH] << '\n';
		cout << "Средний балл: " << pupils[i].average << '\n';
		cout << "===============================\n";
	}
}

void osn1Delete()
{
	int numDel, i;
	cout << "Введите номер ученика, которого вы хотите удалить:\n";
	cin >> numDel;
	i = numDel - 1;
	pupils[i] = clear;
	cout << "Информация очищена.\n\n";
}

void osn1Search() 
{
	string surnameSearch;
	cout << "Введите фамилию ученика, которого вы хотите найти:\n";
	cin >> surnameSearch;
	for (int i = 0; i < SIZE; i++)
	{
		if (surnameSearch == pupils[i].surname)
		{
			cout << "Ученик с фамилией " << surnameSearch << " имеет порядковый номер " << i + 1 << '\n';
		}
	}
}





// =====================================  О С Н О В А   2  =====================================

union un_Pawnshop
{
	string name;
	string product; // товар
	int price;
	int pledge; // залог
	int date;
	int term; // срок
};

struct Pawnshop
{
	string name;
	string product; // товар
	int price;
	int pledge; // залог
	int date;
	int term; // срок
} clients[SIZE];

int osn2Cin();
void osn2Cout(int &kolvo);
void osn2Search();

void osnova2()
{
	int kolvo;
	short choose;
	do {
		cout << "Выберите, что сделать:\n1 — ввод информации;\n2 — вывод информации;\n3 — поиск информации;\n4 — выход.\n";
		cin >> choose;
		switch (choose)
		{
		case 1: kolvo = osn2Cin(); break;
		case 2: osn2Cout(kolvo); break;
		case 3: osn2Search(); break;
		case 4: main(); break;
		}
	} while (choose != 4);
}

int osn2Cin()
{
	int kolvo;
	do {
		cout << "Введите кол-во клиентов (от 1 до " << SIZE << "):\n";
		cin >> kolvo;
	} while (kolvo < 1 || kolvo > SIZE);

	for (int i = 0; i < kolvo; i++)
	{
		cout << "Клиент №" << i + 1 << '\n';
		cout << "Введите контактные данные клиента:\n";
		cin >> clients[i].name;
		cout << "Введите наименование товара:\n";
		cin >> clients[i].product;
		cout << "Введите стоимость товара:\n";
		cin >> clients[i].price;
		cout << "Введите сумму залога:\n";
		cin >> clients[i].pledge;
		cout << "Введите дату сдачи:\n";
		cin >> clients[i].date;
		cout << "Введите срок хранения:\n";
		cin >> clients[i].term;
		cout << "===============================\n";
	}
	return kolvo;
}

void osn2Cout(int &kolvo)
{
	for (int i = 0; i < kolvo; i++)
	{
		cout << "Клиент №" << i + 1 << '\n';
		cout << "Конктактные данные клиента: " << clients[i].name << '\n';
		cout << "Наименование товара: " << clients[i].product << '\n';
		cout << "Стоимость залога: " << clients[i].pledge << '\n';
		cout << "Дата сдачи: " << clients[i].date << '\n';
		cout << "Срок хранения: " << clients[i].term << '\n';
		cout << "===============================\n";
	}
}

void osn2Search()
{
	string productSearch;
	cout << "Введите наименование товара, который вы хотите найти:\n";
	cin >> productSearch;
	for (int i = 0; i < SIZE; i++)
	{
		if (productSearch == clients[i].product)
		{
			cout << "Товар с наименованием " << productSearch << " имеет порядковый номер " << i + 1 << '\n';
		}
	}
}







// =====================================  Д О П   1 . 1  =====================================


#include <iostream>;
#include <string>;
#define records 30
using namespace std;
int dday, mmonth, yyear;

void add11();
void del11();
void show11();
void search11();
int decision;

struct date {
	unsigned day : 5;
	unsigned month : 7;
	unsigned year : 12;
};

enum sex {
	female = 1, male
}s;

struct citizen {
	string name;
	string surname;
	date birth;
	string adress;
	sex s;
};

citizen Person[records];
citizen empty;

int codow = 0;

void dop11() {
	setlocale(LC_CTYPE, "Russian");
	cout << "Выберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск информации по дате рождения;\n5 — выход.\n";
	cin >> decision;
	int l = 10;
	do {
		switch (decision) {
		case 1: add11(); break;
		case 2: del11(); break;
		case 3: show11(); break;
		case 4: search11(); break;
		case 5: main(); break;
		}
	} while (l > 0);
}

void add11() {
	setlocale(LC_CTYPE, "Russian");
	int o, t;
	s = female;
	if (codow < records) {
		cout << "Имя - ";
		cin >> Person[codow].name;
		cout << "Фамилия - ";
		cin >> Person[codow].surname;
		cout << "День рождения - ";
		cin >> dday;
		Person[codow].birth.day = dday;
		cout << "Месяц рождения - ";
		cin >> mmonth;
		Person[codow].birth.month = mmonth;
		cout << "Год рождения - ";
		cin >> yyear;
		Person[codow].birth.year = yyear;
		cout << "Пол(женский - 1, мужской - 2) - ";
		cin >> o;
		t = (int)s - o;
		if (t == 0) {
			Person[codow].s = female;
		}
		else {
			Person[codow].s = male;
		}
		cout << "Адрес - ";
		cin >> Person[codow].adress;
		cout << endl;

		codow++;
	}
	else {
		cout << "Вы ввели максимальное количество записей";
	}
	cout << "Выберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск информации по дате рождения;\n5 — выход.\n";
	cin >> decision;
	cout << endl;
}

void del11()
{
	setlocale(LC_CTYPE, "Russian");
	int purge;
	cout << "Введите номер записи, которую необходимо удалить:\n" << endl;
	cin >> purge;
	for (int de = (purge - 1); de < codow; de++)
		Person[de] = Person[de + 1];
	codow = codow - 1;
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск информации по дате рождения;\n5 — выход.\n";
	cin >> decision;
	cout << endl;
}

void show11() {
	setlocale(LC_CTYPE, "Russian");
	int choice;
		for (int i = 0; i < codow; i++) {
			cout << "Имя - ";
			cout << Person[i].name << endl;
			cout << "Фамилия - ";
			cout << Person[i].surname << endl;
			cout << "День рождения - ";
			cout << Person[i].birth.day << endl;
			cout << "Месяц рождения - ";
			cout << Person[i].birth.month << endl;
			cout << "Год рождения - ";
			cout << Person[i].birth.year << endl;
			cout << "Пол - ";
			cout << Person[i].s << endl;
			cout << "Адрес - ";
			cout << Person[i].adress << endl;
		}
		cout << "Выберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск информации по дате рождения;\n5 — выход.\n";
		cin >> decision;
	cout << endl;
}

void search11() {
	setlocale(LC_CTYPE, "Russian");
	int yo;
	cout << "Введите год, по которому следует осуществить поиск: ";
	cin >> yo;
	for (int i = 0; i < codow; i++) {
		if (yo == Person[i].birth.year) {
			cout << "Имя - ";
			cout << Person[i].name << endl;
			cout << "Фамилия - ";
			cout << Person[i].surname << endl;
			cout << "День рождения - ";
			cout << Person[i].birth.day << endl;
			cout << "Месяц рождения - ";
			cout << Person[i].birth.month << endl;
			cout << "Год рождения - ";
			cout << Person[i].birth.year << endl;
			cout << "Пол - ";
			cout << Person[i].s << endl;
			cout << "Адрес - ";
			cout << Person[i].adress << endl << endl;
		}
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск информации по дате рождения;\n5 — выход.\n";
	cin >> decision;
	cout << endl;
}









// =====================================  Д О П   1 . 2  =====================================


#include <iostream>
#include <string>
#define num 30
#define len 30
using namespace std;


void add12();
void show12();
void find12();

union un_vehicle
{
	int number;
	string destination;
	string days;
	string departure;
	string arrival;
};

struct vehicle {
	int number;
	string destination;
	char days[len];
	char departure[len];
	char arrival[len];
} Train[num];


int cou = 0;

void dop12() {
	setlocale(LC_CTYPE, "Russian");
	cout << "Выберите, что сделать:\n1 — ввод информации;\n2 — вывод информации;\n3 — поиск информации;\n4 — выход.\n";
	cin >> decision;
	int l = 10;
	do {
		switch (decision) {
		case 1: add12(); break;
		case 2: show12(); break;
		case 3: find12(); break;
		case 4: main(); break;
		default: break;
		}
	} while (l > 0);
}


void add12() {
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите\n";
	if (cou < num) {
		cout << "Номер поезда - ";
		cin >> Train[cou].number;
		cout << "Пункт назначения - ";
		cin >> Train[cou].destination;
		cout << "Дни следования - ";
		cin >> Train[cou].days;
		cout << "Время отправления - ";
		cin >> Train[cou].departure;
		cout << "Время прибытия - ";
		cin >> Train[cou].arrival;
		cou++;
	}
	else {
		cout << "Введено максимальное количество записей. ";
	};
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — вывод информации;\n3 — поиск информации;\n4 — выход.\n";
	cin >> decision;
	cout << endl;
}

void show12() {
	int choice;
	setlocale(LC_CTYPE, "Russian");
		for (int i = 0; i < cou;) {
			cout << "Номер поезда - ";
			cout << Train[i].number << endl;
			cout << "Пункт назначения - ";
			cout << Train[i].destination << endl;
			cout << "Дни следования - ";
			cout << Train[i].days << endl;
			cout << "Время отправления - ";
			cout << Train[i].departure << endl;
			cout << "Время прибытия - ";
			cout << Train[i].arrival << endl;
			i++;
		}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — вывод информации;\n3 — поиск информации;\n4 — выход.\n";
	cin >> decision;
	cout << endl;
}

void find12() {
	string search;
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите, по какому пункту назначения необходимо осуществить поиск: ";
	cin >> search;
	for (int i = 0; i < cou; i++) {
		if (Train[i].destination == search) {
			cout << "Номер поезда - ";
			cout << Train[i].number << endl;
			cout << "Пункт назначения - ";
			cout << Train[i].destination << endl;
			cout << "Дни следования - ";
			cout << Train[i].days << endl;
			cout << "Время отправления - ";
			cout << Train[i].departure << endl;
			cout << "Время прибытия - ";
			cout << Train[i].arrival << endl;
		}
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — вывод информации;\n3 — поиск информации;\n4 — выход.\n";
	cin >> decision;
	cout << endl;
}










// =====================================  Д О П   2 . 1  ===================================== (6)


#define size 30

int decision21;
int dday21, mmonth21;

void add21();
void del21();
void show21();
void search21();

struct date21 {
	unsigned day : 5;
	unsigned month : 7;
};

enum faculty {
	IT = 1, Economy, HTiT, PIM, LesHoz, LesInzh
} fa;

struct Students {
	string snp;
	date21 entrance;
	string speciality;
	int group;
	faculty fa;
	float aver;
} student[size], zero;

int codow21 = 0;

int dop21() {
	setlocale(LC_ALL, "Russian");
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по среднему баллу;\n5 — выход.\n";
	cin >> decision;
	do {
		switch (decision) {
		case 1: add21(); break;
		case 2: del21(); break;
		case 3: show21(); break;
		case 4: search21(); break;
		case 5: main(); break;
		}
	} while (true);
}

void add21() {
	int o, t;
	fa = IT;
	if (codow21 < size) {
		cout << "ФИО - ";
		cin >> student[codow21].snp;
		cout << "День поступления - ";
		cin >> dday21;
		student[codow21].entrance.day = dday21;
		cout << "Месяц поступления - ";
		cin >> mmonth21;
		student[codow21].entrance.month = mmonth21;
		cout << "Специальность - ";
		cin >> student[codow21].speciality;
		cout << "Группа - ";
		cin >> student[codow21].group;
		cout << "Введите название факультета (ФИТ - 1, Экономический - 2, ХТиТ - 3, ПИМ - 4, ЛесХоз - 5, ЛесИнж - 6): ";
		cin >> o;
		switch (o) {
		case 1: student[codow21].fa = IT;
		case 2: student[codow21].fa = Economy;
		case 3: student[codow21].fa = HTiT;
		case 4: student[codow21].fa = PIM;
		case 5: student[codow21].fa = LesHoz;
		case 6: student[codow21].fa = LesInzh;
		}
		cout << "Средний балл - ";
		cin >> student[codow21].aver;

		codow21++;
	}
	else {
		cout << "Вы ввели максимальное количество записей";
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по среднему баллу;\n5 — выход.\n";
	cin >> decision;
	cout << endl;
}

void del21() {
	int purge;
	cout << "Введите номер записи, которую необходимо удалить: " << endl;
	cin >> purge;
	for (int de = (purge - 1); de < codow21; de++)
		student[de] = student[de + 1];
	codow21 = codow21 - 1;
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по среднему баллу;\n5 — выход.\n";
	cin >> decision;
	cout << endl;
}

void show21() {
	int choice;
	int no;
		for (int i = 0; i < codow21; i++) {
			cout << "\nФИО - ";
			cout << student[i].snp << endl;
			cout << "День поступления - ";
			cout << student[i].entrance.day << endl;
			cout << "Месяц поступления - ";
			cout << student[i].entrance.month << endl;
			cout << "Специальность - ";
			cout << student[i].speciality << endl;
			cout << "Группа - ";
			cout << student[i].group << endl;
			cout << "Название факультета - ";

			if (student[i].fa == 1) cout << "ФИТ\n";
			if (student[i].fa == 2) cout << "Экономический\n";
			if (student[i].fa == 3) cout << "ХТиТ\n";
			if (student[i].fa == 4) cout << "ПИМ\n";
			if (student[i].fa == 5) cout << "ЛесХох\n";
			if (student[i].fa == 6) cout << "ЛесИнж\n";

			cout << "Средний балл - ";
			cout << student[i].aver << endl;
		}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по среднему баллу;\n5 — выход.\n";
	cin >> decision;
	cout << endl;
}

void search21() {
	int sr;
	cout << "Введите средний балл, по которому следует осуществить поиск - ";
	cin >> sr;
	for (int i = 0; i < codow21; i++) {
		if (sr == student[i].aver) {
			cout << "ФИО - ";
			cout << student[i].snp << endl;
			cout << "День поступления - ";
			cout << student[i].entrance.day << endl;
			cout << "Месяц поступления - ";
			cout << student[i].entrance.month << endl;
			cout << "Специальность - ";
			cout << student[i].speciality << endl;
			cout << "Группа - ";
			cout << student[i].group << endl;
			cout << "Название факультета - ";
			cout << student[i].fa << endl;
			cout << "Средний балл - ";
			cout << student[i].aver << endl;
		}
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по среднему баллу;\n5 — выход.\n";
	cin >> decision;
	cout << endl;
}








// ==========================================  Д О П   2 . 2  ========================================== (1)


#define len 30
int day, month;

using namespace std;

void add22();
void show22();
void search22();

enum capital
{
	Moscow = 1, Warsaw, NurSultan, Minsk
} cap;

struct Country {
	string title;
	string president_surname;
	int population;
	int area;
	capital cap;
} country[len];

union un_Country {
	char title[len];
	char president_surname[len];
	int population;
	int area;
	capital cap;
} un_country;


int decision22;
int codow22 = 0;

void dop22() {
	setlocale(LC_CTYPE, "Russian");
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — вывод информации;\n3 — поиск информации;\n4 — выход.\n";
	cin >> decision22;
	do {
		switch (decision22) {
		case 1: add22(); break;
		case 2: show22(); break;
		case 3: search22(); break;
		case 4: main(); break;
		}
	} while (decision22 != 4);
}

void add22() {
	int o, t;
	cap = Moscow;
	if (codow22 < len) {
		cout << "Введите название страны (Россия - 1, Польша - 2, Казахстан - 3, Беларусь - 4) - ";
		cin >> un_country.title;
		country[codow22].title = un_country.title;
		cout << "Столица (Москва - 1, Варшава - 2, Нур-Султан - 3, Минск - 4) - ";
		cin >> o;
		t = (int)cap - o;
		if (t == 0) {
			country[codow22].cap = Moscow;
		}
		else if (t == 1) {
			country[codow22].cap = Warsaw;
		}
		else if (t == 2) {
			country[codow22].cap = NurSultan;
		}
		else {
			country[codow22].cap = Minsk;
		}
		cout << "Фамилия президента - ";
		cin >> un_country.president_surname;
		country[codow22].president_surname = un_country.president_surname;
		cout << "Численность -  ";
		cin >> un_country.population;
		country[codow22].population = un_country.population;
		cout << "Площадь - ";
		cin >> un_country.area;
		country[codow22].area = un_country.area;

		codow22++;
	}
	else {
		cout << "Вы ввели максимальное количество записей";
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — вывод информации;\n3 — поиск информации;\n4 — выход.\n";
	cin >> decision22;
	cout << endl;
}

void show22() {
	for (int i = 0; i < codow22; i++)
	{
		cout << "Название - ";
		if (country[i].title == "1") cout << "Россия\n";
		if (country[i].title == "2") cout << "Польша\n";
		if (country[i].title == "3") cout << "Казахстан\n";
		if (country[i].title == "4") cout << "Беларусь\n";
		cout << "Столица - ";
		if (country[i].cap = Moscow) cout << "Москва";
		else if (country[i].cap = Warsaw) cout << "Варшава";
		else if (country[i].cap = NurSultan) cout << "Нур-Султан";
		else if (country[i].cap = Minsk) cout << "Минск";
		cout << "\nФамилия президента - ";
		cout << country[i].president_surname << endl;
		cout << "Численность -  ";
		cout << country[i].population << endl;
		cout << "Площадь - ";
		cout << country[i].area << endl;
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — вывод информации;\n3 — поиск информации;\n4 — выход.\n";
	cin >> decision22;
	cout << endl;
}

void search22() {
	string yo;
	cout << "Введите название страны, по которой следует осуществить поиск - ";
	cin >> yo;
	for (int i = 0; i < codow22; i++) {
		string p = country[i].title;
		if (yo == country[i].title) {
			cout << "Название - ";
			cout << country[i].title << endl;
			cout << "Столица - ";
			cout << country[i].cap << endl;
			cout << "Фамилия президента - ";
			cout << country[i].president_surname << endl;
			cout << "Численность -  ";
			cout << country[i].population << endl;
			cout << "Площадь - ";
			cout << country[i].area << endl;
		}
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — вывод информации;\n3 — поиск информации;\n4 — выход.\n";
	cin >> decision22;
	cout << endl;
}










// ==========================================  Д О П   3 . 1  ==========================================


void add31();
void del31();
void show31();
void search31();
int decision31;


enum origin {
	purchase = 1, theft, gift
} orig;

struct library {
	string author;
	string title;
	string press;
	string availability;
	origin orig;
	int year;
} Book[records], zeroo;

int codow31 = 0;

void dop31() {
	setlocale(LC_CTYPE, "Russian");
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision31;
	do {
		switch (decision31) {
		case 1: add31(); break;
		case 2: del31(); break;
		case 3: show31(); break;
		case 4: search31(); break;
		case 5: main(); break;
		}
	} while (decision31 != 5);
}

void add31() {
	setlocale(LC_CTYPE, "Russian");
	int o, t;
	orig = purchase;
	if (codow31 < records) {
		cout << "Автор - ";
		cin >> Book[codow31].author;
		cout << "Название - ";
		cin >> Book[codow31].title;
		cout << "Издательство (МАНН - 1, Зарубежная Классика - 2, ЭКСМО - 3, Jellyfish - 4): ";
		cin >> Book[codow31].press;
		cout << "Наличие - ";
		cin >> Book[codow31].availability;
		cout << "Происхождение (Покупка - 1, кража - 2, подарок - 3): ";
		cin >> o;
		t = (int)orig - o;
		if (t == 0) {
			Book[codow31].orig = purchase;
		}
		else if (t == 1) {
			Book[codow31].orig = theft;
		}
		else {
			Book[codow31].orig = gift;
		}
		cout << "Год издательства: ";
		cin >> Book[codow31].year;

		codow31++;
	}
	else {
		cout << "Вы ввели максимальное количество записей";
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision31;
	cout << endl;
}

void del31()
{
	int purge = 1;
	setlocale(LC_CTYPE, "Russian");
	for (int de = (purge - 1); de < codow31; de++)
		Book[de] = Book[de + 1];
	codow31 = codow31 - 1;
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision31;
	cout << endl;
}

void show31() {
	setlocale(LC_CTYPE, "Russian");
	for (int i = 0; i < codow31; i++)
	{
		cout << "Автор - ";
		cout << Book[i].author << endl;
		cout << "Название - ";
		cout << Book[i].title << endl;
		cout << "Издательство - ";
		if (Book[i].press == "1") cout << "МАНН\n";
		if (Book[i].press == "2") cout << "Зарубажная классика\n";
		if (Book[i].press == "3") cout << "ЭКСМО\n";
		if (Book[i].press == "4") cout << "Jellyfish\n";
		cout << "Наличие - ";
		cout << Book[i].availability << endl;
		cout << "Происхождение - ";
		if (Book[i].orig = purchase) cout << "покупка\n";
		else if (Book[i].orig =  theft) cout << "кража\n";
		else if (Book[i].orig = gift) cout << "подарок\n";
		cout << "Год издательства: ";
		cout << Book[i].year << endl;
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision31;
	cout << endl;
}

void search31() {
	setlocale(LC_CTYPE, "Russian");
	int yo;
	cout << "Введите год, по которому следует осуществить поиск - ";
	cin >> yo;
	for (int i = 0; i < codow31; i++) {
		if (yo == Book[i].year) {
			cout << "Автор - ";
			cout << Book[i].author << endl;
			cout << "Название - ";
			cout << Book[i].title << endl;
			cout << "Издательство - ";
			cout << Book[i].press << endl;
			cout << "Наличие - ";
			cout << Book[i].availability << endl;
			cout << "Происхождение - ";
			cout << Book[i].orig << endl;
			cout << "Год издательства: ";
			cout << Book[i].year << endl;
		}
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision31;
	cout << endl;
}









// ==========================================  Д О П   3 . 2  ==========================================

void add32();
void del32();
void show32();
void search32();

int decision32;


enum origin32 {
	purchase32 = 1, theft32, gift32
} orig32;

struct library32 {
	string author;
	string title;
	string press;
	string availability;
	origin orig;
	int year;
} book[records], zero32;

union un_library {
	char author[len];
	char title[len];
	char press[len];
	char availability[len];
	origin orig[len];
	int year;
} un_book;

int codow32 = 0;

void dop32() {
	setlocale(LC_ALL, "russian");
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision32;
	do {
		switch (decision32) {
		case 1: add32(); break;
		case 2: del32(); break;
		case 3: show32(); break;
		case 4: search32(); break;
		case 5: main(); break;
		}
	} while (decision32 != 5);
}

void add32() {
	setlocale(LC_ALL, "russian");
	int o, t;
	orig32 = purchase32;
	if (codow32 < records) {
		cout << "Автор - ";
		cin >> un_book.author;
		book[codow32].author = un_book.author;
		cout << "Название - ";
		cin >> un_book.title;
		book[codow32].title = un_book.title;
		cout << "Издательство (МАНН - 1, Зарубежная Классика - 2, ЭКСМО - 3, Jellyfish - 4): ";
		cin >> un_book.press;
		book[codow32].press = un_book.press;
		cout << "Наличие - ";
		cin >> un_book.availability;
		book[codow32].availability = un_book.availability;
		cout << "Происхождение (покупка - 1, кража - 2, подарок - 3): ";
		cin >> o;
		t = (int)orig - o;
		if (t == 0) {
			book[codow32].orig = purchase;
		}
		else if (t == 1) {
			book[codow32].orig = theft;
		}
		else {
			book[codow32].orig = gift;
		}
		cout << "Год издательства: ";
		cin >> un_book.year;
		book[codow32].year = un_book.year;

		codow32++;
	}
	else {
		cout << "Вы ввели максимальное количество записей";
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision32;
	cout << endl;
}

void del32()
{
	setlocale(LC_ALL, "russian");
	int purge = 1;
	for (int de = (purge - 1); de < codow32; de++)
		book[de] = book[de + 1];
	codow32 = codow32 - 1;
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision32;
	cout << endl;
}

void show32() {
	setlocale(LC_ALL, "russian");
	for (int i = 0; i < codow32; i++)
	{
		cout << "Автор - ";
		cout << book[i].author << endl;
		cout << "Название - ";
		cout << book[i].title << endl;
		cout << "Издательство - ";
		if (book[i].press == "1") cout << "МАНН\n";
		else if (book[i].press == "2") cout << "Зарубажная классика\n";
		else if (book[i].press == "3") cout << "ЭКСМО\n";
		else if (book[i].press == "4") cout << "Jellyfish\n";
		cout << "Наличие - ";
		cout << book[i].availability << endl;
		cout << "Происхождение - ";
		if (book[i].orig = purchase) cout << "покупка\n";
		else if (book[i].orig = theft) cout << "кража\n";
		else if (book[i].orig = gift) cout << "подарок\n";
		cout << "Год издательства: ";
		cout << book[i].year << endl;
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision;
	cout << endl;
}

void search32() {
	setlocale(LC_ALL, "russian");
	int yo;
	cout << "Введите год, по которому нужно искать: ";
	cin >> yo;
	for (int i = 0; i < codow32; i++) {
		if (yo == book[i].year) {
			cout << "Автор - ";
			cout << book[i].author << endl;
			cout << "Название - ";
			cout << book[i].title << endl;
			cout << "Издательство - ";
			if (book[i].press == "1") cout << "МАНН\n";
			else if (book[i].press == "2") cout << "Зарубажная классика\n";
			else if (book[i].press == "3") cout << "ЭКСМО\n";
			else if (book[i].press == "4") cout << "Jellyfish\n";
			cout << "Наличие - ";
			cout << book[i].availability << endl;
			cout << "Происхождение - ";
			if (book[i].orig = purchase) cout << "покупка\n";
			else if (book[i].orig = theft) cout << "кража\n";
			else if (book[i].orig = gift) cout << "подарок\n";
			cout << "Год издательства: ";
			cout << book[i].year << endl;
		}
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision32;
	cout << endl;
}








// ==========================================  M A I N  ==========================================


int main()
{
	setlocale(LC_ALL, "ru");
	short choose;
	do {
		cout << "Выберите задание лабораторной:\n1 — основа 1;\n2 — основа 2;\n3 — доп 1.1;\n4 — доп 1.2;\n5 — доп 2.1;\n6 — доп 2.2;\n7 — доп 3.1;\n8 — доп 3.2;\n9 — завершение работы.\n";
		cin >> choose;
		switch (choose)
		{
		case 1: osnova1(); break;
		case 2: osnova2(); break;
		case 3: dop11(); break;
		case 4: dop12(); break;
		case 5: dop21(); break;
		case 6: dop22(); break;
		case 7: dop31(); break;
		case 8: dop32(); break;
		case 9: cout << "До свидания!\n"; exit(0); break;
		}
	} while (choose != 9);
}