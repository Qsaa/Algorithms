//3. Коллекционер Диего
//Диего увлекается коллекционированием наклеек.На каждой из них написано число, 
//и каждый коллекционер мечтает собрать наклейки со всеми встречающимися числами.
//
//Диего собрал N наклеек, некоторые из которых, возможно, совпадают.Как - то раз к нему 
//пришли K коллекционеров.i - й из них собрал все наклейки с номерами не меньшими, чем pi.
//Напишите программу, которая поможет каждому из коллекционеров определить, сколько 
//недостающих ему наклеек есть у Диего.Разумеется, гостей Диего не интересуют повторные 
//экземпляры наклеек.
//
//
//Формат ввода
//В первой строке содержится единственное число N(0 ≤ N ≤ 100 000) — количество наклеек у Диего.
//
//В следующей строке содержатся N целых неотрицательных чисел(не обязательно различных) — номера 
//наклеек Диего.Все номера наклеек не превосходят 109.
//
//В следующей строке содержится число K(0 ≤ K ≤ 100 000) — количество коллекционеров, 
//пришедших к Диего.В следующей строке содержатся K целых чисел pi(0 ≤ pi ≤ 109), 
//где pi — наименьший номер наклейки, не интересующий i - го коллекционера.
//
//
//Формат вывода
//Для каждого коллекционера в отдельной строке выведите количество различных чисел на наклейках, 
//которые есть у Диего, но нет у этого коллекционера.
//
//
//Пример 1
//Ввод
//1
//5
//2
//4 6
//Вывод
//0
//1
//
//
//Пример 2
//
//Ввод
//3
//100 1 50
//3
//300 0 75
//Вывод
//3
//0
//2
//
//https://contest.yandex.ru/contest/45468/problems/3/?success=84368581#31889/2015_07_20/IWrTVHV8F6
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void collector_diego(vector<size_t>& stiks_diego, vector<size_t>& stiks_collectors)
{
    if (stiks_diego.size() == 0)
    {
        for (size_t i = 0; i < stiks_collectors.size(); ++i)
        {
            cout << 0 << endl;
        }
        return;
    }
    // preprare data of stiks_collectors stiks_diego (is not empty)
    vector<size_t> stiks_diego_clear;
    stiks_diego_clear.reserve(stiks_diego.size() + 1);
    
    sort(stiks_diego.begin(), stiks_diego.end());
    stiks_diego_clear.push_back(stiks_diego[0]);
    for (size_t el : stiks_diego)
    {
        if (stiks_diego_clear.back() != el)
        {
            stiks_diego_clear.push_back(el);
        }
    }

    // preprare data of stiks_collectors
    vector<size_t> stiks_collectors_sort;
    stiks_collectors_sort.reserve(stiks_collectors.size());
    for (size_t i = 0; i < stiks_collectors.size(); ++i)
    {
        stiks_collectors_sort.push_back(stiks_collectors[i]);
    }
    sort(stiks_collectors_sort.rbegin(), stiks_collectors_sort.rend());
    

    // data is ready
    map<size_t, size_t> result;
    size_t i = stiks_diego_clear.size() - 1;
    size_t j = 0;
    while (j < stiks_collectors_sort.size())
    {
        if (stiks_diego_clear[i] < stiks_collectors_sort[j])
        {
            result[stiks_collectors_sort[j]] = i + 1;
            //cout << i + 1 << endl;
            ++j;
        }
        else if (i > 0)
        {
            --i;
        }
        else
        {
            result[stiks_collectors_sort[j]] = 0;
            //cout << 0 << endl;
            ++j;
        }
    }

    // print result
    for (size_t i = 0; i < stiks_collectors.size(); ++i)
    {
        cout << result[stiks_collectors[i]] << endl;
    }
}


void collector_diego_slowly(const vector<size_t>& stiks_diego, const vector<size_t>& stiks_collectors)
{
    size_t result = 0;
    for (size_t i = 0; i < stiks_collectors.size(); ++i)
    {
        for (size_t sticker_diego : stiks_diego)
        {
            if (sticker_diego < stiks_collectors[i])
            {
                ++result;
            }
        }
        cout << result << endl;
        result = 0;
    }
}



void test_collector_diego()
{
    size_t n_diego; cin >> n_diego;
    vector<size_t> stickers_diego;
    for (size_t i = 0; i < n_diego; ++i)
    {
        size_t sticker; cin >> sticker;
        stickers_diego.push_back(sticker);
    }
    
    size_t n_collectors; cin >> n_collectors;
    vector<size_t> stickers_collectors;
    for (size_t i = 0; i < n_collectors; ++i)
    {
        size_t sticker; cin >> sticker;
        stickers_collectors.push_back(sticker);
    }
    //*/

    /*//Test 1
    size_t n_diego = 1;
    vector<size_t> stickers_diego = { 5 };

    size_t n_collectors = 2;
    vector<size_t> stickers_collectors = {4, 6};
    //*/

    /*//Test 2
    size_t n_diego = 3;
    vector<size_t> stickers_diego = {100, 1, 5};

    size_t n_collectors = 3;
    vector<size_t> stickers_collectors = { 300, 0, 75};
    //*/

    collector_diego(stickers_diego, stickers_collectors);
}