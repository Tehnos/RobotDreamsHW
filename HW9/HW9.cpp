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

void toUppercase(char str[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= ('a' - 'A'); 
		}
	}
}

int main()
{
	const unsigned int size = 10;
	/*int arr[size];

	std::cout << "Enter "<< size<< " numbers: ";
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
	translateArray(arr, size);
	printArray(arr, size);*/
	char text[size];
	std::cout << "Enter your text: ";
	std::cin.getline(text, size);
	toUppercase(text);
	std::cout <<std::endl<< text;


}
