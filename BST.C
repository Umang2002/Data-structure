#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * Delete(struct Node *root,int data){
    
    struct Node * temp = root;
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left,data);
    else if(data > root->data) root->right = Delete(root->right,data);
    else
    {
      
    } 
}



int findMin(struct Node * root){
    struct Node * temp;
    temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp->data;
}

int findMax(struct Node * root){
    struct Node * temp;
    temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp->data;
}

struct Node * create_new_node(int data){
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp-> left = NULL;
    temp->right = NULL;
    return temp;
};

struct Node * Insert(struct Node * root,int data){
    if(root == NULL){
        root = create_new_node(data);
    }else if(data <= root->data){
        root->left = Insert(root->left,data);
    }else{
        root->right=Insert(root->right,data);
    }
    return root;
}

int Search_Data(struct Node * root,int data){
    if(root==NULL) return 0;
    else if(root->data == data) return 1;
    else if(data <= root->data) return Search_Data(root->left ,data);
    else return Search_Data(root->right,data);
}


int main(){
     struct Node * root = NULL; 
     int choice,min,max;
   
     root = Insert(root,20);
      Insert(root,40);
      Insert(root,12);
      Insert(root,30);
      Insert(root,15);
      Insert(root,23);
    while(1){ 
    printf("\n################### Binary Search Tree ##################");
    printf("\n1. Search Operation: ");
    printf("\n2. Find Minimum :");
    printf("\n3. Find Maximum :");
    printf("\n Enter Your Choice:");
    scanf("%d",&choice);

    switch(choice){
        case 1:
             int n; 
             printf("Enter number to be searched: \n");
            scanf("%d", &n);
            if (Search_Data(root, n) == 1)
            {
                printf("Found\n");
            }
            else
            {
                printf("Not Found\n");
            }
            break;
        case 2:
            min = findMin(root);
            printf("Minimum out of this is : %d",min);
            break;
        case 3:
           max = findMax(root);
           printf("Maximum out of this is: %d",max);
           break;
           }
    }
  return 0;
}

