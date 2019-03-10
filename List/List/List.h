
#ifndef List_h__
#define List_h__

namespace DataStructure
{
	template<class T>
	struct Node
	{
		using NodePtr = std::_Rebind_pointer_t<void*, Node>;
		NodePtr m_next;
		NodePtr m_prev;
		T m_data;

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

	template<class T, class Alloc = std::allocator<T>>
	class List
	{
		static_assert(!_ENFORCE_MATCHING_ALLOCATORS || std::is_same<T, typename Alloc::value_type>::value);

	private:
		using reference = T&;
		using const_reference = const T&;

		using _Alty = std::_Rebind_alloc_t<Alloc, T>;
		using _Alty_traits = std::allocator_traits<_Alty>;
		using ListNode = Node<T>;
		using _Alnode = std::_Rebind_alloc_t<Alloc, ListNode>;
		using _Alnode_traits = std::allocator_traits<_Alnode>;
		using NodePtr = typename _Alnode_traits::pointer;

	private:
		class Iterator
		{
		public:
			explicit Iterator(NodePtr const current)
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
			NodePtr m_current;
		};

		class Const_Iterator
		{
		public:
			Const_Iterator(NodePtr const current)
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
			NodePtr m_current;
		};

	public:
		List()
			: m_size(0)
		{
			m_head = buyHeadNode();
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
			return Iterator(m_head);
		}

		Const_Iterator end() const noexcept
		{
			return Const_Iterator(m_head);
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
			return m_head->m_next->m_data;
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
			NodePtr rightNode = position.m_current;
			NodePtr leftNode = rightNode->m_prev;
			NodePtr newNode = new Node(rightNode, leftNode, std::forward<Args>(value)...);

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
		NodePtr buyHeadNode()
		{	// get head node using current allocator
			return buyNode(NodePtr(), NodePtr());
		}

		NodePtr buyNode(NodePtr next, NodePtr prev)
		{	// allocate a node and set links
			_Alnode al;

			NodePtr headNodePtr = al.allocate(1);

			if (next == NodePtr())
			{	// point at self
				next = headNodePtr;
				prev = headNodePtr;
			}

			_Alnode_traits::construct(al, std::addressof(headNodePtr->m_next), next);
			_Alnode_traits::construct(al, std::addressof(headNodePtr->m_prev), prev);

			return headNodePtr;
		}

		void underflowError()
		{
			throw std::underflow_error("List is Empty!");
		}

	public:
		using iterator = Iterator;
		using const_iterator = Const_Iterator;

	private:
		NodePtr m_head;
		std::size_t m_size;
	};
}

#endif // List_h__