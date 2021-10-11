#include "Header.h"
#include "Lists.h"
#include <iostream>
#include "Lists.h"
struct AAA
{
	int key;
	int mas;
	AAA(int k, int z)
	{
		key = k;
		mas = z;
	}
};
namespace hashTC
{
	Object create(int size, int(*f)(void*))															//������� �������� ������ ������� - �������
	{
		return *(new Object(size, f));															    //����� ������(������ �������, ���������)
	}
	int Object::hashFunction(void* data)
	{
		return (FunKey(data) % sizeO);
	};
	bool Object::insert(void* data)
	{
		return (Hash[hashFunction(data)].insert(data));
	};
	bool Object::deleteByData(void* data)
	{
		for (int i = 0; i < sizeO; i++)
		{
			listx::Element* e = Hash[i].getFirst();                                                 //� - ��� ��������� �� ������ ���������� ��������-������ �������
			bool k = 0;
			while (e != NULL)
			{
				if ((((AAA*)data)->mas) == (((AAA*)e->data)->mas))
				{
					return(Hash[i].deleteByElement(e));
				}
				e = e->getNext();
			};
		}
	};
	listx::Element* Object::search(void* data)
	{
		return Hash[hashFunction(data)].search(data);
	};
	void Object::Scan()
	{
		for (int i = 0; i < sizeO; i++)
		{
			std::cout << i + 1 << ". ";
			Hash[i].scan();
			std::cout << '\n';
		}
	};
	void Object::Scan1(void* data)
	{
		std::cout << "��������� ������: " << std::endl;
		for (int i = 0; i < sizeO; i++)
		{
			Hash[i].scan1(data);
		}
	};
}
