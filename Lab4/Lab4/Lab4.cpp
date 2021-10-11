#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

int main();

//======================= Основа =======================

struct BankClients
{
	string name;
	string accType;
	string accNumber;
	string sum;
	string date;
};

const short N = 20;

void input(BankClients clients[])
{
	int num;
	do {
		cout << "Введите количество клиентов банка (не более " << N << "): ";
		cin >> num;
	} while (num < 1 || num > N);
	fflush(stdin);
	for (int i = 0; i < num; i++)
	{
		cout << "\tКлиент №" << i + 1 << endl;
		cout << "Введите ФИО клиента:\n";
		cin >> clients[i].name;
		cout << "Введите тип счёта:\n";
		cin >> clients[i].accType;
		cout << "Введите номер счёта:\n";
		cin >> clients[i].accNumber;
		cout << "Введите сумму на счёте:\n";
		cin >> clients[i].sum;
		cout << "Введите дату последнего изменения:\n";
		cin >> clients[i].date;
		cout << "\n\n";
	}
}

void output(BankClients clients[])
{
	int ClientNum;
	cout << "Введите номер клиента, которого вы хотите вывести:\n";
	cin >> ClientNum;
	int i = ClientNum - 1;
	cout << "\tКлиент №" << ClientNum << '\n';
	cout << "ФИО клиента: " << clients[i].name << '\n';
	cout << "Тип счёта: " << clients[i].accType << '\n';
	cout << "Номер счёта: " << clients[i].accNumber << '\n';
	cout << "Сумма на счёте: " << clients[i].sum << '\n';
	cout << "Дата последнего изменения: " << clients[i].date << "\n\n\n";
}

void deleteClient(BankClients clients[])
{
	int numCin;
	cout << "Введите порядковый номер клиента, информацию о котором Вы хотите удалить:\n";
	cin >> numCin;
	cout << '\n';
	int i = numCin - 1;
	clients[i].name = ' ';
	clients[i].accType = ' ';
	clients[i].accNumber = ' ';
	clients[i].sum = ' ';
	clients[i].date = ' ';
	cout << '\n';
}

void search(BankClients clients[])
{
	string numSearch;
	cout << "Введите номер счёта искомого клиента:\n";
	cin >> numSearch;
	for (int i = 0; i < N; i++)
	{
		if (numSearch == clients[i].accNumber)
		{
			cout << "Клиент №" << i + 1 << ": счёт №" << clients[i].name << '\n';
		}
	}
	cout << "\n\n";
}

void ofile(BankClients clients[])
{
	string buf;
	int num;
	do {
		cout << "Введите количество клиентов банка (не более " << N << "): ";
		cin >> num;
	} while (num < 1 || num > N);
	fflush(stdin);
	ofstream file1("information.txt");
	for (int i = 0; i < num; i++)
	{
		cout << "\tКлиент №" << i + 1 << '\n';
		file1 << "\tКлиент №" << i + 1 << '\n';
		cout << "Введите ФИО клиента:\n";
		file1 << "ФИО клиента: ";
		cin >> clients[i].name;
		file1 << clients[i].name;
		cout << "Введите тип счёта:\n";
		file1 << "\nТип счёта: ";
		cin >> clients[i].accType;
		file1 << clients[i].accType;
		cout << "Введите номер счёта:\n";
		file1 << "\nНомер счёта: ";
		cin >> clients[i].accNumber;
		file1 << clients[i].accNumber;
		cout << "Введите сумму на счёте:\n";
		file1 << "\nСумма на счёте: ";
		cin >> clients[i].sum;
		file1 << clients[i].sum;
		cout << "Введите дату последнего изменения:\n";
		file1 << "\nДата последнего изменения: ";
		cin >> clients[i].date;
		file1 << clients[i].date << "\n\n";
	}
	cout << "\n\n";
}

void ifile(BankClients clients[])
{
	string strInf;
	ifstream file1 ("information.txt");
	while (file1)
	{
		getline(file1, strInf);
		cout << strInf << '\n';
	}
}

void osnova()
{
	setlocale(LC_ALL, "ru");
	short choose;
	BankClients clients[N];
	do {
		cout << "Выберите, что сделать:\n1 — ввод элементов структуры с клавиатуры;\n2 — вывод элементов стуктуры в консольное окно;"
			"\n3 — удаление заданной структурированной переменной; \n4 — поиск информации; \n5 — запись информации в файл; \n6 — чтение данных из файла; \n7 — выход из программы.\n";
		cin >> choose;
		switch (choose)
		{
		case 1: input(clients); break;
		case 2: output(clients); break;
		case 3: deleteClient(clients); break;
		case 4: search(clients); break;
		case 5: ofile(clients); break;
		case 6: ifile(clients); break;
		case 7: main(); break;
		}
	} while (choose != 7);
}





//=======================  Доп 1  =======================


struct Student {
	string name;
	int maths;
	int physics;
	int english;
	int oap;
};

void exams(Student* students, int SIZE) {

	int numStudents = 0;
	for (int i = 0; i < SIZE; ++i) {

		if ((students[i].maths == 5 || students[i].maths == 4) &&
			(students[i].physics == 5 || students[i].physics == 4) &&
			(students[i].english == 5 || students[i].english == 4) &&
			(students[i].oap == 5 || students[i].oap == 4))
		{
			cout << i << ") Студент: " << students[i].name << " сдал экзамены на 4 или 5" << endl;
			numStudents++;
		}
		else cout << i << ") Студент: " << students[i].name << " не сдал экзамены на 4 или 5" << endl;
	}
	cout << "Сотношение студентов, сдавших экзамен на 4 или 5, ко всем студентам " << ((double)numStudents / (double)SIZE) * 100 << " % " << endl;
}

void displayInfo(Student* students, int SIZE) {
	for (int i = 0; i < SIZE; ++i) {
		cout << "Имя студента: " << students[i].name << endl;
		cout << "Математика: " << students[i].maths << endl;
		cout << "Физика: " << students[i].physics << endl;
		cout << "Английский: " << students[i].english << endl;
		cout << "ОАП: " << students[i].oap << endl;
		cout << "============================================" << endl;
	}
}

void  ifileStud(Student* students, int SIZE) {
	ifstream fin("studentsInfo.txt");
	if (!fin.is_open()) {
		cout << "Не удаётся открыть файл для чтения " << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < SIZE; ++i) {
		fin >> students[i].maths;
		fin >> students[i].physics;
		fin >> students[i].english;
		fin >> students[i].oap;
		fin >> students[i].name;
	}
	cout << "\nВыведена информация из файла studentsInfo.txt\n";
}

void dop1()
{
	setlocale(LC_CTYPE, "ru");
	const int SIZE = 10;
	Student students[SIZE];
	short choose;
	do {
		cout << "\nВыберите, что сделать:\n1 — проверить, сколько студентов положительно сдали экзамены;\n2 — вывести в консоль информацию о студенте;\n3 — вывести информацию из файла;\n4 — выход из программы.\n";
		cin >> choose;
		switch (choose)
		{
		case 1: exams(students, SIZE); break;
		case 2: displayInfo(students, SIZE); break;
		case 3: ifileStud(students, SIZE); break;
		case 4: main(); break;
		}
	} while (choose != 4);
}







//=======================  Доп 2  =======================


struct Train {
	string Place;// место назначения
	int NumTrain; // номер поезда
	string time; // время отбытия 
};


bool compTrain(Train lhs, Train rhs)
{
	return lhs.Place < rhs.Place;
}

void displayTrain(Train* trains, int SIZE) {
	sort(trains, trains + SIZE, compTrain); 

	for (int i = 0; i < SIZE; ++i)
	{
		cout << "Номер поезда: " << trains[i].NumTrain << "\t";
		cout << "Место прибытия: " << trains[i].Place << "\t\t";
		cout << "Время прибытия на вокзал: " << trains[i].time << "\t";
		cout << "\n========================================================================================" << endl;
	}
};

void displayTrainMode(Train* trains, int SIZE, string user_time)
{
	sort(trains, trains + SIZE, compTrain);

	if (user_time.size() > 5 || user_time.size() < 2)
	{
		cout << "Некорретная дата " << endl;
		exit(1);
	}

	istringstream x(user_time, istringstream::in);                        
	int time_user1;
	x >> time_user1;
	x.clear();

	int hours_user = time_user1 / 100; // часы 
	int minuts_user = time_user1 % 100;// минуты 

	if (hours_user < -1 || hours_user>60 || minuts_user < -1 || minuts_user >60)
	{
		cout << "Некорретная дата " << endl;
		exit(1);
	}


	cout << "Ваше время : " << hours_user << " часов, " << minuts_user << " минут " << endl;
	int all_user_time = hours_user * 60 * 60 + minuts_user * 60; //секунды с начатого дня

	vector <int> time_train;

	for (int i = 0; i < SIZE; i++)
	{
		istringstream x(trains[i].time, istringstream::in);                        
		int train_rail;
		x >> train_rail;
		int train_hours = train_rail / 100;
		int train_minuts = train_rail % 100;
		time_train.push_back((train_hours * 60 * 60) + (train_minuts * 60));
	}
	bool ones = false;

	for (int i = 0; i < SIZE; i++)
	{
		if (all_user_time < time_train[i])
		{
			cout << "Номер поезда: " << trains[i].NumTrain << "\t";
			cout << "Место прибытия: " << trains[i].Place << "\t\t";
			cout << "Время прибытия на вокзал: " << trains[i].time << "\t";
			cout << "\n========================================================================================" << endl;
			ones = true;
		}
	}
	if (ones == false)
	{
		cout << "Нет поездов." << endl;
	}
}
;

void ifileTrain(Train* trains, int SIZE)
{
	ifstream fin("trainsInfo.txt");

	if (!fin.is_open()) { 
		cout << "Не удаётся открыть файл для чтения " << endl;
		exit(EXIT_FAILURE);
	}

	vector<string> fileinfo;
	string line, word; 
	stringstream x;
	for (int i = 0; i < SIZE; ++i) {

		fin >> trains[i].NumTrain;//номер поезда 
							
		getline(fin, line); 

		x << line; // деление строки
		while (x >> word)
		{
			fileinfo.push_back(word);
		}

		for (int k = 0; k < fileinfo.size(); ++k)
		{
			if (k == 0) { trains[i].Place = fileinfo[k]; } 
			if (k == 1) { trains[i].time = fileinfo[k]; }
		}

		x.clear();
		line.clear();
		word.clear(); //очистка
		fileinfo.clear();
	}

}

void dop2()
{
	setlocale(LC_CTYPE, "rus");
	const int SIZE = 5;
	Train trains[SIZE];
	ifileTrain(trains, SIZE); 
	displayTrain(trains, SIZE);
	cout << "\nВведите дату (формат ЧЧММ): "; 
	string user_time;
	cin >> user_time;
	cout << endl;
	displayTrainMode(trains, SIZE, user_time);
}




//struct Camp {
//	string CampName;
//	string CampPlace;
//	string CampType;
//	int voucher;
//};
//
//bool comp1(Camp lhs, Camp rhs)
//{
//	return lhs.CampName < rhs.CampName;
//}
//
//bool comp(Camp lhs, Camp rhs)
//{
//	return lhs.CampType < rhs.CampType;
//}
//
//void showInfo(Camp* lager, int SIZE) {
//	sort(lager, lager + SIZE, comp);
//	int index1 = 0;
//	int index2 = 0;
//
//	for (int i = 0; i < SIZE; i++)
//	{
//		if (lager[i].CampType == lager[i + 1].CampType)
//		{
//			index1 = i;
//			break;
//		}
//	}
//
//	for (int i = SIZE; i > 0; i--)
//	{
//		if (lager[i].CampType == lager[i - 1].CampType)
//		{
//			index2 = i;
//			break;
//		}
//	}
//
//	sort(lager + index1, lager + index2 + 1, comp1);
//
//	for (int i = 0; i < SIZE; ++i) {
//		cout << "Название лагеря: " << lager[i].CampName << "\t";
//		cout << "Место лагеря: " << lager[i].CampPlace << "\t";
//		cout << "Профиль лечения: " << lager[i].CampType << "\t\t";
//		cout << "Количество путевок: " << lager[i].voucher << "\t" << endl;
//		cout << "===============================================================================================================" << endl;
//	}
//};
//
//void ifileCamp(Camp* lager, int SIZE)
//{
//
//	ifstream fin("laggerInfo.txt");
//
//	if (!fin.is_open()) {
//		cout << "Не удаётся открыть файл для чтения " << endl;
//		exit(EXIT_FAILURE);
//	}
//
//	vector<string> fileinfo;
//	string line, word;
//	stringstream x;
//	for (int i = 0; i < SIZE; ++i) {
//		fin >> lager[i].voucher;
//		getline(fin, line);
//		x << line;
//		while (x >> word)
//		{
//			fileinfo.push_back(word);
//		}
//		for (int k = 0; k < fileinfo.size(); k++)
//		{
//			if (k == 0) { lager[i].CampName = fileinfo[k]; }
//			if (k == 1) { lager[i].CampPlace = fileinfo[k]; }
//			if (k == 2) { lager[i].CampType = fileinfo[k]; }
//		}
//		x.clear();
//		line.clear();
//		word.clear();
//		fileinfo.clear();
//	}
//	cout << "\nИнформация считана из файла laggerInfo.txt\n";
//}
//
//void dop3()
//{
//	setlocale(LC_CTYPE, "ru");
//	const int SIZE = 5;
//	Camp lager[SIZE];
//	short choose;
//	do {
//		cout << "\nВыберите, что сделать:\n1 — вывести информацию из файла;\n2 — вывести в консоль информацию о путёвках;\n3 — завершение работы.\n";
//		cin >> choose;
//		switch (choose)
//		{
//		case 1: ifileCamp(lager, SIZE); break;
//		case 2: showInfo(lager, SIZE); break;
//		case 3: main(); break;
//		}
//	} while (choose != 3);
//}





//=======================  Доп 3  =======================

struct Camp {
	string CampName;
	string CampPlace;
	string CampType;
	int voucher;
};

bool comp1(Camp lhs, Camp rhs)
{
	return lhs.CampName < rhs.CampName;
}

bool comp(Camp lhs, Camp rhs)
{
	return lhs.CampType < rhs.CampType;
}

void showInfo(Camp* lagger, int SIZE) {
	sort(lagger, lagger + SIZE, comp);
	int index1 = 0;
	int index2 = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (lagger[i].CampType == lagger[i + 1].CampType)
		{
			index1 = i;
			break;
		}
	}

	for (int i = SIZE; i > 0; i--)
	{
		if (lagger[i].CampType == lagger[i - 1].CampType)
		{
			index2 = i;
			break;
		}
	}

	sort(lagger + index1, lagger + index2 + 1, comp1);


	for (int i = 0; i < SIZE; ++i) {
		cout << "Название лагеря: " << lagger[i].CampName << "\t";
		cout << "Место лагеря: " << lagger[i].CampPlace << "\t";
		cout << "Профиль лечения: " << lagger[i].CampType << "\t\t";
		cout << "Количество путевок: " << lagger[i].voucher << "\t" << endl;
		cout << "==============================================================================================================" << endl;
	}

}

void ifileCamp(Camp* lagger, int SIZE)
{

	ifstream fin("lagggerInfo.txt");

	if (!fin.is_open()) {
		cout << "Не удаётся открыть файл для чтения " << endl;
		exit(EXIT_FAILURE);
	}

	vector<string> fileinfo;
	string line, word;
	stringstream x;
	for (int i = 0; i < SIZE; ++i) {
		fin >> lagger[i].voucher;
		getline(fin, line);
		x << line;
		while (x >> word)
		{
			fileinfo.push_back(word);
		}
		for (int k = 0; k < fileinfo.size(); k++)
		{
			if (k == 0) { lagger[i].CampName = fileinfo[k]; }
			if (k == 1) { lagger[i].CampPlace = fileinfo[k]; }
			if (k == 2) { lagger[i].CampType = fileinfo[k]; }
		}
		x.clear();
		line.clear();
		word.clear();
		fileinfo.clear();
	}
	cout << "\nИнформация считана из файла lagggerInfo.txt\n\n";
}


void dop3()
{

	setlocale(LC_CTYPE, "ru");
	const int SIZE = 5;
	Camp lager[SIZE];
	short choose;
	do {
		cout << "Выберите, что сделать:\n1 — вывести информацию из файла;\n2 — вывести в консоль информацию о путёвках;\n3 — завершение работы.\n";
		cin >> choose;
		switch (choose)
		{
		case 1: ifileCamp(lager, SIZE); break;
		case 2: showInfo(lager, SIZE); break;
		case 3: exit(0); break;
		}
	} while (choose != 3);
}

//=======================  Main =======================

int main()
{
	setlocale(LC_ALL, "ru");
	short chooseM;
	cout << "Введите, какую лабораторную выполнить:\n1 — основное задание (3 вариант);\n2 — дополнительное задание №1;\n3 — дополнительное задание №2;\n4 — дополнительное задание №3;\n5 — завершение работы.\n";
	cin >> chooseM;
	switch (chooseM)
	{
	case 1: osnova(); break;
	case 2: dop1(); break;
	case 3: dop2(); break;
	case 4: dop3(); break;
	case 5: cout << "\nДо свидания!\n"; break;
	}
}