#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
int good_string(vector<int>& c_count)
{
	//std::greater<>();
	sort(c_count.begin(), c_count.end());

	int result = 0;
	
	size_t i = 0;
	size_t n = c_count.size();
	size_t done = 0;

	while(i < c_count.size() - 1)
	{
		result += (c_count[i] - done) * (n - i - 1);
		done = c_count[i];
		++i;
	}
	return result;
}//*/


int good_string(vector<int>::iterator begin, vector<int>::iterator end, int floor = 0)
{
	if (next(begin) == end)
	{
		return 0;
	}
	int min = *min_element(begin, end);
	int result = 0;
	result += (end - begin - 1) * (min - floor);
	for (vector<int>::iterator here = begin; here != end; ++here)
	{
		if (*here == min)
		{
			result += good_string(begin, here, min);
			begin = next(here);
		}
	}
	return result;
}


int test_good_string()
{
	size_t N; cin >> N;
	vector<int> c_count;
	c_count.reserve(N);
	for (size_t i = 0; i < N; ++i)
	{
		int count;
		cin >> count;
		c_count.push_back(count);
	}
	cout << good_string(c_count.begin(), c_count.end());
	return 0;
}