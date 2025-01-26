#include <iostream>


int factorialRecursion(int count)
{
	if (count <= 1)
		return 1;
	else
		return count * factorialRecursion(count - 1);
}

void printNaturalNumbersDescendingRecursion(int count)
{
	if (count <= -1) return;
	std::cout << count << " ";
	printNaturalNumbersDescendingRecursion(count - 1);

}
void printNaturalNumbersAscendingRecursion(int start, int count)
{
	if (start > count) return;
	std::cout << start << " ";
	printNaturalNumbersAscendingRecursion(start + 1, count);
}
