#include <iostream>
#include <queue>

using namespace std;

// 정점을 담을 큐 ((row, col), cost)
queue <pair < pair <int, int>, int>> que;

// 격자( 0: 이동가능, 1: 이동 불가능)
int MAT[1001][1001];
// 동서남북 순서로 탐색할 배열
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
int T;
int N, M;
int S_r, S_c, E_r, E_c;
int Answer;
int main() {
  scanf("%d", &T);
  for(int test_case = 1; test_case <= T; test_case++) {
    // 격자 초기화
    for(int i = 1; i <= N; i++) {
      for(int  j = 1; j<= M; j++) {
        MAT[i][j] = 0;
      }
    }
    // 큐 초기화
    while(!que.empty()) {
      que.pop();
    }
    scanf("%d %d", &N, &M);
    scanf("%d %d %d %d", &S_r, &S_c, &E_r, &E_c);
    // 시작점(S_r, S_c 이동횟수0) 삽입
    que.push(make_pair(make_pair(S_r, S_c),0));
    MAT[S_r][S_c] = 1;
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
        scanf("%d", &MAT[i][j]);
      }
    }
    Answer = -1;
    while(!que.empty()) {
      int now_row = que.front().first.first;
      int now_col = que.front().first.second;
      int now_cost = que.front().second;
      que.pop();
      // 종료조건
      if(now_row == E_r && now_col == E_c) {
        Answer = now_cost;
        break;
      }
      // 탐색조건
      else {
        for(int i = 0; i < 4; i++) {
          int nxt_row = now_row + dr[i];
          int nxt_col = now_col + dc[i];
          int nxt_cost = now_cost + 1;
          // 이동지점이 격자 안에 있는 경우
          if(nxt_row >= 1 && nxt_row <= N
            && nxt_col >= 1  && nxt_col <= M) {
              // 이동지점이 이동 가능한 곳일 경우
              if(MAT[nxt_row][nxt_col] == 0) {
                MAT[nxt_row][nxt_col] = 1;
                que.push(make_pair(make_pair(nxt_row, nxt_col), nxt_cost));
              }
            }
        }
      }
    }
    printf("#%d %d\n", test_case, Answer);
  }
}
