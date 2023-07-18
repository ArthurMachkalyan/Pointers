#include <iostream>
using namespace std;

#define tab "\t"
#define delimetr "\n-------------------------------------\n"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);


void main() {
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n); 
	Print(arr, n);
}

void FillRand(int arr[], const int n) {
	for (int i = 0; i < n; i++)
	{
		// Обращение к элементам массива через арифметику указателей
		// и оператор разыменовывыания 
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n) {
	for (int i = 0; i < n; i++)
	{
		// Обращение к элементам массива через оператор индексирования
		cout << arr[i] << tab;
		// [] - оператор индексирования (subscript operator)
	}
	cout << endl;
}

