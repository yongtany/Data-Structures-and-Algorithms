#include <iostream>

int T, N, M;
int Answer;
int visited[11];
int MAT[11][11];

// 현재 방문중인 정점 번호, 현재까지 누적된 통행료, 방문한 도시 수
void dfs(int idx, int cost, int cnt) {
    // 모든 도시를 전부 방문했을 때
    if(cnt == N) {
        // 시작점으로 돌아갈 길이 있을 경우만
        if(MAT[idx][M] != 0) {
            // 기존 답보다 새로운 비용이 더 적게 든다면
            if(Answer == -1 || Answer > cost + MAT[idx][M]) {
                Answer = cost + MAT[idx][M];
            }
        }
    }
    else {
        for(int i = 0; i <= N; i++) {
            // 방문한 적이 없고, 길이 있는 도시만 탐색
            if(visited[i] == 0 && MAT[idx][i] != 0) {
                // 가지치기. 기존 정답보다 누적비용이 작을 경우만 탐색
                if((Answer == -1 || Answer > cost + MAT[idx][i])) {
                    visited[i] = 1;
                    dfs(i, cost + MAT[idx][i], cnt + 1);
                    visited[i] = 0;
                }
            }
        }
    }
}

int main() {
    scanf("%d", T);
    for(int test_case = 1; test_case <= T; test_case ++) {
        scanf("%d %d", &N, &M);
        // 초기화
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                MAT[i][j] = 0;
            }
        }
        for(int i = 1; i <= N; i++) {
            visited[i] = 0;
        }
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                scanf("%d", &MAT[i][j]);
            }
        }
        Answer = -1;
        visited[M] = 1;
        // DFS 탐색(위치, 비용, 현재까지 방문한 도시의 도시의 수)
        // 시작점: 0, 비용: 0, 방문한 도시수: 1
        dfs(M, 0, 1);
        printf("#%d %d\n", test_case, Answer);
    }
}
