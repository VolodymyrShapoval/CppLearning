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

void pushFront(int*& arr, int& size, const int& value)
{
	int* new_arr = new int[size+1];
	new_arr[0] = value;

	for (int i = 0; i < size; ++i)
	{
		new_arr[i+1] = arr[i];
	}
	++size;

	delete[] arr;

	arr = new_arr;
}

void emplaceAt(int*& arr, int& size, const int& position, const int& value)
{
	if (position < 0 || position > size) 
		throw invalid_argument("Position cannot be less than 0 or greater than size of array!");
	
	++size;
	int* new_arr = new int[size];
	
	for (int i = 0, j = 0; i < size; ++i)
	{
		if (i == position)
		{
			new_arr[i] = value;
			continue;
		}
		new_arr[i] = arr[j];
		++j;
	}

	delete[] arr;

	arr = new_arr;
}

void pushBack(int*& arr, int& size, const int& value)
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

void popFront(int*& arr, int& size)
{
	int* new_arr = new int[size-1];
	for (int i = 1; i < size; i++)
	{
		new_arr[i-1] = arr[i];
	}
	--size;

	delete[] arr;

	arr = new_arr;
}

void erase(int*& arr, int& size, const int& position)
{
	if (position < 0 || position > size)
		throw invalid_argument("Position cannot be less than 0 or greater than size of array!");

	--size;
	int* new_arr = new int[size];

	for (int i = 0, j = 0; i < size && j < size+1; ++j)
	{
		if (j == position) continue;
		new_arr[i] = arr[j];
		++i;
	}

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
			mat[i][j] = rand() % 20 + 10;
		}
	}
}

void emplaceAt(int**& mat, int& rows, int& cols, const int& positionI, const int& positionJ, const int& value)
{
	if (positionI < 0 || positionI >= rows)
		throw invalid_argument("Position cannot be less than 0 or greater than number of rows!");
	if (positionJ < 0 || positionJ > cols)
		throw invalid_argument("Position cannot be less than 0 or greater than number of cols!");
	
	int colsNum = cols;
	for (int i = 0; i < rows; i++)
	{
		if (i == positionI)
		{
			emplaceAt(mat[positionI], cols, positionJ, value);
			continue;
		}
		emplaceAt(mat[i], cols, colsNum, 0);
		--cols;
	}
}

void printMatrix(const int* const* mat, const int& rows, const int& cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (mat[i][j] == 0) continue;
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

		// Копіювання динамічного масиву
		int* new_arr = copyArray(arr, size);
		printArray(new_arr, size);

		// Вставити елемент на початок
		cout << "Push front: " << endl;
		pushFront(new_arr, size, 100);
		printArray(new_arr, size);

		// Видалити елемент з початку
		cout << "Pop front: " << endl;
		popFront(new_arr, size);
		printArray(new_arr, size);

		// Вставити елемент по іденксу
		cout << "Emplace at: " << endl;
		emplaceAt(new_arr, size, 10, 100);
		printArray(new_arr, size);

		// Видалити елемент по індексу
		cout << "Erase: " << endl;
		erase(new_arr, size, 10);
		printArray(new_arr, size);

		// Вставити елемент в кінець
		cout << "Push back: " << endl;
		pushBack(new_arr, size, 100);
		printArray(new_arr, size);

		// Видалити елемент з кінця
		cout << "Pop back: " << endl;
		popBack(new_arr, size);
		printArray(new_arr, size);

		delete[] new_arr;
		delete[] arr;

		new_arr = nullptr;
		arr = nullptr;

		// ------ Виконання двовимірного динамічного масиву -------
		int rows = 5;
		int cols = 3;
		int** mat = new int* [rows];

		createMatrix(mat, rows, cols);
		generateMatrix(mat, rows, cols);

		cout << "Jagged array: " << endl;
		emplaceAt(mat, rows, cols, 0, 1, 100);

		emplaceAt(mat, rows, cols, 1, 1, 100);
		emplaceAt(mat, rows, cols, 1, 2, 100);

		emplaceAt(mat, rows, cols, 2, 1, 100);
		emplaceAt(mat, rows, cols, 2, 2, 100);
		emplaceAt(mat, rows, cols, 2, 3, 100);

		emplaceAt(mat, rows, cols, 3, 1, 100);
		emplaceAt(mat, rows, cols, 3, 2, 100);

		emplaceAt(mat, rows, cols, 4, 1, 100);
		printMatrix(mat, rows, cols);

		deleteMatrix(mat, rows);
	}
	catch (exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
}