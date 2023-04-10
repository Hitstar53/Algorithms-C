#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
//graph data structure in c
struct edge
{
    int src;
    int dest;
    int weight;
};
struct graph
{
    int v;
    int e;
    struct edge* edges;
    int **adj;
};
//create graph
struct graph* createGraph(int v,int e)
{
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->v=v;
    g->e=e;
    g->edges=(struct edge*)malloc(e*sizeof(struct edge));
    g->adj=(int**)malloc(v*sizeof(int*));
    for(int i=0;i<v;i++)
    {
        g->adj[i]=(int*)malloc(v*sizeof(int));
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++) 
        {
            g->adj[i][j]=0;
        }
    }
    return g;
}
//add edge
void addEdge(struct graph* g,int src,int dest,int weight)
{
    g->adj[src][dest]=weight;
    g->adj[dest][src]=weight;
}
//print graph
void printGraph(struct graph* g)
{
    for(int i=0;i<g->v;i++)
    {
        for(int j=0;j<g->v;j++)
        {
            printf("%d ",g->adj[i][j]);
        }
        printf("\n");
    }
}
//dijkstra's algorithm acc. to cormen
void dijkstra(struct graph* g,int src)
{
    int dist[g->v]; //to store the shortest dist from src
    int visited[g->v]; //to keep track of visited nodes
    for(int i=0;i<g->v;i++)
    {
        dist[i]=INT_MAX; //initial dists to infinity
        visited[i]=0; //initially all nodes are unvisited
    }
    dist[src]=0; //dist of src from itself is 0
    //loop through all vertices except the src
    for(int i=0;i<g->v;i++)
    {
        int min=INT_MAX;
        int u;
        //find unvisited vertex with the min dist from src
        for(int j=0;j<g->v;j++) 
        {
            if(visited[j]==0 && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }
        visited[u] = 1; //mark the selected vertex as visited
        //update dist of unvisited neighbours of current vertex
        for(int j=0;j<g->v;j++)
        {
            if(visited[j]==0 && g->adj[u][j]!=0 && dist[u]+g->adj[u][j]<dist[j])
            {
                dist[j]=dist[u]+g->adj[u][j];
            }
        }
    }
    //printing the shortest dist from src to all vertices
    printf("Dijkstra's Algorithm\nVertex\tDist\n");
    for(int i=0;i<g->v;i++)
    {
        printf("%d\t%d\n",i,dist[i]);
    }
}
//bellman ford algorithm
void bellmanFord(struct graph* g,int src)
{
    int v = g->v;
    int e = g->e;
    int dist[v];
    //dist from src to all vertices as infinite
    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    //Relax all edges |V| - 1 times.
    for (int i=1;i<=v-1;i++)
    {
        for (int j=0;j<e;j++)
        {
            int u = g->edges[j].src;
            int v = g->edges[j].dest;
            int weight = g->edges[j].weight;
            if (dist[u]!=INT_MAX && dist[u]+weight<dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    //Check for negative-weight cycles.
    for (int i=0;i<e;i++)
    {
        int u = g->edges[i].src;
        int v = g->edges[i].dest;
        int weight = g->edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
    // printing the shortest dist from src to all vertices
    printf("BellmanFord Algorithm\nVertex\tDist\n");
    for(int i=0;i<g->v;i++)
    {
        printf("%d\t%d\n",i,dist[i]);
    }
}
int main(int argc, char const *argv[])
{
    int v,e;
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    printf("Enter the number of edges: ");
    scanf("%d",&e);
    struct graph* g = createGraph(v,e);
    printf("Enter edges: \n");
    int src,dest,weight;
    for(int i=0;i<e;i++)
    {
        printf("Enter edge %d: ",i+1);
        scanf("%d %d %d",&src,&dest,&weight);
        addEdge(g,src,dest,weight);
        g->edges[i].src=src;
        g->edges[i].dest=dest;
        g->edges[i].weight=weight;
    }
    printf("The adjacency matrix is: \n");
    printGraph(g);
    printf("\nEnter source vertex: ");
    scanf("%d",&src);
    dijkstra(g,src);
    printf("\nEnter source vertex: ");
    scanf("%d",&src);
    bellmanFord(g,src);
    return 0;
}
