#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n)
{
    int i;
    int max = a[0];
    for(i = 0; i < n; i++)
        if(a[i] > max) max = a[i];
    return max;
}

int main(void) {
    int i;
    int *height;
    int number;
    printf("사람수 : ");
    scanf("%d", &number);
    height = calloc(number, sizeof(int));
    srand(time(NULL));
    printf("%d명의 사람의 키를 입력하세요.\n", number);
    for(i = 0; i < number; i++) {
        height[i] = 150 + rand()% 40;
        printf("height[%d] = %d\n", i, height[i]);
    }
    printf("가장 키큰 사람은 %dcm 입니다.", maxof(height, number));
    free(height);
    return 0;
}
