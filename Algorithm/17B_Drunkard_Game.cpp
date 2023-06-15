#include <iostream>;

namespace v1
{
	struct Ring_queue
	{
		void push(int n)
		{
			tail_ = tail_ % capasity_;
			data_[tail_] = n;
			++tail_;
		}

		void double_push(int n1, int n2)
		{
			push(n1);
			push(n2);;
		}

		int pop()
		{
			int tmp = data_[head_];
			head_ = (head_ + 1) % capasity_;
			return tmp;
		}

		size_t size()
		{
			return (tail_ > head_) ? (tail_ - head_) : (capasity_ + tail_ - head_);
		}

	private:
		size_t head_ = 0;
		size_t tail_ = 0;
		size_t capasity_ = 11;
		int data_[11];
	};
}

namespace v2
{
	struct Ring_queue
	{
		void push(int n)
		{
			data_[(head_ + size_) % capasity_] = n;
			++size_;
		}

		void double_push(int n1, int n2)
		{
			push(n1);
			push(n2);;
		}

		int pop()
		{
			int tmp = data_[head_];
			head_ = (head_ + 1) % capasity_;
			--size_;
			return tmp;
		}

		size_t size()
		{
			return size_;
		}

	private:
		size_t head_ = 0;
		size_t size_ = 0;
		size_t capasity_ = 10;
		int data_[10];
	};
}



int drunkard_game()
{
	using namespace v2;
	using namespace std;
	Ring_queue player1;
	int n;
	for (size_t i = 0; i < 5u; ++i)
	{
		cin >> n;
		player1.push(n);
	}
	Ring_queue player2;
	for (size_t i = 0; i < 5u; ++i)
	{
		cin >> n;
		player2.push(n);
	}
	
	for (size_t n = 1'000'000; n; --n)
	{
		int p1 = player1.pop();
		int p2 = player2.pop();
		if (p1 > p2)
		{
			if (p1 == 9 && p2 == 0)
			{
				player2.double_push(p1, p2);
			}
			else
			{
				player1.double_push(p1, p2);
			}
		}
		else
		{
			if (p2 == 9 && p1 == 0)
			{
				player1.double_push(p1, p2);
			}
			else
			{
				player2.double_push(p1, p2);
			}
		}

		if (player1.size() == 10)
		{
			cout << "first " << 1'000'000 - n + 1 << endl;
			return 0;
		}
		else if (player2.size() == 10)
		{
			cout << "second " << 1'000'000 - n + 1 << endl;
			return 0;
		}
	}
	cout << "botva" << endl;
	return 0;
}

int test_drunkard_game()
{
	drunkard_game();
	return 0;
}