#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

#define MAXN 1001
#define id short
#define relation int
#define name string

using namespace std;

unordered_map<name, id> name2id;
id nowid = 0;

relation weights[MAXN] = {0};
relation relations[MAXN][MAXN] = {{0}};

id gang[MAXN] = {0};
id gangs = 0;

name head[MAXN] = {""};
unordered_map<id, id> people;

relation totals[MAXN] = {0};

int main()
{
    int n, k;
    cin >> n >> k;
    for (id i = 0; i < n; i++)
    {
        name name1, name2;
        id id1, id2;
        relation m;
        cin >> name1 >> name2 >> m;
        if (name2id.count(name1))
            id1 = name2id[name1];
        else
            id1 = name2id[name1] = nowid++;
        if (name2id.count(name2))
            id2 = name2id[name2];
        else
            id2 = name2id[name2] = nowid++;
        relations[id1][id2] += m;
        relations[id2][id1] += m;
    }
    for (id now = 0; now < nowid; now++)
    {
        for (int next = 0; next < nowid; next++)
            weights[now] += relations[now][next];
    }
    // for (int i = 0; i < nowid; i++) cout << i << " " << weights[i] << endl;
    for (id now = 0; now < nowid; now++)
    {
        if (gang[now])
            continue;
        gangs++;
        queue<id> pending;
        pending.push(now);
        people[now] = 0;
        bool got[MAXN] = {false};
        while (!pending.empty())
        {
            id ingang = pending.front();
            gang[ingang] = now;
            pending.pop();
            got[ingang] = true;
            people[now]++;
            for (id next = 0; next < nowid; next++)
            {
                if (relations[ingang][next] && !got[next])
                {
                    pending.push(next);
                    totals[now] += relations[ingang][next];
                }
            }
        }
    }
    for (pair<const name, id> now : name2id)
        if (head[gang[now.second]] == "" || weights[name2id[head[gang[now.second]]]] < weights[now.second])
        {
            head[gang[now.second]] = now.first;
        }
    sort(head, head + gangs);
    for (id i = 0; i < nowid; i++)
    {
        if (head[i] == "" || people[gang[name2id[head[i]]]] < 3 || totals[gang[name2id[head[i]]]] <= k)
            continue;
        cout << head[i] << " " << people[gang[name2id[head[i]]]] << endl;
    }
    return 0;
}
