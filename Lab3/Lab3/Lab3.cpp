#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Основа 1: скопировать с k до k+3; гласные

int main()
{
	setlocale(LC_ALL, "ru");
	int k, num = 0, counter = 0;
	cout << "Введите, с какой строки копировать:\n";
	cin >> k;
	int k1 = k + 3;
	string str;
	ifstream file1("fileMain1_1.txt");
	ofstream file2("fileMain1_2.txt");
	k--;
	k1--;
	while (getline(file1, str))
	{
		if (num >= k && num <= k1)
		{
			file2 << str << '\n';
			for (int j = 0; j < 8; j++)
			{
				if (str[j] == 'a' || str[j] == 'o' || str[j] == 'e' || str[j] == 'y' || str[j] == 'u' || str[j] == 'i')
					counter++;
			}
		}
		num++;
	}
	cout << counter << " гласных букв.\n";
}

//Основа 2: прочитать строку,записать в другой файл полностью

//string fileInput1(string* pStrIn)
//{
//	ofstream file1_input("fileMain2_1.txt");
//	file1_input << *pStrIn; //запись строки с консоли в файл
//	file1_input.close();
//	return *pStrIn;
//}
//
//string fileOutput1(string *pStrOut)
//{
//	ifstream file1_output("fileMain2_1.txt");
//	getline(file1_output, *pStrOut); //получение строки из файла и вывод в консоль
//	file1_output.close();
//	return *pStrOut;
//}
//
//string fileInput2(string *pStrOut)
//{
//	ofstream file2_input("fileMain2_2.txt");
//	file2_input << *pStrOut; // запись строки strOut во второй файл
//	return *pStrOut;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	string strIn, strOut;
//	string* pStrOut = &strOut;
//	cout << "Введите строку с цифрами и пробелами:\n";
//	getline(cin, strIn);
//	string* pStrIn = &strIn;
//	fileInput1(pStrIn);
//	fileOutput1(pStrOut);
//	cout << "В файле записана строка: " << *pStrOut << endl;
//	fileInput2(pStrOut);
//}

//Доп 1_1 (Вариант 2): скопировать в файл строки с 'а'

//int main()
//{
//	setlocale(LC_ALL, "ru");
//	int k, num = 0, counter = 0;
//	string str;
//	ifstream file1("file2_1_1.txt");
//	ofstream file2("file2_1_2.txt");
//	while (getline(file1, str))
//	{
//		if(str[0] == 'a' || str[0] == 'A')
//		{
//			file2 << str << '\n';
//		}
//	}
//}

//Доп 1_2 (Вариант 2): вывести в консоль самую короткую группу

//string fileOut(string *pStrOut)
//{
//	ofstream file1("file2_2_1.txt");
//	file1 << *pStrOut;
//	file1.close();
//	return *pStrOut;
//}
//
//string fileIn(string* pStrIn)
//{
//	string StrIn, min = "0000000";
//	ifstream file2("file2_2_1.txt");
//	while (file2)
//	{
//		file2 >> StrIn;
//		if (StrIn.length() < min.length())
//			min = StrIn;
//	}
//	cout << "Самая короткая группа: " << min << '\n';
//	file2.close();
//	return min;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	string strOut, strIn;
//	string* pStrOut = &strOut, * pStrIn = &strIn;
//	cout << "Введите группы цифр, разделенные пробелом:\n";
//	getline(cin, strOut);
//	fileOut(pStrOut);
//	fileIn(pStrIn);
//}

//Доп 2_1 (Вариант 6): копировать с n по k; гласные

//int main()
//{
//	setlocale(LC_ALL, "ru");
//	int n, k, num = 0, counter = 0;
//	cout << "Введите, с какой строки копировать:\n";
//	cin >> n;
//	cout << "Введите, до какой строки копировать:\n";
//	cin >> k;
//	string str;
//	ifstream file1("file6_1_1.txt");
//	ofstream file2("file6_1_2.txt");
//	k--;
//	n--;
//	while (getline(file1, str))
//	{
//		if (num >= n && num <= k)
//		{
//			file2 << str << '\n';
//			for (int j = 0; j < 8; j++)
//			{
//				if (str[j] == 'q' || str[j] == 'w' || str[j] == 'r' || str[j] == 't' || str[j] == 'p' || str[j] == 's' || str[j] == 'd' || str[j] == 'f' ||
//					str[j] == 'g' || str[j] == 'h' || str[j] == 'j' || str[j] == 'k' || str[j] == 'l' || str[j] == 'z' || str[j] == 'x' || str[j] == 'c' ||
//					str[j] == 'v' || str[j] == 'b' || str[j] == 'n' || str[j] == 'm')
//					counter++;
//			}
//		}
//		num++;
//	}
//	cout << counter << " согласных букв.\n";
//}

//Доп 2_2 (Вариант 6): вывести строку с четной длиной nl

//string fileOut(string *pStrOut)
//{
//	ofstream file1("file6_2_1.txt");
//	file1 << *pStrOut;
//	file1.close();
//	return *pStrOut;
//}
//
//string fileIn(string* pStrIn)
//{
//	string StrIn;
//	ifstream file2("file6_2_1.txt");
//	while (file2)
//	{
//		file2 >> StrIn;
//		if (StrIn.length() % 2 == 0)
//			cout << StrIn << '\n';
//	}
//	file2.close();
//	return StrIn;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	string strOut, strIn;
//	string* pStrOut = &strOut, * pStrIn = &strIn;
//	cout << "Введите группы цифр, разделенные пробелом:\n";
//	getline(cin, strOut);
//	fileOut(pStrOut);
//	fileIn(pStrIn);
//}

//Доп 3_1 (Вариант 9): строки с 'c' между n1 и n2 

//int main()
//{
//	setlocale(LC_ALL, "ru");
//	int n1, n2, num = 0, counter = 0;
//	string str;
//	cout << "Введите, с какой строки копировать:\n";
//	cin >> n1;
//	cout << "Введите, до какой строки копировать:\n";
//	cin >> n2;
//	ifstream file1("file9_1_1.txt");
//	ofstream file2("file9_1_2.txt");
//	n1--;
//	n2--;
//	while (getline(file1, str))
//	{
//		if (num >= n1 && num <= n2)
//		{
//			if (str[0] == 'C' || str[0] == 'c')
//			{
//				file2 << str << '\n';
//				for (int i = 0; i < str.length(); i++)
//				{
//					if (str[i] == ' ')
//					{
//						counter++;
//					}
//				}
//			}
//		}
//		num++;
//	}
//	cout << "В первой строке второго файла " << ++counter << " слова.\n";
//}

// Доп 3_2 (Вариант 9): порядковый номер слова макс длины

//string fileOut(string *pStrOut)
//{
//	ofstream file1("file9_2_1.txt");
//	file1 << *pStrOut;
//	file1.close();
//	return *pStrOut;
//}
//
//string fileIn(string* pStrIn)
//{
//	string StrIn, min = "0000000";
//	short counter = 1, SequenceNum;
//	ifstream file2("file9_2_1.txt");
//	while (file2)
//	{
//		file2 >> StrIn;
//		if (StrIn.length() < min.length())
//		{
//			min = StrIn;
//			SequenceNum = counter;
//		}
//		counter++;
//	}
//	cout << "Порядковый номер самого короткого слова: " << SequenceNum << '\n';
//	file2.close();
//	return StrIn;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	string strOut, strIn;
//	string* pStrOut = &strOut, * pStrIn = &strIn;
//	cout << "Введите группы цифр, разделенные пробелом:\n";
//	getline(cin, strOut);
//	fileOut(pStrOut);
//	fileIn(pStrIn);
//}