#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct node *insertAfterNode(struct Node *head,struct Node *prenode,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    (*ptr).data=data;
    ptr->next=prenode->next;
    prenode->next=ptr;
     return 0;//return head; can also be used
}
void LinkedListTraversal(struct Node *ptr)
{
    while(ptr!=NULL){
    printf("element %d\n", ptr->data);
    ptr = ptr->next;
    }
}
struct Node * insertionAtEnd(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return 0;
}
struct Node * insertionAtFirst(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    printf("element added at the start of the list\n");
    return head;
}
struct Node * insertionAtindex(struct Node *head,int data,int index){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1){
    i++;
    p=p->next;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return 0;

}

int main()
{
    printf("this is a program for traversal of linked list\n");
    struct Node *head;
    struct Node *second;
    struct Node *third,*insert;
    struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    //insert= (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = second;

    second->data = 9;
    second->next = third;


    third->data = 90;
    third->next = fourth;

    fourth->data = 90;
    fourth->next = NULL;

    
    LinkedListTraversal(head);
    //head=insertionAtFirst(head,56);
    // insertionAtindex(head,34,2);
    //insertionAtEnd(head,34);
    insertAfterNode(head,third,34);
    LinkedListTraversal(head);

    return 0;
}