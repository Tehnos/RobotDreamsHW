#include <iostream>

int main()
{
    std::cout << "I love C++\n";

    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (i > j)
                std::cout << " * ";
            else
                std::cout << "  ";
        }
        std::cout << std::endl;
    }
}
