#include <iostream>
#define NUMS_MAX (0xffffffffffffffff)

using namespace std;

unsigned long long SEED = 0;

unsigned long long rand64()
{
    // return (unsigned long long)(rand() % 1000000);
    SEED = (SEED * 6364136223846793005ULL + 1442695040888963407ULL);
    return ((SEED >> 3) & 0xffffffffULL);
}

void srand64(unsigned long long seed)
{
    // srand((unsigned int)seed);
    SEED = seed;
}

template <typename _T>
struct LinkNode
{
    _T value;
    LinkNode<_T> *next;
};

int binary_search(unsigned long long *nums, int n, int m)
{
    for (int fin = 0; fin < n - 1; fin++)
    {
        int m = fin;
        for (int i = fin; i < n; i++)
        {
            if (nums[i] < nums[m])
                m = i;
        }
        unsigned long long t = nums[m];
        nums[m] = nums[fin];
        nums[fin] = t;
    }
    int ans = 0;
    for (int _ = 0; _ < m; _++)
    {
        unsigned long long search = rand64();
        int left = 0, right = n - 1, i = 0;
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
        {
            ans++;
        }
    }
    return ans;
}

unsigned int hash64(unsigned long long n)
{
    unsigned int result = 0;
    while (n)
    {
        result ^= n;
        n /= 1000000;
    }
    return result % 1000000;
}

int hash_search(unsigned long long *nums, int n, int m)
{
    struct LinkNode<unsigned long long> *buckets[1000000] =
    {
        NULL
    };
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        unsigned int hashval = hash64(nums[i]);
        struct LinkNode<unsigned long long> *now = buckets[hashval];
        int n = 0;
        if (now)
        {
            while (now->next != NULL && now->value != nums[i])
            {
                now = now->next;
                //cout << "\r" << (n++) << flush;
            }
            if (now->value != nums[i])
            {
                if (now->value == hashval + 1)
                    now->value = nums[i];
                else
                {
                    now->next = new struct LinkNode<unsigned long long>;
                    now->next->next = NULL;
                    now->next->value = nums[i];
                }
            }
        }
        else
        {
            buckets[hashval] = new struct LinkNode<unsigned long long>;
            buckets[hashval]->next = NULL;
            buckets[hashval]->value = nums[i];
        }
    }
    for (int i = 0; i < m; i++)
    {
        unsigned long long search = rand64();
        struct LinkNode<unsigned long long> *now = buckets[hash64(search)];
        if (now)
        {
            while (now->next != NULL && now->value != search)
            {
                now = now->next;
            }
            if (now->value == search)
                ans++;
        }
    }
    return ans;
}

int main()
{
    int ans, n, m, t;
    unsigned long long s;
    cin >> n >> m >> s >> t;
    srand64(s);
    unsigned long long *nums = new unsigned long long[n];
    for (int i = 0; i < n; i++)
    {
        nums[i] = rand64();
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
    cout << rand64() << "\n"
         << ans << endl;
}
