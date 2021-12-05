#include <iostream>

using namespace std;

struct LinkNode
{
    char value;
    int next;
    bool already;
    LinkNode() : value(0), next(0) {}
    LinkNode(char v, int n, bool a) : value(v), next(n), already(a) {}
} nodes[100000] = {{0, 0, false}};

int main()
{
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int addr, next;
        char value;
        cin >> addr >> next >> value;
        nodes[addr] = {value, next, false};
    }
    // for (int fin = s; nodes[fin].next != -1; fin++)
    // {
    //     int m = fin;
    //     for (int i = fin; nodes[i].next != -1; i++)
    //     {
    //         if (nodes[i].value < nodes[m].value)
    //             m = i;
    //     }
    //     //cout << m << " " << fin << endl;
    //     int x1 = nodes[m].before, x2 = nodes[fin].before;
    //     if (x1 == -1)
    //     {
    //         if (x2 == -1)
    //         {
    //             cerr << "WHAT" << endl;
    //             return 1;
    //         }
    //         x1 = s;
    //     }
    //     else if (x2 == -1)
    //         x2 = s;
    //     nodes[x1].next = fin;
    //     nodes[m].next = nodes[fin].next;
    //     nodes[fin].next = m;
    // }
    for (int i = 0; i < n; i++)
    {
        char m = -1;
        int index;
        for (int addr = s; addr != -1; addr = nodes[addr].next)
        {
            if (!nodes[addr].already && (nodes[addr].value < m || m == -1))
            {
                m = nodes[addr].value;
                index = addr;
            }
        }
        if (m == -1)
        {
            cerr << "WHAT?\?!" << endl;
            return 1;
        }
        nodes[index].already = true;
        cout << m << flush;
    }
    // for (int now = s; nodes[now].next != -1; now = nodes[now].next)
    //     cout << nodes[now].value;
    cout << endl;
    return 0;
}
