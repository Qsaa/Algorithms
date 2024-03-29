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
https://contest.yandex.ru/contest/45468/problems/

- ������ 1
Hello, world!

     #
     ##
#########
!,Hdelorw

- ������ 2
Twas brillig, and the slithy toves
Did gyre and gimble in the wabe;
All mimsy were the borogoves,
And the mome raths outgrabe.
         #
         #
         #
         #
         #
         #         #
         #  #      #
      #  # ###  ####
      ## ###### ####
      ##############
      ##############  ##
#  #  ############## ###
########################
,.;ADTabdeghilmnorstuvwy
*/

#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

void histogram(const string& s)
{
    size_t top = 0;
    map<char, size_t> dict_c;
    for (auto c : s)
    {
        // the following conditional is necessary only for the second option
        //if (c != ' ' && c != '\n')
        {
            dict_c[c] += 1;
            if (dict_c[c] > top)
            {
                top = dict_c[c];
            }
        }
    }

    //print data
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
    //Variant 1
    //===============
    string str;
    str.reserve(10000);
    ifstream input("input.txt");
    for (string word; input >> word; str += word);
    input.close();
    histogram(str);
    //===============

    //// Variant 2
    //char str[10001];
    //ifstream input("input.txt");
    //if (input.is_open())
    //{
    //    input.get(str, 100000, EOF);
    //}
    //input.close();
    //histogram(str);
    
    
    //test1
    //histogram("Hello, world!");
    //=======

    //test2
    //histogram("Twas brillig, and the slithy toves\
    //           Did gyre and gimble in the wabe;\
    //           All mimsy were the borogoves,\
    //           And the mome raths outgrabe.");
    //======
}