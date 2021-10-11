#include "Tree.h"
int sum = 0;

void Tree::AddNode(int k)
{


	if (this->node == NULL)
	{
		this->node = new Node;
		this->node->count = 1;
		this->node->key = k;
		this->node->left = this->node->right = NULL;
		return;
	}

	Node* temp = this->node;

	while (true)
	{

		if (k == temp->key)
		{
			temp->count++;
			return;
		}

		if (k < temp->key)
		{
			if (temp->left == NULL)
			{
				temp->left = new Node;
				temp->left->count = 1;
				temp->left->key = k;
				temp->left->left = temp->left->right = NULL;
				return;
			}
			else
			{
				temp = temp->left;
				continue;
			}

		}

		if (k > temp->key)
		{
			if (temp->right == NULL)
			{
				temp->right = new Node;
				temp->right->count = 1;
				temp->right->key = k;
				temp->right->left = temp->right->right = NULL;
				return;
			}
			else
			{
				temp = temp->right;
				continue;
			}

		}
	}
}
void printToFile(Node* t, ofstream& file) {
	if (t == NULL)
		return;
	file << t->key << '\n';
	printToFile(t->left, file);
	printToFile(t->right, file);
}
void pushFromFile(Node** t, int a) {
	if ((*t) == NULL) {
		(*t) = new Node;
		(*t)->key = a;
		(*t)->left = (*t)->right = NULL;
		return;
	}
	if (a > (*t)->key)
		pushFromFile(&(*t)->right, a);
	else
		pushFromFile(&(*t)->left, a);
}


void Tree::MyTask(Node* temp, int tab) {
	ifstream file("In.txt");
	ofstream fileOut("Out.txt");
	string Temp;
	int newNumber;
	if (!file.is_open()) {
		cout << "\nОшибка Открытия In.txt\n";
	}
	if (!fileOut.is_open()) {
		cout << "\nОшибка Отрытия Out.txt\n";
	}
	while (!file.eof()) {
		file >> newNumber;
		pushFromFile(&temp->right, newNumber);
	}
	printToFile(temp->right, fileOut);
	file.close();
	fileOut.close();
	cout << "\nУспешно\n";
	PrintTree(temp->left, tab + 1);
	system("Out.txt");


}
void Tree::PrintTree(Node* temp, int tab)
{
	int i;
	if (temp != NULL)
	{
		PrintTree(temp->right, tab + 1);
		for (i = 1; i <= tab; i++)
			cout << "   ";
		cout << temp->key << endl;
		PrintTree(temp->left, tab + 1);
	}
}
void Tree::Delete(int key) //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Node* Del, * Prev_Del, * R, * Prev_R;
	Del = this->node;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->left;
		else
			Del = Del->right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nНет такого ключа");
	}
	if (Del->right == NULL) // поиск элемента R для замены
		R = Del->left;
	else
		if (Del->left == NULL)
			R = Del->right;
		else
		{
			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL)
			{
				Prev_R = R;
				R = R->right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->right = Del->right;
			else
			{
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == this->node) this->node = R;
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->left = R; // на левую ветвь 
		else
			Prev_Del->right = R;	// на правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	cout << endl << "Готово" << endl;
}


//Прямой(нисходящий) обход корень-левый-правый
void Tree::DirectBypass(Node* temp)
{
	if (temp)
	{
		cout << temp->key << "  ";
		if (temp->left)
			DirectBypass(temp->left);
		if (temp->right)
			DirectBypass(temp->right);
	}
}

//cмешанный(обратный) обход левый-корень-правый
void Tree::ReverseBypass(Node* temp)
{
	if (temp)
	{
		if (temp->left)
			ReverseBypass(temp->left);
		cout << temp->key << "  ";
		if (temp->right)
			ReverseBypass(temp->right);
	}
}


void Tree::DownScan(Node* temp) //node*e ук-ли на текущий узел
{
	if (temp != NULL)
	{
		// вызываем функцию для текущего элемента
		DownScan(temp->left);	// вызываем рекурсивно для левого элемента 
		DownScan(temp->right);
		cout << temp->key << "  ";
	}

}


bool Tree::Balance(Node* temp)
{
	if (temp)
	{
		if (temp->right)
		{
			this->counter++;
			Balance(temp->right);
		}

		if (temp->left)
		{
			this->counter--;
			Balance(temp->left);
		}
		if (this->counter >= -1 && this->counter <= 1)
			return true;
		else
			return false;
	}
}

int Tree::check_right(Node* temp)
{
	if (temp) {
		if (temp->left)
		{
			check_right(temp->left);
			sum++;
		}
		if (temp->right)
			check_right(temp->right);

		return sum;
	}
}