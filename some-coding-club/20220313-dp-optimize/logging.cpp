// https://codeforces.com/problemset/problem/319/C
// Codeforces Contest #319 C. Kalila and Dimna in the Logging Industry
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 3;
ll slope[maxn], sec[maxn];
// dp[i]=min{j=1..i-1}(dp[j]+(a[i]-1)*b[j]+b[i])
// dp[i]=min{j=1..i-1}(b[j]*a[i]+(dp[j]-b[j]))+b[i]
//                      k    x       b
ll dp[maxn];
int a[maxn], b[maxn];
vector<int> st;
int ptr;
double cross(int i, int j)
{
    return (double)(sec[j] - sec[i]) / (slope[i] - slope[j]);
}
void add(int i)
{
    while (ptr + 1 < st.size() && cross(st.back(), *++st.rbegin()) > cross(*++st.rbegin(), i))
        st.pop_back();
    st.push_back(i);
}
ll calc(int i, int x) { return slope[i] * x + sec[i]; }
int find(int x)
{
    while (ptr + 1 < st.size() && calc(st[ptr], x) > calc(st[ptr + 1], x))
        ptr++;
    return st[ptr];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    dp[1] = b[1];
    slope[1] = b[1];
    add(1);
    for (int i = 2; i <= n; i++)
    {
        int li = find(a[i]);
        dp[i] = calc(li, a[i]) + b[i];
        slope[i] = b[i];
        sec[i] = dp[i] - b[i];
        add(i);
    }

    cout << dp[n] << endl;

    return 0;
}
