#include <iostream>
//task 1
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void swap(int* a, int* b)
{
	if (a != nullptr && b != nullptr)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}
//task2
bool find(const int* arr, int size, int elem)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == elem)
			return true;
	}
	return false;
}
//task3
bool calculateSum(const double* arr, int arrSize, double& sum)
{
	if (arrSize <= 0)
		return false;
	sum = 0;
	for (int i = 0; i < arrSize; i++)
	{
		sum += arr[i];
	}
	return true;
}
int main()
{
	//task1
	//int number_1 = 4;
	//int number_2 = 8;

	//std::cout << "Number 1 = " << number_1 << std::endl;
	//std::cout << "Number 2 = " << number_2 << std::endl;
	//swap(number_1, number_2);

	//std::cout << "Number 1 = " << number_1 << std::endl;
	//std::cout << "Number 2 = " << number_2 << std::endl;
	//swap(&number_1, &number_2);

	//std::cout << "Number 1 = " << number_1 << std::endl;
	//std::cout << "Number 2 = " << number_2 << std::endl;

	//task2
	/*const int size = 5;
	int arr[size]{ 1,2,3,4,5 };
	int fElem;
	std::cout << "Enter number what u wanna find: ";
	std::cin >> fElem;
	if (find(arr, size, fElem))
	{
		std::cout << "Number " << fElem << " is found in the array " << std::endl;
	}
	else {
		std::cout << "Number " << fElem << " not found in array" << std::endl;
	}*/

	const int size = 5;
	double arr[size]{ };
	double sum = 0;
	if (calculateSum(arr, size, sum))
	{
		std::cout << "The sum of the array elements: " << sum << std::endl;
	}
	else
	{
		std::cout << "The array is empty or has an invalid size." << std::endl;
	}

}
