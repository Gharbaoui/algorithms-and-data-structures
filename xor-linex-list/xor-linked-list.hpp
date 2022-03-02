#include <memory>
#include <functional>
#include <algorithm>
/*
 simple xor linked list implmention it's just for testing
 maybe there's some errors but i think it shows the basic ideas of xor linked list
  */


template <typename T>
struct Node
{
	Node() : pn(nullptr) {}
	Node(const T &val) : pn(nullptr), data(val) {}
	Node&operator=(const Node &rhs) {
		data = rhs.data;
		pn = rhs.pn;
		return *this;
	}
	T		data;
	Node	*pn;
};

template <typename T, typename __alloc=std::allocator<Node<T>>>
struct XorLinkedListCont
{
	private:
		__alloc alloc;
	public:
		typedef	Node<T>	node;
		class	iterator;
		iterator begin()
		{
			return iterator(head);
		}
		iterator end()
		{
			return iterator(nullptr);
		}
		XorLinkedListCont();
		node	*data();
		template <typename InputIter>
		void	insert(InputIter first, InputIter last);
		void	insert(const T &val);
		void	excute_on(const std::function<void (const T &)>);
		node	*head;
		node	*cur;
		node	*prv;
};


template <typename T, typename __alloc>
typename XorLinkedListCont<T, __alloc>::node* XorLinkedListCont<T, __alloc>::data()
{
	return head;
}
template <typename T, typename __alloc>
XorLinkedListCont<T, __alloc>::XorLinkedListCont() : head(nullptr), prv(nullptr) , cur(nullptr) {}

template <typename T, typename __alloc>
void	XorLinkedListCont<T, __alloc>::insert(const T &val)
{
	node *tmp = alloc.allocate(1);
	alloc.construct(tmp, val);
	if (!head)
	{
		head = tmp;
	
		head->pn = reinterpret_cast<node *>(
		reinterpret_cast<uintptr_t>(prv) ^ 
		reinterpret_cast<uintptr_t>(nullptr)
		);
	
		cur = head;
	}
	else
	{
		tmp->pn = reinterpret_cast<node *>(
		reinterpret_cast<uintptr_t>(cur) ^
		reinterpret_cast<uintptr_t>(nullptr));
	
		cur->pn = reinterpret_cast<node *>(
		reinterpret_cast<uintptr_t>(prv) ^
		reinterpret_cast<uintptr_t>(tmp));
	
		prv = cur;
		cur = tmp;
	}
}


template <typename T, typename __alloc>
void	XorLinkedListCont<T, __alloc>::excute_on(std::function<void (const T &val)> func)
{
	node *current = head;
	node *previous = nullptr;
	node *next;
	while (current)
	{
		func(current->data);
		next = reinterpret_cast<node *>(
			reinterpret_cast<uintptr_t> (previous) ^
			reinterpret_cast<uintptr_t> (current->pn)
		);
		previous = current;
		current = next;
	}
}


template <typename T, typename __alloc>
template <typename InputIter>
void	XorLinkedListCont<T, __alloc>::insert(InputIter first, InputIter last)
{
	while (first != last)
	{
		insert(*first);
		++first;
	}
}


template <typename T, typename __alloc>
class	XorLinkedListCont<T, __alloc>::iterator
{
	public:
		typedef	T			value_type;
		typedef	std::size_t		difference_type;
		typedef	std::bidirectional_iterator_tag	iterator_category;
		typedef	T*				pointer;
		typedef	T&			reference;
		iterator(); // no default
		iterator(node *start, node *prv=nullptr);
		iterator(const iterator &cp);
		iterator&operator=(const iterator &rhs);
		iterator&operator++();
		iterator&operator--();
		T		&operator*();
		bool	operator==(const iterator &rhs);
		bool	operator!=(const iterator &rhs);
	private:
			node	*current;
			node	*prv;
			node	*next;
};

template <typename T, typename __alloc>
XorLinkedListCont<T, __alloc>::iterator::iterator()
{
	current = nullptr;
	prv = nullptr;
	next = nullptr;
}

template <typename T, typename __alloc>
XorLinkedListCont<T, __alloc>::iterator::iterator(const iterator &cp)
{
	*this = cp;
}


template <typename T, typename __alloc>
typename XorLinkedListCont<T, __alloc>::iterator &XorLinkedListCont<T, __alloc>::iterator::operator=(const iterator &rhs)
{
	current = rhs.current;
	prv = rhs.prv;
	next = rhs.next;
	return *this;
}

template <typename T, typename __alloc>
XorLinkedListCont<T, __alloc>::iterator::iterator(node *cur, node *prv)
{
	current = cur;
	prv = prv;
	next = nullptr;
	if (cur)
	next = reinterpret_cast<node *>
		(
		 	reinterpret_cast<uintptr_t>(prv) ^ reinterpret_cast<uintptr_t>(cur->pn)
		 );
}


template <typename T, typename __alloc>
typename XorLinkedListCont<T, __alloc>::iterator &XorLinkedListCont<T, __alloc>::iterator::operator++()
{
	prv = current;
	current = next;
	if (current)
	next = reinterpret_cast<node *>(
		reinterpret_cast<uintptr_t>(prv) ^
		reinterpret_cast<uintptr_t>(current->pn)
	);
	return *this;
}


template <typename T, typename __alloc>
typename XorLinkedListCont<T, __alloc>::iterator &XorLinkedListCont<T, __alloc>::iterator::operator--()
{
	next = current;
	current = prv;
	prv = reinterpret_cast<node *>(
	reinterpret_cast<uintptr_t>(next) ^ reinterpret_cast<uintptr_t>(current->pn)
	);
	return *this;
}

template <typename T, typename __alloc>
bool	XorLinkedListCont<T, __alloc>::iterator::operator==(const iterator &rhs)
{
	return (current == rhs.current);
}

template <typename T, typename __alloc>
bool	XorLinkedListCont<T, __alloc>::iterator::operator!=(const iterator &rhs)
{
	return (current != rhs.current);
}

template <typename T, typename __alloc>
T &XorLinkedListCont<T, __alloc>::iterator::operator*()
{
	return current->data;
}
