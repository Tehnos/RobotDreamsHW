#include <iostream>
#include "DynamicIntArray.h"

void testDynamicIntArray()
{
    //default constructor
    DynamicIntArray arr1;
    std::cout << "Test 1: Default constructor - Size: " << arr1.getSize() << " (Expected: 0)\n";
    //constructor with size
    DynamicIntArray arr2(5);
    std::cout << "Test 2: Constructor with size - Size: " << arr2.getSize() << " (Expected: 5)\n";
    //operator[]
    arr2[0] = 10;
    arr2[1] = 20;
    arr2[2] = 30;
    std::cout << "Test 3: operator[] - arr2[0]: " << arr2[0] << " (Expected: 10)\n";
    std::cout << "Test 4: operator[] - arr2[1]: " << arr2[1] << " (Expected: 20)\n";
    std::cout << "Test 5: operator[] - arr2[2]: " << arr2[2] << " (Expected: 30)\n";
    // clear
    arr2.clear();
    std::cout << "Test 7: clear - Size: " << arr2.getSize() << " (Expected: 0)\n";
    //comparison operators
    DynamicIntArray arr3(3);
    arr3[0] = 10;
    arr3[1] = 20;
    arr3[2] = 30;
    DynamicIntArray arr4(3);
    arr4[0] = 10;
    arr4[1] = 20;
    arr4[2] = 30;
    DynamicIntArray arr5(2);
    arr5[0] = 10;
    arr5[1] = 20;
    std::cout << "Test 8: operator== - arr3 == arr4: " << (arr3 == arr4) << " (Expected: 1)\n";
    std::cout << "Test 9: operator== - arr3 == arr5: " << (arr3 == arr5) << " (Expected: 0)\n";
    std::cout << "Test 10: operator!= - arr3 != arr5: " << (arr3 != arr5) << " (Expected: 1)\n";
    //copy constructor
    DynamicIntArray arr6(arr3);
    std::cout << "Test 11: Copy constructor - arr6[0]: " << arr6[0] << " (Expected: 10)\n";
    std::cout << "Test 12: Copy constructor - arr6[1]: " << arr6[1] << " (Expected: 20)\n";
    std::cout << "Test 13: Copy constructor - arr6[2]: " << arr6[2] << " (Expected: 30)\n";
    //assignment operator
    DynamicIntArray arr7;
    arr7 = arr3;
    std::cout << "Test 14: Assignment operator - arr7[0]: " << arr7[0] << " (Expected: 10)\n";
    std::cout << "Test 15: Assignment operator - arr7[1]: " << arr7[1] << " (Expected: 20)\n";
    std::cout << "Test 16: Assignment operator - arr7[2]: " << arr7[2] << " (Expected: 30)\n";
    // Test setSize (increase size)
    arr7.setSize(5);
    std::cout << "Test 17: setSize (increase) - Size: " << arr7.getSize() << " (Expected: 5)\n";
    std::cout << "Test 18: setSize (increase) - arr7[3]: " << arr7[3] << " (Expected: 0)\n"; 
    // Test setSize (decrease size)
    arr7.setSize(2);
    std::cout << "Test 19: setSize (decrease) - Size: " << arr7.getSize() << " (Expected: 2)\n";
    // Test push_back
    arr7.push_back(40);
    std::cout << "Test 20: push_back - Size: " << arr7.getSize() << " (Expected: 3)\n";
    std::cout << "Test 21: push_back - arr7[2]: " << arr7[2] << " (Expected: 40)\n";
    // Test self-assignment
    arr7 = arr7;
    std::cout << "Test 22: Self-assignment - arr7[0]: " << arr7[0] << " (Expected: 10)\n";
    std::cout << "Test 23: Self-assignment - arr7[1]: " << arr7[1] << " (Expected: 20)\n";
    std::cout << "Test 24: Self-assignment - arr7[2]: " << arr7[2] << " (Expected: 40)\n";
}
int main()
{
	testDynamicIntArray();
}
