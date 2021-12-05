#include <iostream>
#define MAXN 1001

using namespace std;

int main()
{
    int nums[MAXN], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int t = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}
