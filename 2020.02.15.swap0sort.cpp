#include <iostream>

using namespace std;

template <typename T>
int indexOf(T *arr, int n, T toFind)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == toFind)
            return i;
    }
    return -1;
}

int main()
{
    int n, left = 0, index0 = 0, ans = 0;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (nums[i] != i)
            left++;
        if (nums[i] == 0)
            index0 = i;
    }
    while (left - 1)
    {
        if (index0 == 0) {
            for (int i = 1; i < n; i++)
            {
                if (nums[i] != i) {
                    // cout << "Number " << nums[i] << " is at index " << i << ", swapping with 0" << endl;
                    nums[0] = nums[i];
                    nums[i] = 0;
                    index0 = i;
                    ans++;
                    break;
                }
            }
        }
        while (nums[0] != 0)
        {
            int i = indexOf(nums, n, index0);
            // cout << "Swap(0, " << index0 << ");" << endl;
            nums[index0] = index0;
            nums[i] = 0;
            left--;
            ans++;
            // for (int j = 0; j < n; j++) cout << nums[j] << " "; cout << "   " << left << endl;
            index0 = i;
        }
    }
    cout << ans << endl;
    return 0;
}
