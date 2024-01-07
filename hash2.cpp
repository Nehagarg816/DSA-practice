#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;
    pair<string, int> p;
    p = make_pair("Hello", 1);
    m.insert(p);

    p = make_pair("Nice", 4);
    m.insert(p);
    m["meet"] = 3;
    cout << "Size of the map is " << m.size() << endl;
    cout << m["Nice"] << endl;
    cout << m.at("Nice") << endl;
    cout << m.at("meet") << endl;
    cout << m["hey"] << endl;
    cout << m.at("hey") << endl;
    // for (auto i : m)
    // {
    //     cout << i.first << " - " << i.second << endl;
    // }
    // unordered_map<string, int>::iterator it = m.begin(); // O(1)
    // while (it != m.end())
    // {
    //     cout << it->first << " - " << it->second << endl;
    //     it++;
    // }
    map<string, int>::iterator it = m.begin(); // O(logn)
    while (it != m.end())
    {
        cout << it->first << " - " << it->second << endl;
        it++;
    }
    return 0;
}