#ifndef List_h__
#define List_h__

#include <string>

template<class T>
class List
{
private:
	struct Node
	{
		T m_data;
		Node* m_prev;
		Node* m_next;

		Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr);
	};

	class iterator
	{
	private:
		Node* m_current;

	public:
		explicit iterator(Node* const current);

		friend class List;

		T& operator*();

		iterator operator=(const iterator rhs);

		bool operator==(const iterator& rhs);
		bool operator!=(const iterator& rhs);

		iterator operator++();
		iterator operator--();
	};

	class const_iterator
	{
	private:
		const Node* m_current;

	public:
		const_iterator(const Node* const current);

		const T& operator*();

		const_iterator operator=(const const_iterator rhs);

		bool operator==(const const_iterator& rhs);
		bool operator!=(const const_iterator& rhs);

		const_iterator operator++();
		const_iterator operator--();

	};

private:
	Node m_head;
	Node m_tail;
	int m_size;

public:
	List();
	List(const List& other);
	List& operator=(const List& other);

	int size();

	bool isEmpty();

	iterator begin();
	iterator end();

	const_iterator cbegin() const;
	const_iterator cend() const;

	T& front();
	T& back();

	void pushBack(const T& element);
	void popBack();

	void pushFront(const T& element);
	void popFront();

	iterator insert(const iterator position, const T& element);
	iterator erase(const iterator position);

	~List();

private:
	void underflowError();

};

template<class T>
List<T>::List()
	: m_size(0)
{
	m_head.m_next = &m_tail;
	m_tail.m_prev = &m_head;
}

template<class T>
List<T>::List(const List<T>& other)
	: List()
{
	for (auto it = other.cbegin(); it != other.cend(); ++it)
	{
		pushBack(*it);
	}
}

template<class T>
List<T>& List<T>::operator=(const List<T>& other)
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

template<class T>
int List<T>::size()
{
	return m_size;
}

template<class T>
bool List<T>::isEmpty()
{
	return m_size == 0;
}

template<class T>
typename List<T>::iterator List<T>::begin()
{
	return iterator(m_head.m_next);
}

template<class T>
typename List<T>::iterator List<T>::end()
{
	return iterator(&m_tail);
}

template<class T>
typename List<T>::const_iterator List<T>::cbegin() const
{
	return const_iterator(m_head.m_next);
}

template<class T>
typename List<T>::const_iterator List<T>::cend() const
{
	return const_iterator(&m_tail);
}

template<class T>
T& List<T>::front()
{
	return m_head.m_next->m_data;
}

template<class T>
T& List<T>::back()
{
	return m_tail.m_prev->m_data;
}

template<class T>
void List<T>::pushBack(const T& element)
{
	insert(end(), element);
}

template<class T>
void List<T>::popBack()
{
	if (isEmpty())
	{
		underflowError();
	}

	erase(--end());
}

template<class T>
void List<T>::pushFront(const T& element)
{
	insert(begin(), element);
}

template<class T>
void List<T>::popFront()
{
	if (isEmpty())
	{
		underflowError();
	}

	erase(begin());
}

template<class T>
typename List<T>::iterator List<T>::insert(const iterator position, const T& element)
{
	Node* next = position.m_current;
	Node* prev = position.m_current->m_prev;

	Node* newNode = new Node(element, prev, next);

	next->m_prev = newNode;
	prev->m_next = newNode;

	++m_size;

	return iterator(newNode);
}

template<class T>
typename List<T>::iterator List<T>::erase(const iterator position)
{
	if (isEmpty())
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

template<class T>
List<T>::~List()
{
	while (m_size > 0)
	{
		popBack();
	}
}

template<class T>
List<T>::Node::Node(const T& data /*= T()*/, Node* prev /*= nullptr*/, Node* next /*= nullptr*/)
	: m_data(data)
	, m_prev(prev)
	, m_next(next)
{

}

template<class T>
List<T>::iterator::iterator(Node* const current)
	: m_current(current)
{

}

template<class T>
T& List<T>::iterator::operator*()
{
	return m_current->m_data;
}

template<class T>
typename List<T>::iterator List<T>::iterator::operator=(const iterator rhs)
{
	m_current = rhs.m_current;
	return *this;
}

template<class T>
bool List<T>::iterator::operator==(const iterator& rhs)
{
	return rhs.m_current == m_current;
}

template<class T>
bool List<T>::iterator::operator!=(const iterator& rhs)
{
	return !(operator==(rhs));
}

template<class T>
typename List<T>::iterator List<T>::iterator::operator++()
{
	m_current = m_current->m_next;
	return *this;
}

template<class T>
typename List<T>::iterator List<T>::iterator::operator--()
{
	m_current = m_current->m_prev;
	return *this;
}

template<class T>
List<T>::const_iterator::const_iterator(const Node* const current)
	: m_current(current)
{

}

template<class T>
const T& List<T>::const_iterator::operator*()
{
	return m_current->m_data;
}

template<class T>
typename List<T>::const_iterator List<T>::const_iterator::operator=(const const_iterator rhs)
{
	m_current = rhs.m_current;
	return *this;
}

template<class T>
bool List<T>::const_iterator::operator==(const const_iterator& rhs)
{
	return rhs.m_current == m_current;
}

template<class T>
bool List<T>::const_iterator::operator!=(const const_iterator& rhs)
{
	return !(operator==(rhs));
}

template<class T>
typename List<T>::const_iterator List<T>::const_iterator::operator++()
{
	m_current = m_current->m_next;
	return *this;
}

template<class T>
typename List<T>::const_iterator List<T>::const_iterator::operator--()
{
	m_current = m_current->m_prev;
	return *this;
}

template<class T>
void List<T>::underflowError()
{
	std::string exception = std::string("Stack is Empty!");
	throw std::underflow_error(exception);
}

#endif // List_h__