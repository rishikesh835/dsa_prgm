#include<stdio.h>
#include<stdlib.h>
struct Circularqueue{
    int size;
    int f; 
    int r;
    int *arr;
};
int isFull(struct Circularqueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}
int isEmpty(struct Circularqueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
void enqueue(struct Circularqueue *ptr,int val){
    if(isFull(ptr)){
        printf("Circular queue overflow\n");
    }
    else{
        ptr->r=(ptr->r+1)%ptr->size;
        ptr->arr[ptr->r]=val;
        printf("enqued element:%d\n",val);
    }
}
int dequeue(struct Circularqueue *ptr){
    int a=-1;
    if(isEmpty(ptr)){
        printf("the Circular queue is empty\n");
    }
    else{
        ptr->f=(ptr->f+1)%ptr->size;
        a=ptr->arr[ptr->f];
    }
    return a;
}
int main(){
    struct Circularqueue q;
    q.size=4;
    q.f=0;
    q.r=0;
    q.arr=(int *)malloc(q.size*sizeof(int));
    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,80);
    printf("Dequeueing element %d\n",dequeue(&q));
    printf("Dequeueing element %d\n",dequeue(&q));
    printf("Dequeueing element %d\n",dequeue(&q));
    printf("Dequeueing element %d\n",dequeue(&q));
    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,80);
    enqueue(&q,80);
    if(isEmpty(&q)){
        printf("Circular queue is Empty\n");
    }
    if(isFull(&q)){
        printf("Circular queue is Full");
    }
    return 0;
}