#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node *START = NULL;
struct node *create_node(){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}
void Insert_at_first(int num)
{
    struct node *temp = create_node();
    temp->data = num;
    if(START==NULL){
        START = temp;
        temp->next = NULL;
    }
    else{
        temp->next = START;
        START = temp;
    }
}
void View_list(){
    struct node *temp = START;
    if(START==NULL){
        printf("List is Empty \n");
    }
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
int main(){
    int choice,number;
    while(1){
        printf("1. Insert at first\n");
        printf("2. View list\n");
        printf("3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                while(1){
                printf("Enter number {'0' for stop} : ");
                scanf("%d",&number);
                if(number!=0)
                    Insert_at_first(number);
                else
                    break;
                }
                break;
            case 2:
                View_list();
                break;
            case 3:
                printf("Thank you ...");
                exit(1);
                break;
            default:
                printf("Enter valid choice");
                break;
        }
    }
}