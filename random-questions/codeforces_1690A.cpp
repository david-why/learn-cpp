// https://codeforces.com/contest/1690/problem/A
// Codeforces Contest #1690 A. Print a Pedestal (Codeforces logo?)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        const int p = n / 3;
        switch (n % 3)
        {
        case 0:
            cout << p << " " << p + 1 << " " << p - 1 << endl;
            break;
        case 1:
            cout << p <<  " " << p + 2 <<" " << p - 1 << endl;
            break;
        case 2:
            cout << p + 1 << " " << p + 2 << " " << p - 1 << endl;
            break;
        }
    }

    return 0;
}
