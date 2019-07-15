#include <iostream>

int n, m, G[11][11], sol = 0xfffffff, chk[11];

void solve(int V, int W)
{
  if(V == n)
  {
    if(W < sol) sol = W;
      return;
  }
  for(int i = 1; i <= n; i++)
    if(!chk[i] && G[V][i])
    {
      chk[i] = 1;
      solve(i, W+G[V][i]);
      chk[i] = 0;
    }
}

int main(void)
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++)
  {
    int s, e, w;
    scanf("%d %d %d", &s, &e, &w);
    G[s][e] = G[e][s] = w;
  }
  solve(1, 0);
  printf("%d\n", sol==0xfffffff ? -1 : sol);
  return 0;
}
