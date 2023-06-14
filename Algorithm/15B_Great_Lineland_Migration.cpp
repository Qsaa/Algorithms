#include <iostream>
#include <vector>
#include <utility>

int great_lineland_migration()
{
	using namespace std;
	vector<pair<int, int>> cities;
	// price, place
	int n; cin >> n;
	vector<int> result(n, -1);
	for (int i = 0; i < n; ++i)
	{
		size_t price; cin >> price;
		while (!cities.empty() && cities.back().first > price)
		{
			result[cities.back().second] = i;
			cities.pop_back();
		}
		cities.push_back(make_pair(price, i));
	}
	
	for (int pos : result)
	{
		cout << pos << " ";
	}
	cout << endl;
	return 0;
}

int test_great_lineland_migration()
{
	great_lineland_migration();
	return 0;
}