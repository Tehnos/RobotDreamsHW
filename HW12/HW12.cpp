#include <iostream>
#include <algorithm>

constexpr unsigned int ROWS = 3;
constexpr unsigned int COLUMNS = 3;
enum class SortingDirection
{
	ByRows,
	ByColumns
};
//Sort in ascending way using the bubble sort algorithm
//Input:  5 1 9 7 3
//Output: 1 3 5 7 9
void bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
}
void bubbleSortColumns(int arr[ROWS][COLUMNS], int colSize)
{
	for (int i = 0; i < ROWS - 1; i++)
	{
		for (int j = 0; j < ROWS - i - 1; j++)
		{
			if (arr[j][colSize] > arr[j + 1][colSize])
				std::swap(arr[j][colSize], arr[j + 1][colSize]);
		}
	}
}



//Sort 2d array using any algorithm (custom quicksort, std::sort, implemented above Bubble Sort
// or using new implementation in-place)
//Input: ByRows
// 1, 5, 4
// 3, 8, 6
// 9, 5, 1
//Output:
// 1, 4, 5
// 3, 6, 8
// 1, 5, 9

//Input: ByColumns
// 1, 5, 4
// 3, 8, 6
// 9, 5, 1
//Output:
// 1, 5, 1
// 3, 5, 4
// 9, 8, 6

void sort(int arr[ROWS][COLUMNS], SortingDirection directions)
{
	//#TODO
	if (directions == SortingDirection::ByRows)
		for (int i = 0; i < ROWS; i++)
		{
			bubbleSort(arr[i], COLUMNS);
		}
	else if (directions == SortingDirection::ByColumns)
		for (int j = 0; j < COLUMNS; j++)
		{
			bubbleSortColumns(arr, j);
		}
}
void printArray(int arr[ROWS][COLUMNS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	/*
	//task1
	const int size = 5;
	int arr[size]{ 5, 1 ,9, 7 ,3 };
	for (int i = 0; i < size; i++)
		std::cout << arr[i];
	std::cout << std::endl;
	bubbleSort(arr, size);
	for (int i = 0; i < size; i++)
		std::cout << arr[i];*/


		//task2
	int arr_2d[ROWS][COLUMNS]{
								{1, 5, 4},
								{3, 8, 6},
								{9, 5, 1} };
	printArray(arr_2d);
	/*sort(arr_2d, SortingDirection::ByRows);
	std::cout << std::endl;

	printArray(arr_2d);
	std::cout << std::endl;*/

	sort(arr_2d, SortingDirection::ByColumns);
	printArray(arr_2d);
	std::cout << std::endl;



	return 0;
}