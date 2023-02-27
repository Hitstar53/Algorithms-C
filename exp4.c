#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void generate_matrices()
{
    //store 11 random numbers between 2 to 6 in an array
    int arr[11];
    srand(time(0));
    for (int i = 0; i < 11; i++)
    {
        arr[i] = rand() % 5 + 2;
    }
    FILE *fp;
    fp = fopen("matrices.txt", "w");
    //generate 10 matrices
    for (int i=0;i<5; i++)
    {
        int n = arr[i];
        int m = arr[i + 1];
        int a[n][m];
        int b[m][n];
        //generate random numbers for matrix a
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = rand() % 10;
            }
        }
        //generate random numbers for matrix b
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                b[i][j] = rand() % 10;
            }
        }
        //write matrix a to matrices.txt
        fprintf(fp, "%d %d\n", n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                fprintf(fp, "%d ", a[i][j]);
            }
        }
        fprintf(fp, "\n%d %d\n", m, n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fprintf(fp, "%d ", b[i][j]);
            }
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}
//matrix chain multiplication using dynamic programming approach

int main(int argc, char const *argv[])
{
    generate_matrices();
    return 0;
}
