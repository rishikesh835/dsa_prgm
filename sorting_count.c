#include<stdio.h>
#include<limits.h>
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
int maximum(int *a,int n){
    int max=INT_MIN;
    for (int i=0;i<n;i++){
        if(max<a[i])
        max=a[i];
    }
    return max;
}
void CountSort(int *a,int n){
    int max=maximum(a,n);
    int *count=(int *)malloc((max+1)*sizeof(int));
    for(int i=0;i<(max+1);i++){
        count[i]=0;
    }
    for(int j=0;j<n;j++){
        count[a[j]]+=1;
    }
    int i,j;
    i=0;//for given array
    j=0;//for given array
    while(i<=max){
        if(count[i]>0){
            a[j]=i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
    } 
}
int main(){
    //int a[]={13,23,7,54,32,12,35,27};
    int *a;
    int n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    input(a,n);
    printf("array before sorting\n");
    print(a,n);
    CountSort(a,n);
    printf("\narray after sorting\n");
    print(a,n);
    return 0;
}