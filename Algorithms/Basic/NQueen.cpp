#include <iostream>

int n, ans, col[10], inc[20], dec[20]; // col : 행, inc : 대각선 /, dec : 대각선 \

void solve(int r)
{
    if(r > n)
    {
        ans++;  // 마지막 행까지 다 놓았으면 해를 추가
        return; // 백트랙
    }
    for(int i = 1; i <= n; i++) // r행에 대해서 각 열에 놓기 시도
        if(!col[i] && !inc[r+i] && !dec[n+(r-i)+1])
        {
            col[i] = inc[r+i] = dec[n+(r-i)+1] = 1; // 체크
            solve(r+1);
            col[i] = inc[r+i] = dec[n+(r-i)+1] = 0; // 백트랙 후 흔적 제거(매우 중요)
        }
}

int main()
{
    scanf("%d", &n);
    solve(1);
    printf("%d", ans);
}
