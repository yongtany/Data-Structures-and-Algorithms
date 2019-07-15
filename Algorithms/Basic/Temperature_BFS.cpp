#include <iostream>
#include <queue>

using namespace std;

struct ELE{int v, cnt;};
queue<ELE> Q;

int main()
{
    int a, b, i;
    ELE temp;
    scanf("%d %d", &a, &b);
    Q.push({a, 0});
    while(!Q.empty())
    {
        temp = Q.front(), Q.pop();
        if(temp.v == b)
            break;
        if(temp.v < b)
        {
            Q.push({temp.v+10, temp.cnt+1});
            Q.push({temp.v+5, temp.cnt+1});
            Q.push({temp.v+1, temp.cnt+1});
        }
        else {
            Q.push({temp.v-10, temp.cnt+1});
            Q.push({temp.v-5, temp.cnt+1});
            Q.push({temp.v-1, temp.cnt+1});
        }
    }
    printf("%d", temp.cnt);
}
