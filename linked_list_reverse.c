#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *START = NULL;
struct node *create_node(){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}
void insert_element_first(int num){
    struct node *temp = create_node();
    temp->data = num;
    if(START==NULL){
        START=temp;
        temp->next = NULL;
    }
    else{
        temp->next = START;
        START = temp;
    }
}   
void view_list(){
    struct node *temp;
    if(START==NULL)
        printf("List is Empty\n");
    else{
        temp = START;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
void reverse_list(){
    struct node *prev, *current, *next;;
    prev = NULL;
    current = START;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev=current;
        current=next;
    }
    START = prev;
}
int main()
{
    int choice,number;
    while(1){
        printf("1. Insert at first\n");
        printf("2. Reverse list\n");
        printf("3. View list\n");
        printf("4. Exit\n");
        printf("Enter your coice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                while(1){
                    printf("Enter number {'0' for stop} : ");
                    scanf("%d",&number);
                    if(number!=0)
                        insert_element_first(number);
                    else
                        break;
                }
                break;
            case 2:
                reverse_list();
                break;
            case 3:
                view_list();
                break;
            case 4:
                printf("Thank you ...");
                exit(0);
                break;
            default:
                printf("Enter valid number\n");
                break;
        }
    }
}