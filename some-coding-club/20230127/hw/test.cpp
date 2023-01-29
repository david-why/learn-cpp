#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

const int maxn = 1 << 25;

int lg2[maxn];

extern "C"
{
    void test(int i);
    void testd(double i);
}

long long gttime()
{
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    time_t tm;

    cout << "Testing array indexing" << endl;
    tm = gttime();
    lg2[1] = 0;
    for (int i = 2; i < maxn; i++)
        lg2[i] = lg2[i >> 1] + 1;
    tm = gttime() - tm;
    cout << "Init took " << tm << endl;
    tm = gttime();
    for (int i = 1; i < maxn; i++)
        test(i);
    tm = gttime() - tm;
    cout << "Test took " << tm << endl;

    cout << "Testing log" << endl;
    tm = gttime();
    for (int i = 1; i < maxn; i++)
        testd(log2(i));
    tm = gttime() - tm;
    cout << "Test took " << tm << endl;

    cout << "Testing popcount" << endl;
    tm = gttime();
    for (int i = 1; i < maxn; i++)
    {
        int c = 0;
        for (int x = i; x; x = x & (x - 1))
            c++;
        test(c);
    }
    tm = gttime() - tm;
    cout << "Test took " << tm << endl;

    cout << "Testing __builtin_popcount" << endl;
    tm = gttime();
    for (int i = 1; i < maxn; i++)
        test(__builtin_popcount(i));
    tm = gttime() - tm;
    cout << "Test took " << tm << endl;
    return 0;
}
