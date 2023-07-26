#include <iostream>
using namespace std;

#define tab "\t"
#define delimetr "\n-------------------------------------\n"

void FillRand(int arr[], const int n);
void print(int arr[], const int n);


void push_back(int*& arr, int& size, const int value);
void push_front(int*& arr, int& size, const int value);
void insert(int*& arr, int& size, const int value, const int index);
void erase(int*& arr, int& size, const int index);


void pop_back(int*& arr, int& size);
void pop_front(int*& arr, int& size);


void main() {
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	cout << endl;
	int* arr = new int[n];
	FillRand(arr, n); 
	print(arr, n);
	int value;
	cout << "Введите добавочное значение: "; cin >> value;
	push_back(arr, n, value);
	cout << "Введите начальное значение: "; cin >> value;
	push_front(arr, n, value);
	cout << "Введите значение для добавления: "; cin >> value;
	cout << endl;
	int index;
	cout << "Введите индекс: "; cin >> index;
	insert(arr, n, value, index);
	cout << "Введите индекс элемента, который хотите удалить: "; cin >> index;
	cout << endl;
	erase(arr, n, index);
	cout << "Удаление последнего значения" << endl;
	pop_back(arr, n);
	cout << "Удаление первого значения" << endl;
	pop_front(arr, n);
	
	delete[] arr;
}

void FillRand(int arr[], const int n) {
	for (int i = 0; i < n; i++)
	{
		// Обращение к элементам массива через арифметику указателей
		// и оператор разыменовывыания 
		*(arr + i) = rand() % 100;
	}
}

void print(int arr[], const int n) {
	for (int i = 0; i < n; i++)
	{
		// Обращение к элементам массива через оператор индексирования
		cout << arr[i] << tab;
		// [] - оператор индексирования (subscript operator)
	}
	cout << endl;
}

void push_back(int*& arr, int& size, const int value) {
	int* buffer = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[size] = value;
	size++;
	print(arr, size);

}

void push_front(int*& arr, int& size, const int value) {
	int* buffer = new int[size + 1];
	buffer[0] = value;
	size++;
	for (int i = 1; i < size; i++)
	{
		buffer[i] = arr[i-1];
	}
	delete[] arr;
	arr = buffer;
	print(arr, size);
}

void pop_back(int*& arr, int& size) {
	--size;
	int* buffer = new int[size];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	print(arr, size);
}

void pop_front(int*& arr, int& size) {
	--size;
	int* buffer = new int[size];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	print(arr, size);
}

void insert(int*& arr, int& size, const int value, const int index) {
	int* buffer = new int[size + 1];
	++size;
	buffer[index] = value;
	if (index < size)
	{
	  for (int i = 0; i < size; i++)
	  {
         i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
	  }
	delete[] arr;
	arr = buffer;
	print(arr, size);
	}
	else 
	{
		cout << "Error: Incorrect index" << endl;
	}
}

void erase(int*& arr, int& size, const int index) {
	int* buffer = new int[size - 1];
	--size;
	for (int i = 0; i < size; i++)
	{
		arr[i] == arr[index] ? buffer[i] = arr[i + 1] : buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	print(arr, size);
}