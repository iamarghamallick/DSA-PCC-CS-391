#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createTreeNode(int data)
{
    struct TreeNode *nn = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    nn->data = data;
    nn->left = nn->right = NULL;
    return nn;
}

struct TreeNode *insert(struct TreeNode *root, int data)
{
    if (root == NULL)
        return createTreeNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

struct TreeNode *inOrderPredecessor(struct TreeNode *root)
{
    // rightmost leaf node of the left sub-tree
    root = root->left;
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct TreeNode *delete(struct TreeNode *root, int key)
{
    struct TreeNode *iPre;
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (key < root->data)
        root->left = delete (root->left, key);
    else if (key > root->data)
        root->right = delete (root->right, key);
    else
    {
        // Case 1: Node with only one child or no child
        if (root->left == NULL)
        {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children, find the in-order predecessor
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = delete (root->left, iPre->data);
    }
    return root;
}

void inOrder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d, ", root->data);
    inOrder(root->right);
}

void preOrder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%d, ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d, ", root->data);
}

int main()
{
    struct TreeNode *root = NULL;
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 11);

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    // delete (root, 8);

    // printf("After deleting: ");
    // inOrder(root);
    // printf("\n");

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}