#include <iostream>
//task1
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
//task 2
void toUppercase(char str[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= ('a' - 'A'); 
		}
	}
}

//task3
bool isPalindrom(const char str[]) {
	int left = 0;
	int right = 0;
	while (str[right] != '\0') {
		right++;
	}
	right--; 
	while (left < right) {
		if (str[left] != str[right]) {
			return false; 
		}
		left++;
		right--;
	}
	return true; 
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
	/*toUppercase(text);
	std::cout <<std::endl<< text;*/

	if (isPalindrom(text))
		std::cout << "It's a palindrome";
	else
		std::cout << "It's not a palindrome";


}
