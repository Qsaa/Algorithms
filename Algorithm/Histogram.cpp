

/*
* ������� ������ ������� ������������ ���������. ��� ����� ��� ������������ ������, �����
������� � ��������� ������������� ��������� ������������� ���� ������. ��� �������� ��������
������� ����� �������� ����������� ������������� ������������� ��������. ������� �� ����� ���������
����������� ���������� �������� � ���������. ����������� � ��� ������, � ������� ������� �������,
�������������� � ��������� ���� �� ���� ���, ������������� �������, ������ �������� ���������������
���������� ���� �������� � ���������.

������ �����
������� ���� �������� ������������� ����� ���������. �� �������� �������� � ��������� ��������� �����,
�����, ����� ���������� (�.�, �!�, �?�, �:�, �-�, �,�, �;�, �(�, �)�), ������� � �������� �����. ������
�������� ����� �� ��������� 10000 ����. ����� �������� ���� �� ���� ������������ ������. ��� ������
�������� ����� �� ������� 200 ��������.��� ������� ������� c ����� �������� � ��������� ����� ��������
������� �� �������� �#�, ���������� ������� ������ ���� ����� ���������� �������� c � ������ ������.
��� ������ ��������� �������� ������, ��������������� ���. �������������� ����������� ���, ����� ������
����� ��������� ���� �� ����� ������, ������ ������ � ������ ������� ���� ���������. �� ���������
�������� ���� �� �����. ������������ �������� � ������� ���������� ����� ��������.

������ ������
��� ������� ������� c ����� �������� � ��������� ����� �������� ������� �� �������� �#�, ����������
������� ������ ���� ����� ���������� �������� c � ������ ������. ��� ������ ��������� �������� ������,
��������������� ���. �������������� ����������� ���, ����� ������ ����� ��������� ���� �� ����� ������,
������ ������ � ������ ������� ���� ���������. �� ��������� �������� ���� �� �����. ������������
�������� � ������� ���������� ����� ��������.
*
*/
#include <iostream>
#include <map>
using namespace std;

void histogram(const string& s)
{
    size_t top = 0;
    map<char, size_t> dict_c;
    for (auto c : s)
    {
        if (c != ' ')
        {
            dict_c[c] += 1;
            if (dict_c[c] > top)
            {
                top = dict_c[c];
            }
        }
    }

    for (; top; --top)
    {
        for (auto el : dict_c)
        {
            if (el.second >= top)
            {
                cout << '#';
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
    for (auto el : dict_c)
    {
        cout << el.first;
    }
    cout << endl;
}

void test_histogram()
{
    histogram("Hello, world!");
    //histogram("Twas brillig, and the slithy toves\
    //           Did gyre and gimble in the wabe;\
    //           All mimsy were the borogoves,\
    //           And the mome raths outgrabe.");
}