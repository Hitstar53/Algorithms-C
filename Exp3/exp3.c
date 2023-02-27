#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
struct point
{
    int x;
    int y;
};
//generate 50 x,y coordinates randomly
void generateXY(struct point *p)
{
    // srand(time(NULL));
    FILE *fp = fopen("data.txt", "w");
    for (int i=0;i<50;i++)
    {
        p[i].x = rand() % 100;
        p[i].y = rand() % 100;
        fprintf(fp, "%d,%d\n", p[i].x, p[i].y);
    }
    fclose(fp);
}
// sort using x coordinates if equal then sort using y coordinates
void sortXY(struct point *p)
{
    int n = 50;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].x > p[j + 1].x)
            {
                struct point temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
            else if (p[j].x == p[j + 1].x)
            {
                if (p[j].y > p[j + 1].y)
                {
                    struct point temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
                }
            }
        }
    }
}
//brute force approach to find convex hull
void bruteforce(struct point *p,int n)
{
    int i, j, k;
    bool flag, flag1, flag2;
    printf("Convex Hull (BruteForce):\n");
    FILE *fp = fopen("ch1.txt", "w");
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            flag = true;
            flag1 = true;
            flag2 = true;
            for (k=0;k<n;k++)
            {
                if (k==i || k==j)
                    continue;
                int val = (p[j].y - p[i].y) * (p[k].x - p[j].x) -
                          (p[k].y - p[j].y) * (p[j].x - p[i].x);
                if (val < 0)
                    flag1 = false;
                else if (val > 0)
                    flag2 = false;
                if (!flag1 && !flag2)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                printf("(%d, %d), (%d, %d)\n", p[i].x, p[i].y, p[j].x, p[j].y);
                fprintf(fp, "%d,%d,%d,%d\n", p[i].x, p[i].y, p[j].x, p[j].y);
            }
        }
    }
    fclose(fp);
}
//find orientation of three points
int orientation(struct point p, struct point q, struct point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0)? 1: 2;
}
//find convex hull using graham scan
void grahamscan(struct point *p,int n)
{
    if (n < 3)
        return;
    int next[n];
    for (int i = 0; i < n; i++)
        next[i] = -1;
    int l = 0;
    for (int i = 1; i < n; i++)
    {
        if (p[i].x < p[l].x)
            l = i;
    }
    int p1 = l, q;
    do
    {
        q = (p1 + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (orientation(p[p1], p[i], p[q]) == 2)
                q = i;
        }
        next[p1] = q;
        p1 = q;
    } while (p1 != l);
    FILE *fp = fopen("ch2.txt", "w");
    printf("\nConvex Hull (Graham Scan):\n");
    for (int i = 0; i < n; i++)
    {
        if (next[i] != -1)
        {
            printf("(%d, %d), (%d, %d)\n", p[i].x, p[i].y, p[next[i]].x, p[next[i]].y);
            fprintf(fp, "%d,%d,%d,%d\n", p[i].x, p[i].y, p[next[i]].x, p[next[i]].y);
        }
    }
    fclose(fp);
}
// convex hull using divide and conquer
void divideConquer(struct point points[], int n)
{
    if (n < 3)
        return; // Base case
    // Find the middle point
    int mid = n / 2;
    // Recursively find the convex hulls of the left and right halves
    divideConquer(points, mid);
    divideConquer(points + mid, n - mid);
    // Merge the two convex hulls
    int i, j, k;
    i = 0, j = 0, k = 0;
    struct point leftHull[mid];
    struct point rightHull[n - mid];
    for (i = 0; i < mid; i++)
        leftHull[i] = points[i];

    for (i = mid; i < n; i++)
        rightHull[i - mid] = points[i];

    i = 0;
    while (i < mid && j < n - mid)
    {
        if (leftHull[i].x < rightHull[j].x)
            points[k++] = leftHull[i++];
        else
            points[k++] = rightHull[j++];
    }

    while (i < mid)
        points[k++] = leftHull[i++];

    while (j < n - mid)
        points[k++] = rightHull[j++];

    // Find the upper and lower hulls of the merged convex hull
    int upperHull[k], lowerHull[k];
    int upperCount = 0, lowerCount = 0;
    for (i = 0; i < k; i++)
    {
        while (upperCount >= 2 && orientation(points[upperHull[upperCount - 2]], points[upperHull[upperCount - 1]], points[i]) != 2)
            upperCount--;
        upperHull[upperCount++] = i;
    }

    for (i = k - 1; i >= 0; i--)
    {
        while (lowerCount >= 2 && orientation(points[lowerHull[lowerCount - 2]], points[lowerHull[lowerCount - 1]], points[i]) != 2)
            lowerCount--;
        lowerHull[lowerCount++] = i;
    }
    // Print the convex hull
    FILE *fp = fopen("ch3.txt", "a");
    for (i = 0; i < upperCount; i++)
    {
        printf("(%d, %d)\n", points[upperHull[i]].x, points[upperHull[i]].y);
        fprintf(fp, "%d,%d\n", points[upperHull[i]].x, points[upperHull[i]].y);
    }
    fclose(fp);
}
int main(int argc, char const *argv[])
{
    //generate 50 x and y coordinates
    struct point p[50];
    generateXY(p);
    sortXY(p);
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    bruteforce(p,50);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Brute Force: %f\n", cpu_time_used);
    start = clock();
    grahamscan(p,50);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Graham Scan: %f\n", cpu_time_used);
    start = clock();
    printf("\nConvex Hull (Divide and Conquer):\n");
    divideConquer(p,50);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Divide and Conquer: %f\n", cpu_time_used);
    return 0;
}

