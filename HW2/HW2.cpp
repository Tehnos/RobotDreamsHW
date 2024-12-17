#include <iostream>
#include <iomanip>

enum class WeekDay {
    Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

int main()
{
    int a, b;

    std::cout << "Enter integer 1:\n";
    std::cin >> a;
    std::cout << "Enter integer 2:\n";
    std::cin >> b;
    std::swap(a, b);
    std::cout << "integer 1 = " << a << ", integer 2 = " << b << std::endl;


    double myDouble = 155.4277;

    std::cout << "My double: " << myDouble << std::endl;

    std::cout << "Double to int: " << static_cast<int>(myDouble) << std::endl;
    std::cout << "formatet double: " << std::setfill('$') << std::setw(20) << myDouble << std::endl << std::endl;

    std::cout << std::fixed;
    std::cout << "Precision 2 digits: " << std::setprecision(2) << myDouble << std::endl;
    std::cout << "Precision 5 digits: " << std::setprecision(5) << myDouble << std::endl;
    std::cout << "Precision 10 digits: " << std::setprecision(10) << myDouble << std::endl;
    std::cout << "Standard notation: " << std::defaultfloat << myDouble << std::endl;
    std::cout << "E-notation: " << std::scientific << myDouble << std::endl;

    std::cout << std::endl << "Numeric values of WeekDay enum:" << std::endl;
    std::cout << "Monday: " << static_cast<int>(WeekDay::Monday) << std::endl;
    std::cout << "Tuesday: " << static_cast<int>(WeekDay::Tuesday) << std::endl;
    std::cout << "Wednesday: " << static_cast<int>(WeekDay::Wednesday) << std::endl;
    std::cout << "Thursday: " << static_cast<int>(WeekDay::Thursday) << std::endl;
    std::cout << "Friday: " << static_cast<int>(WeekDay::Friday) << std::endl;
    std::cout << "Saturday: " << static_cast<int>(WeekDay::Saturday) << std::endl;
    std::cout << "Sunday: " << static_cast<int>(WeekDay::Sunday) << std::endl;

    std::cout << std::endl << "Enter integer :\n";
    int n;
    std::cin >> n;
    bool value = (n != 0);
    std::cout << std::boolalpha << value << std::endl;
}
