// https://codeforces.com/problemset/problem/712/D
// Codeforces Contest #712 D. Memory and Scores
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int __speedup = []()
{ cin.tie(0); ios::sync_with_stdio(false); return 0; }();
template <typename T>
T &rd(T &num)
{
    cin >> num;
    return num;
}
template <typename T = int>
T rd()
{
    T v;
    return rd(v);
}
char *rd(char *s)
{
    cin >> s;
    return s;
}
template <typename T>
void rd(T ptr, size_t len)
{
    while (len--)
        rd(*ptr++);
}
template <size_t I, typename... Args>
typename enable_if<I == tuple_size<tuple<Args...>>::value, void>::type rd(tuple<Args &...> &&t) {}
template <size_t I = 0, typename... Args>
typename enable_if<I != tuple_size<tuple<Args...>>::value, void>::type rd(tuple<Args &...> &&t)
{
    rd(get<I>(t));
    rd<I + 1, Args...>(forward<tuple<Args &...>>(t));
}

const int mod = 1e9 + 7;
template <typename T>
void add(T &a, ll b) { a = (b + a) % mod; }
template <typename T>
void upmin(T &a, T b) { a = min(a, b); }
template <typename T>
void upmax(T &a, T b) { a = max(a, b); }

// -=-=-=-=-=-=-=-=-=-=-=-

const int maxk = 1000 + 5, maxt = 100 + 5, maxn = 2 * maxk * maxt + 100 + 5;
int n;

// dp[i][j]: after i turns, M-L=j
int dp[maxt][maxn];
// sum[i][j]: sum{k=0..j}(dp[i][k])
int sum[maxt][maxn];

int getsum(int i, int j)
{
    if (j < 0)
        return 0;
    if (j > n)
        return sum[i][n - 1];
    return sum[i][j];
}

int main()
{
    int a, b, k, t;
    rd(tie(a, b, k, t));
    int s = abs(a - b) + 2 * k * t;
    n = 2 * s + 1;

    dp[0][a - b + s] = 1;
    for (int i = a - b + s; i <= n; i++)
        sum[0][i] = 1;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int id = -2 * k;
            int su = sum[i - 1][j + id + 2 * k] - getsum(i - 1, j + id - 1); // sum1[i - 1][j + id - 1];
            for (; id <= 0; id++)
            {
                add(dp[i][j], su);
                if (j + id >= 0)
                    add(su, mod - dp[i - 1][j + id]);
                if (j + id + 2 * k + 1 < n)
                    add(su, dp[i - 1][j + id + 2 * k + 1]);
            }

            sum[i][j] = sum[i][j - 1];
            add(sum[i][j], dp[i][j]);
        }
    }

    int ans = 0;
    for (int i = s + 1; i <= n; i++)
        add(ans, dp[t][i]);
    cout << ans << endl;

    return 0;
}