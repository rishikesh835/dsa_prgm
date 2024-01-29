#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *insertion(struct Node *head,int data){   
    struct Node *ptr=head;
    struct Node *new=malloc(sizeof(struct Node));
    new->data=data;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=new;
    new->next=head;
    head=new;
    return head;
}

void LinkedListTraversal(struct Node *head){   
    struct Node *ptr=head;
    do{
    printf("element %d\n", ptr->data);
    ptr = ptr->next;
    }while(ptr!=head);
}
int main()
{
    printf("this is a program for traversal of linked list");
    struct Node *head;
    struct Node *second;
    struct Node *third,*insert;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    //insert= (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = second;

    second->data = 9;
    second->next = third;


    third->data = 90;
    third->next = head;
    printf("linked list before \n");
    LinkedListTraversal(head);
    head=insertion(head,23);
    printf("linked List after");
    LinkedListTraversal(head);
    return 0;
}