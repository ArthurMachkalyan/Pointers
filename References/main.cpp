#include <iostream>
using namespace std;

#define tab "\t"

void main() {
	setlocale(LC_ALL, "");
	int a = 2;
	int& ra = a;
	ra += 3;
	cout << a << endl;
}