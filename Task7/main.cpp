#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// ����������� ��������� �����
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
	
	for (int i = 0, j = 0; i < size && j < size - 1; ++i)
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

//void erase(int*& arr, int& position, int& size)
//{
//	if (position < 0 || position > size)
//		throw invalid_argument("Position cannot be less than 0 or greater than size of array!");
//
//	--size;
//	int* new_arr = new int[size];
//	while(i < )
//}

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

// ���������� ��������� �����

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
		// ��������� ������������ ���������� ������
		int size = 10;
		int* arr = new int[size];

		generateArray(arr, size);
		printArray(arr, size);

		// ��������� ���������� ������
		int* new_arr = copyArray(arr, size);
		printArray(new_arr, size);

		// �������� ������� �� �������
		cout << "Push front: " << endl;
		pushFront(new_arr, size, 100);
		printArray(new_arr, size);

		// �������� ������� � �������
		cout << "Pop front: " << endl;
		popFront(new_arr, size);
		printArray(new_arr, size);

		// �������� ������� �� �������
		cout << "Emplace at: " << endl;
		emplaceAt(new_arr, size, 2, 100);
		printArray(new_arr, size);

		// �������� ������� �� �������
		/*cout << "Pop front: " << endl;
		popFront(new_arr, size);
		printArray(new_arr, size);*/

		// �������� ������� � �����
		cout << "Push back: " << endl;
		pushBack(new_arr, size, 100);
		printArray(new_arr, size);

		// �������� ������� � ����
		cout << "Pop back: " << endl;
		popBack(new_arr, size);
		printArray(new_arr, size);

		delete[] new_arr;
		delete[] arr;

		new_arr = nullptr;
		arr = nullptr;

		// ------ ��������� ����������� ���������� ������ -------
		int rows = 5;
		int cols = 3;
		int** mat = new int* [rows];

		createMatrix(mat, rows, cols);
		generateMatrix(mat, rows, cols);
		printMatrix(mat, rows, cols);
		deleteMatrix(mat, rows);
	}
	catch (exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
}