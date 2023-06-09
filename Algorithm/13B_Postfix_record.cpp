#include <iostream>
#include <sstream>  
#include <string>
#include <vector>
#include <any>


int postfix_record()
{
	using namespace std;

	vector<int> values;

	string str;
	getline(cin, str);
	stringstream ss(str);
	string item;
	while (ss >> item)
	{
		if (item == "*")
		{
			int n = values.back();
			values.pop_back();
			values.back() = values.back() * n;
		}
		//else if (c == '/')
		//{

		//}
		else if (item == "+")
		{
			int n = values.back();
			values.pop_back();
			values.back() = values.back() + n;
		}
		else if (item == "-")
		{
			int n = values.back();
			values.pop_back();
			values.back() = values.back() - n;
		}
		else
		{
			int n = 0;
			for (char c : item)
			{
				n *= 10;
				n += (c - 48);
			}
			values.push_back(n);
		}
	}
	cout << values.back() << endl;
	return 0;
}


int test_postfix_record()
{
	postfix_record();
	return 0;
}