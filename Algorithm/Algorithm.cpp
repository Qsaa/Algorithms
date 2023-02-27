// Algorithm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <cmath>

using namespace std;

//void test_the_most_frequent_element
//{
//    string s = "me3wrm32pkrpe'dfaoekfoekwfpme;flmdsp;fmdpsmfdposmfko4ejrfjeorfjdesofaadsf";
//    string s1 = "";
//    string s2 = "s";
//    string s3 = "ss";
//    string s4 = "     s ";
//    string s5 = "abc";
//    string s6 = "aabccc";
//}

char the_most_frequent_element(const string& str)
{
    map<char, unsigned> my_map;
    for (char c : str)
    {
        ++my_map[c];
    }
    unsigned max = 0;
    char answer = ' ';
    for (pair<char, unsigned>  el : my_map)
    {
        if (el.second > max)
        {
            max = el.second;
            answer = el.first;
        }
    }
    return answer;
}

void quadratic_equcation(int a, int b, int c)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                cout << "multiple roots" << endl;
            }
            else
            {
                cout << "no roots" << endl;
            }
        }
        else
        {
            double ans = (static_cast<double>(-c)) / b;
            cout << ans << endl;
        }
    }
    else
    {
        long int D = b * b - 4 * a * c;
        if (D < 0)
        {
            cout << "no roots" << endl;
        }
        else
        {
            double sqrtD = sqrt(static_cast<double>(D));
            double ans1 = (-b - sqrtD) / (2 * a);
            double ans2 = (-b + sqrtD) / (2 * a);
            if (ans1 < ans2)
            {
                cout << ans1 << " " << ans2 << endl;
            }
            else
            {
                cout << ans2 << " " << ans1 << endl;
            }
        }
    }
}


int main()
{
    quadratic_equcation(1, 2, 1);
    quadratic_equcation(1, 1, 1);
    quadratic_equcation(0, 1, 1);
    quadratic_equcation(0, 0, 1);
    quadratic_equcation(0, 0, 0);
    quadratic_equcation(-5, 4, 1);
    //cout << "1: " << the_most_frequent_element(s1) << endl;
    //cout << "2: " << the_most_frequent_element(s2) << endl;
    //cout << "3: " << the_most_frequent_element(s3) << endl;
    //cout << "4: " << the_most_frequent_element(s4) << endl;
    //cout << "5: " << the_most_frequent_element(s5) << endl;
    //cout << "6: " << the_most_frequent_element(s6) << endl;

    //cout << the_most_frequent_element(s7) << endl;
    return 0;
}
