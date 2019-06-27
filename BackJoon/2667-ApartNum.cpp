#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int map[25][25];  // 정사각형 모양의 지도
int size[323];    // (n*n/2 + 1) 각 단지 집 수
int cnt;          // 단지의 개수 및 번호
int d[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

bool isInside(int a, int b) {
    return (a >= 0 && a < n) && (b >= 0 && b < n);
}

void bfs(int a, int b, int mark) {  // [a, b] 좌표, cnt 단지의 번호

    queue<pair<int, int> > q;
    q.push(pair<int, int>(a, b));   // 좌표 넣고
    map[a][b] = mark;               // 단지 번호 마킹

    while(!q.empty()) {           // queue가 비지 않은 동안
        pair<int, int> p;
        int y = p.first = q.front().first;
        int x = p.second = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {  // up, down, left, right 검사
            if(isInside(y + d[i][0], x + d[i][1]) && map[y + d[i][0]][x + d[i][1]] == 1) {
                bfs(y + d[i][0], x + d[i][1], mark);
            }
        }
    }
}

void Solution(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 1) {
                bfs(i, j, cnt + 2);
                cnt++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 0) continue;

            size[map[i][j]-2]++;
        }
    }
}

void Print() {
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {
        printf("%d\n", size[i]);
    }
}

int main(void) {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    Solution(n);

    sort(size, size+cnt);

    Print();

    return 0;
}
