#include<stdio.h>

void dfs(int src, int adj[][10], int n, int visit[])
{
    visit[src] = 1;
    printf("%d --> ",src);
    for (int i = 0; i < n; i++)
    {
        if (adj[src][i] && !visit[i])
        {
            dfs(i,adj,n,visit);
        }
        
    }
}

int main()
{
    int n, adj[10][10], visit[10], src;
    printf("Enter the number of cities: ");
    scanf("%d",&n);
    printf("Enter the adj matrix: \n");
    for (int i = 0; i < n; i++)
    {
        visit[i] = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&adj[i][j]);
        }
        
    }

    printf("Enter the source: ");
    scanf("%d",&src);

    dfs(src,adj,n,visit);
    
}