#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int sum_in_the_rastangle(auto& matrix, int i_min, int i_max, int j_min, int j_max)
{
	int result = 0;
	for (int i = i_min - 1; i < i_max; ++i)
	{
		for (int j = j_min - 1; j < j_max; ++j)
		{
			result += matrix[i][j];
		}
	}
	return result;
}

int test_sum_in_the_rastangle()
{
	fstream input("08.txt");
	if (!input.is_open())
	{
		cout << "File is not opened" << endl;
	}
	
	int N; input >> N; // count of strings 1000
	int M; input >> M; // count of column 1000
	size_t n_requests; input >> n_requests;
	vector<vector<int>> matrix;
	matrix.resize(N);
	for (size_t i = 0; i < N; ++i)
	{
		matrix[i].resize(M);
		for (size_t j = 0; j < M; ++j)
		{
			int p; input >> p;
			matrix[i][j] = p;
		}
	}
	
	for(size_t i = 0; i < n_requests; ++i)
	{
		int i_min, i_max, j_min, j_max;
		input >> i_min; input >> j_min;
		input >> i_max; input >> j_max;
		cout << sum_in_the_rastangle(matrix, i_min, i_max, j_min, j_max) << endl;
	}
	input.close();
	return 0;
}