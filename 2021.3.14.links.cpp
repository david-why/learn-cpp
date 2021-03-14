#include <iostream>

using namespace std;

struct LinkNode
{
    char value;
    int next;
    bool already;
    LinkNode() : value(0), next(0), already(false) {}
    LinkNode(char v, int n) : value(v), next(n), already(false) {}
    LinkNode(char v, int n, bool a) : value(v), next(n), already(a) {}
} nodes[100000] = {{0, 0, false}};

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        int addr, next;
        char value;
        cin >> addr >> next >> value;
        nodes[addr] = {value, next, false};
    }
    int now = a;
    while (nodes[now].next != -1)
    {
        if (nodes[now].already)
        {
            cerr << "DIDN'T YOU PROMISE ME THERE ARE NO LOOPS?\?!" << endl;
            return 1;
        }
        nodes[now].already = true;
        now = nodes[now].next;
    }
    int now2;
    for (now2 = b; nodes[now2].next != -1 && !nodes[now2].already; now2 = nodes[now2].next)
        ;
    while (now2 != now)
    {
        cout << nodes[now2].value;
        now2 = nodes[now2].next;
    }
    cout << nodes[now2].value;
    cout << endl;
    return 0;
}
