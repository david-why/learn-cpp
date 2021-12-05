// https://www.luogu.com.cn/problem/P3958

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3;

typedef long long ll;
int n, h, r;
struct
{
    ll x, y, z;
} balls[maxn];
bool down[maxn], up[maxn];

double dist(int i, int j)
{
    auto &a = balls[i], &b = balls[j];
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

bool cut(int i, int j)
{
    return dist(i, j) <= 2 * r;
}

int par[maxn];

int froot(int i)
{
    if (par[i] == i)
        return i;
    else
        return par[i] = froot(par[i]);
}

void merge(int i, int j)
{
    int a = froot(j), b = froot(i);
    par[a] = b;
    down[b] = down[b] || down[a];
    up[b] = up[b] || up[a];
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        memset(down, 0, sizeof(down));
        memset(up, 0, sizeof(up));
        cin >> n >> h >> r;
        bool cor = false;
        for (int j = 0; j < n; j++)
        {
            auto &b = balls[j];
            cin >> b.x >> b.y >> b.z;
            par[j] = j;
            if (b.z <= r)
                down[j] = true;
            if (b.z >= h - r)
                up[j] = true;
            for (int k = 0; k < j; k++)
            {
                if (cut(j, k))
                    merge(j, k);
            }
        }
        for (int j = 0; j < n; j++)
            if (up[j] && down[j])
            {
                cor = true;
                break;
            }
        if (cor)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
