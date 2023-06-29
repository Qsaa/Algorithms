#include <iostream>
#include <set>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
#include <utility>
#include <queue>
#include <cmath>
#include <list>

using namespace std;

//task 1
int stones_jewerly(std::istream& input, std::ostream& output)
{
	using namespace std;

	string instr1;
	input >> instr1;
	unordered_set<char> jewerly;
	for (char c : instr1)
	{
		jewerly.insert(c);
	}
	string stones;
	input >> stones;
	int result = 0;
	for (char stone : stones)
	{
		if (jewerly.count(stone))
		{
			++result;
		}
	}
	return result;
}

//task 2
size_t sequence_ones(std::istream& input, std::ostream& output)
{
	using namespace std;
	size_t n; 
	input >> n;

	size_t max_lenght = 0;
	size_t current_lenght = 0;
	int data;
	for (size_t i = 0; i < n; ++i)
	{ 
		input >> data;
		if (data == 1)
		{
			++current_lenght;
			if (max_lenght < current_lenght)
			{
				max_lenght = current_lenght;
			}
		}
		else
		{
			current_lenght = 0;
		}
	}
	return max_lenght;
}

//task 3
void delete_duplicates(std::istream& input, std::ostream& output)
{
	size_t len;
	input >> len;
	if (len <= 0)
	{
		return;
	}

	int prev, now;
	input >> prev;
	output << prev << "\n";
	for (size_t i = 1; i < len; ++i)
	{
		input >> now;
		if (prev != now)
		{
			output << now << "\n";
			prev = now;
		}
	}
}

//task 4
void bracket_sequences(std::set<std::string>& set_brackets, std::string brackets, size_t opened, size_t closed, size_t n, size_t N)
{
	if (opened < N)
	{
		bracket_sequences(set_brackets, brackets + "(", opened + 1, closed, n + 1, N);
	}

	if (opened > closed)
	{
		bracket_sequences(set_brackets, brackets + ")", opened, closed + 1, n + 1, N);
		//bracket_sequences;
	}

	if (n == N * 2)
	{
		set_brackets.insert(brackets);
	}
}


void generating_bracket_sequences(std::istream& input, std::ostream& output)
{
	std::set<std::string> brackets;
	size_t n;
	input >> n;
	bracket_sequences(brackets, "", 0, 0, 0, n);

	for (auto& bracket : brackets)
	{
		std::cout << bracket << "\n";
	}

}

//task 5
int anagrams(std::istream& input, std::ostream& output)
{
	std::unordered_map<char, int> line;
	std::string str1;
	input >> str1;
	for (char c1 : str1)
	{
		++line[c1];
	}

	std::string str2;
	input >> str2;
	for(char c2 : str2)
	{
		--line[c2];
		if (line[c2] == 0)
		{
			line.erase(c2);
		}
	}
	return (line.size() == 0)? 1 : 0;
}

// task 6

unsigned int dist_cities(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int bfs(const vector<vector<int>>& graf, int now, int goal, size_t size)
{
	int depth = 0;
	
	unordered_set<int> visited;
	list<int> queue;

	int rightest = now;
	queue.push_back(now);
	visited.insert(now);

	int last_city = now;
	while (!queue.empty())
	{
		int now = queue.front();
		queue.pop_front();

		if (now == goal)
		{
			return depth;
		}

		for (int city : graf[now])
		{
			if (!visited.count(city))
			{
				queue.push_back(city);
				visited.insert(city);
			}
		}
		if (rightest == now)
		{
			++depth;
			if (!queue.empty())
			{
				rightest = queue.back();
			}
		}
	}
	return -1;
}

int interesting_jorney(std::istream& input, std::ostream& output)
{
	using namespace std;
	size_t n_cities;
	input >> n_cities;

	vector<pair<int, int>> cities(n_cities);
	int x, y;
	for(size_t i = 0; i < n_cities; ++i)
	{
		input >> x;
		input >> y;
		cities[i] = make_pair(x, y);
	}


	vector<vector<int>> graph(n_cities);
	
	unsigned int max_dist;
	input >> max_dist;
	for (size_t i = 0; i < cities.size(); ++i)
	{
		for (size_t j = i + 1; j < cities.size(); ++j)
		{
			if (dist_cities(cities[i], cities[j]) <= max_dist)
			{
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	
	/*output << endl;
	output << endl;
	for (size_t i = 0; i < graph.size(); ++i)
	{
		output << "City " << i << ": ";
		for (int city : graph[i])
		{
			cout << city << " ";
		}
		output << endl;
	}//*/
	int from;
	input >> from;
	int to;
	input >> to;
	return bfs(graph, from - 1, to - 1, n_cities);
}






int preparing_for_the_Yandex_interview()
{
	std::cout << interesting_jorney(std::cin, std::cout) << std::endl;
	return 0;
}

int test_preparing_for_the_Yandex_interview()
{
	preparing_for_the_Yandex_interview();
	return 0;
}