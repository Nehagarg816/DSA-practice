#include <iostream>
using namespace std;

class myArray
{
private:
    int total_size;
    int used_size;
    int *ptr;

public:
    myArray(int tSize, int uSize);
    void set();
    void get();
};

myArray::myArray(int tSize, int uSize)
{
    total_size = tSize;
    used_size = uSize;
    ptr = new int[total_size];
}

void myArray::set()
{
    for (int i = 0; i < used_size; i++)
    {
        cin >> ptr[i];
    }
}

void myArray::get()
{
    for (int i = 0; i < used_size; i++)
    {
        cout << ptr[i] << " ";
    }
}
int main()
{
    myArray marks(10, 4);
    marks.set();
    marks.get();
    return 0;
}