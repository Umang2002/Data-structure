#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * prev;
    struct Node *next;
};

struct Node * last = NULL;

void insert_at_begin(int data){

    struct Node * temp,*ptr,*p;
    ptr = last;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;


    if(last==NULL){
        temp->prev = temp;
        temp->next = temp;
        last = temp;
    }else if(ptr->next =last ){
        temp->prev= last;
        temp->next = last;
        last->prev= temp;
    }else{
        temp->prev = last;
        p = last->next;
        temp->next = p;
        p ->prev = temp;
    }

}
void insert_at_end(int data){
    struct Node * temp,*ptr,*p;
    ptr = last;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;

    if(last==NULL){
        printf("List Is Empty !!!!");
    }else if(ptr->next =last ){
        temp->prev= last;
        temp->next = last;
        last->prev= temp;
        last = temp;
    }else{
        temp->prev = last;
        temp->next= last->next;
        last->next = temp;
        last = temp;
    }
}

void insert_at_pos(int pos,int data)
{
    struct Node *temp,*ptr,*p;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;

        ptr = last->next;
        for(int i=1;i<pos-1;i++){
            ptr= ptr->next;
        }
        temp->prev= ptr;
        temp->next= ptr->next;
        ptr->next->prev = temp;
        ptr->next = temp;

    }


void display_list(){
    struct Node * temp;

    if(last == NULL){
        printf("List is Empty!!!");
    }
    else if(last==last->next){
        printf("%d",last->data);
    }
    else{
        temp=last->next;
        do{
            printf("%d ",temp->data);
            temp= temp->next;
        }while(temp!=last->next);
    }
}


    int main(){
    int choice,num,val,val1,x,y,val3,pos;
  while(1){
    printf("\n1. Insert to nth position");
    printf("\n2. Insert at the begin");
    printf("\n3. Insert at the end");
    printf("\n4. Display the list");
    printf("\n5. Exit");

     printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){

            case 1 :

                printf("Enter position and data : ");
                scanf("%d %d",&pos,&num);
                insert_at_pos(pos,num);
                break;
            case 2 :
              while(1){
                printf("Enter number {'0' for stop} : ");
                scanf("%d",&val);
                if(val!=0)
                  insert_at_begin(val);
                else
                    break;
                }
                break;
            case 3 :
              while(1){
                printf("Enter number {'0' for stop} : ");
                scanf("%d",&val1);
                if(val1!=0)
                 insert_at_end(val1);
                else
                    break;
                }
                break;
            case 4 :
              display_list();
              break;
            case 5:
              printf("Thank You ...");
              exit(1);
              break;
        }
  }
}

