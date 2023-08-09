#include <iostream>
using namespace std;
using std::cout;
using std::endl;
using std::cin;


#define tab "\t"
#define delimetr "\n-------------------------------------\n"

template <class T> void FillRand(T arr, const int n);
template <class T> void FillRand(T** arr, const int rows, const int cols);
template <class T> void print(T arr, const int n);
template <class T> void print(T** arr, const int rows, const int cols);

template <class T> void Allocate(T** arr, const int rows, const int cols);
template <class T> void Clear(T** arr, const int rows, const int cols);

template <class T> void push_back(T*& arr, int& size, const T value);
template <class T> void push_front(T*& arr, int& size, const T value);
template <class T> void insert(T*& arr, int& size, const T value, const int index);
template <class T> void erase(T*& arr, int& size, const int index);

template <class T> void pop_back(T*& arr, int& size);
template <class T> void pop_front(T*& arr, int& size);
template <class T> void pop_col_back(T** arr, const int rows, int& cols);
template <class T> void pop_col_front(T** arr, const int rows, int& cols);
template <class T> void erase_col(T** arr, const int rows, int& cols, const int index);

template <class T> T** push_row_back(T** arr, int& rows, const int cols);
template <class T> T** push_row_front(T** arr, int& rows, const int cols);
template <class T> T** insert_row(T** arr, int& rows, const int cols, const int index);
template <class T> T** pop_row_back(T** arr, int& rows, const int cols);
template <class T> T** pop_row_front(T** arr, int& rows, const int cols);
template <class T> T** erase_row(T** arr, int& rows, const int cols, const int index);

template <class T> void push_col_back(T** arr, const int rows, int& cols);
template <class T> void push_col_front(T** arr, const int rows, int& cols);
template <class T> void insert_col(T** arr, const int rows, int& cols, const int index);


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
	double** arr = new double* [rows];
	//2) Выделяем память под строки:
	Allocate(arr, rows, cols);
	
	cout << delimetr;
	cout << "Исходный массив: " << endl << endl;;
	FillRand(arr, rows, cols);
	print(arr, rows, cols);

	cout << delimetr;

	cout << "Добавление строки в конец массива: " << endl << endl;
	arr = push_row_back(arr, rows, cols);
	print(arr, rows, cols);

	cout << delimetr;

	cout << "Добавление строки в начало массива: " << endl << endl;
	arr = push_row_front(arr, rows, cols);
	print(arr, rows, cols);


	cout << delimetr;
	int index;
	cout << "Введите индекс добавляемой строки: "; cin >> index;
	cout << endl;
	if (index < rows)
	{
	   arr = insert_row(arr, rows, cols, index);
	   print(arr, rows, cols);
	}
	else
	{
		cout << "Error: Incorrect index" << endl;
	}

	cout << delimetr;
	
	cout << "Удаление последней строки: " << endl << endl;
	arr = pop_row_back(arr, rows, cols);
	print(arr, rows, cols);

	cout << delimetr;
	
	cout << "Удаление первой строки: " << endl << endl;
	arr = pop_row_front(arr, rows, cols);
	print(arr, rows, cols);

	cout << delimetr;
	cout << "Добавление столбца в конец: " << endl << endl;
	push_col_back(arr, rows, cols);
	print(arr, rows, cols);

	cout << delimetr;
	cout << "Добавление столбца в начало: " << endl << endl;
	push_col_front(arr, rows, cols);
	print(arr, rows, cols);

	cout << delimetr;

	int col_index;
	cout << "Введите индекс, по которому будет добавлен столбец: "; cin >> col_index;
	cout << endl;
	insert_col(arr, rows, cols, col_index);
	print(arr, rows, cols);

	cout << delimetr;
	int del_index;
	cout << "Введите удаляемый индекс: "; cin >> del_index;
	cout << endl;
	arr = erase_row(arr, rows, cols, del_index);
	print(arr, rows, cols);

	cout << delimetr;
	
	//cout << "Удаление последнего столбца: " << endl << endl;       // Ошибка HEAP 
	//pop_col_back(arr, rows, cols);
	//print(arr, rows, cols);
	
	cout << delimetr;

	/*cout << "Удаление первого столбца: " << endl << endl;  // Ошибка HEAP 
	pop_col_front(arr, rows, cols);
	print(arr, rows, cols);*/

	cout << delimetr;
	/*int erase_index;
	cout << "Введите индекс для удаления столбца: "; cin >> erase_index;
	erase_col(arr, rows, cols, erase_index);
	print(arr, rows, cols);*/



	Clear(arr, rows, cols);

#endif // DYNAMIC_MEMORY_2


}

template <class T> void Allocate(T** arr, const int rows, const int cols) {
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols] {};
	}
}

template <class T> void Clear(T** arr, const int rows, const int cols) {
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

template <class T > void FillRand(T arr, const int n) {
	for (int i = 0; i < n; i++)
	{
		// Обращение к элементам массива через арифметику указателей
		// и оператор разыменовывыания 
		*(arr + i) = rand() % 100;
	}
}

template <class T> void FillRand(T** arr, const int rows, const int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
			arr[i][j] /= 1000;
		}
	}
}

template <class T> void print(T arr, const int n) {
	for (int i = 0; i < n; i++)
	{
		// Обращение к элементам массива через оператор индексирования
		cout << arr[i] << tab;
		// [] - оператор индексирования (subscript operator)
	}
	cout << endl;
}

template <class T> void print(T** arr, const int rows, const int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

template <class T> void push_back(T*& arr, int& size, const T value) {
	T* buffer = new T[size + 1];
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

template <class T> void push_front(T*& arr, int& size, const T value) {
	T* buffer = new T[size + 1];
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

template <class T> void pop_back(T*& arr, int& size) {
	T* buffer = new T[--size];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	print(arr, size);
}

template <class T> void pop_front(T*& arr, int& size) {
	T* buffer = new T[--size];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	print(arr, size);
}

template <class T> void insert(T*& arr, int& size, const T value, const int index) {
	T* buffer = new T[size + 1];
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

template <class T> void erase(T*& arr, int& size, const int index) {
	 T* buffer = new T[size - 1];
	 --size;
	 for (int i = 0; i < size; i++)
	 {
		arr[i] == arr[index] ? buffer[i] = arr[i + 1] : buffer[i] = arr[i];
	 }
	 delete[] arr;
	 arr = buffer;
	 print(arr, size);
	
}

template <class T> T** push_row_back(T** arr, int& rows, const int cols) {
	// 1) Создаем буферный массив указателей
	T** buffer = new T* [rows + 1] {};
	// 2) Копируем адреса строк в новый массив:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) Удаляем исходный массив указателей:
	delete[] arr;
	// 4) Создаем добавляемую строку:
	buffer[rows] = new T[cols] {};
	rows++;
	return buffer;
}

template <class T> T** push_row_front(T** arr, int& rows, const int cols) {
	T** buffer = new T* [rows + 1] {};
	for (int i = 1; i <= rows; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[] arr;
	buffer[0] = new T[cols] {};
	rows++;
	return buffer;
}

template <class T> T** insert_row(T** arr, int& rows, const int cols, const int index) {
	  T** buffer = new T* [rows + 1] {};
	  for (int i = 0; i < rows; i++)
	  {
	  	if (i < index)
	  	{
	  		buffer[i] = arr[i];
	  	}
	  	else
	  	{
	  		buffer[i + 1] = arr[i];
	  	}
	  }
	  buffer[index] = new T[cols] {};
	  rows++;
	  return buffer;
}

template <class T> T** pop_row_back(T** arr, int& rows, const int cols) {
	T** buffer = new T* [rows - 1];
	rows--;
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}

template <class T> T** pop_row_front(T** arr, int& rows, const int cols) {
	T** buffer = new T* [rows - 1];
	rows--;
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}

template <class T> T** erase_row(T** arr, int& rows, const int cols, const int index) {
	T** buffer = new T* [rows - 1];
	rows--;
	for (int i = 0; i < rows; i++)
	{
		if (i < index)
		{
			buffer[i] = arr[i];
		}
		else
		{
			buffer[i] = arr[i + 1];
		}
	}
	delete[] arr;
	return buffer;
}

template <class T> void push_col_back(T** arr, const int rows, int& cols) {
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template <class T> void push_col_front(T** arr, const int rows, int& cols) {
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 1; j <= cols; j++)
		{
			buffer[j] = arr[i][j - 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
} 

template <class T> void insert_col(T** arr, const int rows, int& cols, const int index) {
	cols++;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
		  if (j < index)
		  {
		  	  buffer[j] = arr[i][j];
		  }
		  else
		  {
			  buffer[j + 1] = arr[i][j];
		  }
		}
	    delete[] arr[i];
		arr[i] = buffer;
	}
}

template <class T> void pop_col_back(T** arr, const int rows, int& cols) {
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
}

template <class T> void pop_col_front(T** arr, const int rows, int& cols) {
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
}

template <class T> void erase_col(T** arr, const int rows, int& cols, const int index) {
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols; j++)
		{
			if (j < index)
			{
				buffer[j] = arr[i][j];
			}
			else
			{
				buffer[j] = arr[i][j + 1];
			}
			delete[] arr[i];
			arr[i] = buffer;
		}
	}
}
