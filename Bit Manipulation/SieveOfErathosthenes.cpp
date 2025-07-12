#include <bits/stdc++.h>
using namespace std;
void PrimeNumbers(int n)
{
    vector<bool> prime(n, true);
    for (int i = 2 * 2; i <= n; i += 2)
        prime[i] = false;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == true)
        {
            for (int j = 2 * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == true)
            cout << i << " ";
    }
}

// TC - O(n log log n)
void OptimizedPrimeNumbers(int n)
{
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
            cout << i << " ";
    }
}
int main()
{
    int n = 10;
    PrimeNumbers(n);
    cout << endl;
    OptimizedPrimeNumbers(n);
}