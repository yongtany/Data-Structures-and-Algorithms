/*
#include <iostream>
#include <algorithm>

using namespace std;

int arr[100];
int main() {
  arr[0] = 5;
  arr[1] = 3;
  arr[2] = 1;
  for(int i = 0; i < 3; i++) {
    printf("%d", arr[i]);
  }
  printf("%\n");
  // 오름차순 정렬
  sort(arr + 0, arr + 2 + 1);
  for(int i = 0; i < 3; i++) {
    printf("%d", arr[i]);
  }
  printf("%\n");

  // 내림차순 첫번째 방법
  // 오름차순 정렬 후 뒤에서 부터 출력한다.
  for(int i = 2; i >= 0; i--) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // 내림차순 세번째 방법
  // 기존 배열에 모두 (-1)을 곱한다.
  for(int i = 0; i < 3; i++) {
    arr[i] = arr[i] * (-1);
  }
  // (-1)이 곱해진 배열을 오름차순 정렬
  sort(arr + 0, arr + 2 + 1);
  // 다시 (-1)을 곱해 원래 값으로 바꾼다.
  for(int  i = 0; i < 3; i++) {
    arr[i] = arr[i] * (-1);
  }

  for(int i = 0; i < 3; i++) {
    printf("%d", arr[i]);
  }
}
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct st {
  int t1, t2;
};
// t1 -> t2순으로 오름차순 정렬
bool comp1(const struct st &a, const struct st &b) {
  if(a.t1 == b.t1) return a.t2 < b.t2;
  else return a.t1 < b.t1;
}
// t1 -> t2순으로 내림차순 정렬
bool comp2(const struct st &a, const struct st &b) {
  if(a.t1 == b.t1) return a.t2 > b.t2;
}

int main() {
  st arr2[10];
  for(int i = 0; i < 10; i++) {
    scanf("%d %d", &arr2[i].t1, &arr2[i].t2);
  }
  // 오름차순 정렬
  sort(arr2, arr2 + 10, comp1);
  for(int i = 0; i < 10; i++) {
    printf("arr2[%d] : %d %d\n", i, arr2[i].t1, arr2[i].t2);
  }
  // 내림차순 정렬
  sort(arr2, arr2 + 10, comp2);
  for(int i = 0; i < 10; i++) {
    printf("arr2[%d] : %d %d\n", i, arr2[i].t1, arr2[i].t2);
  }
}
