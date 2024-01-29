// this is a program to implement stack using array
#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
struct Stack{
    int size;
    int top;
    int *arr;
};
// function to know if a Stack is empty or not--boolean logic meathod
int isEmpty(struct Stack *ptr)
{
    return (ptr->top == -1);
}
// function to know if a Stack is empty or not--if else logic
// note that name of this function is different than the function above
int isempty(struct Stack *ptr)
{
    if (ptr->top == -1){
    return 1;
    }
    else{
        return 0;
    }
}
// function to know if a funtion to know if a Stack is full--boolean method
int isFull(struct Stack *ptr)
{
    return (ptr->top == ptr->size-1);
}
// // function to know if a funtion to know if a Stack is full--if else logic
// // note that name of this funtion is different from above
int isfull(struct Stack *ptr){
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//funtion to push elements into the stack.If stack is not full
void push(struct Stack *ptr,int data){
    if(isFull(ptr)){
        printf("stack overflow! can not push %d in stack",data);
    }
    else{
        ptr->top+=1;
        ptr->arr[ptr->top]=data;
    }
}
//funtion to print the values of a stack
void print(struct Stack *ptr){
    for(int i=0;i<=ptr->top;i++){
        printf("%d\n",ptr->arr[i]);
    }
}
void pop(struct Stack *ptr){
    if(isEmpty(ptr)){
        printf("stack is empty nothing can be deleted");
       
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top-=1;
    }
}
int peek(struct Stack *ptr, int i){
    if(ptr->top-i+1<0)
    printf("invalid position!");
    else
    return ptr->arr[ptr->top-i+1];
}
int main()
{
    
    struct  Stack *S;
    S=(struct Stack *)malloc(sizeof(struct Stack));//when this line was not included here compiler 
                                                   //was throwing segmentation error
    S->size = 10;
    S->top = -1;
    S->arr = (int *)malloc(S->size * sizeof(int));
    printf("the stack was created successfully\n");

    push(S,1);
    push(S,2);
    push(S,3);
    push(S,4);
    push(S,5);
    push(S,1);
    push(S,2);
    push(S,3);
    push(S,4);
    push(S,5);
   
    push(S,32);//pushed 11th element which throws stsck overflow
    
    print(S);//to transverse and print stack elements
    pop(S);
    printf("stack after popping element");
    print(S);
    printf("elemnt at this position is %d\n",peek(S,3));
    return 0;
}