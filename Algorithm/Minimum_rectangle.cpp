#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct Point
{
	Point(int in_x, int in_y) : x(in_x), y(in_y) {}

	int x;
	int y;
};

array<int, 4> minimum_restangle(auto& coordinates)
{
	int min_x, min_y, max_x, max_y;
	min_x = max_x = coordinates[0].x;
	min_y = max_y = coordinates[0].y;
	for (size_t i = 1; i < coordinates.size(); ++i)
	{
		if (min_x > coordinates[i].x)
		{
			min_x = coordinates[i].x;
		}
		if (max_x < coordinates[i].x)
		{
			max_x = coordinates[i].x;
		}
		if (min_y > coordinates[i].y)
		{
			min_y = coordinates[i].y;
		}
		if (max_y < coordinates[i].y)
		{
			max_y = coordinates[i].y;
		}
	}
	return {min_x, min_y, max_x, max_y};
}

int test_minimun_restangle()
{
	int K; cin >> K;
	vector<Point> coordinates;
	coordinates.reserve(K);
	for (int i = 0; i < K; ++i)
	{
		int x; cin >> x;
		int y; cin >> y;
		coordinates.push_back(Point(x, y));
	}

	for (auto a : minimum_restangle(coordinates))
	{
		cout << a << " ";
	}
	return 0;
}