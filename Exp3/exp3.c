#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
//generate 50 x & y coordinates
void generateXY(int *x, int *y)
{
    // srand(time(NULL));
    FILE *fp = fopen("data.txt", "a");
    for (int i=0;i<50;i++)
    {
        x[i] = rand() % 100;
        y[i] = rand() % 100;
        fprintf(fp, "%d,%d\n", x[i], y[i]);
    }
    fclose(fp);
}
//convex hull with brute force approach
void convexHull(int *x,int *y)
{
    int n = 50;
    int i, j, k;
    bool flag, flag1, flag2;
    printf("The convex hull is:\n");
    FILE *fp = fopen("convexhull.txt", "a");
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
                int val = (y[j] - y[i]) * (x[k] - x[j]) -
                          (y[k] - y[j]) * (x[j] - x[i]);
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
                printf("(%d, %d), (%d, %d)\n", x[i], y[i], x[j], y[j]);
                fprintf(fp, "%d,%d,%d,%d\n", x[i], y[i], x[j], y[j]);
            }
        }
    }
    fclose(fp);
}
int main(int argc, char const *argv[])
{
    //generate 50 x and y coordinates
    int x[50], y[50];
    generateXY(x, y);
    //find the convex hull
    convexHull(x, y);
    return 0;
}
