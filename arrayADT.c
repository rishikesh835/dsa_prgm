#include<stdio.h>
#include<stdlib.h>
struct myarray{
    int total_size;
    int used_size;
    int *ptr;
};

void createarray(struct myarray *a,int tsize,int usize){
    (*a).total_size=tsize;
    (*a).used_size=usize;
    (*a).ptr=(int *)malloc(tsize * sizeof(int));
    //a->total_size=tsize;
}

void show(struct myarray *a){
    int i;
    for ( i = 0; i < (*a).used_size; i++)
    {
        printf("%d\n",(*a).ptr[i]);//(a->ptr)[i]
    }
}
void setval(struct myarray *a){
    int i,n;
    for ( i = 0; i < (*a).used_size; i++)
    {
    printf("enter element %d",i+1);
    scanf("%d",&n);
    (a->ptr)[i]=n;

    }
    
}
int main(){
    struct myarray marks;
    createarray(&marks,10,2);
    setval(&marks);
    show(&marks);
    return 0;
}