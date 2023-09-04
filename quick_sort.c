#include <stdio.h>
int arr[10];
int partition(int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)      //don't forget this condition.
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}


void qsort(int low, int high)
{
    if (low < high)
    {
        int p = partition(low, high);
        qsort(low, p - 1);
        qsort(p + 1, high);
    }
}

int main()
{
    printf("Enter the 10 values of array: \n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The sorted order is: ");
    qsort(0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}