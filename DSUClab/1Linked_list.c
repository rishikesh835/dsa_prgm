#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
struct Node *createLinkedlist(int data){
    struct Node *p=(struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    return p;

}
void traverse(struct Node *ptr){
    if(ptr==NULL){
        printf("list does not exist");
    }
    else{
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    }
}
struct Node* insert(struct Node *head,int index,int value){
    if(index<1){
        printf("choose another option");
        return head;
    }
    struct Node *ptr=head;
    struct Node *p=(struct Node *)malloc(sizeof(struct Node));
    p->data=value;
    int i=0;
    while(i<index-1){
        ptr = ptr->next;
        i++;
    }
    p->next = ptr->next;
    ptr->next=p;
    return head;
}
struct Node* delete(struct Node *head,int index){
    struct Node *ptr=head;
    struct Node *prev;
    int i=0;
    while(i<index){
        prev=ptr;
        ptr = ptr->next;
        i++;
    }
    prev->next = ptr->next;
    free(ptr);
    return head;
}

int main(){
    int choice;
    printf("enter your choice\n");
    printf("1.to create a linked list\n");
    printf("2.to print a  linked list\n");
    printf("3.to insert at a index in  a linked list\n");
    printf("4.to delete a node linked list\n");
    printf("5.To exit\n");
    
    while(1){
        printf("Enter your choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter data of the first node\n");
            int key;
            scanf("%d",&key);
            struct Node *head=createLinkedlist(key);
            break;
        
        case 2:
            traverse(head);
            printf("\n");
            break;

        case 3:
           int index;
            printf("enter index of element to insert\n");
            scanf("%d",&index);
            int data;
            printf("Enter data to insert\n");
            scanf("%d",&data);
            head=insert(head,index,data);
            break;
        case 4:
           
            printf("enter indes of elemet to be deleted\n");
            scanf("%d",&index);
            head=delete(head,index);
        case 5:
            printf("user choosed to exit\n");
            exit(5);
        default:
            break;
        }
    }
    return 0;
}