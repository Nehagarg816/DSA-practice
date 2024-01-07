#include <iostream>
#include <string>
using namespace std;

int main()
{
    /*code*/
    string name = "Rohan";
    int p = name.size();
    cout << name << endl;
    for (int i = 0; i < name.size() / 2; i++)
    {
        swap(name[i], name[p - 1 - i]);
    }
    cout << name << endl;
    return 0;
}