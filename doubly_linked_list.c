#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
};
struct node *Head = NULL;

// create node
struct node *ctreate_node(){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}

// insert node at last
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

// insert node at first
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

// display list
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

// delete node from last
void delete_last_node(){
    struct node *ptr = Head;
    if(Head==NULL){
        printf("list is empty\n");
    }
    else if(ptr->next == NULL){
        Head = NULL;
        free(ptr);
    }
    else{
        while(ptr->next!=NULL)
            ptr=ptr->next;
        
        ptr->prev->next = NULL;
        free(ptr);
    }
}

//delete node from first
void delete_first_node(){
    struct node *ptr = Head;
    if(Head==NULL){
        printf("List is empty\n");
    }
    else if(ptr->next==NULL){
        Head = NULL;
        free(ptr);
    }
    else{
        Head = ptr->next;
        ptr->next->prev = NULL;
        free(ptr);
    }
}

// ----- main ----- //
int main()
{
    int num,choise;
    while(1){
        printf("1. Insert node at first\n");
        printf("2. Insert node at last\n");
        printf("3. Delete first node\n");
        printf("4. Delete last node\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
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
                delete_first_node();
                break;
            case 4:
                delete_last_node();
                break;
            case 5:
                display_node();
                break;
            case 6:
                printf("Thank You ...");
                exit(0);
                break;
            default:
                printf("Enter valid choice\n");
                break;
        }
    }
}