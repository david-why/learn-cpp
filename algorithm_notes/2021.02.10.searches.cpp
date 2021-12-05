#include <iostream>
#include <random>

using namespace std;

int binary_search(int *nums, int n, int m)
{
    for (int fin = 0; fin < n - 1; fin++)
    {
        int m = fin;
        for (int i = fin; i < n; i++)
        {
            if (nums[i] < nums[m])
                m = i;
        }
        int t = nums[m];
        nums[m] = nums[fin];
        nums[fin] = t;
    }
    int ans = 0;
    for (int _ = 0; _ < m; _++)
    {
        int search = rand() % 1000000;
        int left = 0, right = n - 1, i;
        while (left <= right)
        {
            i = left + (right - left) / 2;
            if (nums[i] == search)
            {
                break;
            }
            if (nums[i] > search)
            {
                right = i - 1;
            }
            else
            {
                left = i + 1;
            }
        }
        if (nums[i] == search)
            ans++;
    }
    return ans;
}

int hash_search(int *nums, int n, int m)
{
    bool buckets[1000000] = {0};
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        buckets[nums[i]] = true;
    }
    for (int i = 0; i < m; i++)
    {
        int search = rand() % 1000000;
        if (buckets[search]) ans += 1;
    }
    return ans;
}

int main()
{
    int ans = 100, n, m, s, t;
    cin >> n >> m >> s >> t;
    srand(s);
    int *nums = new int[n], *searches = new int[m];
    for (int i = 0; i < n; i++)
    {
        nums[i] = rand() % 1000000;
    }
    switch (t)
    {
    case 1:
        ans = binary_search(nums, n, m);
        break;
    case 2:
        ans = hash_search(nums, n, m);
        break;
    default:
        return 1;
    }
    cout << rand() << "\n"
         << ans << endl;
}
