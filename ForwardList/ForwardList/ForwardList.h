#ifndef ForwardList_h__
#define ForwardList_h__

#include <iostream> 

#include <memory>

template <class T>
struct Node
{
	using NodePtr = std::_Rebind_pointer_t<void*, Node>;

	Node(NodePtr next, const T& data)
		: m_next(next)
		, m_data(data)
	{

	}

	Node(NodePtr next, T&& data)
		: m_next(next)
		, m_data(std::move(data))
	{

	}

	NodePtr m_next;
	T m_data;
};

template <class MyList>
struct Iterator
{
	using NodePtr = typename MyList::NodePtr;
	using reference = typename MyList::reference;

	explicit Iterator(NodePtr const current)
		: m_current(current)
	{

	}

	reference operator*()
	{
		return m_current->m_data;
	}

	NodePtr m_current;
};

template <class MyList>
struct Const_Iterator : public Iterator<MyList>
{
	using NodePtr = typename MyList::NodePtr;
	using const_reference = typename MyList::const_reference;

	explicit Const_Iterator(NodePtr const current)
		: m_current(current)
	{

	}

	const_reference operator*()
	{
		return m_current->m_data;
	}

	NodePtr m_current;
};

template <class T, class Alloc = std::allocator<T>>
class ForwardList
{
	static_assert(!_ENFORCE_MATCHING_ALLOCATORS || std::is_same<T, typename Alloc::value_type>::value);

private:
	using NodeAllocator = std::_Rebind_alloc_t<Alloc, Node<T>>;
	using NodeAllocatorTraits = std::allocator_traits<NodeAllocator>;

public:
	using reference = T&;
	using const_reference = const T&;

	using iterator = Iterator<ForwardList>;
	using const_iterator = Const_Iterator<ForwardList>;

	using NodePtr = typename NodeAllocatorTraits::pointer;

public:
	ForwardList()
		: m_head(nullptr)
		, m_size(0)
	{

	}

	ForwardList(const ForwardList& other)
		: ForwardList()
	{

	}

	ForwardList& operator=(const ForwardList& other)
	{
		return *this;
	}

	ForwardList(ForwardList&& other)
		: ForwardList()
	{

	}

	ForwardList& operator=(ForwardList&& other) noexcept
	{
		return *this;
	}

	ForwardList(std::initializer_list<T> init/*, const Allocator& alloc = Allocator()*/)
		: ForwardList()
	{
	}

	ForwardList& operator=(std::initializer_list<T> ilist)
	{
		return *this;
	}

	//explicit ForwardList(const Alloc& alloc)
	//{

	//}

	//ForwardList(size_type count, const T& value, const Alloc& alloc = Allocator())
	//{

	//}

	//explicit ForwardList(size_type count, const Alloc& alloc = Allocator())
	//{

	//}

	~ForwardList()
	{

	}

	[[nodiscard]] iterator begin()
	{
		return iterator(m_head);
	}

	[[nodiscard]] const_iterator begin() const
	{
		return const_iterator(m_head);
	}

	[[nodiscard]] const_iterator cbegin() const
	{
		return begin();
	}

	[[nodiscard]] reference front()
	{
		return *begin();
	}

	[[nodiscard]] const_reference front() const
	{
		return *begin();
	}

	[[nodiscard]] bool empty() const noexcept
	{
		return false;
	}

	[[nodiscard]] std::size_t max_size() const noexcept
	{
		return 0;
	}

	void clear() noexcept
	{

	}

private:
	NodePtr m_head;
	std::size_t m_size;
};

#endif // ForwardList_h__