
#include <iostream>

template <typename T>
struct Node
{
	Node() : value_(T()), next_(nullptr) {}
	Node(T n) : value_(n), next_(nullptr) {}
	
	Node* next_;
	T value_;
};

Node<int>* create_list(size_t n)
{
	if (n == 0)
	{
		return nullptr;
	}

	Node<int>* begin;
	begin = new Node<int>;

	Node<int>* here = begin;
	for (size_t i = 1; i < n; ++i)
	{
		here->next_ = new Node<int>;
		here = here->next_;
		here->value_ = i;
	}
	here->next_ = nullptr;
	return begin;
}

void print_list(const Node<int>* p)
{
	while (p)
	{
		std::cout << p->value_ << " ";
		p = p->next_;
	}
}

Node<int>* revese_list(Node<int>* elem)
{
	if (!elem || !elem->next_)
	{
		return elem;
	}

	Node<int>* el_prev = elem;
	Node<int>* el_this = nullptr;
	
	elem = elem->next_;
	el_prev->next_ = nullptr;
	while (elem)
	{
		el_this = elem;
		elem = elem->next_;

		el_this->next_ = el_prev;
		el_prev = el_this;
	}

	return el_this;
}

int test_list_reverse()
{

	Node<int>* el = create_list(8);
	print_list(el);
	el = revese_list(el);
	print_list(el);
	return 0;
}