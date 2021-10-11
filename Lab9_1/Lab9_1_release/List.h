#pragma once
#include <iostream>
using namespace std;
struct Element                   // ������� ������ 
{
	Element* Prev;                // ��������� �� ���������� ������� 
	Element* Next;                // ��������� �� ��������� ������� 
	void* Data;                  //  ������  
	Element(Element* prev, void* data, Element* next)
	{
		Prev = prev;
		Data = data;
		Next = next;
	}
	Element* GetNext()            // �������� ���������
	{
		return Next;
	};
	Element* GetPrev()            // �������� ����������  
	{
		return Prev;
	};
};
//-----------------------------------------------------------
struct Object                     // ���� ���������� ������� 
{
	Element* Head;                 // ��������� �� ������ ������
	Object()
	{
		Head = NULL;
	};
	Element* GetFirst()            // �������� ������ ������� ������
	{
		return Head;
	};
	Element* GetLast();            // �������� ��������� ������� ������
	Element* Search(void* data);   // �����  ������ ������� �� ������ 
	bool Insert(void* data);       // �������� ������� � ������
	bool InsertEnd(void* data);    // �������� � ����� 
	bool Delete(Element* e);       // ������� �� ������ �������� 
	bool Delete(void* data);       // ������� ������ �� ������
	bool DeleteList();		    // �������� ������ 
	void PrintList(void(*f)(void*));
	void PrintList(void(*f)(void*), Element*);
	int CountList();
	bool DeleteDouble();
	void countList(void(*f)(void*));
	void deleteList(void(*f)(void*));
};
Object Create();
Object detelel();
