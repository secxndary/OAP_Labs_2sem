#include <ctime>             
#include <stdlib.h>
#include <iostream>
using namespace std;
int* sort_Bubble(int m[], int lm)
{
	int buf;
	for (int i = 0; i < lm; i++)
		for (int j = 0; j < lm - i - 1; j++)
			if (m[j] > m[j + 1]) { buf = m[j]; m[j] = m[j + 1]; m[j + 1] = buf; } return m;
};

void insOrd(int m[], int sm, int em, int e)
{
	int buf;
	int i = sm;
	while (i <= em && m[i] < e)
	{
		if (i - 1 >= sm)
			m[i - 1] = m[i];
		i++;
	}  m[i - 1] = e;
}
int* merge(int m[], int sm, int cm, int em)
{
	for (int i = 0; i <= sm; i++)
	{
		if (m[i] > m[cm + 1])
		{
			int buf = m[i];
			m[i] = m[cm + 1];
			insOrd(m, cm + 1, em, buf);
		}
	}
	return m;
}

int* sortMerge(int m[], int lm, int sm = 0)
{
	if (lm > 1)
	{
		sortMerge(m, lm / 2, sm);
		sortMerge(m, lm - lm / 2, sm + lm / 2);
		merge(m, sm, sm + lm / 2 - 1, sm + lm - 1);
	};
	return m;
}

int* sort_Hoara(int mas[], int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2];
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l)
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) sort_Hoara(mas, first, l);
	if (f < last) sort_Hoara(mas, f, last); return mas;
}
int GetRandKey(int reg = 0)
{
	if (reg > 0) srand((unsigned)time(NULL));
	int rmin = 0;   int rmax = 100000;
	return (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
}	int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int N = 50000; int k[N], f[N];
	clock_t t1, t2;
	GetRandKey(1);
	for (int i = 0; i < N; i++) f[i] = GetRandKey(0);
	for (int n = 10000; n <= N; n += 10000)
	{
		cout << "n = " << n << endl;
		cout << "Сортировка пузырьком: ";
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		sort_Bubble(k, n);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
		cout << "Сортировка слиянием: ";
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		sortMerge(k, n);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
		cout << "Сортировка Хоара: ";
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		sort_Hoara(k, 0, n - 1);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl << endl;
	}
	return 0;

}
