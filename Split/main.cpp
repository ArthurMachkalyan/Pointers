#include <iostream>
using namespace std;

#define tab "\t"
#define delimetr "\n---------------------------------------\n"

void FillRand(int arr[], const int size);
void Print(int arr[], int size);


void main() {
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	//1) Определяем количество четных и нечетных значений исходного массива
	int even_count = 0; // четные
	int odd_count = 0; // нечетные

	for (int i = 0; i < n; i++)
	{
		arr[i] % 2 ? odd_count++ : even_count++;
	}

	//2) Выделяем память под массивы
	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];

	//3) Копируем значения из исходного массива в соответсвующие
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		arr[i] % 2 == 0 ? even_arr[j++] = arr[i] : odd_arr[k++] = arr[i];
	}

	//4) Выводим результат
	Print(even_arr, even_count);
	Print(odd_arr, odd_count);
	
	
	delete[] even_arr;
	delete[] odd_arr;

}

void FillRand(int arr[], const int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}