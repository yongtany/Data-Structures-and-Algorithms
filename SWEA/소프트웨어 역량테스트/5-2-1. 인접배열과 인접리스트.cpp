#include <iostream>
#include <vector>

using namespace std;

int T, N, M, A, B;
int MAT[101][101];  // 인접 배열
vector <int> v_list[101]; // 인접 리스트

int main() {
  scanf("%d", &T);
  for(int test_case = 1; test_case <= T; test_case++) {
    scanf("%d %d", &N, &M);
    // 인접배열 초기화
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
        MAT[i][j] = 0;
      }
    }
    // 인접리스트 초기화
    for(int i = 1; i <= N; i++) {
      v_list[i].clear();
    }
    for(int i = 1; i <= M; i++) {
      scanf("%d %d", &A, &B);
      MAT[A][B] = 1;
      v_list[A].push_back(B);
    }
    printf("#%d\n", test_case);
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        printf("%d ", MAT[i][j]);
      }
      printf("\n");
    }
    for(int i = 1; i <= N; i++) {
      for(int j = 0; j < v_list[i].size(); j++) {
        printf("%d", v_list[i][j]);
      }
      printf("\n");
    }
  }
}
