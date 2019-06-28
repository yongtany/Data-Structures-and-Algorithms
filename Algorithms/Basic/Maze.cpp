#include <iostream>
#include <queue>

using namespace std;

struct VERTEX{ int a, b; };
int h, w, Sa, Sb, Ga, Gb, visited[101][101];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char M[101][101];
/*
    h : 미로 높이
    w : 미로 넓이
    Sa, Sb : 시작점 좌표
    Ga, Gb : 종료점 좌표
    visited : 각 정점까지의 거리 기록하면서 방문한지 안한지 체크
    VERTEX : 미로 한칸을 나타내는 구조체로 좌표 값 가짐
    M : 미로의 각 칸이 어떤 값으로 구성되었는지 저장하는 배열
   */

bool safe(int a, int b) // 정점이 미로 내부인지 아닌지 판단
{
  return (0 <= a && a < h) && (0 <= b && b < w);
}

void input(void)
{
  scanf("%d %d", &h, &w);
  for(int i = 0; i < h; i++)
  {
    scanf("%s", M[i]);
    for(int j = 0; j < w; j++)
      if(M[i][j] == 'S') Sa = i, Sb = j;
      else if(M[i][j] == 'G') Ga = i, Gb = j, M[i][j]='.';
  }
}

int solve(void)
{
  queue<VERTEX> Q;
  Q.push((VERTEX){Sa, Sb}), visited[Sa][Sb] = 0;
  while(!Q.empty())
  {
    VERTEX cur = Q.front(); Q.pop();
    if(cur.a == Ga && cur.b == Gb) break;

    for(int i = 0; i < 4; i++)
    {
      int a = cur.a + dx[i], b = cur.b + dy[i];
      if(safe(a, b) && !visited[a][b] && M[a][b] == '.')
      {
        visited[a][b] = visited[cur.a][cur.b]+ 1;
        Q.push((VERTEX){a, b});
      }
    }
  }

  return visited[Ga][Gb];
}


int main()
{
  input();
  printf("%d\n", solve());
}
