#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    //unsigned __int128 n1 = 1ll, n2 = 1ll;
    int n1[120] = {1, 0}, nn1 = 1, n2[120] = {1, 0}, nn2 = 1;
    cin >> n;
    if (n == 0)
        n2[0] = 0;
    //n2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int t[120];
        memcpy(t, n1, sizeof(int) * 120);
        //unsigned __int128 t = n1;
        memcpy(n1, n2, sizeof(int) * 120);
        nn1 = nn2;
        //n1 = n2;
        int carry = 0;
        for (int index = 0; index < nn2; index++)
        {
            int ans = t[index] + n2[index] + carry;
            carry = ans >= 1000000000 ? 1 : 0;
            if (carry == 1)
                ans -= 1000000000;
            n2[index] = ans;
        }
        if (carry)
        {
            n2[nn2] = 1;
            nn2++;
        }
        //n2 = t + n1;
        // cout << n2 << " ";
    }
    // cout << endl;
    cout << n2[nn2 - 1];
    for (int i = nn2 - 2; i >= 0; i--)
        printf("%09d", n2[i]);
    cout << endl;
    //cout << n2 << endl;
    return 0;
}
