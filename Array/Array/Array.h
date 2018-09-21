#ifndef Array_h__
#define Array_h__

#include <string>
#include <iostream>

template<class T, size_t N>
class Array
{
public:
	typedef T* iterator;

public:
	Array()
		: m_capacity(N)
		, m_size(0)
	{
	}

	~Array()
	{
	}

	constexpr size_t size() const noexcept
	{
		return m_size;
	}

	constexpr iterator begin() noexcept
	{
		return m_data;
	}

	constexpr iterator end() noexcept
	{
		return m_data + m_size;
	}

	constexpr bool empty() const noexcept
	{
		return begin() == end();
	}

	const T& operator[](const int index) const
	{
		if (!(index >= 0 && index < m_size))
		{
			outOfRangeError();
		}

		return m_data[index];
	}

	T& operator[](const int index)
	{
		return m_data[index];
	}

	void pushBack(const T& element)
	{
		if (isFull())
		{
			overflowError();
		}

		m_data[m_size] = element;

		++m_size;
	}

	void popBack()
	{
		if (isEmpty())
		{
			underflowError();
		}

		--m_size;
	}

	void insert(const iterator position, const T& element)
	{
		if (isFull())
		{
			overflowError();
		}

		for (auto it = end(); it > position; --it)
		{
			*it = *(it - 1);
		}

		++m_size;

		*position = element;
	}

	void erase(const iterator position)
	{
		if (isEmpty())
		{
			underflowError();
		}

		for (auto it = position; it != end(); ++it)
		{
			*it = *(it + 1);
		}

		--m_size;
	}

private:
	void outOfRangeError()
	{
		std::string exception = std::string("Index is Out of Range");
		throw std::out_of_range(exception);
	}

	void overflowError()
	{
		std::string exception = std::string("Array is Full!");
		throw std::overflow_error(exception);
	}

	void underflowError()
	{
		std::string exception = std::string("Array is Empty!");
		throw std::underflow_error(exception);
	}

private:
	size_t m_capacity;
	size_t m_size;
	T m_data[N];

};

#endif // Array_h__