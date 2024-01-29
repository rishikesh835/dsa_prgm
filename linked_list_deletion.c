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
// deleting the element at the first node
struct Node * deleteFirst(struct Node * head){
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
// deleting the node with a given value
struct Node * deletevalue(struct Node * head,int data){
    struct Node *ptr=head;
    struct Node *q=head->next;

    while(q->data!=data && q->next!=NULL){
        ptr=ptr->next;
        q=q->next;
    }
    if (q->data=data){
    ptr->next=q->next;
    free(q);
    }
    else{
        printf("element is not in the list");
    }
    return head;
}
// deletig the element at index
struct Node * deleteAtIndex(struct Node * head,int i){
    struct Node *ptr=head;
    struct Node *q=head->next;

    int j=0;
    while(j!=i){
        q=q->next;
        ptr=ptr->next;
        j++;
    }
    ptr->next=q->next;
    free(q);
    return head;
}
// deleting the last node
struct Node *deleteLast(struct Node *head){
    struct Node *ptr=head;
    struct Node *q=head->next;
    while(q->next!=NULL){
        q=q->next;
        ptr=ptr->next;
    }
    free(q);
    ptr->next=NULL;
    return head;
}

int main(){
    printf("this is a program for traversal of linked list\n");
    struct Node *head;
    struct Node *second;
    struct Node *third;
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

    printf("linked list before deletion\n");
    LinkedListTraversal(head);
    //head=deleteFirst(head);
    // head=deleteAtIndex(head,2);
    //head=deleteLast(head);
    head=deletevalue(head,23);
    printf("linked list after deletion\n");
    LinkedListTraversal(head);

    

    return 0;
}