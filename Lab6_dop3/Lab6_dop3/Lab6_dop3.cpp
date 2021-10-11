
// ===================================================== ВАРИАНТ 9 =====================================================

#include <iostream>
#include <fstream>
using namespace std;

struct list
{
    float number;
    list* next;
};

short insert(list*&, float);//функция добавления элемента, передается адрес списка и символ, который добавляется 
float del(list*&, float);   //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
void printList(list*);      //функция вывода
void menu(void);            //функция, показывающая меню
void average(list*, short); //функция подсчета суммы положительных чисел
void toFile(list*&);        //функция записи в файл
void fromFile(list*&);      //функция считывания из файла
short search(list*&, float, short);//функция поиска элемента

int main()
{
    setlocale(LC_CTYPE, "Russian");
    list* first = NULL;
    int choice;
    float value;
    short size = 0;
    menu();    // вывести меню 
    cin >> choice;
    while (choice != 7)
    {
        switch (choice)
        {
        case 1:
            cout << "Введите число: "; // добавить число в список
            cin >> value;
            insert(first, value);
            printList(first);
            size++;
            break;
        case 2:
            if (!IsEmpty(first)) // удалить число из списка
            {
                cout << "Введите удаляемое число: ";
                cin >> value;
                if (del(first, value))
                {
                    cout << "Удалено число " << value << endl;
                    printList(first);
                }
                else cout << "Число не найдено." << endl;
            }
            else cout << "Список пуст." << endl;
            break;
        case 3: average(first, size);	// вычисление суммы	
            break;
        case 4: if (!IsEmpty(first))
        {
            cout << "Введите число, которое ищете: ";
            cin >> value;
            search(first, value, size);
            break;
        }
        case 5: toFile(first);
            break;
        case 6: fromFile(first);
            break;
        default: cout << "Неправильный выбор." << endl;
            menu();
            break;
        }
        cout << "Выберите, что сделать дальше:\n";
        cin >> choice;
    }
    cout << "До свидания!" << endl;
    return 0;
}

void menu(void)  //Вывод меню 
{
    cout << "Выберите,что сделать:" << endl;
    cout << "1 - Ввод числа" << endl;
    cout << "2 - Удаление числа" << endl;
    cout << "3 - Вычисление среднего арифметического отрицательных чисел" << endl;
    cout << "4 - Поиск элемента" << endl;
    cout << "5 - Запись в файл" << endl;
    cout << "6 - Чтение из файла" << endl;
    cout << "7 - Выход" << endl;

}


short insert(list*& p, float value) //Добавление числа value в список 
{
    list* newP = new list;
    if (newP != NULL)     //есть ли место?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена." << endl;
    return 0;
}

float del(list*& p, float value)  // Удаление числа 
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next;    // отсоединить узел 
        delete temp;      //освободить отсоединенный узел 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // перейти к следующему 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            free(temp);
            return value;
        }
    }
    return 0;
}

int IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
{
    return p == NULL;
}



void printList(list* p)  //Вывод списка 
{
    if (p == NULL)
        cout << "Список пуст." << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void average(list* p, short size)  // Подсчет среднего отрицательныъ элементов
{
    float sm = 0;
    if (p == NULL)
        cout << "Отрицательных элементов нет." << endl;
    else
    {
        while (p != NULL)
        {
            int num = p->number;
            if (num < 0)
                sm += num;
            p = p->next;
        }
        cout << "Среднее арифметическое отрицательных элементов: " << sm/size << endl;
    }
}


void toFile(list*& p)
{
    list* temp = p;
    list buf;
    ofstream frm("mList.dat");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (temp)
    {
        buf = *temp;
        frm.write((char*)&buf, sizeof(list));
        temp = temp->next;
    }
    frm.close();
    cout << "Список записан в файл mList.dat\n";
}


void fromFile(list*& p)          //Считывание из файла
{
    list buf, * first = nullptr;
    ifstream frm("mList.dat");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    frm.read((char*)&buf, sizeof(list));
    while (!frm.eof())
    {
        insert(first, buf.number);
        cout << "-->" << buf.number;
        frm.read((char*)&buf, sizeof(list));
    }
    cout << "-->NULL" << endl;
    frm.close();
    p = first;
    cout << "\nСписок считан из файла mList.dat\n";
}

short search(list*& p, float value, short size)
{
    short counter = 0;

    list* previous, * current, * temp;


    for (int i = 0; i < size; i++)
    {
        if (value != p->number)
        {
            previous = p;
            current = p->next;
            previous = current;
            current = current->next; // перейти к следующему 
            p = p->next;
            counter++;
        }
    }


    cout << "Элемент " << value << " имеет порядковый номер " << counter << ".\n";

    return counter;

}