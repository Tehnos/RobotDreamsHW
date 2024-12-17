#include <iostream>
#include <cctype>

int main()
{
	int a1, d, n;

	//std::cout << "Enter first element(a1):\n";
	//std::cin >> a1;	
	//std::cout << "Enter arithmetic progression step(d):\n";
	//std::cin >> d;
	//std::cout << "Enter the number of the last element of the arithmetic progression(n):\n";
	//std::cin >> n;
	//std::cout << "Your arimetic progression with:\n-initial element " << a1 << "\n-progression step " << d << "\n-number of elements " << n<<std::endl << std::endl;
	//for (int i = 0; i < n; i++)
	//{
	//	int element = a1 + i * d;
	//	std::cout << element << " ";
	//}
	//std::cout << std::endl;


	//std::cout << "Enter weight:\n";
	//std::cin >> a1;
	//std::cout << "Enter height:\n";
	//std::cin >> d;

	//for (int i = 0; i < a1; i++)
	//{
	//	for (int j = i; j < d; j++)
	//	{
	//		std::cout << " * ";
	//	}
	//	std::cout << std::endl;
	//}
	//	std::cout << std::endl;
	//for (int i = 0; i < a1; i++)
	//{
	//	for (int j = 0; j <= i; j++)
	//	{
	//		std::cout << " * ";
	//	}
	//	std::cout << std::endl;
	//}		
	//std::cout << std::endl;
	//for (int i = 0; i < a1; i++)
	//{
	//	for (int j = 0; j < d; j++)
	//	{
	//		std::cout << " * ";
	//	}
	//	std::cout << std::endl;
	//}
	/*std::cout << std::endl;

	char ch;
	int sum = 0;

	while (true)
	{
		std::cout << "Enter a character: ";
		std::cin >> ch;

		if (ch == '.')
		{
			std::cout << "Exit programm";
			break;
		}
		if (islower(ch))
		{
			ch = toupper(ch);
			std::cout << "Uppercase character: " << ch << "\n";
		}
		else if (isdigit(ch))
		{
			sum += ch - '0';
			std::cout << sum << "\n";
		}
		else if (ispunct(ch) || isspace(ch))
			std::cout << "This character is not handled by the program...\n";
		else
			std::cout << ch<<"\n";

	}*/
	std::cout << std::endl;
	int a = 0, b = 1;
	std::cout << "Enter the number of the Fibonacci sequence element: ";
	std::cin >> n;
	for (int i = 2; i <= n; ++i)
	{
		int fib_n = a + b;
		a = b;
		b = fib_n;
		std::cout << fib_n <<" ";
	}
}
