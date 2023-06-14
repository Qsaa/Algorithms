//==========================
// start 16:10 14.06.2023 - 
//==========================

#include <iostream>
#include <vector>
#include <string>

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
				queue.push(n);
				cout << "ok" << endl;
			}
			else if (command == "pop")
			{
				if (!queue.empty())
				{
					cout << queue.pop() << endl;
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

int test_queue_with_ptotection_error_v1()
{
	v1::queue_with_protection_error();
	return 0;
}