#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
struct activity
{
    int start;
    int end;
    int completion;
};
void generate_activities(struct activity *activity, int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        activity[i].start = rand()%100;
        activity[i].end = rand()%100 + activity[i].start + 1;
        activity[i].completion = activity[i].end - activity[i].start;
    }
}
void print_activities(struct activity *activity, int n)
{
    printf("SrNo.\tStart\tEnd\tCompletion\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i + 1, activity[i].start, activity[i].end, activity[i].completion);
    }
}
void sort_activities(struct activity *activity, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (activity[j].end > activity[j + 1].end)
            {
                struct activity temp = activity[j];
                activity[j] = activity[j + 1];
                activity[j + 1] = temp;
            }
        }
    }
}
// activity selection using dynammic programming
void activity_selector_dynamic(struct activity *activity, int n)
{
    int *opt = (int *)malloc(n * sizeof(int));
    int *sol = (int *)malloc(n * sizeof(int));
    opt[0] = 1;
    sol[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int max = 0;
        for (int j = 0; j < i; j++)
        {
            if (activity[j].end <= activity[i].start && opt[j] > max)
            {
                max = opt[j];
                sol[i] = j;
            }
        }
        opt[i] = max + 1;
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (opt[i] > max)
        {
            max = opt[i];
            sol[n] = i;
        }
    }
    printf("\nSelected activities (Dynamic Programming):\n");
    printf("SrNo.\tStart\tEnd\tCompletion\n");
    int i = sol[n];
    while (i != sol[i])
    {
        printf("%d\t%d\t%d\t%d\n", i + 1, activity[i].start, activity[i].end, activity[i].completion);
        i = sol[i];
    }
    printf("%d\t%d\t%d\t%d\n", i + 1, activity[i].start, activity[i].end, activity[i].completion);
}
// activity selection using greedy approach
void activity_selector_greedy(struct activity *activity, int n)
{
    int i = 0;
    printf("\nSelected activities (Greedy):\n");
    printf("SrNo.\tStart\tEnd\tCompletion\n");
    printf("%d\t%d\t%d\t%d\n", i + 1, activity[i].start, activity[i].end, activity[i].completion);
    for (int j = 1; j < n; j++)
    {
        if (activity[j].start >= activity[i].end)
        {
            printf("%d\t%d\t%d\t%d\n", j + 1, activity[j].start, activity[j].end, activity[j].completion);
            i = j;
        }
    }
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    struct activity activity[n];
    generate_activities(activity, n);
    printf("Activities generated:\n");
    print_activities(activity, n);
    sort_activities(activity, n);
    // printf("\nActivities sorted:\n");
    // print_activities(activity, n);
    //time taken by greedy approach
    clock_t start, end;
    start = clock();
    activity_selector_greedy(activity, n);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken by greedy approach: %f seconds\n", time_taken);
    //time taken by dynamic programming
    start = clock();
    activity_selector_dynamic(activity, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken by dynamic programming: %f seconds\n", time_taken);
    return 0;
}