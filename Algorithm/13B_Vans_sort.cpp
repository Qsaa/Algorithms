#include <iostream>
#include <vector>


int vans_sort()
{
	using namespace std;
	vector<int> reverse;
	
	size_t ahead = 1;
	size_t n; cin >> n;
	
	while(n)
	{
		int i; cin >> i;
		if (i == ahead)
		{
			++ahead;
			while (!reverse.empty() && ahead == reverse.back())
			{
				++ahead;
				reverse.pop_back();
			}
		}
		else
		{
			reverse.push_back(i);
		}
		--n;
	}

	if (reverse.empty())
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}

int test_vans_sort()
{
	vans_sort();
	return 0;
}