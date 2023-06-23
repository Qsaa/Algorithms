//https://contest.yandex.ru/contest/45468/problems/19/
//
//В этой задаче вам необходимо самостоятельно(не используя соответствующие классы и функции стандартной библиотеки) 
//организовать структуру данных Heap для хранения целых чисел, над которой определены следующие операции : 
//a) Insert(k) – добавить в Heap число k; 
//b) Extract достать из Heap наибольшее число(удалив его при этом).
//
//Формат ввода
//В первой строке содержится количество команд N(1 ≤ N ≤ 100000), 
//далее следуют N команд, каждая в своей строке.Команда может иметь формат : 
//“0 <число>” или “1”, обозначающий, соответственно, операции Insert(<число>) и Extract.
//Гарантируется, что при выполнении команды Extract в структуре находится по крайней мере один элемент.
//
//Формат вывода
//Для каждой команды извлечения необходимо отдельной строкой вывести число, полученное при выполнении команды Extract.

//Пример 1
//Ввод
//2
//0 10000
//1
//
//Вывод
//10000
//Пример 2
//Ввод
//14
//0 1
//0 345
//1
//0 4346
//1
//0 2435
//1
//0 235
//0 5
//0 365
//1
//1
//1
//1
//
//
//Вывод
//345
//4346
//2435
//365
//235
//5
//1

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>  

enum Command
{
	Insert,
	Extract
};

namespace v1
{
	template<typename T>
	struct Heap
	{
		Heap() : size_(0u), capacity_(4u), data_(new T[capacity_]) {}

		void insert(T n)
		{
			if (size_ == capacity_)
			{
				capacity((capacity_ + 1) * 2);
			}
			data_[size_] = n;
			++size_;
			filtr_up();
		}

		T extract()
		{
			T top = data_[0u];
			data_[0u] = data_[size_ - 1];
			--size_;
			filtr_down();
			return top;
		}

		void filtr_up()
		{
			size_t i_child = size_ - 1;
			size_t i_parent = (i_child - 1) / 2;
			while (i_child > 0 && (data_[i_parent] < data_[i_child]))
			{
				swap(data_[i_parent], data_[i_child]);
				i_child = i_parent;
				i_parent = (i_child - 1) / 2;
			}
		}

		void filtr_down()
		{
			size_t i_parent = 0u;
			size_t i_left = i_parent * 2 + 1;
			size_t i_right = i_parent * 2 + 2;

			while (i_right < size_)
			{
				size_t i_child = (data_[i_left] < data_[i_right]) ? i_right : i_left;
				if(data_[i_parent] > data_[i_child])
				{
					break;
				}
				swap(data_[i_parent], data_[i_child]);
				i_parent = i_child;
				i_left = i_parent * 2 + 1;
				i_right = i_parent * 2 + 2;
				i_child = (data_[i_left] < data_[i_right]) ? i_right : i_left;

			}

			if (i_left < size_)
			{
				if (data_[i_parent] < data_[i_left])
				{
					swap(data_[i_parent], data_[i_left]);
				}
			}
		}

		void swap(T& a, T& b)
		{
			T tmp = a;
			a = b;
			b = tmp;
		}

		bool capacity(size_t capacity)
		{
			T* new_data = new T[capacity];
			if (new_data == nullptr)
			{
				return false;
			}

			size_t size = (size_ < capacity) ? size_ : capacity;
			for (size_t i = 0; i < size; ++i)
			{
				new_data[i] = data_[i];
			}
			delete[] data_;
			data_ = new_data;
			capacity_ = capacity;
			return true;
		}

		~Heap()
		{
			delete[] data_;
		}
	private:
		size_t size_;

		size_t capacity_;
		T* data_;
	};
}

void insert(std::vector<int>& heap, int n, std::ostream& output)
{
	heap.push_back(n);
	std::make_heap(heap.begin(), heap.end());
	for (int e : heap)
	{
		output << e << " ";
	}
	output << "\n";
}

int extract(std::vector<int>& heap, std::ostream& output)
{
	int res = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap.resize(heap.size() - 1);
	std::make_heap(heap.begin(), heap.end());
	for (int e : heap)
	{
		output << e << " ";
	}
	output << "\n";

	return res;
}


int hipuy(std::istream& input, std::ostream& output)
{
	v1::Heap<int> heap;
	size_t count; input >> count;
	while(count)
	{
		unsigned com; input >> com;
		switch (com)
		{
		case Command::Insert:
			int n; input >> n;
			heap.insert(n);
			break;
		case Command::Extract:
			output << heap.extract() << "\n";
			break;
		default:
			output << "Unknown command\n";
		}
		--count;
	}
	return 0;
}

int test_hipuy()
{
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");
	//hipuy(input, output);
	hipuy(input, std::cout);
	//hipuy(std::cin, std::cout);
	input.close();
	output.close();


	return 0;
}