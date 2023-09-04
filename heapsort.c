
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

void heapbottomup(int arr[], int n)
{
    int i, heap, v, j, k;
    for (i = n / 2; i > 0; i--)
    {
        k = i;
        v = arr[k];
        heap = FALSE;
        while (!heap && (2 * k) <= n)
        {
            j = 2 * k;
            if (j < n)
            {
                if (arr[j] < arr[j + 1])
                {
                    j = j + 1;
                }
            }
            if (v >= arr[j])
            {
                heap = TRUE;
            }
            else
            {
                arr[k] = arr[j];
                k = j;
                arr[k]=v;
            }
        }
    }
}
void heapsort(int arr[], int n)
{
    int i, temp, last = n;
    if (n <= 1)
    {
        return;
    }
    else
    {
        heapbottomup(arr, n);
        temp = arr[last];
        arr[last] = arr[1];
        arr[1] = temp;
        last--;
        heapsort(arr, last);
    }
}
int main()
{
    int h[200], n, i;
    double clk;
    clock_t starttime, endtime;
    printf("Enter the number of resumes:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        h[i] = rand() % 100;
        printf("The candidates ranks are:\t%d\n", h[i]);
    }
    starttime = clock();
    heapsort(h, n);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nThe ranks in sorted order:\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t", h[i]);
    }
    printf("\nThe run time is %f\n", clk);
    return 0;
}