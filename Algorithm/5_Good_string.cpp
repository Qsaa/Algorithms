//5. Хорошая строка
//
//На день рождения маленький Ипполит получил долгожданный подарок — набор дощечек 
//с написанными на них буквами латинского алфавита.Теперь - то ему будет чем 
//заняться долгими вечерами, тем более что мама обещала подарить ему в следующем
//году последовательность целых неотрицательных чисел, если он хорошо освоит этот
//набор.Ради такого богатства Ипполит готов на многое.
//
//Прямо сейчас юный исследователь полностью поглощён изучением хорошести строк.
//Хорошестью строки называется количество позиций от 1 до L  - 1 
//(где L — длина строки), таких, что следующая буква в строке является следующей 
//по алфавиту.Например, хорошесть строки "abcdefghijklmnopqrstuvwxyz" равна 25,
//а строки "abdc" — только 1.
//
//Ипполит размышляет над решением закономерно возникающей задачи : чему равна 
//максимально возможная хорошесть строки, которую можно собрать, используя 
//дощечки из данного набора ? Вы - то и поможете ему с ней справиться.
//
//Формат ввода
//Первая строка ввода содержит единственное целое число N — количество различных 
//букв в наборе(1 ≤ N ≤ 26).Обратите внимание : в наборе всегда используются N 
//первых букв латинского алфавита.
//
//Следующие N строк содержат целые положительные числа ci — количество букв 
//соответствующего типа(1 ≤ ci ≤ 109).Таким образом, первое число означает количество 
//букв "a", второе число задаёт количество букв "b" и так далее.
//
//Формат вывода
//Выведите единственное целое число — максимально возможную хорошесть строки, 
//которую можно собрать из имеющихся дощечек.
//
//Пример 1
//Ввод
//3
//1
//1
//1
//Вывод
//2
//
//Пример 2
//Ввод
//2
//3
//4
//Вывод
//3
//
//==========================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The fastest O(k)
size_t good_string(vector<int>::iterator begin, vector<int>::iterator end, int floor = 0)
{
	if (begin == end )
	{
		return 0;
	}
	int min = *min_element(begin, end);
	size_t result = 0;
	result += (end - begin - 1) * static_cast<size_t>(min - floor);
	vector<int>::iterator here = begin;
	while(here != end)
	{
		if (*here == min)
		{
			result += good_string(begin, here, min);
			begin = here;
		}
		++here;
	}
	result += good_string(begin, here, min);
	return result;
}

// O(n^2) very slowly
int good_string(vector<int>& c_count)
{
	int result = 0;
	for (size_t i = 0; i < c_count.size(); )
	{
		if (c_count[i] == 0)
		{
			++i;
		}
		else
		{
			size_t begin = i;
			size_t end = i;
			while (end <= c_count.size())
			{
				if (end == c_count.size() || c_count[end] == 0)
				{
					for (size_t k = begin; k < end; ++k)
					{
						--c_count[k];
					}
					result += end - begin - 1;
					begin = end;
					break;
				}
				++end;
			}
		}

	}
	return result;
}


int test_good_string()
{
	size_t N; cin >> N;
	vector<int> c_count;
	c_count.reserve(N);
	for (size_t i = 0; i < N; ++i)
	{
		int count;
		cin >> count;
		c_count.push_back(count);
	}
	cout << good_string(c_count.begin(), c_count.end());
	return 0;
}