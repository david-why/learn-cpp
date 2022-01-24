// https://www.luogu.com.cn/problem/P1082?contestId=58741

#include <bits/stdc++.h>

using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y) // ax+by=gcd(a,b), find x,y
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int main()
{
    long long a, b, x, y;
    cin >> a >> b;
    exgcd(a, b, x, y);
    cout << (x % b + b) % b << endl;
    return 0;
}
