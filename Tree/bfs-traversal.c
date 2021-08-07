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

// Tree Level
int getLevel(struct node* root) {
    int lLevel, rLevel;
    if(!root)
        return 0;
    lLevel = getLevel(root->left);
    rLevel = getLevel(root->right);
    if(lLevel > rLevel)
        return (1+lLevel);
    else
        return (1+rLevel);
}

// Print current level
void printCurrentLevel(struct node* root, int level) {
    if(!root)
        return;
    if(level == 1)
        printf("%d ", root->data);
    else {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}

// Levelorder
void printLevelorder(struct node* root) {
    int l = getLevel(root);
    int i;
    for(i=1; i<=l; i++) {
        printf("   Level-%d ---> ", i);
        printCurrentLevel(root, i);
        printf("\n");
    }
}

int main(void) {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level order traversal of binary tree is: \n");
    printLevelorder(root);
    printf("\n");

    return 0;
}