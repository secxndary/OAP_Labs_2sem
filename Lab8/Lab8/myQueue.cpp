#include "myQueue.h"

// ================================== ������ ==================================

void create(Number** begin, Number** end, int p) //������������ ��������� ���-����
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
void view(Number* begin) //����� ��������� ������� 
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Number is empty\n";
        return;
    }
    else
        cout << "�������:\n";
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
    cout << "������� �������.\n\n";
}

short sizeQ(Number* begin) //����������� �������
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
    cout << "������ ������� ���������� " << counter << " ��������.\n\n";
    return counter;
}

Number* maxNum(Number* begin) //����� ������������ �������
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
    cout << "������������ �������: " << max << ".\n\n";
    return mx;
}

void task(Number* begin) //������� 3 ������ ��������, ������� ����� ������
{
    Number* t = begin;
    for (short i = 0; i < 3; i++)
    {
        t->info = NULL;
        t = t->next;
    }
}
