#ifndef Array_h__
#define Array_h__

#include <array>

namespace DataStructure
{
	template<class T, size_t N>
	class Array
	{
	public:
		using iterator = T*;
		using const_iterator = const T*;

		using reference = T&;
		using const_reference = const T&;

	public:
		Array()
			: m_capacity(N)
			, m_size(0)
		{
		}

		~Array()
		{
		}

		constexpr iterator begin() noexcept
		{
			return m_data;
		}

		constexpr const_iterator begin() const noexcept
		{
			return m_data;
		}

		constexpr const_iterator cbegin() const noexcept
		{
			return begin();
		}

		constexpr iterator end() noexcept
		{
			return m_data + m_size;
		}

		constexpr const_iterator end() const noexcept
		{
			return m_data + m_size;
		}

		constexpr const_iterator cend() const noexcept
		{
			return end();
		}

		constexpr size_t size() const noexcept
		{
			return m_size;
		}

		constexpr bool empty() const noexcept
		{
			return m_size == 0;
		}

		reference operator[](const size_t index)
		{
			if (!(index >= 0 && index < m_size))
			{
				outOfRangeError();
			}

			return m_data[index];
		}

		const_reference operator[](const size_t index) const
		{
			if (!(index >= 0 && index < m_size))
			{
				outOfRangeError();
			}

			return m_data[index];
		}

	private:
		bool isFull()
		{
			return m_size == m_capacity;
		}

	private:
		size_t m_capacity;
		size_t m_size;
		T m_data[N];

	};
}

#endif // Array_h__