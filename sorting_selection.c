#include<stdio.h>
#include<stdlib.h>
void print(int a[],int n){
    for(int i=0;i<n;i++){
    printf("%d ",a[i]);
    }
}
void input(int *a,int n){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void selection_sort(int *a, int n){
    int min,temp;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}
int main(){
    int *a;
    int n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    input(a,n);
    printf("array before sorting\n");
    print(a,n);
    selection_sort(a,n);
    printf("\narray after sorting\n");
    print(a,n);
    return 0;
}