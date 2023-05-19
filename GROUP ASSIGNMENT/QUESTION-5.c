/*Write a program to implement round robin scheduling concept using a linked list.
Each node represents a process with attributes as &lt;PID, CPU_time&gt;. A quantum time T
will be input by the user. A process will be executed (when user wants) for quantum
time T and the CPU_time will be updated with CPU_time T, and the current process
node is deleted from the beginning and added to the end of the list. If the updated
CPU_time is &lt;=0, then the process is deleted from the list. After a process is executed
for T time, the the next process in the queue is executed upon user choice. The entire
process gets completed when all process nodes are deleted.*/
#include <stdio.h>
#include <stdlib.h>
struct Process 
{
    int PID, cpuTime;
    struct Process *next;
} *first = NULL, *last = NULL;
struct Process* create( int PID, int cpuTime )
{
    struct Process* node = (struct Process*)malloc(sizeof(struct Process));
    node->cpuTime = cpuTime;
    node->PID = PID;
    node->next = NULL;
    return node;
}
void add( int PID, int cpuTime )
{
    struct Process *n = create( PID, cpuTime );
    if( first == NULL )
    {
        first = n;
        last = n;
        return;
    }
    last->next = n;
    n->next = first;
}
void execute( int T )
{
    first->cpuTime -= T;
    if( first->cpuTime <= 0 )
    {

        if( first == last )
        {
            printf("All processes have finished executing.\n");
            exit(0);
        }
        printf("Process with PID %d finished executing.\n", first->PID);
        first = first->next;
        free( last->next );
        last->next = first;
    }
    else 
    {
        last = first;
        first = first->next;
        printf("Process with PID %d has been executed for given time slice.", last->PID);
        printf("\nRemaining CPU Time: %d ms\n", last->cpuTime);
    }
}
int main()
{
    while(1)
    {
        printf("1. Add process\n2. Execute\nYour choice:");
        int in;
        scanf("%d", &in);
        if( in == 1 )
        {
            int PID, cpuTime;
            printf("Enter PID and CPU Time:");
            scanf("%d %d", &PID, &cpuTime);
            add( PID, cpuTime );
        }
        if( in == 2 )
        {
            int tSlice;
            printf("Enter time slice:");
            scanf("%d", &tSlice);
            execute( tSlice );
        }
    }
}