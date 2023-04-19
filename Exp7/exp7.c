#include <stdio.h>
#include <stdlib.h>
//declare variables
int n,currentSet[10],set[10],target,flag=0;
void sumofsubsets(int currentsum, int k, int r)
{
    //check if the partial sum is equal to target
    currentSet[k]=1;
    if(currentsum+set[k]==target)
    {
        //print the subset
        for (int i=0;i<=k;i++)
        {
            if (currentSet[i]==1)
            {
                printf("%d ", set[i]);
            }
        }
        printf("\n");
        flag = 1;
    }
    else if (currentsum+set[k]+set[k+1]<=target)
    {
        sumofsubsets(currentsum+set[k],k+1,r-set[k]);
    }
    if ((currentsum+r-set[k]>=target) && (currentsum+set[k+1]<=target))
    {
        currentSet[k] = 0;
        sumofsubsets(currentsum,k+1,r-set[k]);
    }
}
int main(int argc, char const *argv[])
{
    int r=0;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i=0;i<n;i++)
    {
        scanf("%d", &set[i]);
        r+=set[i];
    }
    printf("Enter the sum: ");
    scanf("%d", &target);
    for (int i=0;i<n;i++)
    {
        currentSet[i] = 0;
    }
    printf("Subsets with sum %d:\n",target);
    sumofsubsets(0,0,r);
    if (flag==0)
    {
        printf("No subset found\n");
    }
    return 0;
}
