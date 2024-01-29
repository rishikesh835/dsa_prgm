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
    n->data=2;
    n->right=NULL;
    n->left=NULL;
    return n;
}
int main(){
    // struct Node *p;
    // p=(struct Node *)malloc(sizeof(struct Node));
    // p->data=2;
    // p->right=NULL;
    // p->left=NULL;

//     struct Node *p1;
//     p1=(struct Node *)malloc(sizeof(struct Node));
//     p->data=2;
//     p1->right=NULL;
//     p1->left=NULL;

//     struct Node *p2;
//     p2=(struct Node *)malloc(sizeof(struct Node));
//     p->data=2;
//     p2->right=NULL;
//     p2->left=NULL;

// p->left=p1;
// p->right=p2;


//constructing the root node
struct Node *p=CreateNode(2);
struct Node *p1=CreateNode(8);
struct Node *p2=CreateNode(5);

//now linking the nodes
p->left=p1;
p->right=p2;
    return 0;
}