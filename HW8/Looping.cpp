#include <iostream>

int factorialLooping(int count)
{
	int factorial = 1;
	for (int i = 1; i <= count; i++)
	{
		factorial *= i;

	}
	return factorial;
}

void printNaturalNumbersDescending(int count)
{
	for (int i = count; i >= 0; i--)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
void printNaturalNumbersAscending(int count)
{
	for (size_t i = 0; i <= count; i++)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
void countNumbers(int a)
{
	int positive = 0;
	int negative = 0;
	int zero = 0;

	for (int i = 0; i < a; i++)
	{
		int num;
		std::cout << "Enter a number\n";
		std::cin >> num;
		if (num > 0)
			positive++;
		else if (num < 0)
			negative++;
		else
			zero++;
	}
	std::cout << "Positive:" << positive << std::endl;
	std::cout << "Negative:" << negative << std::endl;
	std::cout << "Zeroes:" << zero << std::endl;
}
