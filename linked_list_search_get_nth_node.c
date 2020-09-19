#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *START = NULL;
struct node *create_node(){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}
void insert_last(int num){
    struct node *temp=create_node(),*t;
    temp->data = num;
    if(START==NULL){
        START = temp;
        temp->link = NULL;
    }
    else{
        t = START;
        while(t->link!=NULL)
            t = t->link;
        t->link = temp;
        temp->link = NULL;
    }
}
int count_element(){
    int i=0;
    struct node *temp = START;
    if(START==NULL){
        return -1;
    }
    else{
        while(temp->link!=NULL){
            temp=temp->link;
            i++;
        }
        return i+1;
    }
}
void search_element(int f)
{
    int i=0;
    struct node *temp;
    if(START==NULL){
        printf("List is Empty\n");
    }
    else{
        temp = START;
        while(temp!=NULL){
            if(temp->data == f){
                printf("%d number is store in index number %d\n",f,i+1);
                break;
            }
            i++;
            temp=temp->link;
        }
    }
    if(i==count_element())
        printf("Element is not there\n");
}
void view_list(){
    struct node *temp=START;
    if(START==NULL)
        printf("List is Empty\n");
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->link;
        }
    }
    printf("\n");
}
int main()
{
    int choice,number,search;
    while(1){
        printf("1. Insert at last\n");
        printf("2. search element\n");
        printf("3. View list\n");
        printf("4. Length of List\n");
        printf("5. Exit\n");
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
                if(START==NULL)
                    printf("List is Empty\n");
                else{
                    printf("Which element you want to find : ");
                    scanf("%d",&search);
                    search_element(search);
                }
                break;
            case 3:
                view_list();
                break;
            case 4:
                printf("Length of list is : %d\n",count_element());
                break;
            case 5:
                printf("Thank you ...");
                exit(0);
                break;
            default:
                printf("Enter valid number\n");
                break;
        }
    }
}