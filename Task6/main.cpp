#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

void main()
{
	int a = 5;
	int b = 10;
	string str1 = "Hello";
	string str2 = "World";
	cout << "Before swap:" << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "Before swap:" << endl;
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	try
	{
		cout << "After swap: " << endl;
		Swap(a, b);
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "After swap: " << endl;
		Swap(str1, str2);
		cout << "str1: " << str1 << endl;
		cout << "str2: " << str2 << endl;
	}
	catch (exception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
}