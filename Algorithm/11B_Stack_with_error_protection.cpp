#include <iostream>
#include <vector>

/*
struct Stack
{
	Stack()
	{
		data_ = new int[50];
		capacity_ = 50;
		size_ = 0;
	}
	void realloc()
	{
		capacity_ *= 2;
		int* data_new = new int[capacity_];
		for(size_t i = 0; i < size_; ++i)
		{
			data_new[i] = data_[i];
		}
		delete[] data_;
		data_ = data_new;
	}
	~Stack()
	{
		delete[] data_;
	}

	bool push(int n)
	{
		if (size_ == capacity_)
		{
			realloc();
		}
		data_[size_] = n;
		++size_;
	}
private:
	int* data_;
	size_t size_;
	size_t capacity_;
};//*/



enum Command
{
	PUSH,
	POP, 
	BACK,
	SIZE, 
	CLEAR, 
	EXIT
};


int stack_with_error_protection()
{
	std::vector<int> stack;

	while(true)
	{
		std::string command;
		std::cin >> command;
		if/***/ (command == "push")
		{
			int n;
			std::cin >> n;
			stack.push_back(n);
			std::cout << "ok\n";
		}
		else if (command == "pop")
		{
			if (stack.empty())
			{
				std::cout << "error\n";
			}
			else
			{
				std::cout << stack[stack.size() - 1] << "\n";
				stack.pop_back();
			}
		}
		else if (command == "back")
		{
			if (stack.empty())
			{
				std::cout << "error\n";
			}
			else
			{
				std::cout << stack[stack.size() - 1] << "\n";
			}
		}
		else if (command == "size")
		{
			std::cout << stack.size() << "\n";
		}
		else if (command == "clear")
		{
			stack.clear();
			std::cout << "ok\n";
		}
		else if (command == "exit")
		{
			std::cout << "bye\n";
			break;
		}
	}

	return 0;
}

int test_stack_with_error_protection()
{
	return stack_with_error_protection();
}