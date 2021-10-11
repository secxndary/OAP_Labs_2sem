//Вершина бинарного дерева содержит ключ,  2 целых числа и два указателя на потомков. 
//Написать функцию удаления вершины с максимальной суммой 2 целых значений узла. ( 8 варик )
#include <iostream>
#include <fstream>
using namespace std;

struct Tree          //дерево
{
	int key;         //ключ
	int data1, data2;		 //текст - не более 4 букв
	Tree* Left, * Right;
};

Tree* Root = NULL; 	//указатель корня
Tree* Root1 = NULL;
int maxi = 0;
Tree* makeTree(Tree* Root);       //Создание дерева
Tree* list(int i, int d1, int d2);       //Создание нового элемента
Tree* insertElem(Tree* Root, int key, int data1, int data2);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void leafes(Tree* Root);
void view(Tree* t, int level);    //Вывод дерева 
int counter = 0;
void delAll(Tree* t);             //Очистка дерева
void searchmax();
void searchmaxi(Tree* Root);


void main()
{

	setlocale(0, "Russian");
	int key, choice, n;
	Tree* rc;
	for (;;)
	{
		cout << "Выберите, что сделать:\n1 - создать дерево;\n2 - добавить элемент;\n3 - поиск по ключу;\n4 - удалить элемент;"
			"\n5 - вывести дерево;\n6 - очистить дерево;\n7 - удалить вершину с максимальной суммой двух значений узла;\n8 - выход.\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);	break;
		case 2:  int data1, data2; cout << "\nВведите ключ и два числа: "; cin >> key >> data1 >> data2;

			insertElem(Root, key, data1, data2); break;
		case 3:  cout << "\nВведите ключ: ";  cin >> key;
			rc = search(Root, key);
			break;
		case 4:  cout << "\nВведите удаляемый ключ: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:  if (Root->key >= 0)
		{
			cout << "Дерево повернуто на 90 градусов влево" << endl;
			view(Root, 0);
		}
			  else cout << "Дерево пустое\n";
			break;
		case 6:  delAll(Root); break;
		case 7: searchmax(); break;
		case 8:  exit(0);
		}
	}
}

Tree* makeTree(Tree* Root)    //Создание дерева
{
	int key, data1, data2;
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL)	// если дерево не создано
	{
		cout << "Введите ключ корня: "; cin >> key;
		cout << "Введите два числа корня: "; cin >> data1 >> data2;
		Root = list(key, data1, data2);	// установка указателя на корень
	}
	while (1)                //добавление элементов
	{
		cout << "\nВведите ключ: ";  cin >> key;
		if (key < 0) break;       //признак выхода (ключ < 0)   
		cout << "Введите два числа: "; cin >> data1 >> data2;
		insertElem(Root, key, data1, data2);
	}
	return Root;
}

Tree* list(int i, int d1, int d2)     //Создание нового элемента
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->data1 = d1;
	t->data2 = d2;
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, int data1, int data2)  //Добавление нового элемента
{
	Tree* Prev = nullptr;	     // Prev - элемент перед текущим
	int find = 0;        // признак поиска
	while (t && !find)
	{
		Prev = t;
		//	if (key == t->key)
	//			find = 1;	   //ключи должны быть уникальны
		//	else
		if (key <= t->key) t = t->Left;
		else t = t->Right;
	}
	if (!find)              //найдено место с адресом Prev
	{
		t = list(key, data1, data2);           //создается новый узел 
		if (key <= Prev->key)  // и присоединяется либо 
			Prev->Left = t;    //переход на левую ветвь,
		else
			Prev->Right = t;   // либо на правую 
	}
	return t;
}

Tree* delet(Tree* Root, int key)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->Right == NULL) // поиск элемента R для замены
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // на левую ветвь 
		else
			Prev_Del->Right = R;	// на правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  //Поиск элемента по ключу 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key > (key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "Нет такого элемента\n";
	return rc;
}



void view(Tree* t, int level) //Вывод дерева 
{
	if (t)
	{
		view(t->Right, level + 1);	//вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		cout << endl;
		view(t->Left, level + 1);	//вывод левого поддерева
	}
}


void delAll(Tree* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}


void leafes(Tree* Root)
{
	if (Root->Left == NULL && Root->Right == NULL)
	{
		counter++;
		return;
	}
	else
	{
		if (Root->Left) {
			leafes(Root->Left);
		}
		if (Root->Right) {
			leafes(Root->Right);
		}
	}

}

void searchmaxi(Tree* Root) {
	if (maxi <= Root->data1 + Root->data2)
	{
		maxi = Root->data1 + Root->data2;
		Root1 = Root;
	}
	if (Root->Left) {
		searchmaxi(Root->Left);
	}
	if (Root->Right) {
		searchmaxi(Root->Right);
	}
}
void searchmax() {
	Root1 = Root;
	maxi = Root->data1 + Root->data2;
	searchmaxi(Root);
	Root = delet(Root, Root1->key);
	cout << "Элемент с максимальной суммой " << maxi << " был удалён. ";
}