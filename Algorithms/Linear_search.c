#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key)
{
    int i = 0;
    a[n] = key;
    while(1) {
        if(a[i] == key)
            break;
        i++;
    }
    return i == n ? -1 : i;
}

int main(void)
{
    int i, nx, ky, idx;
    int *x;
    puts("선형 검색(보초법)");
    printf("요소 개수 : ");
    scanf("%d", &nx);
    x = calloc(nx + 1, sizeof(int));
    for(i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("검색 값 : ");
    scanf("%d", &ky);
    idx = search(x, nx, ky);
    if(idx == -1)
        puts("검색에 실패했습니다.");
    else
        printf("%d(은)는 x[%d]에 있습니다.", ky, idx);
    free(x);

    return 0;
}
