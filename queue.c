#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *ptr,int val){
    if(isFull(ptr)){
        printf("queue overflow\n");
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r]=val;
        printf("enqued element:%d\n",val);
    }
}
int dequeue(struct queue *ptr){
    int a=-1;
    if(isEmpty(ptr)){
        printf("the queue is empty\n");
    }
    else{
        ptr->f++;
        a=ptr->arr[ptr->f];
    }
    return a;
}
int main(){
    struct queue q;
    q.size=4;
    q.f=0;
    q.r=0;
    q.arr=(int *)malloc(q.size*sizeof(int));
  
    return 0;
}