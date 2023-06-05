//Красотой строки назовем максимальное число идущих подряд одинаковых букв. (красота строки abcaabdddettq равна 3)
//Сделайте данную вам строку как можно более красивой, если вы можете сделать не более k операций замены символа.
//
//Формат ввода
//В первой строке записано одно целое число k(0 ≤ k ≤ 109)
//Во второй строке дана непустая строчка S(| S | ≤ 2 ⋅ 105).Строчка S состоит только из маленьких латинских букв.
//
//Формат вывода
//Выведите одно число — максимально возможную красоту строчки, которую можно получить.
//
//Пример 1
//Ввод	
//2
//abcaz
//Вывод
//2       4
//
//Пример 2
//Ввод	
//2
//helto
//Вывод
//3
//https ://contest.yandex.ru/contest/45469/problems/2/?success=84328914#30404/2017_04_25/J5lhC5hsbS


#include <iostream>

using namespace std;

size_t beautiful_string(size_t input_k, const string& str)
{
    size_t result = input_k + 1;
    if (result > str.size())
    {
        return str.size();
    }

    for (char c = 'a'; c <= 'z'; ++c)
    {
        size_t k = input_k;
        size_t lenght = 0;
        size_t end = 0; size_t begin = 0;
        while (end < str.size())
        {
            if (str[end] == c)
            {
                ++end;
                lenght = end - begin;
                if (result < lenght)
                {
                    result = lenght;
                }
            }
            else if (k > 0)
            {
                --k;

                ++end;
                lenght = end - begin;
                if (result < lenght)
                {
                    result = lenght;
                }
            }
            else
            {
                if (str[begin] != c)
                {
                    ++k;
                }
                ++begin;
            }
        }
    }
    return result;
}


void test_beautiful_string()
{
    /*
    size_t input_k;
    string input_str;
    cin >> input_k;
    cin >> input_str;
    //*/

    /*
    size_t input_k = 400;
    string input_str = "gcasnpanxtiqghxayrxpvyagmtzapagsqdrsojldoqnugrphltmbjxvklngocdgjcxitufotwuvejpizwmtulmwygurtoizcluuzxuvdqiiffmrwfhkpylmwguotjmgzhvobpaksssgpaocqisuvghbvylrfdaportmfmtydjcwoqqxpbnmkaiaewnwdwvqavgvzvmyqmslhaavtsuohpayxhqgyfsorriqkaizgiryruysygrpmhkprpkyrsolqfclojcltwwjfmnyffewumwbwcfvhlhhhbzdfztiucqbtowrfkwlydzuekwrjyqncofjauzgjhbxqwbcayatdhzkmdpzitzxycopstcqbshvspkfvberfguqeezgxhyrngbkunsngcumurssigqlrphnrfxprmsgivrfvgxygakvkgzubwrssprzdfpirsjuyvxbtygbnpbxhepnxiejjwwtejvpbnibpjngjyfiriciejdaercjnjaqigsyjlybmqrtpxwrcfpmshgdhevqfwapvzjfygtnohydurikqpdekeogokjcneeejgsvkbdahjtcwfiyplbibznzjtvtrdvrlscjfcuzpbvxgewwzppswariagkadfjsrcmhpbnmuqucocsydquoutnarkkttjqywlwqpokwkoaiduvcjmgxqvszwhhwcjfnkoomhjxuviclndzuirqkfjoukkaanrhhrkbarrecfvhvddecejbccffnjncmvnsryredcqzgluligofbgibxbuaeiybbydczzovczsiiessvdgdlunwwzaoapiuwxjyjloxovzgkmpnjvjqejmpikontkiovaeiyfjhrzplzaqjjvyqrkkntzkpngexbiemqlnnhwtjmoeezybqwhomkulryhgzbzixlkrtnnjxxyghdbkcacfbsuafrwafvahqevzeurddnvzzobzzlhgkuurjawjejuurjywnbvflttfasweaxm";
    //*/


    /*size_t input_k = 4;
    string input_str = "acacacazxvbnmasdfghjkiaaaa";
    //*/

    /*
    size_t input_k = 2;
    string input_str = "abcaz";
    //*/


    size_t input_k = 2;
    string input_str = "helto";
    //*/

    cout << beautiful_string(input_k, input_str);

}