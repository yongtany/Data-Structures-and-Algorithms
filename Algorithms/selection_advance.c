#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void selection(int a[], int n)
{
    int i, j;
    for(i = 0; i < n - 1;  i++) {
        int min = i;
        for(j = i + 1; j < n; j++)
            if(a[j] < a[min])
                min = j;
            swap(int, a[i], a[min]);
    }
}

void printArray(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++) {
        if(i == 0)
            printf("{ %d, ", a[i]);
        else if(i == n-1)
            printf("%d }\n", a[i]);
        else printf("%d, ", a[i]);
    }
}


int main(void)
{
    int i, nx;
    int *x;

    printf("배열 원소 개수 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    srand(time(NULL));

    for(i = 0; i < nx; i++) {
        x[i] = rand()%100 +1;
    }

    printArray(x, nx);

    selection(x, nx);
    puts("오름차순 정렬 하였습니다.");

    printArray(x, nx);

    return 0;
}

