#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 100
// Finds the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int sptSet[], int n)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
// Prints the constructed distance array
void printSolution(int dist[], int n, int graph[][V])
{
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\n", i, dist[i]);
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}
// Function that implements Dijkstra's single source shortest path algorithm for a graph represented using adjacency matrix representation
void dijkstra(int graph[][V], int src, int n)
{
    int dist[n], sptSet[n];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = 1;
        for (int v = 0; v < n; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist, n, graph);
}
int main()
{
    int n, graph[V][V], src;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    dijkstra(graph, src, n);
    return 0;
}