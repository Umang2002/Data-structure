#include<stdio.h>
#define N 3
int queue[N];
front=-1;
rear=-1;
void enqueue(int x)
{
    if((rear+1)%N==front)
        printf("queue is overflow");
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=x;
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=x;
    }


}
void dequeue()
{
    if(rear==-1 && front==-1)
        printf("queue is underflow");
    else if(front==rear)
    {
        printf("\n %d is Printed(deleted) from the queue :",queue[front]);

        front=-1;
        rear=-1;

    }
    else
    {
    printf("\n %d is Printed(deleted) from the queue :",queue[front]);
        front=(front+1)%N;
    }


}
void display()
{
    int i=front;
    if(rear==-1 && front==-1)
        printf("queue is underflow");
    else
    {
        while(rear!=i)
        {
            printf("%d   ",queue[i]);
            i=(i+1)%N;
        }
    }


}
void main()
{

    int x,ch,a=1,again;
    printf("\n 1.Printrequest(insertion) \n 2.CurrentJobProcessing(deletion) \n 3.SpoolRequest(display) \n enter the choice :");
       scanf("%d",&ch);

       if(ch<=0 || ch>=4)
       {
            printf("\n re-enter the value \n 1.insertion\n2.deletion\n3.display\n enter the choice :");
       scanf("%d",&ch);
       }
       while(a)
       {
  switch(ch)
  {

  case 1:
        printf("\nenter the value which you want to insert in queue :");
        scanf("%d",&x);
        enqueue(x);
        break;
  case 2:

         dequeue();
         break;
    case 3:
        printf("\your queue is\n");
         display();
         break;

    }
    printf("\n would you like to do any operation  again (1/0):");
    scanf("%d",&again);
    if(again==1)
       {
    a=1;
         printf("\n 1.Printrequest(insertion) \n 2.CurrentJobProcessing(deletion) \n 3.SpoolRequest(display) \n enter the choice :");
       scanf("%d",&ch);
       }
    else
        a=0;

       }
}

/*

 1.Printrequest(insertion)
 2.CurrentJobProcessing(deletion)
 3.SpoolRequest(display)
 enter the choice :1

enter the value which you want to insert in queue :25

 would you like to do any operation  again (1/0):1

 1.Printrequest(insertion)
 2.CurrentJobProcessing(deletion)
 3.SpoolRequest(display)
 enter the choice :1

enter the value which you want to insert in queue :26

 would you like to do any operation  again (1/0):1

 1.Printrequest(insertion)
 2.CurrentJobProcessing(deletion)
 3.SpoolRequest(display)
 enter the choice :1

enter the value which you want to insert in queue :27

 would you like to do any operation  again (1/0):1

 1.Printrequest(insertion)
 2.CurrentJobProcessing(deletion)
 3.SpoolRequest(display)
 enter the choice :1

enter the value which you want to insert in queue :28

 would you like to do any operation  again (1/0):1

 1.Printrequest(insertion)
 2.CurrentJobProcessing(deletion)
 3.SpoolRequest(display)
 enter the choice :1

enter the value which you want to insert in queue :29

 would you like to do any operation  again (1/0):1

 1.Printrequest(insertion)
 2.CurrentJobProcessing(deletion)
 3.SpoolRequest(display)
 enter the choice :2

 25 is Printed(deleted) from the queue :
 would you like to do any operation  again (1/0):1

 1.Printrequest(insertion)
 2.CurrentJobProcessing(deletion)
 3.SpoolRequest(display)
 enter the choice :1

enter the value which you want to insert in queue :30

 would you like to do any operation  again (1/0):1

 1.Printrequest(insertion)
 2.CurrentJobProcessing(deletion)
 3.SpoolRequest(display)
 enter the choice :3
your queue is
26   27   28   29
 would you like to do any operation  again (1/0):
*/

