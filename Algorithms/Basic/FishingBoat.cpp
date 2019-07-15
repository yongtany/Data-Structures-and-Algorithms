#include <iostream>

/* 1차원 연못
int data[101], N, W, ans = 0;

int main()
{
    scanf("%d%d", &N, &W);
    for(int i = 0; i < N; i++)
        scanf("%d", data+i);

    for(int i = 0; i < N+W-1; i++)
    {
        int sum = 0;
        for(int j = 0; j < W; j++)
            sum += data[i+j];
        if(sum > ans) ans = sum;
    }

    printf("%d", ans);
}
*/

/* 2차원 연못 */
#include <iostream>

int data[101][101];
int N, M, H, W;
int res = 0;

int main()
{
    scanf("%d %d", &N, &M);
    scanf("%d %d", &H, &W);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &data[i][j]);

    for(int i = 0; i < N+W-1; i++)
    {
        for(int j = 0; j < M-W+1; j++)
        {
            int sum = 0;
            for(int a = 0; a < H; a++)
                for(int b = 0; b < W; b++)
                    sum += data[i+a][j+b];
            if(sum > res)
                res = sum;
        }
    }
    printf("%d", res);
}
