#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Stack{
    int data;
    struct Stack *next;
};

// create node
struct Stack *create_node(){
    struct Stack *temp;
    temp = (struct Stack *)malloc(sizeof(struct Stack));
    return temp;
}
struct Stack *Head = NULL;

// add element at top
void push(){
    struct Stack *temp = create_node();
    int num;
    printf("Enter number : ");
    scanf("%d",&num);
    temp->data = num;
    if(Head == NULL){
        Head = temp;
        temp->next = NULL;
    }
    else{
        temp->next = Head;
        Head = temp;
    }
}

// remove top element
int pop(){
    if(Head == NULL){
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    else{
        struct Stack *temp = Head;
        Head = temp->next;
        int num = temp->data;
        free(temp);
        return num;
    }
}

// print top element
int peek(){
    if(Head==NULL){
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    return Head->data;
}

// ------> main <------ //
int main()
{
    int choice;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print top element\n");
        printf("4. Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                printf("Poped element is : %d\n",pop());
                break;
            case 3:
                printf("Top element is : %d\n",peek());
                break;
            case 4:
                printf("Thank You ...\n");
                exit(0);
                break;
            default:
                printf("Enter valid choice\n");
                break;
        }
    }
}