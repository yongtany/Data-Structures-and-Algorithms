#include <iostream>
#include <string.h>

int map[17][17];
int check[17][17];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ans;

void go(int x, int y)
{
  check[x][y] = 1;
  if(map[x][y] == 3) {
    ans = 1;
    return;
  }

  for(int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx < 16 && ny < 16 && check[x][y] == 0 && (map[x][y] == 0 || map[x][y] == 3)) {
      go(nx, ny);
    }
  }
}

int main(void) {
  int test = 10;
  while(test--) {
    int nowT, x, y;
    scanf("%d", &nowT);
    for(int i = 0; i < 16; i++) {
      for(int j = 0; j < 16; j++) {
        if(map[i][j] ==2) {
          x = i;
          y = j;
        }
      }
    }
    go(x, y);
    printf("#%d %d\n", nowT, ans);
    ans = 0;
    memset(map, 0, sizeof(map));
    memset(check, 0, sizeof(check));
  }

  return 0;
}
