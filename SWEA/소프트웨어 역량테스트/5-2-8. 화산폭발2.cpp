#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, M;
// 화산의 위치를 담을 벡터 S
vector <pair <int, int >> S;
//BFS시 사용할 큐
queue < pair <int, int >> que;
// MAT의 값
// -1: 파괴된 초원, 0: 초원, 1: 바리게이트, 2: 화산
int MAT[7][7];
int C_MAT[7][7];
// 상하좌우 탐색을 위한 dr, dc
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
int Answer, grass;

void bfs() {
  // 초기화
  while(!que.empty()) {
    que.pop();
  }
  // 격자판을 복사하여 계산
  for(int i = 1; i <= N; i++) {
    for(int  j =1; j <= N; j++) {
      C_MAT[i][j] = MAT[i][j];
    }
  }
  int cand = 0;
  // 화산의 위치로부터 bfs탐색 시작
  for(int i = 0; i < S.size(); i++) {
    que.push(S[i]);
  }
  while(!que.empty()) {
    int now_row = que.front().first;
    int now_col = que.front().second;
    que.pop();
    for(int i = 0; i < 4; i++) {
      int nxt_row = now_row + dr[i];
      int nxt_col = now_col + dc[i];
      if(nxt_row >= 1 && nxt_row <= N
        && nxt_col >= 1 && nxt_col <= N) {
          if(C_MAT[nxt_row][nxt_col] == 0) {
            C_MAT[nxt_row][nxt_col] = -1;
            cand++;
            que.push(make_pair(nxt_row, nxt_col));
          }
        }
    }
  }
  cand = grass - cand;
  if(Answer < cand) {
    Answer = cand;
  }
}

void dfs(int now, int cnt) {
  // 종료조건. M
  if(cnt == M) {
    bfs();
  }
  // 탐색조건
  else {
    for(int i = now; i < N * N; i++) {
      int nxt_row = (i / N) + 1;
      int nxt_col = (i % N) + 1;
      if(MAT[nxt_row][nxt_col] == 0) {
        // (nxt_row, nxt_col)에 추가 바리게이트 생성
        MAT[nxt_row][nxt_col] = 1;
        dfs(i + 1, cnt + 1);
        // 탐색이 끝나면 추가 바리게이트 제거
        MAT[nxt_row][nxt_col] = 0;
      }
    }
  }
}

int main() {
  scanf("%d", &T);
  for(int test_case = 1; test_case <= T; test_case++) {
    scanf("%d %d", &N, & M);
    // 초기화
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        MAT[i][j] = 0;
      }
    }
    S.clear();
    Answer = 0;
    grass = 0; // 최초 초원의 개수

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        scanf("%d", &MAT[i][j]);
        // 초원인 경우
        if(MAT[i][j] == 0) {
          grass ++;
        }
        // 화산인 경우
        else if(MAT[i][j] == 2) {
          S.push_back(make_pair(i, j));
        }
      }
    }
    grass = grass - M;
    dfs(0, 0);
    printf("#%d %d\n", test_case, Answer);
  }
}
