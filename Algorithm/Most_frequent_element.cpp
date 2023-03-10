#include <iostream>
#include <string>
#include <map>

using namespace std;

char the_most_frequent_element(const string& str)
{
    map<char, unsigned> my_map;
    for (char c : str)
    {
        ++my_map[c];
    }
    unsigned max = 0;
    char answer = ' ';
    for (pair<char, unsigned> el : my_map)
    {
        if (el.second > max)
        {
            max = el.second;
            answer = el.first;
        }
    }
    return answer;
}

void test_the_most_frequent_element()
{
    string s = "me3wrm32pkrpe'dfaoekfoekwfpme;flmdsp;fmdpsmfdposmfko4ejrfjeorfjdesofaadsf";
    string s1 = "";
    string s2 = "s";
    string s3 = "ss";
    string s4 = "     s ";
    string s5 = "abc";
    string s6 = "aabccc";

    cout << "Test: 1\n" << "String: "<< s << "\nResult: " << the_most_frequent_element(s1) << endl;
    cout << "Test: 2\n" << "String: " << s << "\nResult: " << the_most_frequent_element(s2) << endl;
    cout << "Test: 3\n" << "String: " << s << "\nResult: " << the_most_frequent_element(s3) << endl;
    cout << "Test: 4\n" << "String: " << s << "\nResult: " << the_most_frequent_element(s4) << endl;
    cout << "Test: 5\n" << "String: " << s << "\nResult: " << the_most_frequent_element(s5) << endl;
    cout << "Test: 6\n" << "String: " << s << "\nResult: " << the_most_frequent_element(s6) << endl;
}

