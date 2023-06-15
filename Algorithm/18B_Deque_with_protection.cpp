#include <iostream>

struct Deque
{
	void push_front(int n)
	{
		head_ = prev_item(head_);
		data_[head_] = n;
	}
	void push_back(int n)
	{
		data_[tail_] = n;
		tail_ = next_item(tail_);
	}

	int pop_front()
	{
		int tmp = data_[head_];
		head_ = next_item(head_);
		return tmp;
	}

	int pop_back()
	{
		tail_ = prev_item(tail_);
		return data_[tail_];
	}

	int front()
	{
		return data_[head_];
	}

	int back()
	{
		return data_[prev_item(tail_)];
	}

	size_t size()
	{
		return (tail_ >= head_) ? tail_ - head_ : capacity_ + tail_ - head_;
	}

	void clear()
	{
		head_ = 0;
		tail_ = 0;
	}


	size_t next_item(size_t n)
	{
		return (n + 1) % capacity_;
	}

	size_t prev_item(size_t n)
	{
		if (n == 0)
		{
			return capacity_ - 1;
		}
		else
		{
			return n - 1;
		}
	}

private:
	const static  size_t capacity_ = 101;
	int data_[capacity_] = { 0 };
	
	size_t head_ = 0;
	size_t tail_ = 0;
	//size_t size_ = 0;
};

void handler_deque(Deque& deque, std::istream& input, std::ostream& output)
{
	std::string command;
	while (true)
	{
		input >> command;
		if (command == "push_front")
		{
			int n; input >> n;
			deque.push_front(n);
			output << "ok\n";
		}
		else if (command == "push_back")
		{
			int n; input >> n;
			deque.push_back(n);
			output << "ok\n";
		}
		else if (command == "pop_front")
		{
			if (deque.size())
			{
				output << deque.pop_front() << "\n";
			}
			else
			{
				output << "error\n";
			}
		}
		else if (command == "pop_back")
		{
			if (deque.size())
			{
				output << deque.pop_back() << "\n";
			}
			else
			{
				output << "error\n";
			}
		}
		else if (command == "front")
		{
			if (deque.size())
			{
				output << deque.front() << "\n";
			}
			else
			{
				output << "error\n";
			}
		}
		else if (command == "back")
		{
			if (deque.size())
			{
				output << deque.back() << "\n";
			}
			else
			{
				output << "error\n";
			}
		}
		else if (command == "size")
		{
			output << deque.size() << "\n";
		}
		else if (command == "clear")
		{
			deque.clear();
			output << "ok\n";
		}
		else if (command == "exit")
		{
			output << "bye\n";
			return;
		}
	}
}


int deque_with_protection()
{
	Deque deque;
	handler_deque(deque, std::cin, std::cout);
	return 0;
}

int test_deque_with_protection()
{
	return deque_with_protection();
}