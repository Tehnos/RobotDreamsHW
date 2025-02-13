#include "DynamicIntArray.h"


DynamicIntArray::DynamicIntArray(std::size_t size):m_size(size)
{
	m_data = new int[size];
}

int& DynamicIntArray::operator[](std::size_t index)
{
	if (index >= m_size)
	{
		std::cout << "Warning: Index out of bounds. Returning the last element.\n";
		return m_data[m_size - 1]; 
	}
	return m_data[index];
}

bool DynamicIntArray::operator==(const DynamicIntArray& other)
{
	if (m_size != other.m_size)
		return false;

	for (size_t i = 0; i < m_size; i++)
	{
		if (m_data[i] != other.m_data[i]) 
			return false;
	}
	return true;
}

bool DynamicIntArray::operator!=(const DynamicIntArray& other)
{
	return !(*this==other);
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other)
{
	m_size = other.m_size;
	m_data = new int[m_size];
	for (size_t i = 0; i < m_size; i++)
	{
		m_data[i] = other.m_data[i];
	}
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other)
{
	if (this != &other)
	{
		delete[] m_data;
		m_size = other.m_size;
		m_data = new int[m_size];
		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = other.m_data[i];
		}
	}
	return *this;
}

void DynamicIntArray::setSize(std::size_t newSize)
{
	if (newSize == m_size)
		return;
	int* newData = new int[newSize]();
	std::size_t copyElements =(newSize < m_size) ? newSize : m_size;
	for (size_t i = 0; i < copyElements; i++)
	{
		newData[i] = m_data[i];
	}

	delete[] m_data;
	m_data = newData;
	m_size = newSize;

}

void DynamicIntArray::push_back(int element)
{
	int* newData = new int[m_size+1];
	for (size_t i = 0; i < m_size; i++)
	{
		newData[i] = m_data[i];
	}
	newData[m_size] = element;
	delete[] m_data;
	m_data = newData;
	++m_size;
}

