#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
};
struct node *Head = NULL;
struct node *ctreate_node(){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}
void insert_node_last(int num){
    struct node *temp = ctreate_node();
    temp->data = num;
    if(Head==NULL){
        Head = temp;
        temp->next = NULL;
        temp->prev = NULL;
    }
    else{
        struct node *t = Head;
        while(t->next!=NULL)
            t = t->next;
        t->next = temp;
        t->next->prev = t;  // or temp->prev = t;
        t->next->next = NULL;  // or temp->next = NULL
    }
}
void insert_node_first(void){
    int num;
    struct node *ptr = ctreate_node();
    printf("Enter number : ");
    scanf("%d",&num);
    ptr->data = num;
    if(Head==NULL){
        Head = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
    }
    else{
        ptr->next = Head;
        ptr->prev = NULL;
        Head->prev = ptr;
        Head = ptr;
    }
}
void display_node(){
    struct node *temp=Head;
    if(Head==NULL){
        printf("List is empty\n");
    }
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
int main()
{
    int num,choise;
    while(1){
        printf("1. Insert node at first\n");
        printf("2. Insert node at last\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter choise : ");
        scanf("%d",&choise);
        switch (choise){
            case 1:
                insert_node_first();
                break;
            case 2:
                printf("Enter number : ");
                scanf("%d",&num);
                if(num!=0)
                    insert_node_last(num);
                break;
            case 3:
                display_node();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Enter valid choice\n");
                break;
        }
    }
}