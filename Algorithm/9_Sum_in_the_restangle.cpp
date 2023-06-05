#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;
using Line = vector<int>;

int test_sum_in_the_rastangle()
{
	// Need to replace cin on input 
	// uncommint lines of code where it reading from file
	
	//fstream input("9_Sum_in_the_restangle_00.txt");
	//fstream input("9_Sum_in_the_restangle_00.txt");
	//if (!input.is_open())
	//{
	//	cout << "File is not opened" << endl;
	//}
	
	// begin of reading data___
	size_t N; cin >> N; // count of strings 1000
	size_t M; cin >> M; // count of column 1000
	size_t& n_strings = N;
	size_t& n_columns = M;
	
	size_t n_requests; cin >> n_requests;
	Matrix data_matrix;
	data_matrix.resize(n_strings);
	for (size_t i = 0; i < data_matrix.size()/* = n_strings*/; ++i)
	{
		data_matrix[i].resize(n_columns);
		for (size_t j = 0; j < data_matrix[0].size()/* = n_columns*/; ++j)
		{
			int p; cin >> p;
			data_matrix[i][j] = p;
		}
	}
	// input.close();
	// end of reading data___

	// Matrix of prefix amounts 
	Matrix pref_amount_matrix;

	pref_amount_matrix.resize(n_strings);
	pref_amount_matrix[0].resize(n_columns);
	pref_amount_matrix[0][0] = data_matrix[0][0];
	for (size_t j = 1; j < n_columns; ++j)
	{
		pref_amount_matrix[0][j] = pref_amount_matrix[0][j - 1] + data_matrix[0][j];
	}
	for (size_t i = 1; i < n_strings; ++i)
	{
		Line pref_amount_line(n_columns);
		pref_amount_matrix[i].resize(n_columns);
		
		pref_amount_line[0] = data_matrix[i][0];
		pref_amount_matrix[i][0] = pref_amount_matrix[i - 1][0] + pref_amount_line[0];
		for (size_t j = 1; j < n_columns; ++j)
		{
			pref_amount_line[j] = pref_amount_line[j - 1] + data_matrix[i][j];
			pref_amount_matrix[i][j] = pref_amount_matrix[i - 1][j] + pref_amount_line[j];
		}
	}
	// end of prefix sum calculation
	

	for(size_t i = 0; i < n_requests; ++i)
	{
		int i_min, i_max, j_min, j_max;
		cin >> i_min; cin >> j_min;
		cin >> i_max; cin >> j_max;
		i_min -= 2;
		i_max -= 1;
		j_min -= 2;
		j_max -= 1;

		int result = 0;
		result = pref_amount_matrix[i_max][j_max];
		if (i_min >= 0 && j_min >= 0)
		{
			result += pref_amount_matrix[i_min][j_min];
		}
		if (i_min >= 0)
		{
			result -= pref_amount_matrix[i_min][j_max];
		}
		if (j_min >= 0)
		{
			result -= pref_amount_matrix[i_max][j_min];
		}
		cout << result << endl;
	}
	return 0;
}