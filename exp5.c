#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
struct job
{
    int start;
    int end;
    int completion;
};
void generate_jobs(struct job *jobs, int n)
{
    srand(time(0));
    for (int i=0;i<n;i++)
    {
        jobs[i].start = rand()%10;
        jobs[i].end = rand()%10+jobs[i].start+1;
        jobs[i].completion = jobs[i].end - jobs[i].start;
    }
}
void print_jobs(struct job *jobs, int n)
{
    for (int i=0;i<n;i++)
    {
        printf("Job %d: %d %d %d\n", i+1, jobs[i].start, jobs[i].end, jobs[i].completion);
    }
}
void sort_jobs(struct job *jobs, int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (jobs[j].start > jobs[j+1].start)
            {
                struct job temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }
}
//job sqeuecing using dynamic programming
void job_sequencing(struct job *jobs, int n)
{
    int *table = (int *)malloc(n*sizeof(int));
    int *path = (int *)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
    {
        table[i] = jobs[i].completion;
        path[i] = i;
    }
    for (int i=1;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            if (jobs[j].end <= jobs[i].start)
            {
                if (table[i] < table[j] + jobs[i].completion)
                {
                    table[i] = table[j] + jobs[i].completion;
                    path[i] = j;
                }
            }
        }
    }
    int max = 0;
    int index = 0;
    for (int i=0;i<n;i++)
    {
        if (table[i] > max)
        {
            max = table[i];
            index = i;
        }
    }
    printf("\nThe maximum completion time is %d", max);
    printf("\nThe jobs to be selected are: ");
    while (index != path[index])
    {
        printf("%d ", index+1);
        index = path[index];
    }
    printf("%d\n", index+1);
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct job jobs[n];
    generate_jobs(jobs, n);
    printf("Jobs generated:\n");
    print_jobs(jobs, n);
    sort_jobs(jobs, n);
    printf("\nJobs sorted:\n");
    print_jobs(jobs, n);
    job_sequencing(jobs, n);
    return 0;
}
