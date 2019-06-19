#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void partition(int a[], int n)
{
  int i;
  int pl = 0;
  int pr = n - 1;
  int x = a[n / 2];
  do {
    while(a[pl] < x) pl++;
    while(a[pr] > x) pr--;
    if(pl <= pr) {
      swap(int , a[pl], a[pr]);
      pl++;
      pr--;
    }
  } while(pl <= pr);
  printf("피벗의 값은 %d입니다.\n", x);
  printf("피벗 이하의 그룹\n");
  for(i = 0; i<= pl -1; i++)
    printf("%d ", a[i]);
  putchar('\n');

  if(pl > pr + 1) {
    printf("피벗과 일치하는 그룹\n");
    for(i = pr + 1; i < pl -1; i++)
      printf("%d ", a[i]);
    putchar('\n');
  }

  printf("피벗 이상의 그룹\n");
  for(i = pr + 1; i < n; i++)
    printf("%d ", a[i]);
  putchar('\n');
}

int main(void)
{
  int i, nx;
  int *x;
  puts("배열을 나눕니다.");
  printf("요소 개수 : ");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int));
  for(i = 0; i < nx; i++) {
    printf("x[%d] : ", i);
    scanf("%d", &x[i]);
  }

  partition(x, nx);
  free(x);

  return 0;
}
