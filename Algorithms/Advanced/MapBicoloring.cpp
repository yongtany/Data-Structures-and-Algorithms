/* 인접 행렬 */
// #include <iostream>

// int n, m, G[200][200], visited[200];

// void solve(int v, int c)
// {
//   visited[v] = c;
//   int can = 1;
//   for(int i = 0; i < n; i++)
//     if(G[v][i] && visited[i] == c) can = 0;

//   if(!can)
//   {
//     visited[v] = 0;
//     return;
//   }
//   for(int i = 0; i < n; i++)
//   {
//     if(!visited[i] && G[v][i])
//     {
//       solve(i, 1);
//       solve(i, 2);
//     }
//   }
// }


// int main()
// {
//   scanf("%d %d", &n, &m);
//   for(int i = 0; i < m; i++)
//   {
//     int s, e;
//     scanf("%d %d", &s, &e);
//     G[s][e] = G[e][s] = 1;
//   }

//   solve(0, 1);
//   for(int i = 0; i < n; i++)
//     if(visited[i] == 0)
//     {
//       puts("IMPOSSIBLE");
//       return 0;
//     }
//   printf("OK");
//   return 0;
// }

/* 인접 리스트 */
#include <iostream>
#include <vector>

using namespace std;

int n, m, visited[200];
vector<int> G[200];

void solve(int v, int c)
{
  visited[v] = c;
  int can = 1;
  for(int i = 0; i < G[v].size(); i++)
    if(visited[G[v][i]] == c) can = 0;
  if(!can)
  {
    visited[v] = 0;
    return;
  }
  for(int i = 0; i < G[v].size(); i++)
  {
    if(!visited[G[v][i]])
    {
      solve(G[v][i], 1);
      solve(G[v][i], 2);
    }
  }
}

int main()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++)
  {
    int s, e;
    scanf("%d %d", &s, &e);
    G[s].push_back(e);
    G[e].push_back(s);
  }
  solve(0, 1);
  for(int i = 0; i < n; i++)
    if(visited[i] == 0)
    {
      puts("IMPOSSIBLE");
      return 0;
    }
    printf("OK");
    return 0;
}
