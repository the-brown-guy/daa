#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int arr[100];
void merge(int, int, int);
void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = (high + low) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
    return;
}

void merge(int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int i = low;
    int temp[100];
    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
        {
            temp[i] = arr[left];
            left++;
        }
        else
        {
            temp[i] = arr[right];
            right++;
        }
        i++;
    }
    while (left <= mid)
    {
        temp[i] = arr[left];
        left++;
        i++;
    }

    while (right <= high)
    {
        temp[i] = arr[right];
        right++;
        i++;
    }

    for (int k = low; k <= high; k++)
    {
        arr[k] = temp[k];
    }
}

int main()
{
    int n;
    printf("Enter the number of employee: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = 1 + (rand() % 100);
    }
    printf("The generated number are: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
        printf(" ");
    }
    printf("\n");
    printf("The sorted numbers are: \n");

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
        printf(" ");
    }
}