/*
#include <iostream>

int a1[101][101], a2[101][101];
int n, m;

void copy()
{
  int i, j;
  for(i = 1; i <= n; i++)
    for(j = 1; j <= m; j++)
      a1[i][j] = a2[i][j];
}
void fill1(int x, int y)
{
  if(x < 1 || y < 1 || x > n || y > m) return;
  if(a1[x][y] == 0)
  {
    a1[x][y] = 2;
    fill1(x+1, y);
    fill1(x-1, y);
    fill1(x, y+1);
    fill1(x, y-1);
  }
}

void fill2(int x, int y)
{
  if(x < 1 || y < 1 || x > n || y > m) return;
  if(a2[x][y] == 0)
  {
    a2[x][y] = 2;
    fill2(x+1, y);
    fill2(x-1, y);
    fill2(x, y+1);
    fill2(x, y-1);
  }
}

int check(int x, int y)
{
  int t = 0;
  if(a1[x+1][y] == 2) t++;
  if(a1[x-1][y] == 2) t++;
  if(a1[x][y+1] == 2) t++;
  if(a1[x][y-1] == 2) t++;
  return t;
}

int main()
{
  int i, j, hour = 0, count;
  scanf("%d %d", &n, &m);
  for(i = 1; i <= n; i++)
    for(j = 1; j <= m; j++)
    {
      scanf("%d", &a1[i][j]);
      a2[i][j] = a1[i][j];
    }
    fill1(1, 1);
    fill2(1, 1);

    while(1)
    {
      count = 0;
      for(i = 1; i <=n; i++)
        for(j = 1; j <=m; j++)
        {
          if(a1[i][j] == 1 && check(i, j) >= 2)
          {
            a2[i][j] = 0;
            count++;
          }
        }
        if(count == 0)
        {
          printf("%d", hour);
          break;
        }
        for(i = 1; i <= n; i++)
          for(j = 1; j <=m; j++)
            if(a1[i][j] && a2[i][j] ==0)
              fill2(i, j);
        hour++;
        copy();
    }
    return 0;
}
*/

// Solve 2
#include <iostream>

int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int h, w, S[101][101], res;

bool inside(int a, int b)
{
  return ((0 <= a && a < h) && (0 <= b && b < w));
}

bool done(void)
{
  int cnt = 0;
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++)
      if(S[i][j] == -1 || S[i][j] > 2)
        S[i][j] = 0;
      else if(S[i][j] == 2 || S[i][j] == 1)
        S[i][j] = 1, cnt++;
  return cnt == 0;
}

int solve(int a, int b)
{
  S[a][b]  = -1;
  for(int i = 0; i < 4; i++)
    if(inside(a + dx[i], b + dy[i]))
    {
      if(S[a + dx[i]][b + dy[i]] == 0)
        solve(a + dx[i], b+dy[i]);
      else if(S[a + dx[i]][b + dy[i]] > 0)
        S[a + dx[i]][b + dy[i]]++;
    }
}

int main()
{
  scanf("%d %d", &h, &w);
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++)
      scanf("%d", &S[i][j]);
  for(res = 0; !done(); res++)
    solve(0, 0);
  printf("%d", res);
  return 0;
}
