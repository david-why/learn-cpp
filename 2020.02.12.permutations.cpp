#include <iostream>
#define MAXN 100

using namespace std;

int INITIAL;
bool used[MAXN + 1] = {false};
int nums[MAXN + 1] = {0};

void permutations(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (used[i])
            continue;
        nums[INITIAL - n] = i;
        used[i] = true;
        permutations(n - 1);
    }
}

int main()
{
    cin >> INITIAL;
    permutations(INITIAL);
    return 0;
}
