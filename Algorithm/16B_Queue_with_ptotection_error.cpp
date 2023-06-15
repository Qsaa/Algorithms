#include <iostream>
#include <vector>
#include <string>

#include <fstream>
#include <queue>


namespace v1
{
	struct Queue
	{
		Queue() {}

		void push(int n)
		{
			queue_.push_back(n);
		}

		int pop()
		{
			return queue_[first_++];
		}

		int front()
		{
			return queue_[first_];
		}

		size_t size()
		{
			return (empty()) ? 0 : (queue_.size() - first_);
		}

		void clear()
		{
			queue_.clear();
			first_ = 0;
		}

		bool empty()
		{
			return (queue_.empty() || (queue_.size() <= first_));
		}

		~Queue() {}
	private:
		std::vector<int> queue_;
		size_t first_ = 0;
	};//*/
}

namespace v2
{
	struct Queue
	{
		Queue() : head_(0u), tail_(0u), capacity_(0u), data_(new int[capacity_])
		{}

		bool empty()
		{
			return (size() == 0);
		}

		size_t size()
		{
			return tail_ - head_;
		}

		int front()
		{
			return data_[head_];
		}

		int back()
		{
			return data_[tail_ - 1];
		}

		void push(int n)
		{
			if (tail_ == capacity_)
			{
				if (size() * 2 < capacity_)
				{
					shift_queue_ahead();
				}
				else
				{
					capacity((capacity_ + 2) * 2);
				}
			}
			data_[tail_] = n;
			++tail_;
		}

		void shift_queue_ahead()
		{
			size_t size = tail_ - head_;
			for (size_t i = 0; i < size; ++i, ++tail_)
			{
				data_[i] = data_[head_ + i];
			}
			head_ = 0;
			tail_ = size;
		}

		void capacity(size_t n)
		{
			int* new_data = new int[n];

			size_t size = tail_ - head_;
			for (size_t i = 0; i < size; ++i, ++tail_)
			{
				new_data[i] = data_[head_ + i];
			}
			head_ = 0;
			tail_ = size;

			delete[] data_;
			data_ = new_data;
			capacity_ = n;
		}

		int pop()
		{
			return  data_[head_++];
		}

		void clear()
		{
			head_ = 0;
			tail_ = 0;
			capacity_ = 0;
			delete[] data_;
			data_ = nullptr;
		}

		~Queue()
		{
			delete[] data_;
		}

	private:
		size_t head_;
		size_t tail_;
		size_t capacity_;
		int* data_;
	};
}

namespace v3
{
	//using Queue = std::queue<int>;
	struct Queue : std::queue<int>
	{
		int pop()
		{
			int tmp = front();
			std::queue<int>::pop();
			return tmp;
		}

		void clear()
		{
			//Queue::~Queue();
			//std::queue<int> queue;
			//this = &queue;
			while(!empty())
			{
				std::queue<int>::pop();
			}
		}
	};
}

template<typename T>
int handler_queue(T& queue, std::istream& input, std::ostream& output)
{
	while (true)
	{
		std::string command; input >> command;
		if (command == "push")
		{
			int n; input >> n;
			queue.push(n);
			output << "ok" << std::endl;
		}
		else if (command == "pop")
		{
			if (!queue.empty())
			{
				output << queue.pop() << std::endl;
			}
			else
			{
				output << "error" << std::endl;
			}

		}
		else if (command == "front")
		{
			if (!queue.empty())
			{
				output << queue.front() << std::endl;
			}
			else
			{
				output << "error" << std::endl;
			}
		}
		else if (command == "size")
		{
			output << queue.size() << std::endl;
		}
		else if (command == "clear")
		{
			queue.clear();
			output << "ok" << std::endl;
		}
		else if (command == "exit")
		{
			output << "bye" << std::endl;
			break;
		}
	}

	return 0;
}

int queue_with_ptotection_error()
{
	v1::Queue queue;
	handler_queue(queue, std::cin, std::cout);
	return 0;
}

int test_queue_with_ptotection_error()
{
	queue_with_ptotection_error();
	return 0;
}

/*
void check1()
{
	std::ifstream input1("16B_Queue_with_protection_error_08.txt");
	std::ofstream output1("output1.txt");
	v1::queue_with_protection_error(input1, output1);
	input1.close();
	output1.close();


	std::ifstream input2("16B_Queue_with_protection_error_08.txt");
	std::ofstream output2("output2.txt");
	v2::queue_with_protection_error(input2, output2);
	output2.close();
	input2.close();

	std::ifstream comp1("output1.txt");
	std::ifstream comp2("output2.txt");

	std::string str1;
	std::string str2;
	size_t n_line = 0;
	while (comp1 >> str1 && comp2 >> str2)
	{
		++n_line;
		if (str1 != str2)
		{
			std::cout << n_line << ": " << str1 << " ; " << str2 << "\n";
		}
	}
}//*/