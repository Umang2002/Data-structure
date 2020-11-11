#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

void preOrder(struct Node * root){
       
       if(root==NULL){
           return 0;
       }
       printf("%d ",root->data);
       preOrder(root->left);
       preOrder(root->right);
}

void inOrder(struct Node * root){
       
       if(root==NULL){
           return 0;
       }
       inOrder(root->left);
       printf("%d ",root->data);
       inOrder(root->right);
}
void postOrder(struct Node * root){
       
       if(root==NULL){
           return 0;
           }
       postOrder(root->left);
       postOrder(root->right);
       printf("%d ",root->data);
}

struct Node * create_node(){
    int x;
    struct Node * temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data(-1 for no node) :\n");
    scanf("%d",&x);
    temp->data = x;
    if(x==-1){
        return 0;
    }
    printf("Enter left Node of %d \n",x);
    temp->left = create_node();
    printf("Enter Right Node of %d \n",x);
    temp->right = create_node();
    return temp;

}

int main(){
    struct Node * root;
    root= NULL;
    root = create_node();
    printf("Preorder is :");
    preOrder(root);
    printf("\n");
    printf("Inorder is :");
    inOrder(root);
    printf("\n");
    printf("Postorder is :");
    postOrder(root);
}