#include<stdio.h>
#include<stdlib.h>
void print(int a[],int n){
    for(int i=0;i<n;i++){
    printf("%d ",a[i]);
    }
}
int main(){
    int *a;
    int n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("array before sorting is\n");
    print(a,n);
    for(int i=0;i<n-1;i++){
        int issorted=1;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                issorted=0;
            }
            if(issorted==1){
                break;
            }
        }
    }
    printf("\narray after sorting\n");
    print(a,n);
    return 0;
}