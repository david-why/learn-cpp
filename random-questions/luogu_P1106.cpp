// https://www.luogu.com.cn/problem/P1106
// Luogu P1106 删数问题
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 250 + 5;
string n;
string ans;
int k;
struct val
{
    const string *s;
    int v;
    size_t getlen() const
    {
        if (v != 0)
            return s->length() - 1;
        size_t l = s->length() - 1;
        int i = 1;
        while (s->at(i) == 0)
            l--, i++;
        return l;
    }
    bool operator<(const val &o) const
    {
        if (getlen() < o.getlen())
            return true;
        if (getlen() > o.getlen())
            return false;
        int i = 0, j = 0;
        while (i < s->length())
        {
            if (i == v)
                i++;
            if (j == o.v)
                j++;
            if (s->at(i) < o.s->at(j))
                return true;
            if (s->at(i) > o.s->at(j))
                // if (s[i] > o.s[j])
                return false;
            i++;
            j++;
        }
        return false;
    }
    bool operator>(const val &o) const { return !operator<(o); }
};
void dfs(int v, string s)
{
    if (v == 0)
    {
        ans = s;
        return;
    }
    priority_queue<val, vector<val>, greater<val>> pq;
    for (int i = 0; i < s.length(); i++)
        pq.push({&s, i});
    s.erase(pq.top().v, 1);
    while (s.front() == '0')
        s.erase(0, 1);
    if (s.length() == 0)
        s.push_back('0');
    dfs(v - 1, s);
}
int main()
{
    cin >> n >> k;
    dfs(k, n);
    cout << ans << endl;

    return 0;
}
