#include<stdio.h>
#include<stdlib.h>
struct ArrayQueue
{
    int front,rear;
    int capacity;
    int *array;
};
struct ArrayQueue *create_Queue(int cap)
{
    struct ArrayQueue *Q = malloc(sizeof(struct ArrayQueue));
    if(!Q)
        return NULL;
    Q->front = -1;
    Q->rear = -1;
    Q->capacity = cap;
    Q->array = malloc(sizeof(int)*Q->capacity);
    if(!Q->array)
        return NULL;
    return Q;
}
int isEmpty(struct ArrayQueue *Q)
{
    return(Q->front==-1);
}
int isFull(struct ArrayQueue *Q)
{
    return((Q->rear+1)%(Q->capacity)==(Q->front));
}
int QueueSize(struct ArrayQueue *Q)
{
    return((Q->capacity-Q->front+Q->rear+1)%(Q->capacity));
}
void enQueue(struct ArrayQueue *Q,int data)
{
    if(isFull(Q))
        printf("Overflow\n");
    else
    {
        Q->rear = (Q->rear+1)%(Q->capacity);
        Q->array[Q->rear] = data;
        if(Q->front==-1)
            Q->front = Q->rear;
    }
}
int deQueue(struct ArrayQueue *Q)
{
    int data = -1;
    if(isEmpty(Q))
    {
        printf("Queue is Empty");
        return -1;
    }
    else
    {
        data = Q->array[Q->front];
        if(Q->front==Q->rear)
            Q->front=Q->rear=-1;
        else
            Q->front = (Q->front+1)%Q->capacity;
    }
    return data;
}
void deleteQueue(struct ArrayQueue *Q)
{
    if(Q)
    {
        if(Q->array)
            free(Q->array);
        free(Q);
    }
}
int main()
{
    int choice,number,size,d;
    struct ArrayQueue *Queue;
    printf("Enter size of Queue : ");
    scanf("%d",&size);
    Queue = create_Queue(size);
    while(1)
    {
        printf("\n1. For enter data\n");
        printf("2. For delete data\n");
        printf("3. For clear Queue\n");
        printf("4. For Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter number {'0' for stop} : ");
            scanf("%d",&number);
            while(number!=0)
            {
                printf("Enter number {'0' for stop} : ");
                scanf("%d",&number);
                if(number!=0)
                    enQueue(Queue, number);
            }
            break;
        case 2:
            d = deQueue(Queue);
            if(d!=-1)
            {
                printf("Your first element successfully deleted\n");
                printf("Your deleter element is : %d\n",d);
            }
            break;
        case 3:
            deleteQueue(Queue);
            printf("Queue is successfully deleted\n");
            break;
        case 4:
            printf("Thank You ...");
            exit(0);
            break;
        default:
            printf("Enter valid number\n");
            break;
        }
    }
}
