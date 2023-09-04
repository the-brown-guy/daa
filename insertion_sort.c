#include <stdio.h>
void inser_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            arr[j] = key;
            j--;
        }
    }
}

int main()
{
    int arr[10];
    int n;
    printf("Enter the number of values: \n");
    scanf("%d",&n);
        for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    inser_sort(arr, n);
    printf("The sorted array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        printf(" ");
    }
}