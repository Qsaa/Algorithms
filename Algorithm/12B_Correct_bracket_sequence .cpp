#include <iostream>
#include <string>
#include <vector>


int correct_bracket_sequence()
{
	std::string data; std::cin >> data;
	std::vector<char> brackets;
	for (char c : data)
	{
		if (c == '(' || c == '[' || c == '{')
		{
			brackets.push_back(c);
		}
		else if (c == ')' || c == ']' || c == '}')
		{
			if (brackets.empty())
			{
				std::cout << "no\n";
				return 0;
			}

			if (
				(brackets.back() == '(' && c == ')') ||
				(brackets.back() == '[' && c == ']') ||
				(brackets.back() == '{' && c == '}')
				)
			{
				brackets.pop_back();
			}
			else
			{
				std::cout << "no\n";
				return 0;
			}
		}
	}

	if (brackets.empty())
	{
		std::cout << "yes\n";
	}
	else
	{
		std::cout << "no\n";
	}
	return 0;
}



int test_correct_bracket_sequence()
{
	correct_bracket_sequence();
	return 0;
}