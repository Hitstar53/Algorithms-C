#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// sum of subsets problem using backtracking
int n, x[10], w[10], d, sum = 0, flag = 0;
void sumofsubsets(int cs, int k, int r)
{
    x[k] = 1;
    if (cs + w[k] == d)
    {
        // printf("Subset: ");
        for (int i = 0; i <= k; i++)
        {
            if (x[i] == 1)
            {
                printf("%d ", w[i]);
            }
        }
        printf("\n");
        // printf("\nSum: %d\n", d);
        flag = 1;
    }
    else if (cs + w[k] + w[k + 1] <= d)
    {
        sumofsubsets(cs + w[k], k + 1, r - w[k]);
    }
    if ((cs + r - w[k] >= d) && (cs + w[k + 1] <= d))
    {
        x[k] = 0;
        sumofsubsets(cs, k + 1, r - w[k]);
    }
}
int main(int argc, char const *argv[])
{
    int i, r = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
        r += w[i];
    }
    printf("Enter the sum: ");
    scanf("%d", &d);
    for (i = 0; i < n; i++)
    {
        x[i] = 0;
    }
    printf("Subsets with sum %d:\n", d);
    sumofsubsets(0, 0, r);
    if (flag == 0)
    {
        printf("No subset found\n");
    }
    return 0;
}
