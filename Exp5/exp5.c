#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
struct activity
{
    int start;
    int end;
    int completion;
};
void generate_activities(struct activity *activity, int n)
{
    srand(time(0));
    for (int i=0;i<n;i++)
    {
        activity[i].start = rand()%100;
        activity[i].end = rand()%100+activity[i].start+1;
        activity[i].completion = activity[i].end - activity[i].start;
    }
}
void print_activities(struct activity *activity, int n)
{
    printf("SrNo.\tStart\tEnd\tCompletion\n");
    for (int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\n", i+1, activity[i].start, activity[i].end, activity[i].completion);
    }
}
void sort_activities(struct activity *activity, int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (activity[j].end > activity[j+1].end)
            {
                struct activity temp = activity[j];
                activity[j] = activity[j+1];
                activity[j+1] = temp;
            }
        }
    }
}
//activity selection using dynammic programming
void activity_selector_dynamic(struct activity *activity, int n)
{
    int *opt = (int *)malloc(n*sizeof(int));
    int *sol = (int *)malloc(n*sizeof(int));
    opt[0] = 0;
    for (int i=1;i<n;i++)
    {
        int j=i-1;
        while (j>=0 && activity[j].end>activity[i].start)
        {
            j--;
        }
        if (j==-1)
        {
            opt[i] = activity[i].completion;
            sol[i] = -1;
        }
        else
        {
            opt[i] = activity[i].completion + opt[j];
            sol[i] = j;
        }
    }
    int max = 0;
    int max_index = 0;
    for (int i=0;i<n;i++)
    {
        if (opt[i]>max)
        {
            max = opt[i];
            max_index = i;
        }
    }
    printf("\nSelected activities (Dp):\n");
    printf("SrNo.\tStart\tEnd\tCompletion\n");
    while (max_index!=-1)
    {
        printf("%d\t%d\t%d\t%d\n", max_index+1, activity[max_index].start, activity[max_index].end, activity[max_index].completion);
        max_index = sol[max_index];
    }
}
//activity selection using greedy approach
void activity_selector_greedy(struct activity *activity, int n)
{
    int i=0;
    printf("\nSelected activities (Greedy):\n");
    printf("SrNo.\tStart\tEnd\tCompletion\n");
    printf("%d\t%d\t%d\t%d\n", i+1, activity[i].start, activity[i].end, activity[i].completion);
    for (int j=1;j<n;j++)
    {
        if (activity[j].start>=activity[i].end)
        {
            printf("%d\t%d\t%d\t%d\n", j+1, activity[j].start, activity[j].end, activity[j].completion);
            i=j;
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
    printf("\nActivities sorted:\n");
    print_activities(activity, n);
    activity_selector_greedy(activity, n);
    activity_selector_dynamic(activity, n);
    return 0;
}
