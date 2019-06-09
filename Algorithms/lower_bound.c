#include <stdio.h>

int n, k, A[100000001];
int solve(int s, int e)
{
    int m;
    while(e-s>0)
    {
        m = (s+e)/2;
        if(A[m] < k) s=m+1;
        else e=m;
    }
    return e + 1;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", A+i);
    scanf("%d", &k);
    printf("%d\n", solve(0, n));
    return 0;
}
