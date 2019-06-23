#include <iostream>
#include <cstring>
using namespace std;

int T, M, N, K;
int cabbage[51][51] = {0};    // 배추 밭
int dy[4] = {-1, 1, 0, 0};  // 상 하 좌 우 이동을 위한 y좌표 배열
int dx[4] = {0, 0, -1, 1};  // 상 하 좌 우 이동을 위한 x좌표 배열

void DFS(int y, int x)  // 깊이 우선 탐색을 진행하여 배추들을 모두 탐색한다.
{
  if(x < 0 || y < 0 || y >= N || x >= M) return; // 범위 제한
  if(cabbage[y][x]!=1) return;  // 아무것도 없다면
  cabbage[y][x] = 2;  // 탐색 완료

  for(int i = 0; i < 4; i++)  // 상 하 좌 우 다음 좌표로 탐색
  {
    int nextX = x + dx[i];
    int nextY = y + dy[i];
    DFS(nextY, nextX);
  }
}

int main()
{
  cin >> T;
  for(int i = 0; i < T; i++)
  {
    int cnt = 0;
    cin>>M>>N >>K;

    for(int j = 0; j < 51; j++)
      memset(cabbage[j], 0, sizeof(int)*51);  // 배열 초기화
    for(int j = 0; j < K; j++)
    {
      int x, y;
      cin>>x>>y;
      cabbage[y][x] = 1;
    }
    for(int j = 0; j < M; j++)
      for(int k = 0; k < N; k++)
        if(cabbage[k][j]==1)
          DFS(k, j), cnt++;
    cout<<cnt<<'\n';
  }

  return 0;
}
