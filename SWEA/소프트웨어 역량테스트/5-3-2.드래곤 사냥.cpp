#include <iostream>
#include <algorithm>

using namespace std;

int T, is_Answer;
int P, N;

struct st {
  // 파워, 보너스, 드래곤 번호
  int K, B, idx;
};
struct st M[1001];
// K기준 오름차순 정렬
bool comp(const struct st &a, const struct st &b) {
  return a.K < b.K;
}

int main() {
  scanf("%d", &T);
  for(int test_case = 1; test_case <= T; test_case++) {
    scanf("%d %d", &P, &N);
    for(int i = 1; i <= N; i++) {
      scanf("%d %d", &M[i].K, &M[i].B);
      M[i].idx = i;
    }
    // 드래곤의 파워 기준 오름차순 정렬
    sort(M + 1, M + N + 1, comp);
    is_Answer = 1;
    // 정렬된 드래곤을 순서대로 검색
    for(int i = 1; i <= N; i++) {
      if(M[i].K < P) {
        P = P + M[i].B;
      }
      else {
        is_Answer = -1;
        break;
      }
    }
    if(is_Answer == -1) {
      printf("#%d -1\n", test_case);
    }
    else {
      printf("#%d ", test_case);
      for(int i = 1; i <= N; i++) {
        printf("%d ", M[i].idx);
      }
      printf("\n");
    }
  }
}
