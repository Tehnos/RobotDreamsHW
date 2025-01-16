#include <iostream>

void translateArray(int numbers[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] > 0)
			numbers[i] *= 2;
		else if (numbers[i] < 0)
			numbers[i] = 0;
	}
}
void printArray(int numbers[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout<< numbers[i]<<" ";
	}
}

int main()
{
	const unsigned int size = 10;
	int arr[size];

	std::cout << "Enter "<< size<< " numbers: ";
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
	translateArray(arr, size);
	printArray(arr, size);

}
