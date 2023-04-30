// https://vjudge.net/problem/LightOJ-1132

#include <bits/stdc++.h>

using namespace std;

const int maxn = 52;

struct matrix
{
    uint arr[maxn][maxn];
    int n;

    matrix(int n = 0) : arr(), n(n) { memset(arr, 0, maxn * maxn * sizeof(uint)); }
    matrix(uint arr[maxn][maxn], int n) : arr(), n(n) { memcpy(this->arr, arr, maxn * maxn * sizeof(uint)); }
    matrix operator*(const matrix &x) const
    {
        matrix res(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    res.arr[i][j] += arr[i][k] * x.arr[k][j];
        return res;
    }
    matrix operator^(long long k) const
    {
        matrix a = *this, b = *this;
        k--;
        while (k)
        {
            if (k & 1)
                a = a * b;
            b = b * b;
            k >>= 1;
        }
        return a;
    }
};

uint C[maxn][maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    C[0][0] = 1;
    for (int i = 1; i <= 51; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++)
    {
        long long n;
        int k;
        cin >> n >> k;
        if (n == 1)
        {
            cout << "Case " << z << ": " << 1 << "\n";
            continue;
        }
        matrix m(k + 2);
        for (int j = 0; j <= k; j++)
        {
            for (int i = j; i <= k; i++)
            {
                m.arr[i][j] = C[k - j][i - j];
            }
        }
        for (int i = 0; i <= k; i++)
            m.arr[i][k + 1] = m.arr[i][0];
        m.arr[k + 1][k + 1] = 1;
        m = m ^ (n - 1);
        uint ans = 0;
        for (int i = 0; i <= k + 1; i++)
            ans += m.arr[i][k+1];
        cout << "Case " << z << ": " << ans << "\n";
    }
}
