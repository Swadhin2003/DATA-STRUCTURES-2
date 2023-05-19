//WAP to implement four numbers of D-queues in an array.
#include<stdio.h>
#include<conio.h>
#define MAX 16
int deque[MAX];
int left=-1, right=-1;
void insert_right(int);
void insert_left(int);
void delete_right(void);
void delete_left(void);
void display(void);
int main()
{
    int choice,d=1,x=0,y=1;
    while(d<5)
    {
        printf("For %d array:",d);
    do
    {
        printf("\n1.Insert at right ");
        printf("\n2.Insert at left ");
        printf("\n3.Delete from right ");
        printf("\n4.Delete from left ");
        printf("\n5.Display ");
        printf("\n6.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {  
            case 1:
                insert_right(y);
                break;
            case 2:
                insert_left(y);
                break;
            case 3:
                delete_right();
                break;
            case 4:
                delete_left();
                break;
            case 5:
                display();
                break;
        }
        x++;
    } while(x!=4);
    y++;
    d++;
    x=0;
    }
    getch();
    display();
    return 0;
}
void insert_right(int y)
{
    int val;
    printf("\nEnter the value to be added:");
    scanf("%d",&val);
    if(left==4*(y-1) && right==(4*y)-1 || (left==right+1) )
    {
        printf("\nOVERFLOW");
    }
    if(left==-1)        
    {
        left=0;
        right=0;
    }
    else
    {
        if(right==(4*y)-1)
            right=4*(y-1);
        else
            right=right+1;
    }
    deque[right]=val;
}
void insert_left(int y)
{
    int val;
    printf("\nEnter the value to be added:");
    scanf("%d",&val);
    if(left==4*(y-1) && right==(4*y-1) || (left==right+1) )
    {
        printf("\nOVERFLOW");
    }
    else if(left==-1)       
    {
        left=0;
        right=0;
    }
    else
    {
        if(left==4*(y-1))
            left=(4*y)-1;
        else
            left=left-1;
    }
    deque[left]=val;
}
void delete_right()
{
    if(left==-1)
    {
        printf("\nUNDERFLOW");
        return;
    }
    printf("\nThe deleted element is %d\n", deque[right]);
    if(left==right)         
    {
        left=-1;
        right=-1;
    }
    else
    {
        if(right==0)
        right=MAX-1;
        else
        right=right-1;
    }
}
void delete_left()
{
    if(left==-1)
    {
        printf("\nUNDERFLOW");
        return;
    }
    printf("\nThe deleted element is %d\n", deque[left]);
    if(left==right)          
    {
        left=-1;
        right=-1;
    }
    else
    {
        if(left==MAX-1)
            left=0;
        else
            left=left+1;
    }
}
void display()
{
    int front=left, rear=right;
    if(front==-1)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nThe elements in the queue are:\n");
    if(front<=rear)
    {
        while(front<=rear)
        {
            printf("%d\t",deque[front]);
            front++;
        }
    }
    else
    {
        while(front<=MAX-1)
        {
            printf("%d\t",deque[front]);
            front++;
        }
        front=0;
        while(front<=rear)
        {
            printf("%d\t",deque[front]);
            front++;
        }
    }
    printf("\n");
}