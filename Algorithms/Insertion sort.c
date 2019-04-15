#include <stdio.h>

int main(void) {
    int i, j, temp;
    int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    for(i = 0; i < 9; i++) {
        j = i;
        while(array[j] > array[j+1]) {
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            j--;
        }
    }
    for(i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

// 데이터가 이미 거의 정렬된 상태에 한해서는 어떤 알고리즘보다도 빠르다는 특징이 있다.
// 시간 복잡도 N * (N + 1) / 2 => O(N*N)
