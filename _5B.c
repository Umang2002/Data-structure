#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data,x,y,z;
    struct node *next;
}node;
node *head1,*head2,*head3;
node* creatploy(){
    node *toadd=(node*)malloc(sizeof(node));
    printf("Enter data x(power) y(power) z(power)\n");
    scanf("%d %d %d %d",&toadd->data,&toadd->x,&toadd->y,&toadd->z);
    toadd->next=NULL;
    int c;
    printf("Do you Enter more term(Enter 1 for add or 2 for end)\n");
    scanf("%d",&c);
    if(c==1){
        toadd->next=creatploy();
    }
    return toadd;
}

void display(node *head){
node *tem=head;
while(tem->next!=NULL){
    printf("%dx%dy%dz%d + ",tem->data,tem->x,tem->y,tem->z);
    tem=tem->next;
}
printf("%dx%dy%dz%d \n",tem->data,tem->x,tem->y,tem->z);
}


int com(node *head1,node *head2){
    if(head1->x>head2->x || (head1->x==head2->x && head1->y>head2->y) || 
    (head1->x==head2->x && head1->y==head2->y && head1->z>head2->z)){
        return 1;
    }
    if(head1->x==head2->x && head1->y==head2->y && head1->z==head2->z){
        return 0;
    }
    return -1;
}
node* add(node *head1,node *head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node *toadd=(node*)malloc(sizeof(node));
    int c=com(head1,head2);
    if(c==1){
       toadd->data =head1->data;
       toadd->x=head1->x;
       toadd->y=head1->y;
       toadd->z=head1->z;
       toadd->next=add(head1->next,head2);
    }
    else if(c==-1){
       toadd->data=head2->data;
       toadd->x=head2->x;
       toadd->y=head2->y;
       toadd->z=head2->z;
       toadd->next=add(head1,head2->next);
    }
    else{
       toadd->data=head2->data+head1->data;
       toadd->x=head2->x;
       toadd->y=head2->y;
       toadd->z=head2->z;
       toadd->next=add(head1->next,head2->next);
    }
    return toadd;
}

int main(){
    printf("Enter First Ploynomial:\n");
    head1=creatploy();
    printf("Enter Secound Ploynomial:\n");
    head2=creatploy();

    head3=add(head1,head2);
    printf("First ploynomial is:\n");
    display(head1);

    printf("Secound plonomial is:\n");
    display(head2);

    printf("sum is:\n");
    display(head3);
    

}