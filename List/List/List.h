#ifndef List_h__
#define List_h__

template<class T>
class List
{
private:
	using reference = T&;
	using const_reference = const T&;

private:
	struct Node
	{
		T m_data;
		Node* m_prev;
		Node* m_next;

		Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr)
			: m_data(data)
			, m_prev(prev)
			, m_next(next)
		{
		}
	};

	class iterator
	{
	public:
		explicit iterator(Node* const current)
			: m_current(current)
		{
		}

		friend class List;

		reference operator*()
		{
			return m_current->m_data;
		}

		iterator operator=(const iterator rhs)
		{
			m_current = rhs.m_current;
			return *this;
		}

		bool operator==(const iterator& rhs)
		{
			return rhs.m_current == m_current;
		}

		bool operator!=(const iterator& rhs)
		{
			return !(operator==(rhs));
		}

		iterator operator++()
		{
			m_current = m_current->m_next;
			return *this;
		}

		iterator operator--()
		{
			m_current = m_current->m_prev;
			return *this;
		}

	private:
		Node* m_current;
	};

	class const_iterator
	{
	public:
		const_iterator(const Node* const current)
			: m_current(current)
		{
		}

		const T& operator*()
		{
			return m_current->m_data;
		}

		const_iterator operator=(const const_iterator rhs)
		{
			m_current = rhs.m_current;
			return *this;
		}

		bool operator==(const const_iterator& rhs)
		{
			return rhs.m_current == m_current;
		}

		bool operator!=(const const_iterator& rhs)
		{
			return !(operator==(rhs));
		}

		const_iterator operator++()
		{
			m_current = m_current->m_next;
			return *this;
		}

		const_iterator operator--()
		{
			m_current = m_current->m_prev;
			return *this;
		}

	private:
		const Node* m_current;
	};

public:
	List()
		:m_size(0)
	{
		m_head.m_next = &m_tail;
		m_tail.m_prev = &m_head;
	}

	List(const List& other)
		: List()
	{
		for (auto it = other.cbegin(); it != other.cend(); ++it)
		{
			pushBack(*it);
		}
	}

	List& operator=(const List& other)
	{
		while (m_size > 0)
		{
			popBack();
		}

		for (auto it = other.cbegin(); it != other.cend(); ++it)
		{
			pushBack(*it);
		}

		return *this;
	}

	~List()
	{
		while (m_size > 0)
		{
			popBack();
		}
	}

	iterator begin() noexcept
	{
		return iterator(m_head.m_next);
	}

	const_iterator begin() const noexcept
	{
		return const_iterator(m_head.m_next);
	}

	const_iterator cbegin() const noexcept
	{
		return begin();
	}

	iterator end() noexcept
	{
		return iterator(&m_tail);
	}

	const_iterator end() const noexcept
	{
		return const_iterator(&m_tail);
	}

	const_iterator cend() const noexcept
	{
		return end();
	}

	reference front()
	{
		return m_head.m_next->m_data;
	}

	const_reference front() const
	{
		return m_head.m_next->m_data;
	}

	reference back()
	{
		return m_tail.m_prev->m_data;
	}

	const_reference back() const
	{
		return m_tail.m_prev->m_data;
	}

	void pushBack(const T& element)
	{
		insert(end(), element);
	}

	void popBack()
	{
		if (empty())
		{
			underflowError();
		}

		erase(--end());
	}

	void pushFront(const T& element)
	{
		insert(begin(), element);
	}

	void popFront()
	{
		if (empty())
		{
			underflowError();
		}

		erase(begin());
	}

	iterator insert(iterator position, const T& element)
	{
		Node* next = position.m_current;
		Node* prev = position.m_current->m_prev;

		Node* newNode = new Node(element, prev, next);

		next->m_prev = newNode;
		prev->m_next = newNode;

		++m_size;

		return iterator(newNode);
	}

	iterator erase(iterator position)
	{
		if (empty())
		{
			underflowError();
		}

		position.m_current->m_prev->m_next = position.m_current->m_next;
		position.m_current->m_next->m_prev = position.m_current->m_prev;

		iterator i = position;

		delete position.m_current;

		--m_size;

		return iterator(i.m_current->m_next);
	}

	size_t size() const noexcept
	{
		return m_size;
	}

	bool empty() const noexcept
	{
		return m_size == 0;
	}

private:
	void underflowError()
	{
		throw std::underflow_error("Stack is Empty!");
	}

private:
	Node m_head;
	Node m_tail;
	size_t m_size;
};

#endif // List_h__