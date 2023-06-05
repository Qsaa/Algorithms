#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

int test_sum_in_the_rastangle()
{
	//fstream input("08.txt");
	fstream input("9_Sum_in_the_restangle_00.txt");
	if (!input.is_open())
	{
		cout << "File is not opened" << endl;
	}
	
	size_t N; input >> N; // count of strings 1000
	size_t M; input >> M; // count of column 1000
	size_t& n_strings = N;
	size_t& n_columns = M;
	
	size_t n_requests; input >> n_requests;
	Matrix data_matrix;
	data_matrix.resize(n_strings);
	for (size_t i = 0; i < data_matrix.size()/*n_strings*/; ++i)
	{
		data_matrix[i].resize(n_columns);
		for (size_t j = 0; j < data_matrix[0].size()/*n_columns*/; ++j)
		{
			int p; input >> p;
			data_matrix[i][j] = p;
		}
	}

	Matrix aux_matrix;
	aux_matrix.resize(n_strings);
	for (size_t i = 0; i < n_strings; ++i)
	{
		aux_matrix[i].resize(n_columns);
		aux_matrix[i][0] = data_matrix[i][0];
		for (size_t j = 1; j < n_columns; ++j)
		{
			aux_matrix[i][j] = aux_matrix[i][j - 1] + data_matrix[i][j];
		}
	}

	for(size_t i = 0; i < n_requests; ++i)
	{
		int i_min, i_max, j_min, j_max;
		input >> i_min; input >> j_min;
		input >> i_max; input >> j_max;
		i_min -= 1;
		i_max -= 1;
		j_min -= 1;
		j_max -= 1;

		int result = 0;
		for (size_t i = i_min; i <= i_max; ++i)
		{
			result += aux_matrix[i][j_max] - aux_matrix[i][j_min] + data_matrix[i][j_min];
		}
		cout << result << endl;
	}
	input.close();
	return 0;
}