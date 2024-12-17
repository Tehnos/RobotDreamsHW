#include <iostream>
#include <numbers>

const unsigned SecondsInMinute = 60;
const unsigned MinutesInHour = 60;
const unsigned SecondsPerHour = SecondsInMinute * MinutesInHour;

int main()
{
    int seconds;
    std::cout << "Enter the number of seconds spent playing the game:\n";
    std::cin >> seconds;

    int hours = seconds / SecondsPerHour;
    seconds %= SecondsPerHour;

    int minutes = seconds / MinutesInHour;
    seconds %= MinutesInHour;

    std::cout << "You spent in the game: " << hours << " hour, " << minutes << " minutes, " << seconds << " seconds\n";

    int a, b, c;
    std::cout << "Enter integer 1:\n";
    std::cin >> a;
    std::cout << "Enter integer 2:\n";
    std::cin >> b;
    std::cout << "Enter integer 2:\n";
    std::cin >> c;

    std::cout << "Sum of these numbers: " << a + b + c << std::endl << "The product of these numbers: " << a * b * c << std::endl << "avg: " << static_cast<float>((a + b + c) / 3) << std::endl;

    std::cout << "Enter integer 1:\n";
    std::cin >> a;
    std::cout << "Enter integer 2:\n";
    std::cin >> b;

    bool lessThan = a < b;
    bool equal = a == b;
    bool moreThan = a > b;
    bool lessOrEqual = a <= b;

    std::cout << std::boolalpha;
    std::cout << "first integer lessThan second: " << lessThan << std::endl;
    std::cout << "first integer equal second: " << equal << std::endl;
    std::cout << "first integer moreThan second: " << moreThan << std::endl;
    std::cout << "first integer lessOrEqual second: " << lessOrEqual << std::endl;

    std::cout << "Enter the height of the rectangle: \n";
    std::cin >> a;
    std::cout << "Enter the width of the rectangle: \n";
    std::cin >> b;
    std::cout << "Rectangle area: " << a * b << std::endl;
    std::cout << "Rectangle perimeter: " << 2 * a + 2 * b << std::endl;


    int R;
    std::cout << "Enter the radius of the circle:\n";
    std::cin >> R;
    std::cout << "Circle area: " << std::numbers::pi * R * R;
    std::cout << "Length : " << 2 * std::numbers::pi * R;
}

