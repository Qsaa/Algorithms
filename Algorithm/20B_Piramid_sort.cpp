#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

template<typename T>
struct Heap
{
	Heap() :size_(0u), capacity_(4), data_(new T[4]) {}

	bool capacity(size_t new_capacity)
	{
		T* new_data = new T[new_capacity];
		if (new_data == nullptr)
		{
			std::cout << "Error" << std::endl;
			return false;
		}
		size_t size = (size_ < new_capacity) ? size_ : new_capacity;
		for (size_t i = 0; i < size; ++i)
		{
			new_data[i] = data_[i];
		}
		delete[] data_;
		data_ = new_data;
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
		int first_n = data_[0];
		data_[0] = data_[size_ - 1];
		--size_;
		filtr_down();
		return first_n;
	}

	void filtr_up()
	{
		int i_child = size_ - 1;
		int i_parent = (i_child - 1) / 2;
		//while (data_[i_child] > data_[i_parent])
		while (data_[i_child] < data_[i_parent])
		{
			swap(data_[i_child], data_[i_parent]);
			i_child = i_parent;
			i_parent = (i_child - 1) / 2;
		}

	}

	void filtr_down()
	{
		size_t i_parent = 0;
		size_t i_left = i_parent * 2 + 1;
		size_t i_right = i_parent * 2 + 2;
		size_t max_child = 0;
		while (i_right < size_)
		{
			//max_child = (data_[i_left] < data_[i_right]) ? i_right : i_left;
			max_child = (data_[i_left] > data_[i_right]) ? i_right : i_left;
			//if (data_[max_child] <= data_[i_parent])
			if (data_[max_child] >= data_[i_parent])
			{
				break;
			}
			swap(data_[max_child], data_[i_parent]);
			i_parent = max_child;
			i_left = i_parent * 2 + 1;
			i_right = i_parent * 2 + 2;

		}
		if (
			(i_left < size_) &&
			//(data_[i_parent] < data_[i_left])
			(data_[i_parent] > data_[i_left])
			)
		{
			swap(data_[i_left], data_[i_parent]);
		}
	}

	void swap(T& a, T& b)
	{
		T t = a;
		a = b;
		b = t;
	}

	void print()
	{
		using namespace std;
		cout << "Heap" << endl;
		for (size_t i = 0; i < size_; ++i)
		{
			cout << data_[i] << " ";
		}
		cout << endl;
	}
private:
	size_t size_;
	size_t capacity_;
	T* data_;
};



int piramid_sort(std::istream& input, std::ostream& output)
{
	Heap<int> heap;
	size_t n; input >> n;
	for(size_t i = 0; i < n; ++i)
	{
		int data; input >> data;
		heap.insert(data);
	}
	for (size_t i = 0; i < n; ++i)
	{
		output << heap.extract() << " ";
	}
	output << "\n";
	return 0;
}


int test_piramid_sort()
{
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");
	//piramid_sort(std::cin, std::cout);
	//piramid_sort(input, std::cout);
	piramid_sort(input, output);
	input.close();
	output.close();
	return 0;
}