#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class SuperCar
{
private:
    string name;

public:
    int fuel;
    static int gear;
    SuperCar(string n, int f)
    {
        this->fuel = f;
        this->name = n;
    }
    SuperCar(SuperCar &s)
    {
        this->fuel = s.fuel;
        this->name = s.name;
    }
    void display()
    {
        cout << "Car model is " << name << endl;
        cout << "total fuel remained is " << fuel << endl;
        cout << "Static =" << gear << endl;
    }
};

int SuperCar ::gear = 4;

class Car : public SuperCar
{
public:
    Car() : SuperCar("Swift", 100)
    {
    }
    void display()
    {
        cout << "Speed of Car is 230km";
    }
};

// SuperCar::gear = 4;
// int sum(int a) return 6;
// float sum(int a) return 6.0;
int main()
{
    // SuperCar s("Swift", 100);
    // // Car c;
    // // s = &c;
    // // s->display();
    // SuperCar s2(s);
    // s2.fuel = 200;
    // cout << s.fuel << endl;
    // s.fuel = 150;
    // cout << s2.fuel << endl;
    // // s2.display();

    char s1[] = "abc";

    char s2[] = "def";
    strcat(s1, s2);
    cout << s1;
    return 0;
}