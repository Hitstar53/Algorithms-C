#include <stdio.h>
#include <limits.h>
void matrixChainOrder(int p[], int n, int m[5][5], int s[5][5])
{
    int i, min, q;
    for (int d = 1; d < n - 1; d++)
    {
        for (int i = 1; i < n - d; i++)
        {
            int j = i + d;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}
void printOptimalParentheses(int s[5][5], int i, int j)
{
    if (i == j)
    {
        printf("A%d ", i);
    }
    else
    {
        printf("(");
        printOptimalParentheses(s, i, s[i][j]);
        printOptimalParentheses(s, s[i][j] + 1, j);
        printf(")");
    }
}
int main()
{
    int p[] = {1, 2, 3, 4, 3};
    int n = 5;
    int m[5][5] = {0};
    int s[5][5] = {0};
    matrixChainOrder(p, n, m, s);
    printf("\nMatrix s:\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix m:\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\nOptimal Parenthesization is: ");
    printOptimalParentheses(s, 1, n - 1);
    printf("\n Minimum number matrices multiplication is %d ", m[1][n - 1]);
    return 0;
}