#include <iostream>

int T, N, M;
int P[3001];  // P[i] : i번째 방의 포탈
int Answer;

void dfs(int idx, int sum) {
  // 종료 조건
  if(idx == M) {
    if(sum > Answer) {
      Answer = sum;
    }
  }
  // 탐색 조건
  else {
    if(P[idx] <= M) { // 가지치기
      dfs(P[idx], sum + 1);
    }
  }
}

int main() {
  scanf("%d", &T);
  for(int test_case = 1; test_case <= T; test_case++) {
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N - 1;  i++) {
      scanf("%d", &P[i]);
    }
    // 출구를 찾지 못한다면 -1
    Answer = -1;
    // i번째 포탈은 i보다 큰 방으로 ㅇ이동하므로
    // 출구보다 큰 방번호는 살펴볼 필요가 없다.
    for(int i = 1;  i < M; i++) {
      dfs(i, 0);
    }
    printf("#%d %d \n", test_case, Answer);
  }
}
