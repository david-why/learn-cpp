#include <iostream>

using namespace std;

struct node
{
    short height, value;
    struct node *left, *right;
    node(short h, short v, node *l, node *r) : height(h), value(v), left(l), right(r) {}
};

void updateHeight(node *root)
{
    root->height = max(
                       (root->left ? root->left->height : 0),
                       (root->right ? root->right->height : 0)) +
                   1;
}

void rotate_left(node *&root)
{
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void rotate_right(node *&root)
{
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

short balance_factor(node *root)
{
    return (root->left ? root->left->height : 0) - (root->right ? root->right->height : 0);
}

void insert(node *&root, short value)
{
    if (root == NULL)
    {
        root = new node(1, value, NULL, NULL);
        return;
    }
    if (value < root->value)
    {
        insert(root->left, value);
        updateHeight(root);
        if (balance_factor(root) >= 2)
        {
            if (balance_factor(root->left) > 0)
                rotate_right(root);
            else if (balance_factor(root->left) < 0)
            {
                rotate_left(root->left);
                rotate_right(root);
            }
        }
    }
    else
    {
        insert(root->right, value);
        updateHeight(root);
        if (balance_factor(root) <= -2)
        {
            if (balance_factor(root->right) < 0)
                rotate_left(root);
            else if (balance_factor(root->right) > 0)
            {
                rotate_right(root->right);
                rotate_left(root);
            }
        }
    }
}

void preOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->value << ' ';
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->value << ' ';
    inOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->value << ' ';
}

int main()
{
    node *root = NULL;
    for (short i = 2; i < 101; i += 2)
        insert(root, i);
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
}
