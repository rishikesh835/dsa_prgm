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
    return (ptr->top == ptr->size);
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
int main()
{
    
    struct  Stack *S;
    S=(struct Stack *)malloc(sizeof(struct Stack));//when this line was not included here compiler 
    //was throwing segmentation error
    S->size = 80;
    S->top = -1;
    S->arr = (int *)malloc(S->size * sizeof(int));

    if(isempty(S)){
        printf("Stack is empty");
    }
    else{
        printf("the Stack is not empty");
    }
    return 0;
}