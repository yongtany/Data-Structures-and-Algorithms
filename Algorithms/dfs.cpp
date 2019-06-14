#include <stdio.h>

int n, m, G[101][101];
bool visited[101];

void dfs(int k)
{
    for(int i = 1; i <=n; i++)
        if( G[k][i] && !visited[G[k][i]] )
        {
            visited[G[k][i]] = true;
            dfs(G[k][i]);
        }
    return;
}


int main()
{
    scanf("%d, %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        G[a][b] = G[b][a] = w;
    }
}

