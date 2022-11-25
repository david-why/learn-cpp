// https://codeforces.com/problemset/problem/1152/C
// Codeforces Contest #1152 C. Neko does Maths
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e9+7, smn = 32000;
int solve(int a, int b) {
    if (a>b) swap(a,b);
    if (b%a==0) return 0;
    int d = b-a;
    // cout<<d<<endl;
    if (d%a==0 || a%d==0) return 0;
    int ma=0;
    if (a<d) {
        for (int i=1;i*i<=d;i++){
            if(d%i)continue;
            if(i>a){ma=i-a;break;}
            if(d/i>a){ma=d/i-a;}
        }
    } else{
        ma=(a+d-1)/d*d-a;
    }
    return ma;
}
int main()
{
    int a, b; cin >> a >> b;
    cout << solve(a,b) << endl;

    return 0;
}
