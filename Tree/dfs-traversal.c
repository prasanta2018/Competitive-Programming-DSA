#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Inorder
void printInorder(struct node* root) {
    if(!root)
        return;

    printInorder(root->left);
    printf("%d ",root->data);
    printInorder(root->right);
}

// Preorder
void printPreorder(struct node* root) {
    if(!root)
        return;

    printf("%d ",root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

// Postorder
void printPostorder(struct node* root) {
    if(!root)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ",root->data);
}

int main(void) {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder traversal of binary tree is: ");
    printInorder(root);
    printf("\n");

    printf("Preorder traversal of binary tree is: ");
    printPreorder(root);
    printf("\n");

    printf("Postorder traversal of binary tree is: ");
    printPostorder(root);
    printf("\n");

    return 0;
}