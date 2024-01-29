#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node *ptr)
{
    while(ptr!=NULL){
    printf("element %d\n", ptr->data);
    ptr = ptr->next;
    }
}
int main()
{
    printf("this is a program for traversal of linked list");
    struct Node *head;
    struct Node *second;
    struct Node *third,*fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    //insert= (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = second;

    second->data = 9;
    second->next = third;


    third->data = 90;
    third->next = NULL;

    fourth->data = 76;
    fourth->next = NULL;
    LinkedListTraversal(head);
    return 0;
}