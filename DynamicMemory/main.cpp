#include <iostream>
using namespace std;
using std::cout;
using std::endl;
using std::cin;


#define tab "\t"
#define delimetr "\n-------------------------------------\n"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void print(int arr[], const int n);
void print(int** arr, const int rows, const int cols);



void push_back(int*& arr, int& size, const int value);
void push_front(int*& arr, int& size, const int value);
void insert(int*& arr, int& size, const int value, const int index);
void erase(int*& arr, int& size, const int index);


void pop_back(int*& arr, int& size);
void pop_front(int*& arr, int& size);

int** push_row_back(int** arr, int& rows, const int cols); // Добавляет пустую строку в конец двумерного динам. массива

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main() {
	setlocale(LC_ALL, "");


#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	cout << endl;
	int* arr = new int[n];
	FillRand(arr, n); 
	print(arr, n);
	int value;
	/*cout << "Введите добавочное значение: "; cin >> value;
	push_back(arr, n, value);
	cout << "Введите начальное значение: "; cin >> value;
	push_front(arr, n, value);
	cout << "Введите значение для добавления: "; cin >> value;
	cout << endl;*/
    int index;
	/*cout << "Введите индекс: "; cin >> index;
	insert(arr, n, value, index);*/
	cout << "Введите индекс элемента, который хотите удалить: "; cin >> index;
	cout << endl;
	erase(arr, n, index);
	/*cout << "Удаление последнего значения" << endl;
	pop_back(arr, n);
	cout << "Удаление первого значения" << endl;
	pop_front(arr, n);*/
	
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

   // 1) Создаем массив указателей:
	int** arr = new int* [rows];
	//2) Выделяем память под строки:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	
	FillRand(arr, rows, cols);
	print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	print(arr, rows, cols);

	// Удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	//2) Удаление массива указателей
	delete[] arr;

#endif // DYNAMIC_MEMORY_2


}

void FillRand(int arr[], const int n) {
	for (int i = 0; i < n; i++)
	{
		// Обращение к элементам массива через арифметику указателей
		// и оператор разыменовывыания 
		*(arr + i) = rand() % 100;
	}
}

void FillRand(int** arr, const int rows, const int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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

void print(int** arr, const int rows, const int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
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
	int* buffer = new int[--size];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	print(arr, size);
}

void pop_front(int*& arr, int& size) {
	int* buffer = new int[--size];
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

int** push_row_back(int** arr, int& rows, const int cols) {
	// 1) Создаем буферный массив указателей
	int** buffer = new int* [rows++];
	// 2) Копируем адреса строк в новый массив:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) Удаляем исходный массив указателей:
	delete[] arr;
	// 4) Создаем добавляемую строку:
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}