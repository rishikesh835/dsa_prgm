// this a program to implement stack by using linked list
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
// funtion to check if stack is empty top would have Null data
int isEmpty(struct Node *top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }

}
// funtion to check if stack is full it happens when there is no space in system 
int isfull(struct Node *top){
    struct Node *p=(struct Node *)malloc(sizeof(struct Node));
    if(p==NULL)
    return 1;
    else
    return 0;
}
// function to push an element into the stack 
struct Node *push(struct Node *top,int x){
    if(isfull(top)){
        printf("struct overflow!");
    }
    else{
        struct Node *n=(struct Node *)malloc(sizeof(struct Node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}
//funtion to print all the elements in the stack 
//this is same as the transversal of a linked list
void LinkedListTraversal(struct Node *ptr){
    
    while(ptr!=NULL){
    printf("element %d\n", ptr->data);
    ptr = ptr->next;

    }
}
int pop(struct Node **top){
    if(isEmpty(top)){
        printf("Stack underflow!");
    }
    else{
        struct Node * n=*top;
        *top=(*top)->next;
        int x=n->data;
        free(n);
        return x;
    }
}
int peek(struct Node *top,int pos){
    struct Node *ptr=top;
    for (int i=0;(i<pos-1 && ptr!=NULL);i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
    
}
int main(){
    struct Node* top=NULL;
    top=push(top,78);
    top=push(top,34);
    top=push(top,74);
    top=push(top,64);
    top=push(top,23);
    LinkedListTraversal(top);
    int element=pop(&top);//pointer address is passed because function doesn't makes any changes to the top in main()
    printf("element popped %d\n",element);
    LinkedListTraversal(top);
    printf("this elment is at postion 2: %d",peek(top,2));
    return 0;
}