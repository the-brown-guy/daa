#include <stdio.h>

int count, w[10], target, x[10];
void subset(int cs, int k, int r)
{
    int i;
    x[k] = 1;
    if (cs + w[k] == target)
    {
        printf("Subset solution = %d\n", ++count);
        for (i = 0; i <= k; i++)
        {
            if (x[i] == 1)
            {
                printf("%d\n", w[i]);
            }
        }
    }
    else if (cs + w[k] + w[k + 1] <= target)
    {
        subset(cs + w[k], k + 1, r - w[k]);
    }
    if ((cs + r - w[k] >= target) && (cs + w[k + 1]) <= target)
    {
        x[k] = 0;
        subset(cs, k + 1, r - w[k]);
    }
    x[k] = 0;
}

int main()
{
    int sum = 0, i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    printf("Enter the required sum: ");
    scanf("%d", &target);
    for (i = 0; i < n; i++)
    {
        sum += w[i];
    }
    if (sum < target)
    {
        printf("No solution exists.\n");
    }
    else
    {
        printf("The solution is:\n");
        count = 0;
        subset(0, 0, sum);
        if (count == 0)
        {
            printf("No solution exists.\n");
        }
    }
    return 0;
}