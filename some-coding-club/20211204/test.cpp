#include <bits/stdc++.h>
#include "graph/merge_find_set.hpp"

using namespace std;

int main()
{
    mfset<int, 5> d;
    d.merge(1, 2);
    d.merge(2, 3);
    d.merge(3, 0);
    cout << d.connected(0, 2) << endl;
}
