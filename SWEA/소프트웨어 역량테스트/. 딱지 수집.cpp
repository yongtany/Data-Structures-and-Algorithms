#include <iostream>
#include <algorithm>

using namespace std;

int T;
int N, K, P;
int A[101];

int main() {
  scanf("%d", &T);
  for(int test_case = 1; test_case <= T; test_case++) {
    scanf("%d %d %d", &N, &K, &P);
    for(int i = 1; i <= N; i++) {
      scanf("%d", &A[i]);
    }
    // 답이 없을 경우 -1 출력
    int Answer = -1;
    // 영미가 가지고 있는 딱지의 수
    int rem = 0;
    for(int i = 1; i <= N; i++) {
      rem = rem + A[i];
      // 한번에 줄수 있는 최대한의 딱지 수
      int m = min(P, rem);
      K = K - m;
      rem = rem - m;
      if(K <= 0) {
        Answer = i;
        break;
      }
    }
    printf("#%d %d\n", test_case, Answer);
  }
}
