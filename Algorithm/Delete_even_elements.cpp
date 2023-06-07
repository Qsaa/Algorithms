#include <iostream>
#include <vector>

std::ostream& operator<< (std::ostream& out, std::vector<int> vec)
{
	for (int el : vec)
	{
		out << el << " ";
	}
	out << std::endl;
	return out;
}


int delete_even_elements()
{
	//std::vector<int> vec = { 1, 4, 5, 7, 8, 3, 2 };
	//std::vector<int> vec = { 1 };
	//std::vector<int> vec = { 2 };
	std::vector<int> vec = { 0 };
	std::cout << vec;
	size_t i = 0;
	size_t j = 0;
	while(i < vec.size())
	{
		if (vec[i] % 2 == 0)
		{
			vec[j] = vec[i];
			++j;
		}
		++i;
	}
	while (i - j)
	{
		vec.pop_back();
		++j;
	}
	std::cout << vec;
	return 0;
}

int test_delete_even_elements()
{
	delete_even_elements();
	return 0;
}