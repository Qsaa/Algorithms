#include <string>
#include <iostream>

namespace v2
{
	struct Queue
	{
		Queue() : first_(0u), size_(0u), capacity_(4u), data_(new int[4])
		{}

		bool empty()
		{
			return (size() == 0);
		}

		size_t size()
		{
			return size_;
		}

		int front()
		{
			return data_[first_];
		}

		int back()
		{
			return data_[size_ - 1];
		}

		void push_back(int n)
		{
			if (size_ == capacity_)
			{
				capacity((capacity_ + 1) * 2);
			}
			data_[size_] = n;
			++size_;
		}

		void capacity(size_t n)
		{
			int* new_data = new int[n];
			for (size_t i = 0; i < size_; ++i)
			{
				new_data[first_ + i] = data_[first_ + i];
			}
			delete[] data_;
			data_ = new_data;
		}

		int pop_front()
		{
			--size_;
			return  data_[first_++];
		}

		void clear()
		{
			first_ = 0;
			size_ = 0;
			capacity_ = 0;
			delete[] data_;
			data_ = nullptr;
		}

		~Queue()
		{
			delete[] data_;
		}

	private:
		size_t first_;
		size_t size_;
		size_t capacity_;
		int* data_;
	};


	int queue_with_protection_error()
	{
		using namespace std;
		Queue queue;
		while (true)
		{
			string command; cin >> command;
			if (command == "push")
			{
				int n; cin >> n;
				queue.push_back(n);
				cout << "ok" << endl;
			}
			else if (command == "pop")
			{
				if (!queue.empty())
				{
					cout << queue.pop_front() << endl;
				}
				else
				{
					cout << "error" << endl;
				}

			}
			else if (command == "front")
			{
				if (!queue.empty())
				{
					cout << queue.front() << endl;
				}
				else
				{
					cout << "error" << endl;
				}
			}
			else if (command == "size")
			{
				cout << queue.size() << endl;
			}
			else if (command == "clear")
			{
				queue.clear();
				std::cout << "ok" << std::endl;
			}
			else if (command == "exit")
			{
				cout << "bye" << endl;
				break;
			}
		}

		return 0;
	}

}

int test_queue_with_ptotection_error_v2()
{
	v2::queue_with_protection_error();
	return 0;
}