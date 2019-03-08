
#ifndef List_h__
#define List_h__

namespace DataStructure
{
	template<class T>
	class List
	{
	private:
		using reference = T & ;
		using const_reference = const T&;

	private:
		struct Node
		{
			Node* m_next;
			Node* m_prev;
			T m_data;

			Node()
			{

			}

			Node(Node* next, Node* prev, const T& data)
				: m_next(next)
				, m_prev(prev)
				, m_data(data)
			{
			}

			Node(Node* next, Node* prev, T&& data)
				: m_next(next)
				, m_prev(prev)
				, m_data(std::move(data))
			{
			}

			template<class... Args>
			Node(Node* next, Node* prev, Args&&... data)
				: m_next(next)
				, m_prev(prev)
				, m_data(T(std::forward<Args>(data)...))
			{
			}
		};

		class Iterator
		{
		public:
			explicit Iterator(Node* const current)
				: m_current(current)
			{
			}

			friend class List;

			reference operator*()
			{
				return m_current->m_data;
			}

			Iterator operator=(const Iterator rhs)
			{
				m_current = rhs.m_current;
				return *this;
			}

			bool operator==(const Iterator& rhs)
			{
				return rhs.m_current == m_current;
			}

			bool operator!=(const Iterator& rhs)
			{
				return !(operator==(rhs));
			}

			Iterator operator++()
			{
				m_current = m_current->m_next;
				return *this;
			}

			Iterator operator--()
			{
				m_current = m_current->m_prev;
				return *this;
			}

		private:
			Node* m_current;
		};

		class Const_Iterator
		{
		public:
			Const_Iterator(const Node* const current)
				: m_current(current)
			{
			}

			friend class List;

			const T& operator*()
			{
				return m_current->m_data;
			}

			Const_Iterator operator=(const Const_Iterator rhs)
			{
				m_current = rhs.m_current;
				return *this;
			}

			bool operator==(const Const_Iterator& rhs)
			{
				return rhs.m_current == m_current;
			}

			bool operator!=(const Const_Iterator& rhs)
			{
				return !(operator==(rhs));
			}

			Const_Iterator operator++()
			{
				m_current = m_current->m_next;
				return *this;
			}

			Const_Iterator operator--()
			{
				m_current = m_current->m_prev;
				return *this;
			}

		private:
			const Node* m_current;
		};

	public:
		List()
			: m_head(new Node())
			, m_tail(new Node())
			, m_size(0)
		{
			m_head->m_next = m_tail;
			m_tail->m_prev = m_head;
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

			for (auto elem : other)
			{
				pushBack(elem);
			}

			return *this;
		}

		List(List&& other)
			: List()
		{
			for (auto elem : other)
			{
				pushBack(std::move(elem));
			}

			while (other.m_size > 0)
			{
				other.popBack();
			}
		}

		List& operator=(List&& other)
		{
			for (auto elem : other)
			{
				pushBack(std::move(elem));
			}

			while (other.m_size > 0)
			{
				other.popBack();
			}

			return *this;
		}

		List(std::initializer_list<T> init)
			: List()
		{
			for (auto elem : init)
			{
				pushBack(elem);
			}
		}

		~List()
		{
			while (m_size > 0)
			{
				popBack();
			}
		}

		Iterator begin() noexcept
		{
			return Iterator(m_head->m_next);
		}

		Const_Iterator begin() const noexcept
		{
			return Const_Iterator(m_head->m_next);
		}

		Const_Iterator cbegin() const noexcept
		{
			return begin();
		}

		Iterator end() noexcept
		{
			return Iterator(m_tail);
		}

		Const_Iterator end() const noexcept
		{
			return Const_Iterator(m_tail);
		}

		Const_Iterator cend() const noexcept
		{
			return end();
		}

		reference front()
		{
			return m_head->m_next->m_data;
		}

		const_reference front() const
		{
			return m_head.m_next->m_data;
		}

		reference back()
		{
			return m_tail->m_prev->m_data;
		}

		const_reference back() const
		{
			return m_tail.m_prev->m_data;
		}

		void pushFront(const T& element)
		{
			insert(begin(), element);
		}

		void pushFront(T&& element)
		{
			insert(begin(), std::move(element));
		}

		void pushBack(const T& value)
		{
			insert(end(), value);
		}

		void pushBack(T&& value)
		{
			insert(end(), std::move(value));
		}

		void popFront()
		{
			if (empty())
			{
				underflowError();
			}

			erase(cbegin());
		}

		void popBack()
		{
			if (empty())
			{
				underflowError();
			}

			erase(--cend());
		}

		template<class... Args>
		decltype(auto) emplaceBack(Args&&... args)
		{
			insert(end(), std::forward<Args>(args)...);

			return back();
		}

		template< class... Args >
		reference emplaceFront(Args&&... args)
		{
			insert(begin(), std::forward<Args>(args)...);

			return front();
		}

		//iterator insert(iterator position, const T& element)
		//{
		//	Node* rightNode = position.m_current;
		//	Node* leftNode = rightNode->m_prev;
		//	Node* newNode = new Node(rightNode, leftNode, element);

		//	rightNode->m_prev = newNode;
		//	leftNode->m_next = newNode;

		//	++m_size;

		//	return iterator(newNode);
		//}

		template<class... Args>
		Iterator insert(Iterator position, Args&&... value)
		{
			Node* rightNode = position.m_current;
			Node* leftNode = rightNode->m_prev;
			//Node* newNode = new Node(rightNode, leftNode, std::forward<Args>(value)...);
			Node* newNode = new Node(rightNode, leftNode, std::forward<Args>(value)...);

			++m_size;

			rightNode->m_prev = newNode;
			leftNode->m_next = newNode;

			return iterator(newNode);
		}

		Iterator erase(Const_Iterator position)
		{
			if (empty())
			{
				underflowError();
			}

			position.m_current->m_prev->m_next = position.m_current->m_next;
			position.m_current->m_next->m_prev = position.m_current->m_prev;

			Const_Iterator tmpPosition = position;

			delete position.m_current;

			--m_size;

			return Iterator(tmpPosition.m_current->m_next);
		}

		void clear() noexcept
		{
			for (auto it = cbegin(); it != cend(); ++it)
			{
				popBack();
			}
		}

		constexpr size_t size() const noexcept
		{
			return m_size;
		}

		constexpr bool empty() const noexcept
		{
			return m_size == 0;
		}

	private:
		void underflowError()
		{
			throw std::underflow_error("List is Empty!");
		}

	public:
		using iterator = Iterator;
		using const_iterator = Const_Iterator;

	private:
		Node* m_head;
		Node* m_tail;
		std::size_t m_size;
	};
}

#endif // List_h__