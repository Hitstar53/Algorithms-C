#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char mcmOrder[50];
int a = 0;
char m = 'A';
int top = -1;
//matrix struct
struct matrix
{
    int m[50][50];
    int r;
    int c;
};
//print matrix
void printMatrix(struct matrix mat)
{
    for (int i = 0; i < mat.r; i++)
    {
        for (int j = 0; j < mat.c; j++)
        {
            printf("%d\t", mat.m[i][j]);
        }
        printf("\n");
    }
}
//matrix multiplication (regular multiplication)
struct matrix matrixMultiplier(int r1, int r2, int c1, int c2, int matrixA[r1][c1], int matrixB[r2][c2])
{
    struct matrix matrixC;
    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            for (int k = 0; k < c1; ++k)
            {
                matrixC.m[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    matrixC.r = r1;
    matrixC.c = c2;
    return matrixC;
}
//generate random matrices with given random sizes
void generateMatrices()
{
    FILE *fptr;
    fptr = fopen("matrices.txt", "w");
    srand(time(0));
    for (int i = 0; i < 11; i++)
    {
        int n = rand() % 32 + 15;
        fprintf(fptr, "%d ", n);
    }
    fclose(fptr);
}
//normal order of matrix multiplication
struct matrix normalMult(struct matrix mat[10], int p[11])
{
    struct matrix finalAns;
    finalAns = matrixMultiplier(mat[0].r, mat[1].r, mat[0].c, mat[1].c, mat[0].m, mat[1].m);
    for (int i = 2; i < 10; i++)
    {
        finalAns = matrixMultiplier(finalAns.r, mat[i].r, finalAns.c, mat[i].c, finalAns.m, mat[i].m);
    }
    return finalAns;
}
//matrix chain multiplication order answer
struct matrix mcmAnswer(struct matrix m[10], int p[11])
{
    struct matrix stack[10];
    for (int i = 0; mcmOrder[i] != '\0'; i++)
    {
        if (mcmOrder[i] == '(')
        {
            continue;
        }
        if (mcmOrder[i] != ')')
        {
            stack[++top] = m[mcmOrder[i] - 'A'];
            continue;
        }
        if (mcmOrder[i] == ')')
        {
            int tempTop = top;
            struct matrix mat2 = stack[top--];
            struct matrix mat1 = stack[top--];
            struct matrix ans = matrixMultiplier(mat1.r, mat2.r, mat1.c, mat2.c, mat1.m, mat2.m);
            stack[++top] = ans;
        }
    }

    return stack[top];
}
//function to print parenthesis
void parenthesis(int x, int y, int n, int matrixk[11][11])
{
    if (x == y)
    {
        mcmOrder[a] = m;
        a++;
        m++;
        return;
    }

    mcmOrder[a++] = '(';
    parenthesis(x, matrixk[x][y], n, matrixk);
    parenthesis(matrixk[x][y] + 1, y, n, matrixk);

    mcmOrder[a++] = ')';
}
//matrix chain multiplication
void mcm(int size, int mcm[size][size], int p[size], int matrixK[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mcm[i][j] = 0;
            matrixK[i][j] = 0;
        }
    }
    int q, j;
    for (int x = 2; x < size; x++)
    {
        for (int i = 1; i < size - x + 1; i++)
        {
            j = i + x - 1;
            mcm[i][j] = __INT_MAX__;
            for (int k = i; k <= j - 1; k++)
            {
                q = mcm[i][k] + mcm[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < mcm[i][j])
                {
                    mcm[i][j] = q;
                    matrixK[i][j] = k;
                }
            }
        }
    }
    parenthesis(1, size - 1, size, matrixK);
}
int main()
{
    generateMatrices();
    FILE *fptr;
    fptr = fopen("matrices.txt", "r");
    int p[11];
    int mcmMatrix[11][11];
    int matrixK[11][11];
    for (int i = 0; i < 11; i++)
    {
        fscanf(fptr, "%d ", &p[i]);
    }
    struct matrix allMatrices[10];
    for (int i = 0; i < 10; i++)
    {
        allMatrices[i].r = p[i];
        allMatrices[i].c = p[i + 1];
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < allMatrices[i].r; j++)
        {
            for (int k = 0; k < allMatrices[i].c; k++)
            {
                allMatrices[i].m[j][k] = rand() % 2;
            }
        }
    }
    mcm(11, mcmMatrix, p, matrixK);
    //record the time taken by the normal multiplication
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    struct matrix finalAns1 = normalMult(allMatrices, p);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Final Answer (Normal):\n");
    printf("%d %d\n", finalAns1.r, finalAns1.c);
    for (int i = 0; i < finalAns1.r; i++)
    {
        for (int j = 0; j < finalAns1.c; j++)
        {
            printf("%d\t", finalAns1.m[i][j]);
        }
        printf("\n");
    }
    printf("\nTime taken by normal multiplication: %f\n", cpu_time_used);
    //record the time taken by the mcm multiplication
    start = clock();
    struct matrix finalAns2 = mcmAnswer(allMatrices, p);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nFinal Answer (MCM):\n");
    printf("%d %d\n", finalAns2.r, finalAns2.c);
    for (int i = 0; i < finalAns2.r; i++)
    {
        for (int j = 0; j < finalAns2.c; j++)
        {
            printf("%d\t", finalAns2.m[i][j]);
        }
        printf("\n");
    }
    printf("\nTime taken by mcm multiplication: %f\n", cpu_time_used);
    return 0;
}