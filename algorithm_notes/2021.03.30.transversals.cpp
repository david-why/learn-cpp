#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int v;
    node *l;
    node *r;
    node() : v(0), l(NULL), r(NULL) {}
    node(int val) : v(val), l(NULL), r(NULL) {}
    node(int val, node *left, node *right) : v(val), l(left), r(right) {}
};

node *create(int *post, int *in, int postL, int postR, int inL, int inR)
{
    // cout << "create " << postL << ' ' << postR << ' ' << inL << ' ' << inR << endl;
    if (postL > postR)
        return NULL;
    node *root = new node;
    int v = post[postR];
    root->v = v;
    int k = -1;
    for (int i = inL; i <= inR; i++)
    {
        if (in[i] == v)
        {
            k = i - inL;
            break;
        }
    }
    // cout << k << ' ' << v << endl;
    if (k == -1)
        return NULL;
    root->l = create(post, in, postL, postL + k - 1, inL, inL + k - 1);
    root->r = create(post, in, postL + k, postR - 1, inL + k + 1, inR);
    return root;
}

int main()
{
    int n;
    cin >> n;
    int post[n], in[n];
    for (int i = 0; i < n; i++)
        cin >> post[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    node *root = create(post, in, 0, n - 1, 0, n - 1);
    if (root == NULL)
        return 1;
    queue<node *> now;
    now.push(root);
    while (!now.empty())
    {
        node *n = now.front();
        now.pop();
        cout << n->v;
        if (n->l)
            now.push(n->l);
        if (n->r)
            now.push(n->r);
        if (!now.empty())
            cout << " ";
    }
    cout << endl;
    return 0;
}
