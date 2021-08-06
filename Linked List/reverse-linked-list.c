// Iterative C program to reverse a linked list
#include<stdio.h>
#include<stdlib.h>

// link list node
struct node {
    int data;
    struct node* next;
};

// Function to reverse a linked list
void reverse(struct node** head)
{
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next = NULL;

    while(current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to push a node
void push(struct node** head, int new_data)
{
    struct node* new_node = (struct  node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

// Function to print linked list
void printList(struct node* head)
{
    struct node* temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(void) {
    struct node* head = NULL;

    push(&head, 20);
    push(&head, 25);
    push(&head, 85);
    push(&head, 95);
    push(&head, 105);  

    printf("Given linked list:");
    printList(head);
    printf("\n");

    reverse(&head);
    printf("Reversed linked list:");
    printList(head);
    printf("\n");

    return 0;
}