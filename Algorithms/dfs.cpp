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

/* 인접리스트로 구현 했을 경우
void dfs(int k)
{
  for(int i=0; i < G[i].size(); i++)
    if(!visited[G[k][i].to])
    {
      visited[G[k][i].to] = true;
      dfs(G[k][i]);
    }

    return;
}
*/

/* 인접 행렬 */
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

