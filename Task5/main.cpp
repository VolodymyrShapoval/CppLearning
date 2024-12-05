#include <iostream>
#include <stdexcept>

using namespace std;

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void main()
{
	int a = 5, b = 10;
	cout << "Before swap:" << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	try
	{
		cout << "After swap: " << endl;
		Swap(&a, &b);
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
	}
	catch (exception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
}