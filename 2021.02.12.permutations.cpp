#include <iostream>
#define MAXN 100

using namespace std;

int INITIAL;
bool used[MAXN + 1] = {false};
int nums[MAXN + 1] = {0};
int ans = 0;

void permutations(int n)
{
    if (n == 0)
    {
        for (int i = 0; i < INITIAL; i++)
            cout << nums[i] << " ";
        cout << "\n";
        ans++;
        return;
    }
    for (int i = 1; i <= INITIAL; i++)
    {
        if (used[i])
            continue;
        nums[INITIAL - n] = i;
        used[i] = true;
        permutations(n - 1);
        used[i] = false;
    }
}

int main()
{
    cin >> INITIAL;
    if (INITIAL != 0)
        permutations(INITIAL);
    cout << ans << endl;
    return 0;
}
