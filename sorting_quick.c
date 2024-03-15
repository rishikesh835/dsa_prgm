#include <stdio.h>
#include <stdlib.h>
void print(int a[], int n)
{
    for (int iter = 0; iter < n; iter++)
    {
        printf("%d ", a[iter]);
    }
}
void input(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
int partition(int *a, int low, int high)
{
    int pivot = a[low], temp;
    int i = low + 1;
    int j = high;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    // swap a[low] & a[j]
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
void quick_sort(int *a, int low, int high)
{
    int PartitionIndex;
    if (low < high)
    {
        PartitionIndex = partition(a, low, high);
        quick_sort(a, low, PartitionIndex - 1);
        quick_sort(a, PartitionIndex + 1, high);
    }
}
int main()
{
    int *a;
    int n;
    printf("enter the size of array\n");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    input(a, n);
    printf("array before sorting\n");
    print(a, n);
    quick_sort(a, 0, n - 1);
    printf("\narray after sorting\n");
    print(a, n);
    return 0;
}