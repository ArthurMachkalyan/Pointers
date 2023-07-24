#include <iostream>
using namespace std;

#define tab "\t"
#define delimetr "\n-------------------------------------\n"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);


void push_back(int*& arr, int& size, const int value);
void push_front(int*& arr, int& size, const int value);
void insert(int*& arr, int& size, const int value, const int index);
void erase(int*& arr, int& size, const int index);


void pop_back(int*& arr, int& size);
void pop_front(int*& arr, int& size);


void main() {
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	cout << endl;
	int* arr = new int[n];
	FillRand(arr, n); 
	Print(arr, n);
	int value;
	cout << "������� ���������� ��������: "; cin >> value;
	push_back(arr, n, value);
	cout << "������� ��������� ��������: "; cin >> value;
	push_front(arr, n, value);
	cout << "������� �������� ��� ����������: "; cin >> value;
	cout << endl;
	int index;
	cout << "������� ������: "; cin >> index;
	insert(arr, n, value, index);
	cout << "������� ������ ��������, ������� ������ �������: "; cin >> index;
	cout << endl;
	erase(arr, n, index);
	cout << "�������� ���������� ��������" << endl;
	pop_back(arr, n);
	cout << "�������� ������� ��������" << endl;
	pop_front(arr, n);

	delete[] arr;
}

void FillRand(int arr[], const int n) {
	for (int i = 0; i < n; i++)
	{
		// ��������� � ��������� ������� ����� ���������� ����������
		// � �������� ���������������� 
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n) {
	for (int i = 0; i < n; i++)
	{
		// ��������� � ��������� ������� ����� �������� ��������������
		cout << arr[i] << tab;
		// [] - �������� �������������� (subscript operator)
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
	Print(arr, size);

}

void push_front(int*& arr, int& size, const int value) {
	int* buffer = new int[size + 1];
	buffer[0] = value;
	for (int i = 1; i < size + 1; i++)
	{
		buffer[i] = arr[i-1];
	}
	delete[] arr;
	arr = buffer;
	size++;
	Print(arr, size);
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
	Print(arr, size);
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
	Print(arr, size);
}

void insert(int*& arr, int& size, const int value, const int index) {
	int* buffer = new int[size + 1];
	++size;
	buffer[index] = value;
	if (index < size)
	{
	  for (int i = 0; i < size; i++)
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
	delete[] arr;
	arr = buffer;
	Print(arr, size);
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
		if (arr[i] == arr[index])
		{
			buffer[i] = arr[i + 1];
		}
		else
		{
			buffer[i] = arr[i];
		}
	}
	delete[] arr;
	arr = buffer;
	Print(arr, size);
}