#include<stdio.h>
int linearsearch(int arr[],int size,int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element){
            return i;
        }
    }
    return -1;
    
}
int binarysearch(int arr[],int size,int element){
    int low=0,mid,high=size-1;
    while(low<=high){
        mid=(low+high)/2;
        if (arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    return -1;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,65,76};
    int size=sizeof(arr)/sizeof(int);
    int element=4;
    int searchindex=linearsearch(arr,size,4);
    printf("the element %d is found at %dth index by linear search\n",element,searchindex);
    int index=binarysearch(arr,size,element);
    printf("the element %d is found at %dth index by binary search\n",element,index);
return 0;
}