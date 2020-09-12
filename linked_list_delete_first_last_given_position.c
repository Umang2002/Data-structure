#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *START = NULL;
struct node *create_node()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}
void insert_last(int num)
{
    struct node *temp = create_node(),*t=START;
    temp->data = num;
    if(START==NULL){
        START = temp;
        temp->next = NULL;
    }
    else{
        while(t->next!=NULL)
            t=t->next;
        t->next = temp;
        temp->next=NULL;
    }
}
void delete_last()
{
    struct node *temp = START;
    if(START==NULL){
        printf("List is Empty\n");
    }
    else{
        while(temp->next->next!=NULL)
            temp=temp->next;
        free(temp->next);
        temp->next = NULL;
    }
}
void delete_first()
{
    struct node *temp = START;
    if(START==NULL){
        printf("List is Empty\n");
    }
    else{
        START = temp->next;
        free(temp);
    }
}
void delete_nth(int pos)
{
    struct node *temp = START, *t;
    int count=0;
    if(START==NULL){
        printf("List is Empty\n");
    }
    else{
        while(count!=pos-2){
            temp=temp->next;
            count++;
        }
        t=temp->next;
        temp->next=temp->next->next;
        free(t);
    }
}
void view_list(){
    struct node *test;
    test = START;
    if(START==NULL){
        printf("List is Empty");
    }
    else{
        while(test!=NULL){
            printf("%d ",test->data);
            test=test->next;
        }
    }
    printf("\n");
}
int find_length(struct node *temp){
    if(temp==NULL)
        return 0;
    return 1+find_length(temp->next);
}
void delete_list()
{
    struct node *current = START, *next;
    while(current!=NULL){
        next = current->next;
        free(current);
        current = next;
    }
    START = NULL;
}
int main()
{
    struct node *list;
    int choice,position,number,pos;
    while(1){
        printf("1. Insert at last\n");
        printf("2. delete first element\n");
        printf("3. delete nth element\n");
        printf("4. delete last element\n");
        printf("5. Delete entire list\n");
        printf("6. Find length of list\n");
        printf("7. View list\n");
        printf("8. Exit\n");
        printf("Enter your coice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                while(1){
                    printf("Enter number {'0' for stop} : ");
                    scanf("%d",&number);
                    if(number!=0)
                        insert_last(number);
                    else
                        break;
                }
                break;
            case 2:
                delete_first();
                break;
            case 3:
                printf("Enter position : ");
                scanf("%d",&pos);
                delete_nth(pos);
                break;
            case 4:
                delete_last();
                break;
            case 5:
                delete_list();
                break;
            case 6:
                list = START;
                printf("Length of list is : %d\n",find_length(list));
                break;
            case 7:
                view_list();
                break;
            case 8:
                printf("Thank you ...");
                exit(0);
                break;
            default:
                printf("Enter valid number\n");
                break;
        }
    }
}