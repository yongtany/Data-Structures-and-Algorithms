#include <iostream>

int A[10][10], ans, mi, mj;
void input()
{
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            scanf("%d", &A[i][j]);
}

int solve()
{
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            if(ans < A[i][j])
            {
                ans = A[i][j];
                mi = i + 1;
                mj = j + 1;
            }
}

int main()
{
    input();
    solve();
    printf("%d\n%d %d\n", ans, mi, mj);
    return 0;
}
