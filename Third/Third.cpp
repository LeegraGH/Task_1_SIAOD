//1.	Найти индекс первого вхождения минимального значения среди отрицательных чисел массива.
//2.	Вставить новый элемент массива после минимального элемента массива.
//3.	Удалить все элементы массива равные минимальному значению в массиве среди отрицательных чисел.

#include <iostream>
#include <vector>

using namespace std;

void fill(vector <int>* array, int k, int* mn)
{
	for (int i = 0; i < k; i++)
	{
		int h;
		cin >> h;
		(*array).push_back(h);
		if (h < *mn) *mn = h;
	}
}

void out(vector <int>* array, int k)
{
	for (int i = 0; i < k; i++)
	{
		cout << (*array)[i] << " ";
	}
}

int search(vector <int> array, int k)
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

void add(vector <int>* array, int k, int idx, int h)
{
	for (int i = 0; i < k; i++)
	{
		if (i == idx)
		{
			(*array).insert((*array).begin() + idx + 1, h);
		}
	}
}

void del(vector <int>* array, int* k, int idx)
{
	int h = (*array)[idx];
	for (int i = 0; i < *k; i++)
	{

		if ((*array)[i] == h)
		{
			(*array).erase((*array).begin() + i);
			(*k)--;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите количество элементов в массиве: ";
	int n;
	cin >> n;
	int mn = 100000000;
	vector <int> arr;
	fill(&arr, n, &mn);
	if (mn >= 0)
	{
		cout << "В массиве нет отрицательных чисел" << endl;
		return 0;
	}
	int idx = search(arr, n);
	cout << "\n";
	cout << "Введите новый элемент массива, который хотите вставить в него: ";
	int h;
	cin >> h;
	n += 1;
	add(&arr, n, idx, h);
	del(&arr, &n, idx);
	out(&arr, n);
	return 0;
}