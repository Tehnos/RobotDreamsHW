#include <iostream>
constexpr unsigned int ROWS = 4;
constexpr unsigned int COLUMNS = 6;
enum class SortingDirection
{
	Ascending,
	Descending
};
//task 1
bool find(int arr_2d[ROWS][COLUMNS], int toFind)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
			if (arr_2d[i][j] == toFind)
				return true;
	}
	return false;
}

//task 2
bool isSorted(const int* arr, int size,SortingDirection sortingDirection)
{
	for (int i = 1; i < size; i++)
	{
		if (sortingDirection == SortingDirection::Ascending)
		{
		if (arr[i] < arr[i - 1])
			return false;
		}
		else if(sortingDirection == SortingDirection::Descending)
			if (arr[i]  > arr[i - 1])
				return false;

	}
	return true;
}

//task 3
void traverseTopDownRightLeftByColumns(int arr_2d[ROWS][COLUMNS])
{
	for (int j = COLUMNS - 1; j >= 0; j--)
	{
		for (int i = 0; i < ROWS; i++)
		{
			std::cout << arr_2d[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

//#3_2
void traverseLeftRightDownTopSwitchingByRows(int arr_2d[ROWS][COLUMNS])
{
	for (int i = ROWS - 1; i >= 0; i--)
	{
		if (i % 2 == 0)
		{
			for (int j = COLUMNS-1; j >=0; j--)
			{
				std::cout << arr_2d[i][j] << " ";

			}
		}
		else
			for (int j = 0; j < COLUMNS; j++)
			{
				std::cout << arr_2d[i][j] << " ";
			}
		std::cout << std::endl;
	}
}
int main()
{
	//task 1
	int arr_2d[ROWS][COLUMNS] = {
	  {11, 12, 13, 14, 15, 16 },
	  {21, 22, 23, 24, 25, 26 },
	  {31, 32, 33, 34, 35, 36 },
	  {41, 42, 43, 44, 45, 46 }
	};
	/*
	int toFind;
	std::cout << "Enter the number to search for: ";
	std::cin >> toFind;

	if (find(arr_2d, toFind))
	{
		std::cout << "The number " << toFind << " was found in the 2D array." << std::endl;
	}
	else
	{
		std::cout << "The number " << toFind << " was not found in the 2D array." << std::endl;
	}*/
	//task 2

	/*const int size = 5;
	int arr[size]{ 1,2,3,4,5 };
	int arr1[size]{ 1,2,3,2,5 };
	int arr2[size]{ 6,4,3,2,1 };
	int arr3[size]{ 6,4,3,0,1 };
	std::cout << "Array 1 is sorted (ascending): "
		<< (isSorted(arr, size, SortingDirection::Ascending) ? "true" : "false") << std::endl;
	std::cout << "Array 2 is sorted (descending): "
		<< (isSorted(arr1, size, SortingDirection::Ascending) ? "true" : "false") << std::endl;
	std::cout << "Array 3 is sorted (ascending): "
		<< (isSorted(arr2, size, SortingDirection::Descending) ? "true" : "false") << std::endl;
	std::cout << "Array 4 is sorted (descending): "
		<< (isSorted(arr3, size, SortingDirection::Descending) ? "true" : "false") << std::endl;
*/

	//task 3

	//traverseTopDownRightLeftByColumns(arr_2d);
	//task 3_2
	//traverseLeftRightDownTopSwitchingByRows(arr_2d);
}
