#include <iostream>



/* solve 1
int n;

int solve()
{
    int cnt = 0;
    scanf("%d", &n);
    for(int a = 1; a <= n; a++)
        for(int b = a; b <= n; b++)
            for(int c = b; c <= n; c++)
                if(a + b + c == n && a + b > c)
                    cnt++;
    return cnt;


}

int main(void)
{
    printf("%d\n", solve());
}
*/

/* solve 2 */
int cnt, chk[21][21][21];

void solve(int n, int a, int b, int c)
{
  if(a+b+c==n)
  {
    if(a<=b && b<=c && a+b>c && chk[a][b][c]==0)
      cnt++;
      chk[a][b][c]=1;
      return;
  }
  solve(n, a+1, b, c);
  solve(n, a, b+1, c);
  solve(n, a, b, c+1);
}

int main(void)
{
  int n;
  scanf("%d", &n);
  solve(n, 1, 1, 1);
  printf("%d\n", cnt);
}


