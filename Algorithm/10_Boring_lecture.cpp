#include <iostream>
#include <fstream>
#include <string>
#include <map>

int boring_lecture();

int test_boring_lecture()
{
	boring_lecture();
	return 0;
}

void print_answer(const std::map<char, uint64_t>& dict)
{
	for (auto pair : dict)
	{
		std::cout << pair.first << ": " << pair.second << std::endl;
	}
}


int boring_lecture()
{
	std::string str; std::cin >> str;
	
	//std::string str;
	//std::fstream input("10_Boring_lecture_09.txt");
	//if (!input.is_open())
	//{
	//	std::cout << "Error" << std::endl;
	//}
	// input >> str;
	// input.close();
	
	//long long unsigned
	std::map<char, uint64_t> dict;
	size_t len = str.size();
	for (size_t i = 0; i < len; ++i)
	{
		dict[str[i]] += (i + 1) * (len - i);
	}
	print_answer(dict);

	return 0;
}