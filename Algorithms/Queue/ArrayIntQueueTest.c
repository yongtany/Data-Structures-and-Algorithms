#include <stdio.h>
#include "ArrayIntQueue.h"

int main(void)
{
  ArrayIntQueue q;
  if(Initialize(&q, 64) == -1) {
    puts("큐 생성에 실패하였습니다.");
    return 1;
  }

  while(1) {
    int menu, x;
    printf("현재 데이터 수 : %d / %d\n", Size(&q), Capacity(&q));
    printf("(1)인큐 (2)팝 (3)피크 (4)출력 (0)종료 : ");
    scanf("%d", &menu);

    if(menu == 0) break;
    switch(menu) {
      case 1: /*-- 인큐 --*/
        printf("데이터 : ");
        scanf("%d", &x);
        if(Enque(&q, x) == -1)
          puts("\a오류 : 인큐에 실패하였습니다.");
        break;

      case 2: /*-- 디큐 --*/
        if(Deque(&q, &x) == -1)
          puts("\a오류 : 디큐에 실패하였습니다.");
        else
          printf("디큐 데이터는 %d입니다.\n", x);
        break;

      case 3: /*-- 피크 --*/
        if(Peek(&q, &x) == -1)
          puts("\a오류 : 피크에 실패하였습니다.");
        else
          printf("피크 데이터는 %d입니다.\n", x);
        break;

      case 4: /*-- 출력 --*/
        Print(&q);
        break;
    }
  }
  Terminate(&q);
  return 0;
}
