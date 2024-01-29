#include<stdio.h>
#include<stdlib.h>
//defining stack with array
typedef struct stack{
    int top;
    int data[10];
}stack;
// declaring operations of stack
void push(stack *s,int val);
int pop(stack *s);
void top(stack *s);
void list(stack *s);
int main(){
    stack *s=(stack *)malloc(sizeof(stack));
    s->top=-1;
    int choice=1;
    while(choice !=4){
        
    printf("enter your choice 1.push 2.pop 3.list stack 4.end \n");
    scanf("%d",&choice); 

        switch(choice){
            case 1: 
                int val;
                printf("input value to enter\n");
                scanf("%d",&val);
                push(s,val);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                list(s);
                break;
            case 4:
                printf("program ended\n");
                break;

        }
    }
    return 0;
}


//funtion to push the element into the stack
void push(stack *s,int val){
    s->top++;
    if(s->top!=10){
        s->data[s->top]=val;
    }
    else{
        printf("stack is full\n");
    }
}


//funtion to pop the top most element
int pop(stack *s){
    if(s->top>-1){
        printf("%d popped\n",s->data[s->top]);
        s->top--;
    }
    else{
        printf("stack is empty\n");
    }
}

//funtion to list the stack
void list(stack *s){
    for(int i=s->top;i>=0;i--){
        printf("%d  ",s->data[i]);
    }
    printf("\n");
}