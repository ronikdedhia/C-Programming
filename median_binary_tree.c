#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *create(int data)
{
    struct node *tree = (struct node *)malloc(sizeof(struct node));
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}
struct node *insertNode(struct node *root, int data)
{
    if (root == NULL)
        root = create(data);
    else if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}
int findMed(struct node *root, int n)
{
    if (root == NULL)
        return 0;
    int count = 0;
    struct node *current = root, *pre, *prev;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            count++;
            if (n % 2 != 0 && count == (n + 1) / 2)
                return current->data;
            else if (n % 2 == 0 && count == (n / 2) + 1)
                return (prev->data + current->data) / 2;
            prev = current;
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = NULL;
                prev = pre;
                count++;
                if (n % 2 != 0 && count == (n + 1) / 2)
                    return current->data;
                else if (n % 2 == 0 && count == (n / 2) + 1)
                    return (prev->data + current->data) / 2;
                prev = current;
                current = current->right;
            }
        }
    }
}
int main()
{
    int n;
    struct node *tree = NULL;
    printf("Enter number of elements in array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        tree = insertNode(tree, arr[i]);
    }
    int median = findMed(tree, n);
    printf("The Median Is: %d", median);
}
