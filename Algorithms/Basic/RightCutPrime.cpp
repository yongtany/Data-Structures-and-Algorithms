#include <iostream>

int n, cnt;
int isprime(int x)
{
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return 0;
        return 1;
}

void solve(int num, int len)
{
    if(len == n)
    {
        if(isprime(num))
        {
            cnt++;
            printf("%d\n", num);
        }
        return;
    }
    else
    {
        if(isprime(num))
        { /* 두 번째 자릿수부터는 1, 3, 7, 9 */
            solve(num * 10 + 1, len + 1);
            solve(num * 10 + 3, len + 1);
            solve(num * 10 + 7, len + 1);
            solve(num * 10 + 9, len + 1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    /* 시작 수 는 2, 3, 5, 7 */
    solve(2, 1);
    solve(3, 1);
    solve(5, 1);
    solve(7, 1);
    printf("%d", cnt);
}
