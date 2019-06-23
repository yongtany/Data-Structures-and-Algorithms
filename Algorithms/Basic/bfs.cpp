#include <iostream>
#include <queue>

using namespace std;

bool visited[101];

/* 인접 행렬 */
void bfs(int k)
{
  queue<int> Q;
  Q.push(k), visited[k] = 1;
  while(!Q.empty())
  {
    int current = Q.front(); Q.pop();
    for(int i = 0; i < G[current].size(); i++)
      if(!visited[G[current][i]])
      {
        visited[G[current][i]] = 1;
        Q.push(G[current][i]);
      }
  }
}
/* 인접 리스트
void bfs(int k)
{
  queue<int> Q;
  Q.push(k), visited[k] = 1;
  while(!Q.empty())
  {
    int current=Q.front(); Q.pop();
    for(int i = 0; i< G[current].size(); i++)
      if(!visited[G[current][i]])
      {
        visited[G[current][i]] = 1;
        Q.push(G[current][i]);
      }
  }
}
*/
