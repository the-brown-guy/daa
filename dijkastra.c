#include <stdio.h>
#include <time.h>
#define MAX 10

int choose(int dist[], int visit[], int n){
    int j = 1 , min = 999;
    for(int w = 1 ;  w<=n; w++)
    {
        if(dist[w]<min && visit[w]==0 ){
            j = w;
            min = dist[w];
        }
    }
    return j;
}

void dijkastra(int cost[][MAX], int dist[], int s, int n)
{
    int visit[n];
    for (int i =  1; i <= n; i++)
    {
        dist[i] = cost[s][i];
        visit[i] = 0;
    }
    dist[s] = 0;
    visit[s] = 1;

    for (int  i = 2; i <= n; i++)
    {
        int node = choose(dist, visit, n);
        visit[node] = 1;
        for (int w = 1; w <= n; w++)
        {
            if((dist[node]+cost[node][w]<dist[w]) && !visit[w])
            dist[w] = dist[node]+cost[node][w];
        }
        
    }


}

int main(){
    int n, s,cost[MAX][MAX], dist[MAX];
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d",&cost[i][j]);
        }
        
    }
    printf("Enter the source node: ");
    scanf("%d",&s);

    dijkastra(cost,dist,s,n);

    for (int  i = 1; i <= n; i++)
    {
        printf("%d to %d = %d\n",s,i,dist[i]);
    }
    
    
}