// vertex cover problem using approximation algorithm
#include <stdio.h>
#include <stdlib.h>
int n;
int vcover[100];
void cover(int adj[n][n])
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        vcover[i] = 0;
        visited[i] = 0;
    }
    // copy adj matrix to adj1
    int adj1[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj1[i][j] = adj[i][j];
    int u = 0, v = 0;
    while (1)
    {
        for (u = 0; u < n; u++)
        {
            if (visited[u] == 0)
            {
                for (v = 0; v < n; v++)
                {
                    if (adj1[u][v] == 1 && visited[v] == 0) // if edge exists and v is not visited add to cover and visited
                    {
                        vcover[u] = 1;
                        vcover[v] = 1;
                        visited[u] = 1;
                        visited[v] = 1;
                        break;
                    }
                }
            }
        }
        if (u == n || v == n)
            break;
        // remove edges incident on u and v
        for (int i = 0; i < n; i++)
        {
            adj1[u][i] = 0;
            adj1[i][u] = 0;
            adj1[v][i] = 0;
            adj1[i][v] = 0;
        }
    }
}
int main()
{
    // input graph adj matrix
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int adj[n][n];
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    cover(adj);
    printf("Vertex cover is: ");
    for (int i = 0; i < n; i++)
    {
        if (vcover[i] == 1)
            printf("%d ", i);
    }
}