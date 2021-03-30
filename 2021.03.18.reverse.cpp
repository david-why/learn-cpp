#include <iostream>
#include <cstdio>

using namespace std;

struct LinkNode
{
    int data, next;
    LinkNode() : data(-1), next(-1) {}
    LinkNode(int d, int n) : data(d), next(n) {}
} nodes[100002] = {{}};

int main()
{
    int top, first, now, n, k;
    cin >> first >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int addr;
        cin >> addr;
        cin >> nodes[addr].data >> nodes[addr].next;
    }
    nodes[100001] = {-1, first};
    top = 100001;
    now = first;
    int n2 = 0;
    for (int i = first; i != -1; i = nodes[i].next)
        n2++;
    int m = n2 / k;
    for (int i = 0; i < m; i++)
    {
        //while (nodes[now].next != -1)
        for (int x = 0; x < k - 1; x++)
        {
            int next = nodes[now].next;
            nodes[now].next = nodes[next].next;
            nodes[next].next = nodes[top].next;
            nodes[top].next = next;
            //printf("top next %05d data %d next %05d\n", nodes[top].next, nodes[nodes[top].next].data, nodes[nodes[top].next].next);
        }
        for (int x = 0; x < k; x++)
        {
            if (nodes[top].next == -1)
                break;
            top = nodes[top].next;
            if (nodes[top].next != -1)
                printf("%05d %d %05d\n", top, nodes[top].data, nodes[top].next);
            else
            {
                printf("%05d %d -1\n", top, nodes[top].data);
                return 0;
            }
        }
        now = nodes[top].next;
    }
    int i;
    for (i = now; nodes[i].next != -1; i = nodes[i].next)
    {
        printf("%05d %d %05d\n", i, nodes[i].data, nodes[i].next);
    }
    printf("%05d %d -1\n", i, nodes[i].data);
    return 0;
}
