#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    srand(0U);
    int n, p, m = 1;
    cin >> n >> p;
    int nums[n];
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums, nums + n);
    for (int i = 0; i < n; i++)
    {
        int *mid = upper_bound(nums + i + 1, nums + n, (long long)nums[i] * p);
        int d = mid - nums;
        d = d - i;
        // cout << distance(nums, mid) - i << " " << *mid << endl;
        if (d > m)
            m = d;
    }
    cout << m << endl;
    return 0;
}
