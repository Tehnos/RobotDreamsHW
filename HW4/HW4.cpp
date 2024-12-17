#include <iostream>

enum class Month {
    January = 1, February, March, April, May, June,
    July, August, September, October, November, December
};

int main()
{
    int a, b, c;

    std::cout << "Enter integer 1:\n";
    std::cin >> a;
    std::cout << "Enter integer 2:\n";
    std::cin >> b;
    std::cout << "Enter integer 3:\n";
    std::cin >> c;
    std::cout << std::max({ a,b,c });

    std::cout << "Enter integer:\n";
    std::cin >> a;
    if (a % 5 == 0 && a % 11 == 0)
        std::cout << "The number is divisible by both 5 and 11." << std::endl;
    else
        std::cout << "The number is not divisible by both 5 and 11." << std::endl;


    std::cout << "\nEnter three angles of a triangle: ";
    std::cin >> a >> b >> c;
    if (a > 0 && b > 0 && c > 0 && (a + b + c == 180))
        std::cout << "The angles form a valid triangle." << std::endl;
    else
        std::cout << "The angles do not form a valid triangle." << std::endl;

    std::cout << "Enter integer:\n";
    std::cin >> a;
    if (a > 2 && a <= 5)
        std::cout << "Spring\n";
    else if (a > 5 && a <= 8)
        std::cout << "Summer\n";
    else if (a > 8 && a <= 11)
        std::cout << "Autumn\n";
    else
        std::cout << "Winter\n";

    std::cout << "Enter integer 1:\n";
    std::cin >> a;
    std::cout << "Enter integer 2:\n";
    std::cin >> b;
    int min = (a < b) ? a : b;
    std::cout << min;

    std::cout << "Enter a number (1-12) for a month: ";
    std::cin >> a;

    if (a < 1 || a > 12) {
        std::cout << "Error: Invalid month number. Please enter a number between 1 and 12." << std::endl;
    }
    else {
        Month month = static_cast<Month>(a);

        switch (month) {
        case Month::January:
            std::cout << "January" << std::endl;
            break;
        case Month::February:
            std::cout << "February" << std::endl;
            break;
        case Month::March:
            std::cout << "March" << std::endl;
            break;
        case Month::April:
            std::cout << "April" << std::endl;
            break;
        case Month::May:
            std::cout << "May" << std::endl;
            break;
        case Month::June:
            std::cout << "June" << std::endl;
            break;
        case Month::July:
            std::cout << "July" << std::endl;
            break;
        case Month::August:
            std::cout << "August" << std::endl;
            break;
        case Month::September:
            std::cout << "September" << std::endl;
            break;
        case Month::October:
            std::cout << "October" << std::endl;
            break;
        case Month::November:
            std::cout << "November" << std::endl;
            break;
        case Month::December:
            std::cout << "December" << std::endl;
            break;
        default:
            std::cout << "Error: Invalid month." << std::endl;
            break;
        }
    }
}
