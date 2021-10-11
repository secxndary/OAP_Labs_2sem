#include<iostream> 
#include "myQueue.h"

void main()
{
    setlocale(LC_ALL, "ru");
    Number* begin = NULL, * end, * t;
    t = new Number;
    short size, choose = 0, p, sizeQueue;
    while (choose != 7)
    {
        cout << "Выберите, что сделать:\n1 — ввод очереди;\n2 — вывод очереди;\n3 — очистка очереди;\n4 — определение размера очереди;"
            "\n5 — найти максимальный элемент;\n6 — удалить 3 первых элемента и вывести размер оставшейся очереди;\n7 — выход из программы.\n\n";
        cin >> choose;
        cout << '\n';
        switch (choose)
        {
        case 1: 
            cout << "Введите размер очереди:\n";
            cin >> size;
            cout << "Введите число: ";
            cin >> p;
            create(&begin, &end, p);
            t->info = p;
            t->next = NULL;
            begin = end = t;
            for (int i = 1; i < size; i++) //создание очереди
            {
                cout << "Введите число: ";
                cin >> p;
                create(&begin, &end, p);
            }
            cout << '\n';
            break;
        case 2:
            view(begin);
            break;
        case 3:
            del(begin);
            break;
        case 4:
            sizeQueue = sizeQ(begin);
            break;
        case 5:
            maxNum(begin);
            break;
        case 6:
            task(begin);
            cout << "Размер новой очереди составялет " << sizeQueue - 3 << " элемента.\n\n";
            break;
        case 7:
            cout << "До свидания!\n"; exit(0);
        }
    }
}