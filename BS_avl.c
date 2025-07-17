#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
int Max(int a, int b)
{
    return a > b ? a : b;
}
int getheight(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}
struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}
struct Node *leftRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = y->right;

    x->right = y;
    y->left = T2;

    y->height = Max(getheight(y->right), getheight(y->left)) + 1;
    x->height = Max(getheight(x->right), getheight(x->left)) + 1;
    return x;
}
struct Node *rightRotate(struct Node *x)
{
    struct Node *y = x->left;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = Max(getheight(y->right), getheight(y->left)) + 1;
    x->height = Max(getheight(x->right), getheight(x->left)) + 1;
    return y;
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->key);
        inorder(root->right);
    }
}
struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
    {
        return (createNode(key));
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    return node;
    node->height = 1 + Max(getheight(node->left), getheight(node->right));
    int bf = getBalanceFactor(node);
    // left left case
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    // right right case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    // left right case
    if (bf > 1 && key < node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // right left case
    if (bf < -1 && key < node->right->key)
    {
        node->right = leftRotate(node->right);
        return rightRotate(node);
    }
    return node;
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);

    inorder(root);
    return 0;
}