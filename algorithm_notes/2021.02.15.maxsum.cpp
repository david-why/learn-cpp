#include <iostream>
#include <algorithm>
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

using namespace std;

bool cmp(int a, int b) { return a > b; }

int main()
{
    int n, m;
    cin >> n;
    int neg1[n], pos1[n], in1 = 0, in2 = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t < 0)
            neg1[in1++] = t;
        else
            pos1[in2++] = t;
    }
    sort(neg1, neg1 + in1);
    sort(pos1, pos1 + in2, cmp);
    cin >> m;
    int neg2[m], pos2[m], im1 = 0, im2 = 0;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if (t < 0)
            neg2[im1++] = t;
        else
            pos2[im2++] = t;
    }
    sort(neg2, neg2 + im1);
    sort(pos2, pos2 + im2, cmp);
    int ans = 0;
    for (int i = 0; i < min(in1, im1); i++)
    {
        ans += (neg1[i] * neg2[i]);
    }
    for (int i = 0; i < min(in2, im2); i++)
    {
        ans += (pos1[i] * pos2[i]);
    }
    cout << ans << endl;
    return 0;
}
