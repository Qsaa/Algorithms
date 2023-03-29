#include <iostream>
#include <vector>
#include <array>

using namespace std;

int sum_in_the_rastangle()
{
	return 0;
}

int test_sum_in_the_rastangle()
{
	int N; cin >> N; // count of strings
	int M; cin >> M; // count of column
	size_t n_requests; cin >> n_requests;
	vector<vector<int>> matrix;
	matrix.resize(N);
	for (size_t i = 0; i < N; ++i)
	{
		matrix[i].resize(M);
		for (size_t j = 0; i < M; ++j)
		{
			int p; cin >> p;
			matrix[i][j] = p;
		}
	}
	sum_in_the_rastangle();
	return 0;
}