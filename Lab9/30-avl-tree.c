#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

struct Node *createNode(int data)
{
    struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    nn->height = 1;
    return nn;
}

int getHeight(struct Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalenceFactor(struct Node *node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node *leftRotation(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    y->right = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return y;
}

struct Node *rightRotation(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int bf = getBalenceFactor(root);

    // Left-Left Rotation
    if (bf > 1 && data < root->left->data)
    {
        return rightRotation(root);
    }
    // Right-Right Rotation
    if (bf < -1 && data > root->right->data)
    {
        return leftRotation(root);
    }
    // Left-Right Rotation
    if (bf > 1 && data > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // Right-Left Rotation
    if (bf < -1 && data < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d, ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preOrder(root);
    return 0;
}