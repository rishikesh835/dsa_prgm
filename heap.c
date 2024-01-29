#include<stdio.h>
#include<stdlib.h>
struct Heap{
    int *array;
    int count;
    int capacity;
    int heap_type;
};
//creating heap
//time complexity O(1)
struct Heap *Createheap(int capacity,int heap_type){
    struct Heap *h=(struct Heap *)malloc(sizeof(struct Heap));
    if(h==NULL){
        printf("memorry erorr");
        return;
    }
    h->heap_type=heap_type;
    h->count=0;
    h->capacity=capacity;
    h->array=(int *)malloc(sizeof(int)*h->capacity);
    if(h->array==NULL){
        printf("Memory Error");
        return;
    }
    return h;
}
//returns parents of element
//time complexity O(1)
int Parent(struct Heap *h,int i){
    if(i<=0 || i>=h->count)
    return -1;
    return (i-1)/2;
}
//returns Left Child of parent i
//time complexity O(1)
int LeftChild(struct Heap *h,int i){
    int left=2*i+1;
    if(left>=h->count)
    return  -1;
    return left;
}
//returns Left Child of parent i
//time complexity O(1)
int RightChild(struct Heap *h,int i){
    int right=2*i+2;
    if(right>=h->count)
    return -1;
    return right;
}
//Making elements follow heap property
//Time complexity O(log n)
void PercolateDown(struct Heap *h,int i){
    int l,r,max,temp;
    l=LeftChild(h,i);
    r=rightChild(h,i);
    if(l!=-1 && h->array[l]>h->array[i])
    max=l;
    else
    max=i;
    if(r!=-1 && h->array[r]>h->array[max])
    max=r;
    if(max!=i){
        temp=h->array[i];
        h->array[i]=h->array[max];
        h->array[max]=temp;
    }
    PercolateDown(h,max);
}
//Deleting elements from the heap
//Time Complexity O(log n)
int DeleteMax(struct Heap *h){
    int data;
    if(h->count==0)
    return -1;
    data=h->array[0];
    h->array[0]=h->array[h->count-1];
    h->count--;//reducing the heap size
    PercolateDown(h,0);
    return data;
}
