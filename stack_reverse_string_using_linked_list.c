#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack
{
    char data;
    struct Stack *next;
};
struct Stack *Head = NULL;
struct Stack *create_node(){
    struct Stack *temp;
    temp = (struct Stack *)malloc(sizeof(struct Stack));
    return temp;
}
void push(char c){
    struct Stack *s = create_node();
    s->data = c;
    if(Head==NULL){
        Head = s;
        s->next = NULL;
    }
    else{
        s->next = Head;
        Head = s;
    }
}
char pop(){
    struct Stack *temp = Head;
    Head = temp->next;
    char c = temp->data;
    free(temp);
    return c;
}
void reverse(char *str){
    int len = strlen(str);
    for(int i=0; i<len; i++)
        push(str[i]);
    for(int j=0; j<len; j++)
        str[j] = pop();
}
int main()
{
    char str[100];
    printf("Enter string : ");
    gets(str);
    reverse(str);
    printf("Reversed string is : %s",str);
}