#include <stdio.h>
#include <limits.h>
void printParenthesis(int i, int j, int n, int *bracket, char *name)
{
    if (i == j)
    {
        printf("%c", *name);
        ++*name;
        return;
    }
    printf("(");
    printParenthesis(i, *((bracket + i * n) + j), n, bracket, name);
    printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name);
    printf(")");
}
void matrixChainOrder(int p[], int n)
{
    int m[n][n];
    int bracket[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    printf("Optimal Parenthesization is : ");
    printParenthesis(1, n - 1, n, (int *)bracket, &name);
    printf("nOptimal Cost is : %d", m[1][n - 1]);
}
// Driver code
int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    matrixChainOrder(arr, n);
    return 0;
}
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
    // print matrix a and b
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