#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

static struct
{
    string _add = "add";
    string _delete = "delete";
    string _get = "get";
}command;


vector<pair<size_t, string>> wagons_vec;
unordered_map<string, size_t> wagons_map;

void command_add(size_t count, const string& name)
{
    wagons_vec.push_back(pair(count, name));
    wagons_map[name] += count;
}

void command_delete(size_t count)
{
    size_t i = wagons_vec.size() - 1;
    // можно добавить проверку на длину поезда
    while (count)
    {
        if (wagons_vec[i].first > count)
        {
            wagons_vec[i].first -= count;
            wagons_map[wagons_vec[i].second] -= count;
            return;
        }
        else
        {
            wagons_map[wagons_vec[i].second] -= wagons_vec[i].first;
            count -= wagons_vec[i].first;
            wagons_vec.pop_back();
            --i;

        }
    }
}

void command_get(const string& name)
{
    cout << wagons_map[name] << endl;
}



//string test_s1 = "7 \
//                    add 10 oil \
//                    add 20 coal \
//                    add 5 oil \
//                    get coal \
//                    get oil \
//                    add 1 coal \
//                    get coal";

void underground_delivery()
{
    //vector<pair<size_t,string>> wagons_vec;
    //unordered_map<string, size_t> wagons_map;
    //cout<<numeric_limits<size_t>::max;
    size_t n; cin >> n;
    while (n--)
    {
        string new_command;
        cin >> new_command;
        if (new_command == command._add)
        {
            size_t count; cin >> count;
            string name; cin >> name;
            command_add(count, name);
        }
        else if (new_command == command._delete)
        {
            size_t count; cin >> count;
            command_delete(count);
        }
        else if (new_command == command._get)
        {
            string name; cin >> name;
            command_get(name);
        }
        else
        {
            cout << "Command wasn't foud: _ " << new_command << " _ Error" << endl;
            exit(0);
        }
    }
}

void test_underground_delivery()
{
    underground_delivery();
}