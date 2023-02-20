#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
struct point
{
    int x;
    int y;
};
//generate 50 x and y coordinates randomly and store in array of struct
void generateXY(struct point *p)
{
    //srand(time(NULL));
    FILE *fp = fopen("datab.txt", "a");
    for (int i=0;i<50;i++)
    {
        p[i].x = rand() % 100;
        p[i].y = rand() % 100;
        fprintf(fp, "(%d,%d)\n", p[i].x, p[i].y);
    }
    fclose(fp);
    // for (int i=0;i<50;i++)
    // {
    //     printf("%d %d\n", p[i].x, p[i].y);
    // }
}
//sort using x coordinates if equal then sort using y coordinates
void sortXY(struct point *p)
{
    int n = 50;
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (p[j].x > p[j+1].x)
            {
                struct point temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
            else if (p[j].x == p[j+1].x)
            {
                if (p[j].y > p[j+1].y)
                {
                    struct point temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    //generate 50 x and y coordinates
    struct point p[50];
    generateXY(p);
    sortXY(p);
    //print the sorted array
    for (int i=0;i<50;i++)
    {
        printf("%d %d\n", p[i].x, p[i].y);
    }
    return 0;
}

