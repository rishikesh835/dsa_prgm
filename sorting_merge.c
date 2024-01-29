#include<stdio.h>
#include<stdlib.h>
void print(int a[],int n){
    for(int iter=0;iter<n;iter++){
    printf("%d ",a[iter]);
    }
}
void input(int *a,int n){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void merge(int *a,int mid,int low,int high){
    
    int i=low,b[100];
    int j=mid +1;
    int k=low;
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;k++;
        }
        else{
            b[k]=a[j];
            j++;k++;
        }
        while(i<=mid){
            b[k]=a[i];
            k++;i++;
        }
        while(j<=high){
            b[k]=a[j];
            j++;k++;
        }
    }
    for(int l=low;l<=high;l++){
        a[l]=b[l];
    }
}
void merge_sort(int a[],int low,int high){
    int mid;
    if(low<high){
    mid=(int)(low+high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid+1,high);
    merge(a,mid,low,high);
    }
}
int main(){
    int a[]={13,23,7,54,32,12,35,27};
    //  int *a;
     int n=8;
    // printf("enter the size of array\n");
    // scanf("%d",&n);
    // a=(int *)malloc(n*sizeof(int));
    // input(a,n);
    printf("array before sorting\n");
    print(a,n);
    merge_sort(a,0,n-1);
    printf("\narray after sorting\n");
    print(a,n);
    return 0;
}