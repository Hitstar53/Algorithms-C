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
//matrix chain multiplication using dynamic programming
void load_matices()
{
    FILE *fp;
    fp = fopen("matrices.txt", "r");
    int n, m;
    fscanf(fp, "%d %d", &n, &m);
    int a[n][m];
    int b[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fscanf(fp, "%d", &a[i][j]);
        }
    }
    fscanf(fp, "%d %d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &b[i][j]);
        }
    }
    fclose(fp);
    //print matrix a and b
    printf("Matrix A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}
//multiplication of matrices
void multiply(int a[][10], int b[][10], int c[][10], int n, int m, int p)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
//multiplication of matrices using strassen's algorithm
void strassen(int a[][10], int b[][10], int c[][10], int n, int m, int p)
{

}
int main(int argc, char const *argv[])
{
    generate_matrices();
    load_matices();
    return 0;
}
