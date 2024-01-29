#include<stdio.h>
#include<stdlib.h>
struct queue{
    int data;
    struct queue *next;
};
void LinkedListTraversal(struct queue *ptr){
    
    while(ptr!=NULL){
        printf("Element:%d\n", ptr->data);
        ptr=ptr->next;
    }
}
void enqueue(struct queue **f,struct  queue **r,int val){
    struct queue *n=(struct queue *)malloc(sizeof(struct queue));
    if(n==NULL){
        printf("Queue is Full\n");
    }
    else{
        n->data=val;
        n->next=NULL;
        if((*f)==NULL){
            (*f)=(*r)=n;
        }
        else{
            (*r)->next=n;
            (*r)=n;
        }
    }
}
int dequeue(struct queue **f){
    int val=-1;
    struct queue **ptr=(*f);
    if(f==NULL){
        printf("Queue is already empty\n");
    }
    else{
        (*f)=(*f)->next;
        val=(*ptr)->data;
        free(ptr);
    }
    return val;
}
int main(){
struct queue *f;
struct queue *r;
    LinkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue(&f));
    enqueue(&f,&r,34);
    enqueue(&f,&r,4);
    enqueue(&f,&r,7);
    enqueue(&f,&r,17);
    printf("Dequeuing element %d\n", dequeue(&f));
    printf("Dequeuing element %d\n", dequeue(&f));
    printf("Dequeuing element %d\n", dequeue(&f));
    printf("Dequeuing element %d\n", dequeue(&f));
    LinkedListTraversal(f);
    return 0;
}