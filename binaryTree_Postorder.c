//In preorder traversal order of trversal is
//1.root            2.Left Node                 3.Right Node

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;;
    struct Node *right;
};
struct Node* CreateNode(int data){
    struct Node *n;
    n=(struct Node *)malloc(sizeof(struct Node));
    n->data=data;;
    n->right=NULL;
    n->left=NULL;
    return n;
}
void preorder(struct Node * root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node * root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
void inorder(struct Node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
//          4
//        /   \
//        1    6
//      /  \
//     5    2
int main(){
    //construction root node using funtion
    struct Node *p;
    p=CreateNode(4);
    struct Node *p1=CreateNode(1);
    struct Node *p2=CreateNode(6);
    struct Node *p3=CreateNode(5);
    struct Node *p4=CreateNode(2);


//Linking nodes to make a tree
p->left=p1;
p->right=p2;
p1->left=p3;
p1->right=p4;

preorder(p);
printf("\n");
postorder(p);
printf("\n");
inorder(p);
    return 0;
} 