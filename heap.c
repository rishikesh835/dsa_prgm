#include<stdio.h>
#include<stdlib.h>
struct Heap{
    int *array;
    int count;
    int capacity;
    int heap_type;
};
typedef struct Heap Heap;
//creating heap
//time complexity O(1)
struct Heap *Createheap(int capacity,int heap_type){
    struct Heap *h=(struct Heap *)malloc(sizeof(struct Heap));
    if(h==NULL){
        printf("memory error");
        return h;
    }
    h->heap_type=heap_type;
    h->count=0;
    h->capacity=capacity;
    h->array=(int *)malloc(sizeof(int)*h->capacity);
    if(h->array==NULL){
        printf("Memory Error");
        return NULL;
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
int GetMax(Heap *h)
{
    if (h->count == 0)
        return -1;
    return h->array[0];
}
void PercolateDown(struct Heap *h,int i){
    int l,r,max,temp;
    l=LeftChild(h,i);
    r=RightChild(h,i);
    max = i;
    if(l!=-1 && h->array[l]>h->array[max])
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
void percolateDown(struct Heap *h, int i)
{
    int l, r, max, temp;
    l = LeftChild(h, i);
    r = RightChild(h, i);
    max = i;

    // Determine the maximum of the three: current node, left child, and right child
    if (l != -1 && h->array[l] > h->array[max])
        max = l;
    if (r != -1 && h->array[r] > h->array[max])
        max = r;

    // If the current node is not the maximum, swap it with the maximum child
    if (max != i)
    {
        temp = h->array[i];
        h->array[i] = h->array[max];
        h->array[max] = temp;

        // Recursively percolate down from the swapped child
        percolateDown(h, max);
    }
}
// Destroying heap
void DestroyHeap(Heap *h)
{
    if (h == NULL)
    {
        return;
    }
    free(h->array);
    free(h);
    h = NULL;
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
    percolateDown(h,0);
    return data;
}

void ResizeHeap(Heap *h)
{
    int *array_old = (int *)malloc(sizeof(int)* h->capacity);
    for (int i = 0; i < h->capacity; i++)
        array_old[i] = h->array[i];

    h->array = (int *)malloc(sizeof(int) * h->capacity * 2);
    if (h->array == NULL)
    {
        printf("memory error");
        return;
    }
    for (int i = 0; i < h->capacity; i++)
        h->array[i] = array_old[i];
    h->capacity *= 2;
    free(array_old);
}
void BuildHeap(Heap *h,int *a,int n){
    if(h == NULL) {
        return;
    }
    while(n > h->capacity)
    ResizeHeap(h);
    for(int i = 0;i< n;i++)
    h->array[i] = a[i];
    h->count = n;
    for(int i = (n-1)/2 ;i>=0;i--)
    percolateDown(h,i);
    
}
void insert(Heap *h,int data) {
    int i;
    if(h->count == h->capacity)
    ResizeHeap(h);
    h->count++;
    i = h->count -1;
    while(i>0 && data > h->array[(i-1)/2]){
        h->array[i] = h->array[(i-1)/2];
        i = (i-1)/2;
    }
    h->array[i] = data;
}



int main(){
    Heap *h = Createheap(12,1);
    int arr[] = {1,5,14,2,10,21,18,3,11,8,7,12};

    // BuildHeap(h,arr,12);
    // printf("%d ",GetMax(h));
    // printf("%d ",DeleteMax(h));
    // printf("%d ",GetMax(h));
    
    for(int i= 0;i<12;i++){
        insert(h,arr[i]);
        printf("%d ",GetMax(h));
    }
    return 0;
}