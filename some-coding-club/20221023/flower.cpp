// https://www.luogu.com.cn/problem/P8548?contestId=89333
// Luogu P8548 小挖的买花
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 504, maxq = 1e6+7;
int cost[maxn], fr[maxn], be[maxn];
int c[maxq], f[maxq];
// dp[i][j][k] = i types, j money, k fresh, beauty value
int dp[maxn][maxn];
// mdp1[j][k] = j money, >=k fresh, beauty value
int mdp1[maxn][maxn];
// mdp2[j][k] = <=j money, >=k fresh, beauty value
int mdp2[maxn][maxn];
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    int cm=1, fm=1, bm=1;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i] >> fr[i] >> be[i];
        if (cost[i] > cost[cm]) cm = i;
        if (fr[i] > fr[fm]) fm = i;
        if (be[i] > be[bm]) bm = i;
    }
    int qcm = 1, qfm = 1;
    for (int i = 1; i <= q; i++) {
        cin >> c[i] >> f[i];
        if (c[i] > c[qcm]) qcm = i;
        if (f[i] > f[qfm]) qfm = i;
    }    for (int i = 0; i <= 500; i++) {
        for (int j = 501; j >= 0; j--) {dp[i][j]=mdp1[i][j]=mdp2[i][j]=-1e9;

        }}dp[0][0]=0;
    for (int i = 1; i <= n; i++) {
        for (int j = 500; j >= cost[i]; j--) {
            for (int k = 501; k >= 501-fr[i]; k--)
                dp[j][501] = max(dp[j][501], dp[j-cost[i]][k]+be[i]);
            for (int k = 500; k >= fr[i]; k--)
                dp[j][k] = max(dp[j][k], dp[j-cost[i]][k-fr[i]]+be[i]);
        }
    }
    for (int j = 0; j <= 500; j++) {
        for (int k = 501; k >= 0; k--) {
            mdp1[j][k] = max(mdp1[j][k+1], dp[j][k]);
        }
    }
    for (int j = 0; j <= 500; j++) {
        for (int k = 501; k >= 0; k--) {
            mdp2[j][k] = max(mdp2[max(j-1,0)][k], mdp1[j][k]);
        }
    }
    for (int i = 1; i <= q; i++) {
        // i=n, j<=c[i], k>=f[i]
        int ans = 0;
        // for (pair<const int, map<int, int>> &p : dp[n%2]) {
        //     const int &j = p.first;
        //     if (j > c[i]) break;
        //     for (auto it = p.second.lower_bound(f[i]); it != p.second.end(); it++) {
        //         const int &k = it->first, &v = it->second;
        //         ans = max(ans, v);
        //     }
        // }
        ans = mdp2[c[i]][f[i]];
        cout << ans << "\n";
    }

    return 0;
}