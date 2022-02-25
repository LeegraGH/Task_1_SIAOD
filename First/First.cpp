//1.	Найти индекс первого вхождения минимального значения среди отрицательных чисел массива.
//2.	Вставить новый элемент массива после минимального элемента массива.
//3.	Удалить все элементы массива равные минимальному значению в массиве среди отрицательных чисел.

#include <iostream>

using namespace std;

void fill(int array[], int k, int* mn)
{
	for (int i = 0; i < k; i++)
	{
		int h;
		cin >> h;
		array[i] = h;
		if (h < *mn) *mn = h;
	}
	if (*mn >= 0)
	{
		cout << "В массиве нет отрицательных чисел" << endl;
		exit(0);
	}
}

void out(int array[], int k)
{
	for (int i = 0; i < k; i++)
	{
		cout << array[i] << " ";
	}
}

int search(int array[], int k)
{
	int mn = 100000000;
	int idx = 0;
	for (int i = 0; i < k; i++)
	{
		if (array[i] < mn)
		{
			mn = array[i];
			idx = i;
		}
	}
	return idx;
}

void add(int array[], int k, int idx, int h)
{
	for (int i = (k - 1); i > idx; i--)
	{
		array[i] = array[i - 1];
		if (i == idx + 1)
		{
			array[i] = h;
		}
	}
}

void del(int array[], int* k, int idx)
{
	int h = array[idx];
	int s = 0;
	for (int i = 0; i < *k - 1; i++)
	{

		if (array[i] == h)
		{
			s += 1;
			for (int j = i; j < *k - 1; j++)
			{
				array[j] = array[j + 1];
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
	int mn = 100000000;
	int arr[100];
	fill(arr, n, &mn);
	int idx = search(arr, n);
	cout << "\n";
	cout << "Введите новый элемент массива, который хотите вставить в него: ";
	int h;
	cin >> h;
	n += 1;
	add(arr, n, idx, h);
	del(arr, &n, idx);
	out(arr, n);
	return 0;
}