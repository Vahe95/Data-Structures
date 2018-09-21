#ifndef Stack_h__
#define Stack_h__

#include <string>

template<class T>
class Stack
{
private:
	struct Node
	{
		T m_data;
		Node* m_next;

		Node(const T& data = T(), Node* next = nullptr);
	};

private:
	Node* m_top;
	int m_size;

public:
	Stack();
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);

	bool isEmpty();

	T& top();

	int size();

	void push(const T& data);
	void pop();

	~Stack();

private:
	void pushElementsFromOneStackToOnother(const Stack& from, Stack& to);

	void underflowError();

};

template<class T>
void Stack<T>::underflowError()
{
	std::string exception = std::string("Stack is Empty!");
	throw std::underflow_error(exception);
}

template<class T>
Stack<T>::Stack()
	: m_top(nullptr)
	, m_size(0)
{

}

template<class T>
Stack<T>::Stack(const Stack<T>& other)
	: Stack()
{
	Stack reverseStack;

	pushElementsFromOneStackToOnother(other, reverseStack);
	pushElementsFromOneStackToOnother(reverseStack, *this);
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	Stack temp(other);

	std::swap(m_top, temp.m_top);
	std::swap(m_size, temp.m_size);

	return *this;
}

template<class T>
bool Stack<T>::isEmpty()
{
	return m_size == 0;
}

template<class T>
int Stack<T>::size()
{
	return m_size;
}

template<class T>
T& Stack<T>::top()
{
	return m_top->m_data;
}

template<class T>
void Stack<T>::push(const T& data)
{
	Node* newNode = new Node(data, m_top);

	m_top = newNode;

	++m_size;
}

template<class T>
void Stack<T>::pop()
{
	if (isEmpty())
	{
		underflowError();
	}

	Node* next = m_top;

	m_top = m_top->m_next;

	delete next;

	--m_size;
}

template<class T>
Stack<T>::~Stack()
{
	while (size() > 0)
	{
		pop();
	}
}

template<class T>
void Stack<T>::pushElementsFromOneStackToOnother(const Stack& from, Stack& to)
{
	Node* nextNode = from.m_top;

	while (nextNode != nullptr)
	{
		to.push(nextNode->m_data);
		nextNode = nextNode->m_next;
	}
}

template<class T>
Stack<T>::Node::Node(const T& data /*= T()*/, Node* next /*= nullptr*/)
	: m_data(data)
	, m_next(next)
{

}

#endif // Stack_h__