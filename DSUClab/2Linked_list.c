#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct contact{
    char name[30];
    long int contact_no;
    char email[50];
   struct contact *next;
}contact;

contact *getNode();
void traverse(contact *head);
contact* insert(contact *head);
contact* delete(contact *head,char name[]);
//rishikesh 8384043001 rishikeshmishra835@gmail.com
int main(){
    int choice;
    printf("enter your choice\n");
    printf("1.to create a new phone book\n");
    printf("2.to print the contact\n");
    printf("3.to insert a new contact\n");
    printf("4.to delete a contact linked list\n");
    printf("5.To exit\n");
    
    while(1){
        printf("Enter your choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            
            contact *head=getNode();
            break;
        
        case 2:
            traverse(head);
            printf("\n");
            break;

        case 3:
           contact *p=insert(head);   
           p->next=head;
           head=p;         
            break;
        case 4:
           printf("enter the name of the contact");
           char name[30];
           scanf("%s",name);
            
            head=delete(head,name);
        case 5:
            printf("user choosed to exit\n");
            exit(5);
        default:
            break;
        }
    }
    return 0;
}
//creating node to store contact information
contact *getNode(){
    long int phone_no;
    char name[30],email[50];
    printf("Name of first contact,in order(name,phone,email)\n");
     fgets(name, sizeof(name), stdin);  
    scanf("%ld",&phone_no);
     fgets(email, sizeof(email), stdin); 
    contact *p=(contact *)malloc(sizeof(contact));    
    p->contact_no=phone_no;
    strcpy(p->name,name);
    strcpy(p->email,email);
    p->next = NULL;
    return p;

}
// printinf all the contacts information`   
void traverse(contact *head){
        contact *ptr=head;
    if(ptr==NULL){
        printf("list does not exist");
    }
    else{
    while(ptr->next!= NULL){
        printf("%s %ld %s ",ptr->name,ptr->contact_no,ptr->email);
        ptr = ptr->next;
    }
    }
}
//inserting a new node at the head position
contact* insert(contact *head){
    if(head==NULL){
        printf("choose another option");
        return head;
    }
    contact *node=getNode();
    return node;
}
//deleting a contact with a particular name
contact* delete(contact *head,char name[]){
    contact *ptr=head;
    contact *prev;
   
    while(ptr->name!=name){
        prev=ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
    return head;
}