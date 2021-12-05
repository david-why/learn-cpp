#include <iostream>
#include <queue>

using namespace std;

bool array[60][1286][128] = {{{false}}};

int main()
{
    short m, n, l;
    int t, ans = 0;
    cin >> m >> n >> l >> t;
    for (int z = 0; z < l; z++)
        for (int x = 0; x < m; x++)
            for (int y = 0; y < n; y++)
                cin >> array[z][x][y];
    for (int z = 0; z < l; z++)
    {
        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (!array[z][x][y])
                    continue;
                queue<short> xs, ys, zs;
                int got = 0;
                zs.push(z);
                xs.push(x);
                ys.push(y);
                // pending.push({z, x, y});
                while (!zs.empty())
                {
                    // int *coord = pending.front();
                    short x = xs.front(), y = ys.front(), z = zs.front();
                    // pending.pop();
                    xs.pop();
                    ys.pop();
                    zs.pop();
                    if (x < 0 || y < 0 || z < 0 || x >= m || y >= n || z >= l || !array[z][x][y])
                        continue;
                    array[z][x][y] = false;
                    got++;
                    static short xd[6] = {-1, 1, 0, 0, 0, 0};
                    static short yd[6] = {0, 0, -1, 1, 0, 0};
                    static short zd[6] = {0, 0, 0, 0, -1, 1};
                    for (int i = 0; i < 6; i++)
                    {
                        xs.push(x + xd[i]);
                        ys.push(y + yd[i]);
                        zs.push(z + zd[i]);
                    }
                }
                if (got >= t)
                    ans += got;
            }
        }
    }
    cout << ans << endl;
}
