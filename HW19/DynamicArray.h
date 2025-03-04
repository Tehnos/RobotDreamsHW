#pragma once
#include <cstdlib>
#include <iostream>

template <typename T>
class DynamicArray
{
public:
	DynamicArray() :m_data(nullptr), m_size(0) {};
	DynamicArray(std::size_t size);
	~DynamicArray() { delete[] m_data; }
	T& operator[](std::size_t index);
	void clear() { delete m_data; m_data = nullptr; m_size = 0; };
	bool operator==(const DynamicArray& other);
	bool operator!=(const DynamicArray& other);
	std::size_t getSize() const { return m_size; };
	DynamicArray(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);
	void setSize(std::size_t newSize);
	void push_back(T element);
	void reserve(std::size_t reservedSpace);
	std::size_t getCapacity() const { return m_capacity; };
	void shrinkToFit();
	void pop_back();
	bool operator==(const DynamicArray& other) const;
private:
	T* m_data = nullptr;
	std::size_t m_size = 0;
	std::size_t m_capacity = 0;
};


template <typename T>
DynamicArray<T>::DynamicArray(std::size_t size) :m_size(size)
{
	m_data = new T[m_size]();
	m_capacity = m_size;
}

template <typename T>
T& DynamicArray<T>::operator[](std::size_t index)
{
#ifdef _DEBUG
	if (index >= m_size)
	{
		std::cout << "Warning: Index out of bounds. Returning the last element.\n";
		return m_data[m_size - 1];
	}
#endif
	return m_data[index];
}
template <typename T>
bool DynamicArray<T>::operator==(const DynamicArray& other)
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
template <typename T>
bool DynamicArray<T>::operator!=(const DynamicArray& other)
{
	return !(*this == other);
}
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
	m_size = other.m_size;
	m_data = new T[m_size];
	m_capacity = m_size;
	for (size_t i = 0; i < m_size; i++)
	{
		m_data[i] = other.m_data[i];
	}
}
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
	if (this != &other)
	{
		delete[] m_data;
		m_size = other.m_size;
		m_data = new T[m_size];
		m_capacity = m_size;
		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = other.m_data[i];
		}
	}
	return *this;
}
template <typename T>
void DynamicArray<T>::setSize(std::size_t newSize)
{
	if (newSize == m_size)
		return;
	T* newData = new T[newSize]();
	std::size_t copyElements = (newSize < m_size) ? newSize : m_size;
	for (size_t i = 0; i < copyElements; i++)
	{
		newData[i] = m_data[i];
	}

	delete[] m_data;
	m_data = newData;
	m_size = newSize;
	m_capacity = newSize;

}
template <typename T>
void DynamicArray<T>::push_back(T element)
{
	T* newData = new T[m_size + 1];
	for (size_t i = 0; i < m_size; i++)
	{
		newData[i] = m_data[i];
	}
	newData[m_size] = element;
	delete[] m_data;
	m_data = newData;
	++m_size;
	m_capacity = m_size;
}
template <typename T>
void DynamicArray<T>::reserve(std::size_t reservedSpace)
{
	if (reservedSpace <= m_capacity)
		return;
	T* newData = new T[reservedSpace];
	for (size_t i = 0; i < m_size; i++)
	{
		newData[i] = m_data[i];
	}
	delete[] m_data;
	m_data = newData;
	m_capacity = reservedSpace;
}
template <typename T>
void DynamicArray<T>::shrinkToFit()
{
	if (m_size == m_capacity)
		return;
	T* newData = new T[m_size];
	for (size_t i = 0; i < m_size; i++)
	{
		newData[i] = m_data[i];
	}
	delete[] m_data;
	m_data = newData;
	m_capacity = m_size;
}
template <typename T>
void DynamicArray<T>::pop_back()
{
	if (m_size == 0)
		return;
	--m_size;
	if (m_size == 0)
	{
		delete[] m_data;
		m_data = nullptr;
		return;
	}
	if (m_size * 2 <= m_capacity)
	{
		T* newData = new T[m_size];
		for (size_t i = 0; i < m_size; i++)
		{
			newData[i] = m_data[i];
		}
		delete[] m_data;
		m_data = newData;
		m_capacity = m_size;
	}
}
template <typename T>
bool DynamicArray<T>::operator==(const DynamicArray& other) const
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
