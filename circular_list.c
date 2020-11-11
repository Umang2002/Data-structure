#include <stdio.h>
#include <stdlib.h>


struct Node {
      int data ;
      struct Node * next;
    };

struct Node * last=NULL;

void insert_in_empty(int data){

    struct Node * temp2,*ptr;
    temp2 = (struct Node *)malloc(sizeof(struct Node));
    temp2->data = data;
    last = temp2;
    temp2->next=last;
}

void insert_at_given_pos(int pos,int data){
    struct Node * temp ,*ptr;
    temp = (struct Node *) malloc(sizeof(struct Node));
    ptr=last->next;
    temp->data= data;

    for(int i=1;i<pos-1 ;i++)
      ptr=ptr->next;
      temp->next=ptr->next;
      ptr->next= temp;
}

void insert_at_begin(int data){
   struct Node * temp,*ptr;
   ptr = last;
   temp = (struct Node *)malloc(sizeof(struct Node));
   temp ->data = data;
   if(last==NULL){
       temp->next = temp;
       last = temp;
   }
   else if(temp->next == temp){
       temp->next = ptr->next;
       last->next = temp;
   }else{
       temp->next = ptr->next;
       last->next = temp;
   }
}

void insert_at_end(int data){
    struct Node * temp1,*ptr,*end;
    temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = data;
    ptr = last->next;
    end = last;
    temp1->next = ptr;
    end->next= temp1;
    last = temp1;

}

void delete_first(){
  struct Node *temp;


  if(last==NULL){
      printf("List Is Empty!!!!!");
      return;
  }
    temp = last->next;
  if(temp->next == temp){
     last = NULL;
     free(temp);

  }else{
      last->next = temp->next;
      free(temp);
  }
}

void delete_at_end(){
    struct Node * temp,*ptr,*end;

    if(last==NULL){
        printf("List Is Empty!!");
        return ;
    }
    temp = last->next;
    if(temp->next == temp){
        last==NULL;
        free(temp);
    }else{
        while(temp->next!= last){
          temp=temp->next;
        }
        ptr=temp->next;
        temp->next = ptr->next;
        last= temp;
        free(ptr);
    }
}

void delete_given_data(int data){
   struct Node * temp,*ptr;
   temp= last->next;
   while(temp->next!= last){
    if(temp->next->data == data){
        ptr= temp->next;
        temp->next= ptr->next;
        free(ptr);
    }
        temp = temp->next;
   }

}

void display_list(){
    struct Node *temp3;
    if(last==NULL){
        printf("List Is Empty!!!");
    }else{
        temp3=last->next;
        do{
            printf("%d ",temp3->data);
            temp3=temp3->next;
        }
        while(temp3!=last->next);
    }

}

int main(){
    int choice,num,val,val1,x,y,val3;;
   while(1){
    printf("\n1. Insert To Empty list");
    printf("\n2. Insert at the begin");
    printf("\n3. Insert at the end");
    printf("\n4. Display the list");
    printf("\n5. Exit");
    printf("\n6. Enter the position and data you want to insert ");
    printf("\n7. Delete the first Node");
    printf("\n8. Delete Last Node");
    printf("\n9. Delete the specific data");

    printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){

            case 1 :

                printf("Enter number : ");
                scanf("%d",&num);
                 insert_in_empty(num);
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
            case 6:
               printf("Enter the position and data :");
               scanf("%d %d",&x,&y);
               insert_at_given_pos(x,y);
               break;
            case 7 :
                delete_first();
                break;
            case 8:
                 delete_at_end();
                 break;
            case 9:
                 printf("Enter Data you Want to delete : ");
                 scanf("%d",&val3);
                 delete_given_data(val3);
                 break;
            default:
              printf("Enter valid choice");
        }
   }
}






