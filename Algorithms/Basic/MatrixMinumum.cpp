#include<iostream>

int m[11][11];
int col_check[11];
int n, min_sol = 0x7fffffff;

void input(void)
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &m[i][j]);
}

void solve(int row, int score)
{
  if(row == n)
  {
    if(score < min_sol)
      min_sol = score;
    return;
  }

  for(int i = 0; i < n; i++)
  {
    if(col_check[i] == 0)
    {
      col_check[i] = 1;
      solve(row + 1, score + m[row][i]);
      col_check[i] = 0;
    }
  }
  return;
}

int main()
{
  input();
  solve(0, 0);
  printf("%d", min_sol);
  return 0;
}
