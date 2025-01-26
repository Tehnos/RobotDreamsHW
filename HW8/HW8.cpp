#include <iostream>
#include <numbers>
#include "Looping.h"
#include "Recursion.h"



float getArea(float radius)
{
	return std::numbers::pi * radius * radius;
}
float getCircumference(float radius)
{
	return 2 * std::numbers::pi * radius;
}
int main()
{
	std::cout << "Enter the number of numbers\n";
	int a;
	std::cin >> a;
  countNumbers(a);
	int Factorial = factorialLooping(a);
	int Factorialrec = factorialRecursion(a);
	std::cout << "\nFactorial of the number " << a << " = " << Factorial;
	std::cout << "\nFactorial of the number recusrse " << a << " = " << Factorialrec;

	int R;
	std::cout << "Enter the radius of the circle:\n";
	std::cin >> R;
	float Area = getArea(R);
	float Length = getCircumference(R);
	std::cout << "Circle area: " << Area<<std::endl;
	std::cout << "Length : " << Length << std::endl;

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

