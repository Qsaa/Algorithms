// Algorithm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header_Tests.h"
//==========================
//==========================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

struct Data
{
    static size_t count;
    explicit Data(unsigned char t1, unsigned char t2): _i(count), _t1(t1), _t2(t2), _dif(t1-t2)
    {
        ++count;
    }


    size_t _i;
    unsigned char _t1;
    unsigned char _t2;
    int _dif;
};

ostream &operator<<(ostream& os, const Data& data)
{
    return os << "i: " << data._i << "; t1: " << data._t1 << "; t2: " << data._t2 << "; dif: " << data._dif << endl;
}
size_t Data::count = 0;
//size_t n; cin >> n;
//vector<Data> data;
//data.resize(n);
//
//unsigned char t1;
//unsigned char t2;
//do
//{
//    cin >> t1, cin >> t2;
//    data.push_back(Data::Data(t1, t2));
//}while (--n);

//sort(data.begin(), data.end(), [](const Data& a, const Data& b) {return a._dif < b._dif; });

//cout<<data[0];
////for (const Data& el : data)
////for (auto el : data)
////{
////    cout << el;
////}

////
////vector<Data> data2;
////data2.resize(n);

//vector<int> d = { 1, 2, 3, 4, 5 };
//cout << d;
*/


union Element
{
    int d;
    char c;
};


int main()
{
    vector<int> line = {};
    
    
    size_t k = 2;
    size_t result = 0;
    
    size_t best_result = 0;
    for (size_t j = 0; j < line.size(); ++j)
    {
        result += 1; // строка не пустая!!!!
        for (size_t i = j; i < line.size(); ++i)
        {
            if (k >= line[i])
            {
                result += line[i] + 1;
                k -= line[i];
            }
            else
            {
                break;
            }
        }
        result += k;
        if (best_result < result)
        {
            best_result = result;
        }
    }

    cout << "result: " << result << endl;
    cout << "best_result: " << best_result << endl;
   

    return 0;
}
