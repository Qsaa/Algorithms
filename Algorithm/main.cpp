// Algorithm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header_Tests.h"
//==========================
//==========================
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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


void print_table(const auto& table)
{
    for (auto& row : table)
    {
        cout << row.first << ":" << endl;
        for (auto& el : row.second)
        {
            cout << el << ' ';;
        }
        cout << endl;
    }
}



void table_position_of_single_characters(auto& table, const string& str)
{
    for (size_t i = 0; i < str.size(); ++i)
    {
        table[str[i]].push_back(i);
    }
}

void table_of_distance_characters(auto& table)
{
    for (auto& line : table)
    {
        if (line.second.size() > 1u)
        {
            for (size_t i = 1; i < line.second.size(); ++i)
            {
                line.second[i - 1] = line.second[i] - line.second[i - 1] - 1;
            }
            line.second.pop_back();
        }
        else
        {
            line.second[0] = -1;
        }
    }
}

size_t max_beautiful_string_by_replacing(const auto& table, size_t count_of_replace)
{
    size_t best_result = 0;

    for (auto& row : table)
    {
        if (row.second[0] > -1)
        {
            auto& line = row.second;
                       
            for (size_t j = 0; j < line.size(); ++j)
            {
                size_t result = 1;
                size_t k = count_of_replace;
                for (size_t i = j; i < line.size(); ++i)
                {
                    if (k >= line[i])
                    {
                        result = result + line[i] + (int)1;
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
                result = 0;
            }
        }
    }
    // without replacing
    return best_result;
}

size_t beautiful_string(size_t input_k, const string& input_str)
{
    map<char, vector<int>> table;
    table_position_of_single_characters(table, input_str);
    //print_table(table);
    //cout << endl << endl;
    table_of_distance_characters(table);
    //print_table(table);
    size_t best_result = max_beautiful_string_by_replacing(table, input_k);
    if (best_result == 0) // hav'not replaced 
    {
        best_result = input_k + 1;
    }

    
    if (input_str.size() < best_result)
    {
        return input_str.size();
    }
    else
    {
        return best_result;
    }
}

size_t beautiful_string2(size_t input_k, const string& input_str)
{
    size_t best_result = 0;
    size_t result = 0;

    for (size_t c = 97; c < 123; ++c)
    {
        for (size_t j = 0; j < input_str.size(); ++j)
        {
            size_t k = input_k;
            for (size_t i = j; i < input_str.size(); ++i)
            {
                if (input_str[i] == c)
                {
                    ++result;
                }
                else if (k > 0)
                {
                    ++result;
                    --k;
                }
                else
                {
                    break;
                }
            }
            if (result > best_result)
            {
                best_result = result;
            }
            result = 0;
        }
    }
    return best_result;
}

size_t beautiful_string3(size_t input_k, const string& str)
{
    size_t result = input_k + 1;
    if ( result > str.size())
    {
        return str.size();
    }

    for (char c = 97; c < 123; ++c)
    {
        size_t k = input_k;
        size_t max_lenght = 0;
        size_t end = 0; size_t begin = 0;
        while (end < str.size())
        {
            if (str[end] == c)
            {
                ++end;
                max_lenght = end - begin;
            }
            else if (k > 0)
            {
                ++end;
                --k;
            }
            else
            {
                if (str[begin] != c)
                {
                    ++k;
                }
                ++begin;
            }
            //cout << "begin: " << begin << "   end:" << end << "   lenght:" << max_lenght << endl;
            
        }
        if (result < max_lenght)
        {
            result = max_lenght;
            //cout << "char: " << c << "  result: " << result << endl;
        }
    }
    return result;
}


int main()
{
    /*
    size_t input_k;
    string input_str;
    cin >> input_k;
    cin >> input_str;
    //*/
    
    
    size_t input_k = 400;
    string input_str = "gcasnpanxtiqghxayrxpvyagmtzapagsqdrsojldoqnugrphltmbjxvklngocdgjcxitufotwuvejpizwmtulmwygurtoizcluuzxuvdqiiffmrwfhkpylmwguotjmgzhvobpaksssgpaocqisuvghbvylrfdaportmfmtydjcwoqqxpbnmkaiaewnwdwvqavgvzvmyqmslhaavtsuohpayxhqgyfsorriqkaizgiryruysygrpmhkprpkyrsolqfclojcltwwjfmnyffewumwbwcfvhlhhhbzdfztiucqbtowrfkwlydzuekwrjyqncofjauzgjhbxqwbcayatdhzkmdpzitzxycopstcqbshvspkfvberfguqeezgxhyrngbkunsngcumurssigqlrphnrfxprmsgivrfvgxygakvkgzubwrssprzdfpirsjuyvxbtygbnpbxhepnxiejjwwtejvpbnibpjngjyfiriciejdaercjnjaqigsyjlybmqrtpxwrcfpmshgdhevqfwapvzjfygtnohydurikqpdekeogokjcneeejgsvkbdahjtcwfiyplbibznzjtvtrdvrlscjfcuzpbvxgewwzppswariagkadfjsrcmhpbnmuqucocsydquoutnarkkttjqywlwqpokwkoaiduvcjmgxqvszwhhwcjfnkoomhjxuviclndzuirqkfjoukkaanrhhrkbarrecfvhvddecejbccffnjncmvnsryredcqzgluligofbgibxbuaeiybbydczzovczsiiessvdgdlunwwzaoapiuwxjyjloxovzgkmpnjvjqejmpikontkiovaeiyfjhrzplzaqjjvyqrkkntzkpngexbiemqlnnhwtjmoeezybqwhomkulryhgzbzixlkrtnnjxxyghdbkcacfbsuafrwafvahqevzeurddnvzzobzzlhgkuurjawjejuurjywnbvflttfasweaxm";
    //*/
    
    /*
    size_t input_k = 4;
    string input_str = "acacacazxvbnmasdfghjkiaaaa";
    //*/

    /*
    size_t input_k = 2;
    string input_str = "abcaz";
    //*/

    /*
    size_t input_k = 2;
    string input_str = "helto";
    //*/

    cout << beautiful_string2(input_k, input_str);




  
    return 0;
}
