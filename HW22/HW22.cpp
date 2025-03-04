#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

bool compareByLength(const std::string& a, const std::string& b) {
    return a.size() < b.size();
}

class LengthComparator {
public:
    bool operator()(const std::string& a, const std::string& b) const {
        return a.size() < b.size();
    }
};

unsigned int countDivisibleBy(const std::vector<int>& vec, int number)
{
    return std::count_if(vec.begin(), vec.end(), [number](int val) { return val % number == 0; });
}

void printContainer(const std::vector<std::string>& vec)
{
    for (const auto& str : vec) {
        std::cout << "\"" << str << "\" ";
    }
    std::cout << "\n";
}

void testSorting() {
    std::cout << "Testing sorting by length:\n";

    std::vector<std::string> vec1 = { "apple", "banana", "kiwi", "orange" };
    std::sort(vec1.begin(), vec1.end(), compareByLength);
    std::cout << "Test 1 (compareByLength): ";
	std::cout << "Expected: kiwi apple banana orange\n";
    printContainer(vec1); 

    std::vector<std::string> vec2 = { "apple", "banana", "kiwi", "orange" };
    std::sort(vec2.begin(), vec2.end(), LengthComparator());
    std::cout << "Test 2 (LengthComparator): ";
	std::cout << "Expected: kiwi apple banana orange\n";
    printContainer(vec2); 

    std::vector<std::string> vec3 = { "cat", "dog", "bat", "fox" };
    std::sort(vec3.begin(), vec3.end(), compareByLength);
    std::cout << "Test 3 (compareByLength): ";
	std::cout << "Expected: cat dog bat fox\n";
    std::cout << "The order can be anything, since the lengths are the same\n";
    printContainer(vec3); 

    std::vector<std::string> vec4 = {};
    std::sort(vec4.begin(), vec4.end(), LengthComparator());
    std::cout << "Test 4 (LengthComparator): ";
	std::cout << "Expected: \n";
    printContainer(vec4); 

    std::vector<std::string> vec5 = { "hello" };
    std::sort(vec5.begin(), vec5.end(), compareByLength);
    std::cout << "Test 5 (compareByLength): ";
	std::cout << "Expected: hello\n";
    printContainer(vec5); 

    std::vector<std::string> vec6 = { "a", "bb", "ccc", "dddd", "eeeee" };
    std::sort(vec6.begin(), vec6.end(), LengthComparator());
    std::cout << "Test 6 (LengthComparator): ";
	std::cout << "Expected: a bb ccc dddd eeeee\n";
    printContainer(vec6); 

    std::vector<std::string> vec7 = { "apple", "banana", "kiwi", "orange" };
    std::sort(vec1.begin(), vec1.end(), [](const std::string& a, const std::string& b) {
        return a.size() < b.size();
        });
    std::cout << "Test 7 (lambda): ";
	std::cout << "Expected: kiwi apple banana orange\n";
    printContainer(vec1);
}

void testCountDivisibleBy() {
    std::cout << "Testing countDivisibleBy function:\n";
    std::vector<int> vec1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int number1 = 2;
    std::cout << "Test 1: countDivisibleBy({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 2) = "
        << countDivisibleBy(vec1, number1) << " (Expected: 5)\n";
    
    std::vector<int> vec2 = { 10, 20, 30, 40, 50 };
    int number2 = 10;
    std::cout << "Test 2: countDivisibleBy({10, 20, 30, 40, 50}, 10) = "
        << countDivisibleBy(vec2, number2) << " (Expected: 5)\n";
    
    std::vector<int> vec3 = { 1, 3, 5, 7, 9 };
    int number3 = 2;
    std::cout << "Test 3: countDivisibleBy({1, 3, 5, 7, 9}, 2) = "
        << countDivisibleBy(vec3, number3) << " (Expected: 0)\n";
    
    std::vector<int> vec4 = {};
    int number4 = 5;
    std::cout << "Test 4: countDivisibleBy({}, 5) = "
        << countDivisibleBy(vec4, number4) << " (Expected: 0)\n";
    
    std::vector<int> vec5 = { -5, -10, -15, -20, -25 };
    int number5 = 5;
    std::cout << "Test 5: countDivisibleBy({-5, -10, -15, -20, -25}, 5) = "
        << countDivisibleBy(vec5, number5) << " (Expected: 5)\n";
    
    std::vector<int> vec6 = { 1, 2, 3, 4, 5 };
    int number6 = 1;
    std::cout << "Test 6: countDivisibleBy({1, 2, 3, 4, 5}, 1) = "
        << countDivisibleBy(vec6, number6) << " (Expected: 5)\n";
}
int main() {

	testSorting();
	std::cout << "\n\n";
	testCountDivisibleBy();

    return 0;
}
