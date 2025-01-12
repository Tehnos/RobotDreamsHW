#include <iostream>
#include <numbers>


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

int factorialCycle(int count)
{
	int factorial = 1;
	for (int i = 1; i <= count; i++)
	{
		factorial *= i;

	}
	return factorial;
}

int factorialRecursion(int count)
{
	if (count <= 1)
		return 1;
	else
		return count * factorialRecursion(count - 1);
}

float getArea(float radius)
{
	return std::numbers::pi * radius * radius;
}

float getCircumference(float radius)
{
	return 2 * std::numbers::pi * radius;
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

void printNaturalNumbersDescendingRecursion(int count)
{
	if (count <= -1) return;
	std::cout << count << " ";
	printNaturalNumbersDescendingRecursion(count - 1);

}
void printNaturalNumbersAscendingRecursion(int start, int count)
{
	if (start >count) return;
	std::cout << start << " ";
	printNaturalNumbersAscendingRecursion(start+1,count);
}
int main()
{
	/*std::cout << "Enter the number of numbers\n";
	int a;
	std::cin >> a;
  countNumbers(a);
	int Factorial = factorialCycle(a);
	int Factorialrec = factorialRecurse(a);
	std::cout << "\nFactorial of the number " << a << " = " << Factorial;
	std::cout << "\nFactorial of the number recusrse " << a << " = " << Factorialrec;

	int R;
	std::cout << "Enter the radius of the circle:\n";
	std::cin >> R;
	float Area = getArea(R);
	float Length = getCircumference(R);
	std::cout << "Circle area: " << Area<<std::endl;
	std::cout << "Length : " << Length << std::endl;*/

	int a,b;
	std::cin >> a;
	std::cout << "Natural numbers descending:";
	printNaturalNumbersDescending(a);
	std::cout << "Natural numbers ascending:";
	printNaturalNumbersAscending(a);
	std::cout << "Natural numbers descending recursion:";
	printNaturalNumbersDescendingRecursion(a);
	std::cout << std::endl;
	std::cout << "Enter the number with which the natural numbers begin:";
	std::cin >> a;
	std::cout << "Enter the number to which to print the natural numbers:";
	std::cin >> b;
	if (a > b)
		std::cout << "The first number must be less than the second";
	else
	{
		std::cout << "Natural numbers ascending recursion:";
		printNaturalNumbersAscendingRecursion(a, b);
	}
	std::cout << std::endl;


}

