#pragma once

struct Stack
{
	int data;             //информационный элемент
	Stack* head;		 //вершина стека 
	Stack* next;		 //указатель на следующий элемент
};

struct Stack1
{
	char letter;
	Stack1* head;
	Stack1* next;
};

struct Stack2
{
	int data;             //информационный элемент
	Stack2* head;		 //вершина стека 
	Stack2* next;		 //указатель на следующий элемент
};

void show(Stack* myStk);
int pop(Stack* myStk);
void push(int x, Stack* myStk);
void clear(Stack* myStk);
void task(Stack* myStk);
void ifile(Stack* myStk);
void ofile(Stack* myStk);
void dop1(Stack1* myStk1);
void dop2(Stack2* myStk2);

