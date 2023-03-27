/*
Операционные системы lite
Ограничение времени	1 секунда
Ограничение памяти	64Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt

Васин жесткий диск состоит из M секторов.Вася последовательно устанавливал на него 
различные операционные системы следующим методом : он создавал новый раздел диска из 
последовательных секторов, начиная с сектора номер ai и до сектора bi включительно, 
и устанавливал на него очередную систему.При этом, если очередной раздел хотя бы по 
одному сектору пересекается с каким - то ранее созданным разделом, то ранее созданный 
раздел «затирается», и операционная система, которая на него была установлена, 
больше не может быть загружена.

Напишите программу, которая по информации о том, какие разделы на диске создавал Вася, 
определит, сколько в итоге работоспособных операционных систем установлено и работает 
в настоящий момент на Васином компьютере.

Формат ввода
Сначала вводятся натуральное число M — количество секторов на жестком диске(1 ≤ M ≤ 109) 
и целое число N — количество разделов, которое последовательно создавал Вася(0 ≤ N ≤ 1000).
Далее идут N пар чисел ai и bi, задающих номера начального и конечного секторов 
раздела(1 ≤ ai ≤ bi ≤ M).

Формат вывода
Выведите одно число — количество работающих операционных систем на Васином компьютере.

Пример 1
Ввод
10
3
1 3
4 7
3 4
Вывод
1

Пример 2
Ввод	Вывод
10
4
1 3
4 5
7 8
4 6
Вывод
3

https://contest.yandex.ru/contest/45469/problems/6/
*/



#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool intersected(const pair<int, int>& new_section, pair<int, int>& busy_section)
{ 
	if (new_section.second < busy_section.first || new_section.first > busy_section.second)
	{
		return false;
	}

	if (new_section.first < busy_section.first)
	{
		busy_section.first = new_section.first;
	}
	if (new_section.second > busy_section.second)
	{
		busy_section.second = new_section.second;
	}
	return true;
}

int operation_system_lite(const vector<pair<int,int>>& section_allocat)
{
	size_t n_oper_system = 0;
	bool free_place;
	vector<pair<int, int>> busy_sections;

	for(auto it = section_allocat.rbegin(); it != section_allocat.rend(); ++it) //1000
	{
		free_place = true;
		for (auto& busy_section : busy_sections) // 10^9
		{
			if (intersected(*it, busy_section))
			{
				free_place = false;
			}
		}
		if (free_place)
		{
			++n_oper_system;
			busy_sections.push_back(*it);
		}
	}
	return n_oper_system;
}


int test_operation_system_lite()
{
	//Test 0
	int M; cin >> M;
	int N; cin >> N;
	vector<pair<int, int>> allocation_oper_sys;
	allocation_oper_sys.reserve(N);
	for (size_t i = 0; i < N; ++i)
	{
		pair<int, int> coordinates;
		cin >> coordinates.first;
		cin >> coordinates.second;
		allocation_oper_sys.push_back(coordinates);
	}//*/

	/*//Test 1
	int M = 10;
	int N = 3;
	vector<pair<int, int>> allocation_oper_sys = { {1, 3}, {4, 7}, {3, 4} };
	allocation_oper_sys.reserve(N);
	// == 1
	//*/

	/*//Test 2
	int M = 10;
	int N = 4;
	vector<pair<int, int>> allocation_oper_sys = { {1, 3}, {4, 5}, {7, 8}, {4, 6} };
	allocation_oper_sys.reserve(N);
	// == 3
	//*/ 


	cout << operation_system_lite(allocation_oper_sys) << endl;
	return 0;
}