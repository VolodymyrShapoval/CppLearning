#include<iostream>

using namespace std;

void buildRectangle(int16_t &i)
{
	for(i; i >= 0; i--)
	{
		for (int16_t j = i; j >= 0; j--) 
		{
			cout << '*';
		}
		cout << endl;
	}
}

int main()
{
	int16_t size;

	cout << "Input width of rectangle: ";
	cin >> size;

	buildRectangle(size);

	return 0;
}