#include <iostream>
#include <fstream>
#include <vector>

using namespace std;




int sum_in_the_rastangle(auto& matrix, int i_min, int j_min, int i_max, int j_max)
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
	for (size_t i = 0; i < matrix.size(); ++i)
	{
		matrix[i].resize(M);
		for (size_t j = 0; j < matrix[0].size(); ++j)
		{
			int p; input >> p;
			matrix[i][j] = p;
		}
	}

	vector<vector<vector<vector<int>>>> result_matrix;

	result_matrix.resize(matrix.size());
	for (size_t i = 0; i < matrix.size(); ++i)
	{
		result_matrix[i].resize(matrix[0].size());
		for (size_t j = 0; j < matrix[0].size(); ++j)
		{
			result_matrix[i][j].resize(matrix.size());
			for (size_t k = 0; k < matrix.size(); ++k)
			{
				result_matrix[i][j][k].resize(matrix[0].size());
				for (size_t l = 0; l < matrix[0].size(); ++l)
					result_matrix[i][j][k][l] = sum_in_the_rastangle(matrix, i + 1, j + 1, k + 1, l + 1);
			}
		}
	}//*/


	
	for(size_t i = 0; i < n_requests; ++i)
	{
		int i_min, i_max, j_min, j_max;
		input >> i_min; input >> j_min;
		input >> i_max; input >> j_max;
		//cout << sum_in_the_rastangle(matrix, i_min, j_min, i_max, j_max) << endl;
		cout << result_matrix[i_min - 1][j_min - 1][i_max - 1][j_max - 1] << endl;
	}
	input.close();
	return 0;
}