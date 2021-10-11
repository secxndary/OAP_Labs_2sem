#include <iostream>
#include <fstream>
using namespace std;

struct list
{
    char number;
    list* next;
};

short insert(list*&, char); //функция добавления элемента, передается адрес списка и символ, который добавляется 
char del(list*&, char);   //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
void printList(list*);      //функция вывода
void menu(void);            //функция, показывающая меню
void sum(list*);           //функция подсчета суммы положительных чисел
void toFile(list*&);        //функция записи в файл
void fromFile(list*&);      //функция считывания из файла
short search(list*&, char, short);//функция поиска элемента

int main()
{
    setlocale(LC_CTYPE, "Russian");
    list* first = NULL;
    int choice;
    char value;
    short size = 0;
    menu();    // вывести меню 
    cin >> choice;
    while (choice != 7)
    {
        switch (choice)
        {
        case 1:
            cout << "Введите символ: "; // добавить символ в список
            cin >> value;
            insert(first, value);
            printList(first);
            size++;
            break;
        case 2:
            if (!IsEmpty(first)) // удалить символ из списка
            {
                cout << "Введите удаляемый символ: ";
                cin >> value;
                if (del(first, value))
                {
                    cout << "Удален символ " << value << endl;
                    printList(first);
                }
                else cout << "Число не найдено." << endl;
            }
            else cout << "Список пуст." << endl;
            break;
        case 3: sum(first);	// вычисление суммы	
            break;
        case 4: if (!IsEmpty(first))
        {
            cout << "Введите символ, которое ищете: ";
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
    cout << "1 - Ввод символа" << endl;
    cout << "2 - Удаление символа" << endl;
    cout << "3 - Вычисление суммы положительных чисел" << endl;
    cout << "4 - Поиск элемента" << endl;
    cout << "5 - Запись в файл" << endl;
    cout << "6 - Чтение из файла" << endl;
    cout << "7 - Выход" << endl;

}


short insert(list*& p, char value) //Добавление символа value в список 
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

char del(list*& p, char value)  // Удаление символа 
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

void sum(list* p)  // Подсчет суммы симвоел, кратных 5 и больших 0
{
    float sm = 0;
    if (p == NULL)
        cout << "Положительных элементов нет." << endl;
    else
    {
        while (p != NULL)
        {
            int num = p->number;
            if (num < 9)
                sm = sm + (num);
            p = p->next;
        }
        cout << "Сумма: " << sm << endl;
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

short search(list*& p, char value, short size)
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


    char* pValue = &value;
    cout << "Следующий за ним символ: " << (++(*pValue)) << endl;

    return counter;

}