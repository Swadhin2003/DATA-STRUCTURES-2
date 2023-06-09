#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } 
        while (A[i] <= pivot);
        do
        {
            j--;
        } 
        while (A[j] > pivot);
        if (i < j)
        swap(&A[i], &A[j]);
    } 
    while (i < j);
    swap(&A[l], &A[j]);
    return j;
}
void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}
int main()
{
    int A[] = {8, 2, 7, 1, 6, 9, 4, 5, 0, 3}, n = 10, i;
    QuickSort(A, 0 ,n);
    printf("Sorted Array:");
    for (i = 0; i < 10; i++)
    printf("%d ", A[i]);
    printf("\n");
    return 0;
}