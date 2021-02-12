#include <iostream>
#include <random>

using namespace std;

void bubble(int *nums, int n)
{
    //cout << "bubble" << endl;
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
}

void select(int *nums, int n)
{
    //cout << "select" << endl;
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
}

void insert(int *nums, int n)
{
    //cout << "insert" << endl;
    for (int fin = 0; fin < n - 1; fin++)
    {
        for (int i = fin + 1; i >= 1 && nums[i] < nums[i - 1]; i--)
        {
            int t = nums[i];
            nums[i] = nums[i - 1];
            nums[i - 1] = t;
        }
    }
}

int main()
{
    int n, t, r;
    cin >> n >> t >> r;
    int nums[n], orig[n];
    srand(r);
    for (int i = 0; i < n; i++)
    {
        orig[i] = nums[i] = rand();
    }
    for (int i = 0; i < n; i++)orig[i] = nums[i] = n - i;
    switch (t)
    {
    case 1:
        bubble(nums, n);
        break;
    case 2:
        select(nums, n);
        break;
    case 3:
        insert(nums, n);
        break;
    default:
        return 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < nums[i - 1])
        {
            for (int j = 0; j < n; j++)
                cout << orig[j] << " ";
            cout << endl;
            for (int j = 0; j < n; j++)
                cout << nums[j] << " ";
            cout << endl;
            return 1;
        }
    }
    cout << "OK" << endl;
    return 0;
}
