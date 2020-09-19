#include<stdlib.h>
#include<stdio.h>
#define MAX_SIZE 100
int Stack[MAX_SIZE];
int top=-1;
void push(){
    int num;
    if(top==MAX_SIZE-1){
        printf("Stack is Full\n");
        return;
    }
    printf("Enter number : ");
    scanf("%d",&num);
    Stack[++top] = num;
}
int pop(){
    if(!(top==-1))
        return Stack[top--];
    printf("Stack is Empty\n");
}
int top_element(){
    if(!(top==-1))
        return Stack[top];
    printf("Stack is Empty\n");
}
int main()
{
    int choice;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top element\n");
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
                printf("Top element is : %d\n",top_element());
                break;
            case 4:
                printf("Thank You ...");
                exit(0);
                break;
            default:
                printf("Enter valid choice\n");
                break;
        }
    }
}