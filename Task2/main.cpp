#include<iostream>
#include<ctime>

using namespace std;

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void generateUniqueArray(int arr[], int size)
{
	bool alreadyInArray;
	for (int i = 0; i < size;)
	{
		alreadyInArray = false;
		int generatedValue = rand() % 20;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] == generatedValue)
			{
				alreadyInArray = true;
				break;
			}
		}
		if (!alreadyInArray) {
			arr[i] = generatedValue;
			i++;
		}
	}
}

int searchMinValueInArray(int arr[], int size)
{
	int minValue = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] < minValue)
			minValue = arr[i];
	return minValue;
}

int main()
{
	srand(time(NULL));
	
	const int SIZE = 20;
	int arr[SIZE];

	bool alreadyInArray;
	for (int i = 0; i < SIZE;)
	{
		alreadyInArray = false;
		int generatedValue = rand() % 20;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] == generatedValue)
			{
				alreadyInArray = true;
				break;
			}
		}
		if (!alreadyInArray) {
			arr[i] = generatedValue;
			i++;
		}
	}

	int minElement = searchMinValueInArray(arr, SIZE);

	printArray(arr, SIZE);
	cout << "Min value: " << minElement << endl;

	return 0;
}