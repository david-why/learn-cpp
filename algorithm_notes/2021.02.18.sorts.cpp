#include <iostream>
#include <random>
#include <algorithm>
#define MAXN 1000001

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

void merge(int *nums, int l1, int r1, int l2, int r2)
{
    int i = l1, j = l2;
    static int temp[MAXN];
    int index = 0;
    while (i <= r1 && j <= r2)
    {
        if (nums[i] <= nums[j])
            temp[index++] = nums[i++];
        else
            temp[index++] = nums[j++];
    }
    while (i <= r1)
        temp[index++] = nums[i++];
    while (j <= r2)
        temp[index++] = nums[j++];
    for (i = 0; i < index; i++)
        nums[l1 + i] = temp[i];
}

void merge(int *nums, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge(nums, left, mid);
        merge(nums, mid + 1, right);
        merge(nums, left, mid, mid + 1, right);
    }
}

int partition(int *nums, int left, int right) {
    int temp = nums[left];
    while (left < right) {
        while (left < right && nums[right] > temp) right--;
        nums[left] = nums[right];
        while (left < right && nums[left] <= temp) left++;
        nums[right] = nums[left];
    }
    nums[left] = temp;
    return left;
}

void quick(int *nums, int left, int right) {
    if (left < right) {
        int pos = partition(nums, left, right);
        quick(nums, left, pos - 1);
        quick(nums, pos + 1, right);
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
    case 4:
        merge(nums, 0, n - 1);
        break;
    case 5:
        quick(nums, 0, n - 1);
        break;
    case 6:
        sort(nums, nums + n);
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
