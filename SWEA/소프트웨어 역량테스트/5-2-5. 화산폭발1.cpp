#include <iostream>
#include <vector>

using namespace std;

int T, N;

// 화산의 위치를 담을 벡터 S
vector <pair <int, int>> S;
// MAT의 값
// -1: 파괴된 초원, 0: 초원, 1: 바리게이트, 2: 화산
int MAT[101][101];
// 상하좌우 탐색을 위한 dr, dc
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
int Answer;

void dfs(int now_row, int now_col) {
  // 별다른 종료조건이 필요하지 않음
  // 탐색조건
  for(int i = 0; i < 4; i++) {
    int nxt_row = now_row + dr[i];
    int nxt_col = now_col + dc[i];
    // 다음 지점이 격자 안에 있는 경우
    if(nxt_row >= 1 && nxt_row <= N
      && nxt_col >= 1 && nxt_col <= N) {
        // 다음 지점이 초원인 경우
        if(MAT[nxt_row][nxt_col] == 0) {
          MAT[nxt_col][nxt_col] = -1;
          Answer--;
          dfs(nxt_row, nxt_col);
          // MAT[nxt_row][nxt_col]를 초기화 하지 않음
        }
      }
  }
}

int main() {
  scanf("%d", &T);
  for(int test_case = 1; test_case <= T; test_case++) {
    scanf("%d", &N);
    // 초기화
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        MAT[i][j] = 0;
      }
    }
    S.clear();
    Answer = 0;

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        scanf("%d", &MAT[i][j]);
        // 초원인 경우
        if(MAT[i][j] == 0) {
          Answer++;
        }
        // 화산인 경우
        else if(MAT[i][j] == 2) {
          S.push_back(make_pair(i, j));
        }
      }
    }
    for(int i = 0; i < S.size(); i++) {
      dfs(S[i].first, S[i].second);
    }
    printf("#%d %d\n", test_case, Answer);
  }
}
