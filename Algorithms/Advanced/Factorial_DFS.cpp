#include <iostream>

int T, N;
// i번째 숫자를 이미 선택했는지 여부를 체크할 배열
// i숫자를 이미 선택한 경우 visited[i] = 1
// i숫자를 아직 선택하지 않은 경우 visited[i] = 0
int visited[7];
int Answer[7];

void dfs(int depth) {
  // 종료 조건
  if(depth == N + 1) {
    for(int i = 1; i <= N; i++) {
      printf("%d ", Answer[i]);
    }
    printf("\n");
  }

  // 탐색 조건
  else {
    for(int i = 1; i <= N; i++) {
      // 아직 선택하지 않은 숫자i를 고른다.
      if(visited[i] == 0) {
        visited[i] = 1;
        Answer[depth] = i;
        dfs(depth + 1);
        // 탐색이 끝나면 숫자 i를 선택하기 전 상황으로 원복
        visited[i] = 0;
        Answer[depth] = 0;
      }
    }
  }
}

int main() {
  scanf("%d", &T);
  for(int test_case = 1; test_case <= T; test_case++) {
    scanf("%d", &N);
    // visited배열 초기화
    for(int i = 1; i <= N; i++) {
      visited[i] = 0;
    }
    printf("#%d\n", test_case);
    dfs(1);
  }
}
