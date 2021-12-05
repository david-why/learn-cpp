#include <bits/stdc++.h>
#include "graph/merge_find_set.hpp"

using namespace std;

int main()
{
    merge_find_set<int> d;
    d.connect(1, 12);
    d.connect(12, 13);
    cout << d.connected(1, 13) << endl;
}
