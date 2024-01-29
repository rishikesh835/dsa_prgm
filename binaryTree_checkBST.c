 //In preorder traversal order of trversal is
//1.root            2.Left Node                 3.Right Node

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;  
    struct Node *right;
};
struct Node* CreateNode(int data){
    struct Node *n;
    n=(struct Node *)malloc(sizeof(struct Node));
    n->data=data;
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
int isBST(struct Node * root){
    static struct Node *prev=NULL;
        if(root!=NULL){
            if(!isBST(root->left)){
                return 0; 
            }
            if(prev!=NULL && root->data <= prev->data){
                return 0;
            }
            prev=root;
            return isBST(root->right);
        }
        else{
                return 1;
        }
}
void inorder(struct Node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
//          5
//        /   \
//        3    6
//      /  \
//     1    4
int main(){
    //construction root node using funtion
    struct Node *p=CreateNode(5);
    struct Node *p1=CreateNode(3);
    struct Node *p2=CreateNode(6); 
    struct Node *p3=CreateNode(1);
    struct Node *p4=CreateNode(4);


//Linking nodes to make a tree
p->left=p1;
p->right=p2;
p1->left=p3;
p1->right=p4;

// preorder(p);
// printf("\n");
// postorder(p);
// printf("\n");
// inorder(p);

if(isBST(p)){
    printf("this is a BST");
}
    return 0;
} 