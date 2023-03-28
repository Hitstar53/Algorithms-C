#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//stack implementation
struct stack
{
    int top;
    int capacity;
    int *array;
};
struct stack *createStack(int capacity)
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(struct stack *stack)
{
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct stack *stack)
{
    return stack->top == -1;
}
void push(struct stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
int pop(struct stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}
int peek(struct stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}
void generate_matrices(int arr[])
{
    // store 11 random numbers between 2 to 6 in array
    srand(time(0));
    for (int i = 0; i < 11; i++)
    {
        arr[i] = rand() % 5 + 2;
    }
    FILE *fp;
    fp = fopen("matrices.txt", "w");
    // generate 10 matrices
    for (int i = 0; i < 5; i++)
    {
        int n = arr[i];
        int m = arr[i + 1];
        int a[n][m];
        int b[m][n];
        // generate random numbers for matrix a
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = rand() % 10;
            }
        }
        // generate random numbers for matrix b
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                b[i][j] = rand() % 10;
            }
        }
        // write matrix a to matrices.txt
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
        fprintf(fp, "\n");
    }
    fclose(fp);
}
// print paranthesis and save to stack
struct stack *printParenthesis(int i, int j, int n, int *bracket, char *name, struct stack *optimal)
{
    if (i == j)
    {
        printf("%c", *name);
        push(optimal, *name);
        ++*name;
        return optimal;
    }
    printf("(");
    push(optimal, '(');
    optimal = printParenthesis(i, *((bracket + i * n) + j), n, bracket, name, optimal);
    optimal = printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name, optimal);
    printf(")");
    push(optimal, ')');
    return optimal;
}
// mcm using dp
void matrixChainOrder(int p[], int n, struct stack *optimal)
{
    int m[n][n];
    int bracket[n][n];
    int c = 0;
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
    printf("\nOptimal Parenthesization is: ");
    printParenthesis(1, n - 1, n, (int *)bracket, &name, optimal);
    printf("\nOptimal Cost is: %d", m[1][n - 1]);
}
// multiplication of matrices
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
int main(int argc, char const *argv[])
{
    int orders[11];
    struct stack *optimal = createStack(30);
    generate_matrices(orders);
    matrixChainOrder(orders, 11, optimal);
    //print optimal
    printf("\nOrder of multiplication: ");
    for (int i=0;i<30;i++)
    {
        printf("%c",optimal->array[i]);
    }
    //multiply matrices according to stack and print result

    return 0;
}
