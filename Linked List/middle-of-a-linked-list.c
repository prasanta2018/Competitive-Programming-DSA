// Iterative C program to reverse a linked list
#include<stdio.h>
#include<stdlib.h>

// link list node
struct node {
    int data;
    struct node* next;
};

// Function to print the middle node of a linked list
void printMiddle(struct node** head)
{
    struct node* slow = *head;
    struct node* fast = *head;
    while( fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("The middle node of the linked list is: %d\n", slow->data);
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

    printMiddle(&head);

    return 0;
}