#include <iostream>
#include <stdexcept>

using namespace std;

unsigned long long int factorial(int x)
{
	if (x < 0) throw invalid_argument("Impossible to calculate the factorial of negative number!");
	if (x == 0) return 1;

	return x * factorial(x-1);
}

void main()
{
	int x;
	cout << "Enter number: ";
	cin >> x;

	try
	{
		cout << "Factorial: " << factorial(x) << endl;
	}
	catch(exception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
}