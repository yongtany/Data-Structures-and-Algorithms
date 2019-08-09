#include <stdio.h>
#include <algorithm>

using namespace std;

int T, N;
int S [10001];

// D[i][1] : 마지막에 한 칸 건너 i 지점에 도착했을 때 최대점수
// 즉, 다음번에 반드시 두 칸을 건너야 하는 경우
// i - 1번째 징검돌 -> i번째 징검돌로 이동한 경우

// D[i][2] : 마지막에 두칸 건너 i 지점에 도착했을 때 최대점수
// 즉, 다음번에 한 칸을 건너든 두 칸을 건너든 상관 없는 경우
// i - 2번째 징검돌 -> i번째 징검돌로 이동한 경우
// 시작점 -> 1, 2번째 징검돌로 이동한 경우
int D[10001][3];
int Answer;
int main() {
  scanf("%d", &T);
  for(int test_case = 1; test_case <= T; test_case++) {
    scanf("%d", &N);
    for(int i =1; i <= N; i++) {
      scanf("%d", &S[i]);
    }
    // 시작점의 누적 점수는 0
    D[0][1] = D[0][2] = 0;
    // 1번 돌 밟았을 때
    D[1][2] = S[1];
    // 2번 돌부터 N번돌 까지 탐색
    for(int  i = 2; i <= N; i++) {
      // i - 1 -> i로 이동한 경우
      D[i][1] = D[i - 1][2] + S[i];
      // i - 2 -> i로 이동한 경우
      D[i][2] = max(D[i - 2][1], D[i - 2][2]) + S[i];
    }
    Answer = max(D[N][1], D[N][2]);
    printf("#%d %d \n", test_case, Answer);
  }
}
