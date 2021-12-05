#include <iostream>
#include <cmath>
#include <set>

using namespace std;

set<int> primes;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "1=1" << endl;
        return 0;
    }
    cout << n << "=";
    int sqr = (int)sqrt(n);
    bool need = false;
    for (int i = 2; i <= sqr && n != 1; i++)
    {
        bool isPrime = true;
        int s = (int)sqrt(i);
        for (int p : primes)
        {
            if (i % p == 0)
            {
                isPrime = false;
                break;
            }
            if (p > s)
                break;
        }
        if (!isPrime)
            continue;
        primes.insert(i);
        int k = 0;
        while (n % i == 0)
        {
            n /= i;
            k++;
        }
        switch (k)
        {
        case 0:
            continue;
        case 1:
            if (need)
                cout << "*";
            cout << i;
            need = true;
            break;
        default:
            if (need)
                cout << "*";
            cout << i << "^" << k;
            need = true;
            break;
        }
    }
    if (n != 1)
    {
        if (need)
            cout << "*";
        cout << n;
    }
    cout << endl;
    // for (int p : primes) cout << p << endl;
    return 0;
}
