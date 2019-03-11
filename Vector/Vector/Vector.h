#ifndef Vector_h__
#define Vector_h__

namespace DataStructure
{
	template<class T>
	class Vector
	{
	public:
		using iterator = T*;
		using const_iterator = const T*;
		using reverse_iterator = iterator;
		using const_reverse_iterator = const_iterator;

		using reference = T&;
		using const_reference = const T&;

	public:
		Vector() noexcept
			: m_capacity(0)
			, m_size(0)
			, m_data(new T[m_capacity]())
		{
		}

		explicit Vector(const size_t count)
			: m_capacity(count)
			, m_size(count)
			, m_data(new T[m_capacity]())
		{
		}

		Vector(const size_t count, const T& value)
			: m_capacity(count)
			, m_size(count)
			, m_data(new T[m_capacity])
		{
			std::fill_n(m_data, count, value);
		}

		Vector(std::initializer_list<T> init)
			: m_capacity(init.size())
			, m_size(init.size())
			, m_data(new T[init.size()])
		{
			std::copy(init.begin(), init.end(), m_data);
		}

		Vector(const Vector<T>& other)
			: m_capacity(other.m_capacity)
			, m_size(other.m_size)
			, m_data(new T[m_capacity])
		{
			copyElements(other.m_data, m_data, m_size);
		}

		Vector& operator=(const Vector<T>& other)
		{
			iterator const tmp = new T[other.m_capacity];

			copyElements(other.m_data, tmp, other.m_size);

			delete[] m_data;

			m_capacity = other.m_capacity;
			m_size = other.m_size;
			m_data = tmp;

			return *this;
		}

		Vector(Vector<T>&& right) noexcept
			: m_capacity(right.m_capacity)
			, m_size(right.m_size)
			, m_data(std::move(right.m_data))
		{
			right.m_capacity = 0;
			right.m_size = 0;
			right.m_data = nullptr;
		}

		Vector& operator=(Vector<T>&& right)
		{
			m_capacity = right.m_capacity;
			m_size = right.m_size;
			m_data = std::move(right.m_data);

			right.m_capacity = 0;
			right.m_size = 0;
			right.m_data = nullptr;

			return *this;
		}

		~Vector() noexcept
		{
			delete[] m_data;
		}

		iterator begin() noexcept
		{
			return m_data;
		}

		const_iterator begin() const noexcept
		{
			return m_data;
		}

		const_iterator cbegin() const noexcept
		{
			return begin();
		}

		reverse_iterator rbegin() noexcept
		{
			return m_data + m_size;
		}

		const_reverse_iterator rbegin() const noexcept
		{
			return m_data + m_size;
		}

		const_reverse_iterator crbegin() const noexcept
		{
			return rbegin();
		}

		iterator end() noexcept
		{
			return m_data + m_size;
		}

		const_iterator end() const noexcept
		{
			return m_data + m_size;
		}

		const_iterator cend() const noexcept
		{
			return end();
		}

		reverse_iterator rend() noexcept
		{
			return m_data;
		}

		const_reverse_iterator rend() const noexcept
		{
			return m_data;
		}

		const_reverse_iterator crend() const noexcept
		{
			return rend();
		}

		reference front()
		{
			return *begin();
		}

		const_reference front() const
		{
			return *begin();
		}

		reference back()
		{
			return *(end() - 1);
		}

		const_reference back() const
		{
			return *(end() - 1);
		}

		reference at(const size_t position)
		{
			if (!(position >= 0 && position < m_size))
			{
				throw std::out_of_range("Out of Range!");
			}

			return m_data[position];
		}

		const_reference at(const size_t position) const
		{
			if (!(position >= 0 && position < m_size))
			{
				throw std::out_of_range("Out of Range!");
			}

			return m_data[position];
		}

		T* data() noexcept
		{
			return m_data;
		}

		const T* data() const noexcept
		{
			return m_data;
		}

		constexpr size_t capacity() const noexcept
		{
			return m_capacity;
		}

		constexpr size_t size() const noexcept
		{
			return m_size;
		}

		constexpr bool empty() const noexcept
		{
			return m_size == 0;
		}

		void pushBack(const T& element)
		{
			emplace_back(element);
		}

		void pushBack(T&& element)
		{
			emplace_back(std::move(element));
		}

		void popBack()
		{
			erase(end() - 1);
		}

		iterator insert(const_iterator position, const T& element)
		{
			return emplace(position, element);
		}

		iterator insert(const_iterator position, T&& element)
		{
			return emplace(position, std::move(element));
		}

		iterator erase(const_iterator position)
		{
			if (!(position >= begin() && position < end()))
			{
				throw std::out_of_range("Erase Element Position Out of Range!");
			}

			if (empty())
			{
				throw std::underflow_error("Stack is Empty!");
			}

			iterator tmp = &m_data[position - m_data];
			tmp->~T();

			for (auto it = tmp; it != end() - 1; ++it)
			{
				*(it) = std::move(*(it + 1));
			}

			--m_size;

			return tmp;
		}

		template<class ...Args>
		reference emplace_back(Args&&... args)
		{
			if (needMoreMemory())
			{
				reallocateMemory();
			}

			return m_data[m_size++] = std::move(T(std::forward<Args>(args) ...));
		}

		template<class... Args>
		iterator emplace(const_iterator position, Args&&... args)
		{
			size_t pos = position - m_data;

			if (needMoreMemory())
			{
				reallocateMemory();
			}

			iterator tmp = &m_data[pos];

			for (auto it = end(); it > tmp; --it)
			{
				*it = std::move(*(it - 1));
			}

			++m_size;

			*tmp = std::move(T(std::forward<Args>(args) ...));

			return tmp;
		}

		reference operator[](const size_t index)
		{
			if (!(index >= 0 && index < m_size))
			{
				throw std::out_of_range("Out of Range!");
			}

			return m_data[index];
		}

		const_reference operator[](const size_t index) const
		{
			if (!(index >= 0 && index < m_size))
			{
				throw std::out_of_range("Out of Range!");
			}

			return m_data[index];
		}

		void shrink_to_fit()
		{
			m_capacity = m_size;

			reolocateMemory();
		}

		size_t max_size() const noexcept
		{
			return static_cast<size_t>(std::numeric_limits<T>::max());
		}

		void clear() noexcept
		{
			for (auto it = cbegin(); cbegin() != cend(); ++it)
			{
				popBack();
			}
		}

	private:
		static void copyElements(const_iterator const from, iterator const to, const size_t count)
		{
			for (size_t i = 0; i < count; ++i)
			{
				to[i] = from[i];
			}
		}

		constexpr bool needMoreMemory() const
		{
			return m_size == m_capacity;
		}

		void reallocateMemory()
		{
			m_capacity += (m_capacity / 2) + 1;

			T* tmp = new T[m_capacity];

			copyElements(m_data, tmp, m_size);

			delete[] m_data;

			m_data = tmp;
		}

	private:
		size_t m_capacity;
		size_t m_size;
		T* m_data;
	};
}

#endif // Vector_h__