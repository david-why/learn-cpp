// Count the # of 1's from 1 to N.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    int b = 1, a = 0;
    while (b <= n)
    {
        a += n / b / 10 * b;
        int k = n / b % 10;
        if (k > 1)
            a += b;
        else if (k == 1)
            a += n % b + 1;
        b *= 10;
    }
    cout << a << endl;

    return 0;
}
