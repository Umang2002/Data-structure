#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *last){
    struct node *t;
    if(last==NULL){
        printf("List is Empty");
    }
    else{
        t=last->next;
        do{
            printf("%d ",t->data);
            t=t->next;
        }
        while(t!=last->next);
    }
}
struct node *create_node(){
    struct node *c = malloc(sizeof(struct  node));
    return c;
}
struct node* add_at_beg(struct node *last, int value)
{
    struct node *n = create_node();
    n->data = value;
    // if(last==NULL){
    //     last = n;
    //     last->next=last;
    // }
    // else{
        n->next = last->next;
        last->next = n;
    // }
    return last;
}
struct node* add_at_end(struct node *last, int value)
{
    struct node *n = create_node();
    n->data = value;
    // if(last==NULL){
    //     last = n;
    //     last->next = last;
    // }
    // else{
       n->next = last->next;
       last->next = n;
       last = n;
    // }
    return last;
}
struct node *addafter(struct node *last, int value, int num)
{
    struct node *n = create_node();
    struct node *t = last->next;
    do{
        if(t->data==num){
            n->data = value;
            n->next = t->next;
            t->next = n;
            if(t==last)
                last=n;
            return last;
        }
    }
    while(t->next!=last);
    printf("%d is not in the list",num);
    return last;
}
struct node *del(struct node *last,int value)
{
    struct node *t,*p;
    if(last==NULL){
        printf("List is Empty\n");
        return last;
    }
    if(last==last->next && last->data==value){
        t=last;
        last=NULL;
        free(t);
        return last;
    }
    if(last->next->data==value){
        t=last->next;
        last->next=t->next;
        free(t);
        return last;
    }
    p=last->next;
    while(p->next!=last){
        if(p->next->data==value){
            t=p->next;
            p->next=t->next;
            free(t);
            return last;
        }
        p=p->next;
    }
    if(last->data==value){
        t=last;
        p->next=last->next;
        last=p;
        free(t);
        return last;
    }
    printf("%d is not found");
    return last;
}
struct node *addtoempty(struct node *last,int value)
{
    struct node *n = create_node();
    n->data=value;
    last=n;last->next=last;
    return last;
}
struct node *createList(struct node *last)
{
    int i,n,value;
    printf("How many values you want to enter");
    scanf("%d",&n);
    printf("Enter first value : ");
    scanf("%d",&value);
    last=addtoempty(last,value);
    for(int i=2; i<=n; i++){
        printf("Enter dat for the list : ");
        scanf("%d",&value);
        last = add_at_end(last,value);
    }
    return last;
}
int main()
{
    int choice,item,value;
    struct node *last = NULL;
    while(1){
        printf("\n1. Create List");
        printf("\n2. Display List");
        printf("\n3. Add to empty list");
        printf("\n4. Add at beginning");
        printf("\n5. Add at end");
        printf("\n6. Add after");
        printf("\n7. Delete");
        printf("\n8. Exit");

        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                last=createList(last);
                break;
            case 2:
                display(last);
                break;
            case 3:
                printf("Enter a number for the list : ");
                scanf("%d",&value);
                last=addtoempty(last,value);
                break;
            case 4:
                printf("Enter a number for the list : ");
                scanf("%d",&value);
                last=add_at_beg(last,value);
                break;
            case 5:
                printf("Enter a number for the list : ");
                scanf("%d",&value);
                last=add_at_end(last,value);
                break;
            case 6:
                printf("Enter a number for the list : ");
                scanf("%d",&value);
                printf("Enter item for after new value : ");
                scanf("%d",&item);
                last=addafter(last,value,item);
                break;
            case 7:
                printf("Enter value of element to be deleted");
                scanf("%d",&value);
                last=del(last,value);
                break;
            case 8:
            printf("Thank You ...");
            exit(0);
            default:
            printf("Enter valid choice");
        }
    }
}
