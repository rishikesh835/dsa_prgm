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
void insertin_sort(int *a,int n){
    for (int i=1;i<n;i++){
        for (int j=i;a[j-1]>a[j];j--){
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
        }
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
    insertin_sort(a,n);
    printf("array after sorting\n");
    print(a,n);
    return 0;
}