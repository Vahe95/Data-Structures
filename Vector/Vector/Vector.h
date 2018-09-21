#ifndef Vector_h__
#define Vector_h__

template<class T>
class Vector
{
public:
	typedef T* iterator;

public:
	explicit Vector() noexcept
		: m_capacity(0)
		, m_size(0)
		, m_data(new T[m_capacity])
	{
	}

	explicit Vector(size_t count, const T& value = 0)
		: m_capacity(count)
		, m_size(0)
		, m_data(new T[m_capacity])
	{
		while (count > 0)
		{
			pushBack(value);
			--count;
		}
	}

	Vector(const Vector<T>& other)
		: m_capacity(other.m_capacity)
		, m_size(other.m_size)
		, m_data(new T[m_capacity])
	{
		copyElements(other.m_data, m_data, m_size);
	}

	Vector<T>& operator=(const Vector<T>& other)
	{
		T* const tmp = new T[other.m_capacity];

		copyElements(other.m_data, tmp, other.m_size);

		delete[] m_data;

		m_capacity = other.m_capacity;
		m_size = other.m_size;
		m_data = tmp;

		return *this;
	}

	~Vector()
	{
		delete[] m_data;
	}

	iterator begin() noexcept
	{
		return m_data;
	}

	iterator end() noexcept
	{
		return m_data + m_size;
	}

	T& front()
	{
		return *begin();
	}

	T& back()
	{
		return *(end() - 1);
	}

	T& at(size_t position)
	{
		if (!(position >= 0 && position < m_size))
		{
			outOfRangeError();
		}

		return m_data[position];
	}

	size_t size() const noexcept
	{
		return m_size;
	}

	bool empty() const noexcept
	{
		return m_size == 0;
	}

	void pushBack(const T& element)
	{
		if (size() == m_capacity)
		{
			reolocateMoreMemory();
		}

		m_data[m_size] = element;

		++m_size;
	}

	void popBack()
	{
		if (empty())
		{
			underflowError();
		}

		if (isReolocationNecessoryForLessMemory())
		{
			reolocateLessMemory();
		}

		--m_size;
	}

	void insert(const iterator position, const T& element)
	{
		if (size() == m_capacity)
		{
			reolocateMoreMemory();
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
		if (empty())
		{
			underflowError();
		}

		for (auto it = position; it != (m_data + m_size); ++it)
		{
			*(it) = *(it + 1);
		}

		if (isReolocationNecessoryForLessMemory())
		{
			reolocateLessMemory();
		}

		--m_size;
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
		if (!(index >= 0 && index < m_size))
		{
			outOfRangeError();
		}

		return m_data[index];
	}

private:
	static void copyElements(const T* const from, T* const to, const size_t count)
	{
		for (size_t i = 0; i < count; ++i)
		{
			to[i] = from[i];
		}
	}

	bool isReolocationNecessoryForLessMemory()
	{
		return m_size <= m_capacity / 2;
	}

	void reolocateMemory()
	{
		T* tmp = new T[m_capacity];

		copyElements(m_data, tmp, m_size);

		delete[] m_data;

		m_data = tmp;
	}

	void reolocateMoreMemory()
	{
		m_capacity *= 2;

		reolocateMemory();
	}

	void reolocateLessMemory()
	{
		m_capacity /= 2;

		reolocateMemory();
	}

	void underflowError()
	{
		throw std::underflow_error("Stack is Empty!");
	}

	void outOfRangeError()
	{
		throw std::out_of_range("Index is Out of Range!");
	}

private:
	size_t m_capacity;
	size_t m_size;
	T* m_data;

};

#endif // Vector_h__