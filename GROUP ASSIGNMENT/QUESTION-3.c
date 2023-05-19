/*In a vaccination centre people make queue. But due to unavailability of space in the
same queue, people make a parallel queue (second queue following the first one), then
people make another parallel queue (third queue following the second one) and further
no queues can be made due to unavailability of space. The case can be shown
diagrammatically as follows. The arrow shows the direction in which people can be
added. The box shows the space available for waiting. The size of the three boxes is
equal where the size will be decided by the user.*/
#include <stdio.h>
#define MAX 5
int Queue[3][MAX], front[3], rear[3];
void insert(int n)
{
    if (rear[2] == MAX - 1)
    {
        printf("\nOverflow! No more space in queue is available.\n");
        return;
    }
    int i = 0;
    while (rear[i] == MAX - 1)
        i++;
    if (front[i] == -1)
        front[i]++;
    Queue[i][++rear[i]] = n;
    printf("Patient added successfully to queue.\n");
}
void qdelete()
{
    if (front[0] == -1)
    {
        printf("\nUnderflow! There is nothing in the queue at the moment.\n");
        return;
    }
    int del = Queue[0][front[0]];
    int i = front[0], curr_queue = 0;
    while (i <= rear[curr_queue] && curr_queue < 3)
    {
        if (i == MAX - 1)
        {
            if (curr_queue == 2)
            {
                rear[curr_queue]--;
                break;
            }
            else if (front[curr_queue + 1] != -1)
            {
                Queue[curr_queue][i] = Queue[curr_queue + 1][front[curr_queue + 1]];
                curr_queue++;
                i = front[curr_queue];
                continue;
            }
            else
            {
                rear[curr_queue]--;
                break;
            }
        }
        if (i != rear[curr_queue])
        {
            Queue[curr_queue][i] = Queue[curr_queue][i + 1];
        }
        else
        {
            rear[curr_queue]--;
            if (rear[curr_queue] < front[curr_queue])
                rear[curr_queue] = front[curr_queue] = -1;
            break;
        }
        i++;
    }
    printf("\nPatient number %d has been served\n", del);
}
void display()
{
    if (front[0] == -1)
    {
        printf("\nNo elements present in queue!\n");
        return;
    }
    int i = 0;
    do
    {
        printf("%sQueue: ", i == 0 ? "First " : (i == 1 ? "Second " : "Third "));
        for (int j = front[i]; j <= rear[i]; j++)
        {
            printf("\t%d", Queue[i][j]);
        }
        printf("\n");
        i++;
    } while (front[i] != -1 && i < 3);
}
int main()
{
    for (int i = 0; i < 3; i++)
        front[i] = rear[i] = -1;
    int c = 1;
    int d;
    while (c)
    {
        printf("\nMenu driven program:");
        printf("\n1-Insert element into queue.");
        printf("\n2-Delete element from queue.");
        printf("\n3-Display queue.");
        printf("\n0-Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 0:
            printf("Exited program.");
            break;
        case 1:
            printf("\nEnter patient number: ");
            scanf("%d", &d);
            insert(d);
            break;
        case 2:
            qdelete();
            break;
        case 3:
            display();
            break;
        default:
            printf("Invalid input");
        }
    }
}