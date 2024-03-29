#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    char *arr;
};
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1)
    return 1;
    else {
        return 0;
    }
}
int isEmpty(struct stack *ptr){
    if(ptr->top==-1)
    return 1;
    else {
        return 0;
    }
}
void push(struct stack *ptr,int data){
    if(isFull(ptr)){
        printf("stack is full");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
}
char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("stack underflow");
        return -1;
    }
    else{
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int match(char a,char b){
    if (a=='(' && b==')'){
        return 1;
    }
    if (a=='[' && b==']'){
        return 1;
    }
    if (a=='{' && b=='}'){
        return 1;
    }
    return 0;
}
int parenthesisMatch(char *exp){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(sp, exp[i]);
        }
    
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isEmpty(sp)){
                return 0;
            }
            char popped_ch=pop(sp);
            if (!match(popped_ch,exp[i])){
                return 0;
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    char *exp="[4-6]((8){8*7-9})";
    if(parenthesisMatch(exp)){
        printf("parenthesis is  a match");
    }
    else{
        printf("parenthesis is not a match");
    }

    return 0;
}