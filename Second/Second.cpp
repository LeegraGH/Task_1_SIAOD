//1.	Найти индекс первого вхождения минимального значения среди отрицательных чисел массива.
//2.	Вставить новый элемент массива после минимального элемента массива.
//3.	Удалить все элементы массива равные минимальному значению в массиве среди отрицательных чисел.

#include <iostream>
#include <stdlib.h>

using namespace std;

void fill(int** array, int k, int* mn)
{
	for (int i = 0; i < k; i++)
	{
		int h;
		cin >> h;
		(*array)[i] = h;
		if (h < *mn) *mn = h;
	}
}

void out(int** array, int k)
{
	for (int i = 0; i < k; i++)
	{
		cout << (*array)[i] << " ";
	}
}

int search(int** array, int k)
{
	int mn = 100000000;
	int idx = 0;
	for (int i = 0; i < k; i++)
	{
		if ((*array)[i] < mn)
		{
			mn = (*array)[i];
			idx = i;
		}
	}
	return idx;
}

void add(int** array, int k, int idx, int h)
{
	for (int i = (k - 1); i > idx; i--)
	{
		(*array)[i] = (*array)[i - 1];
		if (i == idx + 1)
		{
			(*array)[i] = h;
		}
	}
}

void del(int** array, int* k, int idx)
{
	int h = (*array)[idx];
	int s = 0;
	for (int i = 0; i < *k - 1; i++)
	{

		if ((*array)[i] == h)
		{
			s += 1;
			for (int j = i; j < *k - 1; j++)
			{
				(*array)[j] = (*array)[j + 1];
			}
		}
	}
	*k -= s;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите количество элементов в массиве: ";
	int n;
	cin >> n;
	int* arr;
	int mn = 100000000;
	arr = (int*)malloc(n * sizeof(int));
	fill(&arr, n, &mn);
	if (mn >= 0)
	{
		cout << "В массиве нет отрицательных чисел" << endl;
		return 0;
	}
	int idx = search(&arr, n);
	cout << "\n";
	cout << "Введите новый элемент массива, который хотите вставить в него: ";
	int h;
	cin >> h;
	n += 1;
	arr = (int*)realloc(arr, n * sizeof(int));
	add(&arr, n, idx, h);
	del(&arr, &n, idx);
	arr = (int*)realloc(arr, n * sizeof(int));
	out(&arr, n);
	free(arr);
	return 0;
}