#include <iostream>

int a, b;
int res = 40;

void solve(int temp, int cnt)
{
  if(cnt > res) return;
  if(temp == b)
  {
    if(cnt < res) res = cnt;
    return;
  }
  if(temp < b) {
    solve(temp + 10, cnt + 1); solve(temp + 5, cnt + 1); solve(temp + 1, cnt +1);
  }
  else {
    solve(temp - 10, cnt + 1); solve(temp - 5, cnt + 1); solve(temp - 1, cnt +1);
  }
}

int main(void)
{
  scanf("%d %d", &a, &b);
  solve(a, 0);
  printf("%d", res);
  return 0;
}
