#include<stdio.h>
#include<stdlib.h>
struct queue{
    int data;
    struct queue *next;
};
struct queue *f;
struct queue *r;
void LinkedListTraversal(struct queue *ptr){
    
    while(ptr!=NULL){
        printf("Element:%d\n", ptr->data);
        ptr=ptr->next;
    }
}
void enqueue(int val){
    struct queue *n=(struct queue *)malloc(sizeof(struct queue));
    if(n==NULL){
        printf("Queue is Full\n");
    }
    else{
        n->data=val;
        n->next=NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}
int dequeue(){
    int val=-1;
    struct queue *ptr=f;
    if(f==NULL){
        printf("Queue is already empty\n");
    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}
int main(){
    LinkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    LinkedListTraversal(f);
    return 0;
}