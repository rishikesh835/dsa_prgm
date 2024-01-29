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
    n->data=data;
    n->left=NULL;
    n->right=NULL;
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
void insert(struct Node* root,int key){
    struct Node* prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            printf("Cannot insert %d,already in BST",key);
            return;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct Node *new=CreateNode(key);
    if(key<prev->data){
        prev->left=new;
        
    }
    else{
        prev->right=new;
       
    }
}
struct Node *inOrderpredecessor(struct Node *root){
    root=root->left;
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}
struct Node *deleteNode(struct Node *root,int value){
    struct Node *ipre=(struct Node *)malloc(sizeof(struct Node));
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    //search for the node
    if(value<root->data){
        root->left=deleteNode(root->left,value);
    }
    else if(value>root->data){
        root->right=deleteNode(root->right,value);
    }
    //deletion strategy when node is found
    else{
        ipre=inOrderpredecessor(root);
        root->data=ipre->data;
        root->left=deleteNode(root->left,ipre->data);
    }
    return root;
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
insert(p,7);
inorder(p);
deleteNode(p,5); 
printf("\n"); 
inorder(p);
return 0;
} 