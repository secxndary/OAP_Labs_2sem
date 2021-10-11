#pragma once
#include<iostream>
#define MYQUEUE1_EQE  0x0000  // возврат в случае пустоты очереди 
using namespace std;

struct Number
{
	int info;
	Number* next;
};

void osnova();

void create(Number** begin, Number** end, int p);
void view(Number* begin);
void del(Number* begin);
short sizeQ(Number* begin);
void task(Number* begin); //удалить три первых, вывести новый размер
Number* maxNum(Number* begin);
