#include <iostream>


struct Head
{
	Head() :size_(0u), capacity_(4), data_(new int[4]) {}
	bool capacity(size_t new_capacity)
	{
		int* new_data = new int[new_capacity];
		if (new_data == nullptr)
		{
			return false;
		}
		for (size_t i = 0; i < size_; ++i)
		{
			new_data[i] = data_[i];
		}
		capacity_ = new_capacity;
		return true;
	}

	void insert(int added_n)
	{
		if (size_ == capacity_)
		{
			capacity((capacity_ + 1) * 2);
		}
		data_[size_] = added_n;
		++size_;
		filtr_up();
	}

	int extract()
	{

		return 0;
	}

	void filtr_up()
	{
		size_t i_child = size_ - 1;
		size_t i_parent = (i_child - 1) / 2;
		while (data_[i_child] > data_[i_parent])
		{
			swap(data_[i_child], data_[i_parent]);
			i_child = i_parent;
			i_parent = (i_child - 1) / 2;
		}

	}

	void swap(int& a, int& b)
	{
		int t = a;
		a = b;
		b = a;
	}
private:
	size_t size_;
	size_t capacity_;
	int* data_;
};


int piramid_sort()
{
	return 0;
}


int test_piramid_sort()
{
	return 0;
}