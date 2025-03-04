#include <iostream>
#include "DynamicArray.h"

void testDynamicArray() {
    {
        DynamicArray<float> arr;
        std::cout << "Test 1: Default constructor\n";
        std::cout << "Expected size: 0, Actual size: " << arr.getSize() << "\n";
        std::cout << "Expected capacity: 0, Actual capacity: " << arr.getCapacity() << "\n";
        std::cout << "----------------------------------------\n";
    }
    {
        DynamicArray<float> arr(5);
        std::cout << "Test 2: Constructor with size\n";
        std::cout << "Expected size: 5, Actual size: " << arr.getSize() << "\n";
        std::cout << "Expected capacity: 5, Actual capacity: " << arr.getCapacity() << "\n";
        std::cout << "----------------------------------------\n";
    }
    {
        DynamicArray<float> arr(3);
        arr[0] = 10.5f;
        arr[1] = 20.3f;
        arr[2] = 30.7f;
        std::cout << "Test 3: Operator[]\n";
        std::cout << "Expected arr[0]: 10.5, Actual: " << arr[0] << "\n";
        std::cout << "Expected arr[1]: 20.3, Actual: " << arr[1] << "\n";
        std::cout << "Expected arr[2]: 30.7, Actual: " << arr[2] << "\n";
        std::cout << "----------------------------------------\n";
    }
    {
        DynamicArray<float> arr;
        arr.push_back(10.5f);
        arr.push_back(20.3f);
        arr.push_back(30.7f);
        std::cout << "Test 4: push_back\n";
        std::cout << "Expected size: 3, Actual size: " << arr.getSize() << "\n";
        std::cout << "Expected arr[0]: 10.5, Actual: " << arr[0] << "\n";
        std::cout << "Expected arr[1]: 20.3, Actual: " << arr[1] << "\n";
        std::cout << "Expected arr[2]: 30.7, Actual: " << arr[2] << "\n";
        std::cout << "----------------------------------------\n";
    }
    {
        DynamicArray<float> arr;
        arr.push_back(10.5f);
        arr.push_back(20.3f);
        arr.push_back(30.7f);
        arr.pop_back();
        std::cout << "Test 5: pop_back\n";
        std::cout << "Expected size: 2, Actual size: " << arr.getSize() << "\n";
        std::cout << "Expected arr[0]: 10.5, Actual: " << arr[0] << "\n";
        std::cout << "Expected arr[1]: 20.3, Actual: " << arr[1] << "\n";
        std::cout << "----------------------------------------\n";
    }
    {
        DynamicArray<float> arr;
        arr.push_back(10.5f);
        arr.push_back(20.3f);
        arr.clear();
        std::cout << "Test 6: clear\n";
        std::cout << "Expected size: 0, Actual size: " << arr.getSize() << "\n";
        std::cout << "Expected capacity: 0, Actual capacity: " << arr.getCapacity() << "\n";
        std::cout << "----------------------------------------\n";
    }
    {
        DynamicArray<float> arr;
        arr.setSize(5);
        std::cout << "Test 7: setSize\n";
        std::cout << "Expected size: 5, Actual size: " << arr.getSize() << "\n";
        std::cout << "Expected capacity: 5, Actual capacity: " << arr.getCapacity() << "\n";
        std::cout << "----------------------------------------\n";
    }
    {
        DynamicArray<float> arr;
        arr.reserve(10);
        std::cout << "Test 8: reserve\n";
        std::cout << "Expected capacity: 10, Actual capacity: " << arr.getCapacity() << "\n";
        std::cout << "Expected size: 0, Actual size: " << arr.getSize() << "\n";
        std::cout << "----------------------------------------\n";
    }
    {
        DynamicArray<float> arr;
        arr.push_back(10.5f);
        arr.push_back(20.3f);
        arr.reserve(10);
        arr.shrinkToFit();
        std::cout << "Test 9: shrinkToFit\n";
        std::cout << "Expected capacity: 2, Actual capacity: " << arr.getCapacity() << "\n";
        std::cout << "----------------------------------------\n";
    }
    {
        DynamicArray<float> arr1;
        arr1.push_back(10.5f);
        arr1.push_back(20.3f);

        DynamicArray<float> arr2;
        arr2.push_back(10.5f);
        arr2.push_back(20.3f);

        std::cout << "Test 10: Operator ==\n";
        std::cout << "Expected: true, Actual: " << (arr1 == arr2) << "\n";
        std::cout << "----------------------------------------\n";
    }
    {
        DynamicArray<float> arr1;
        arr1.push_back(10.5f);
        arr1.push_back(20.3f);

        DynamicArray<float> arr2;
        arr2.push_back(10.5f);
        arr2.push_back(30.7f);

        std::cout << "Test 11: Operator !=\n";
        std::cout << "Expected: true, Actual: " << (arr1 != arr2) << "\n";
        std::cout << "----------------------------------------\n";
    }
}
int main()
{
	testDynamicArray();
}
