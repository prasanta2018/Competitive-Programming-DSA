// Find kth node from Middle towards Head of a Linked List
// Company - Arista Network

#include<stdio.h>
#include<stdlib.h>

// link list node
struct node {
    int data;
    struct node* next;
};

// Function to print the kth node from the middle of a linked list
int printKthFromMiddle(struct node** head, int k)
{
    struct node* slow = *head;
    struct node* fast = *head;
    int i;

    for(i=0; i < k; i++) {
        // before starting of race fast is going ahead of 2k times
        if(fast && fast->next) {
            fast = fast->next->next;
        }
        else {
            return -1;
        }
    }
    // for the remaining (n/2 - k) times, if we start the race then slow will be at the k the element from middle and fast will be at the end of list
    while( fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
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
    int k = 7;
    int result;
    struct node* head = NULL;

    push(&head, 20);
    push(&head, 25);
    push(&head, 85);
    push(&head, 95);
    push(&head, 105);  

    printf("Given linked list:");
    printList(head);
    printf("\n");

    result = printKthFromMiddle(&head, k);

    if(result == -1)
        printf("%d-th node from the middle is not exist\n", k);
    else
        printf("The %d-th node from the middle is: %d\n", k, result);

    return 0;
}