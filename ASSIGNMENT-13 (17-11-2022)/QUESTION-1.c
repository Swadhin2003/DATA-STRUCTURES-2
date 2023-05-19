#include<stdio.h>
#include<stdlib.h>
#ifndef Queue_h
#define Queue_h
struct Node
{
    int data_21051948;
    struct Node *next_21051948;
} *front_21051948 = NULL, *rear_21051948 = NULL;
void enqueue(int x_21051948)
{
    struct Node *t_21051948;
    t_21051948 = (struct Node *)malloc(sizeof(struct Node));
    if (t_21051948 == NULL)
    printf("Queue is FUll\n");
    else
    {
        t_21051948->data_21051948 = x_21051948;
        t_21051948->next_21051948 = NULL;
        if (front_21051948 == NULL)
        front_21051948 = rear_21051948 = t_21051948;
        else
        {
            rear_21051948->next_21051948 = t_21051948;
            rear_21051948 = t_21051948;
        }
    }
}
int dequeue()
{
    int x_21051948 = -1;
    struct Node *t_21051948;
    if (front_21051948 == NULL)
    printf("Queue is Empty\n");
    else
    {
        x_21051948 = front_21051948->data_21051948;
        t_21051948 = front_21051948;
        front_21051948 = front_21051948->next_21051948;
        free(t_21051948);
    }
    return x_21051948;
}
int isEmpty()
{
    return front_21051948 == NULL;
}
#endif 
void BFS(int G_21051948[][7], int start_21051948, int n_21051948)
{
    int i_21051948 = start_21051948, j_21051948;
    int visited_21051948[7] = {0};
    printf("%d ", i_21051948);
    visited_21051948[i_21051948] = 1;
    enqueue(i_21051948);
    while (!isEmpty())
    {
        i_21051948 = dequeue();
        for (j_21051948 = 1; j_21051948 < n_21051948; j_21051948++)
        {
            if (G_21051948[i_21051948][j_21051948] == 1 && visited_21051948[j_21051948] == 0)
            {
                printf("%d ", j_21051948);
                visited_21051948[j_21051948] = 1;
                enqueue(j_21051948);
            }
        }
    }
}
void DFS(int G_21051948[][7], int start_21051948, int n_21051948)
{
    static int visited_21051948[7] = {0};
    int j_21051948;
    if (visited_21051948[start_21051948] == 0)
    {
        printf("%d ", start_21051948);
        visited_21051948[start_21051948] = 1;
        for (j_21051948 = 1; j_21051948 < n_21051948; j_21051948++)
        {
            if (G_21051948[start_21051948][j_21051948] == 1 && visited_21051948[j_21051948] == 0)
            DFS(G_21051948, j_21051948, n_21051948);
        }
    }
}
int main()
{
    int G_21051948[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    DFS(G_21051948, 4, 7);
    printf("\n");
    BFS(G_21051948,2,6);
    return 0;
}