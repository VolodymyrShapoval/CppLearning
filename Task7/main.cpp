#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Одновимірний динамічний масив
void generateArray(int* const arr, const int size)
{
	srand(time(NULL));
	for(int i = 0; i < size; ++i)
	{
		arr[i] = rand() % 20 + 1;
	}
}

int* copyArray(const int* const arr, const int size)
{
	int* new_arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		new_arr[i] = arr[i];
	}
	return new_arr;
}

void pushBack(int*& arr, int& size, const int value)
{
	int* new_arr = new int[size+1];
	for (int i = 0; i < size; ++i)
	{
		new_arr[i] = arr[i];
	}

	new_arr[size] = value;
	++size;

	delete[] arr;

	arr = new_arr;

}

void popBack(int*& arr, int& size)
{
	--size;
	int* new_arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}

	delete[] arr;

	arr = new_arr;
}

void printArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Двовимірний динамічний масив

void createMatrix(int** const mat, const int &rows, const int &cols)
{
	for (int i = 0; i < rows; ++i)
	{
		mat[i] = new int[cols];
	}
}

void generateMatrix(int** const mat, const int& rows, const int& cols)
{
	srand(time(NULL));
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			mat[i][j] = rand() % 20 + 1;
		}
	}
}

void printMatrix(const int* const* mat, const int& rows, const int& cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
}

void deleteMatrix(int** mat, const int &rows)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] mat[i];
		mat[i] = nullptr;
	}
	delete[] mat;
	mat = nullptr;
}

void main()
{
	try
	{
		// Виконання одновимірного динамічного масиву
		int size = 10;
		int* arr = new int[size];

		generateArray(arr, size);
		printArray(arr, size);

		/*delete[] arr;
		arr = nullptr;*/

		// Виконання двовимірного динамічного масиву
		int rows = 5;
		int cols = 3;
		int** mat = new int* [rows];

		createMatrix(mat, rows, cols);
		generateMatrix(mat, rows, cols);
		printMatrix(mat, rows, cols);
		deleteMatrix(mat, rows);

		// Копіювання динамічного масиву
		int* new_arr = copyArray(arr, size);
		printArray(new_arr, size);

		pushBack(new_arr, size, 100);
		printArray(new_arr, size);

		popBack(new_arr, size);
		printArray(new_arr, size);

		delete[] new_arr;
		delete[] arr;

		new_arr = nullptr;
		arr = nullptr;
	}
	catch (exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
}