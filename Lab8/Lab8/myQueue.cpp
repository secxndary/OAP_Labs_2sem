#include "myQueue.h"

// ================================== ОСНОВА ==================================

void create(Number** begin, Number** end, int p) //Формирование элементов оче-реди
{
    Number* t = new Number;
    t->next = NULL;
    if (*begin == NULL)
        *begin = *end = t;
    else
    {
        t->info = p;
        (*end)->next = t;
        *end = t;
    }
}
void view(Number* begin) //Вывод элементов очереди 
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Number is empty\n";
        return;
    }
    else
        cout << "Очередь:\n";
        while (t != NULL)
        {
            cout << t->info << endl;
            t = t->next;
        }
        cout << '\n';
}

void del(Number* begin)
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Number is empty\n";
    }
    else
    {
        while (t != NULL)
        {
            t->info = NULL;
            t = t->next;
        }
    }
    cout << "Очередь очищена.\n\n";
}

short sizeQ(Number* begin) //определение размера
{
    Number* t = begin;
    short counter = 0, data = t->info;
    while (t != NULL)
    {
        if (data != 0)
        {
            counter++;
            t = t->next;
        }
        else t = t->next;
    }
    cout << "Размер очереди составляет " << counter << " элемента.\n\n";
    return counter;
}

Number* maxNum(Number* begin) //найти максимальный элемент
{
    Number* t = begin, * mx = NULL;
    int max;
    if (t == NULL)
    {
        cout << "Number is empty\n"; return 0;
    }
    else
    {
        max = t->info;
        while (t != NULL)
        {
            if (t->info >= max)
            {
                max = t->info;
                mx = t;
            }
            t = t->next;
        }
    }
    cout << "Максимальный элемент: " << max << ".\n\n";
    return mx;
}

void task(Number* begin) //удалить 3 первых элемента, вывести новый размер
{
    Number* t = begin;
    for (short i = 0; i < 3; i++)
    {
        t->info = NULL;
        t = t->next;
    }
}
