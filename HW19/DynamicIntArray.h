#pragma once
#include <cstdlib>
#include <iostream>

class DynamicIntArray
{
public:
    DynamicIntArray() :m_data(nullptr), m_size(0) {};
    DynamicIntArray(std::size_t size);
    ~DynamicIntArray() { delete[] m_data; }
    int& operator[](std::size_t index);
    void clear() { delete m_data; m_data = nullptr; m_size = 0; };
    bool operator==(const DynamicIntArray& other);
    bool operator!=(const DynamicIntArray& other);
    std::size_t getSize() const { return m_size; };
    DynamicIntArray(const DynamicIntArray& other);
    DynamicIntArray& operator=(const DynamicIntArray& other);
    void setSize(std::size_t newSize);
    void push_back(int element);
private:
    int* m_data = nullptr;
    int m_size = 0;
};
