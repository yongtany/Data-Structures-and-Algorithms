/*
// 깊이 우선 탐색
void dfs(int idx, int depth) {
  // 종료조건
  if(depth == N) {
  }
  // 탐색 조건
  else {
    for(int i = -1; i <= N; i++) {
      // 기존에 방문한 정점이 아니고
      // 현재 정점과 연결된 정점인 경우만 탐색
      if(visited[i] == 0 && MAT[idx][i]) {
        // i번째 정점을 방문
        visited[i] = 1;
        dfs(i. depth + 1);
        // 탐색이 끝나면 해제
        visited[i] = 0;
      }
    }
  }
}

// 너비 우선 탐색

// 정점을 담을 큐
queue <int> que;

// 인접 배열
int MAT[1004][1004];

// i번 정점을 이미 방문한경우 visited[i] = 1
// i번 정점을 아직 방문하지 않은 경우 visited[i] = 0
int visited[1004];

// 출발지 S, 목적지 E, 정점의 수 N
int S, E, N;

void bfs() {
  // 1. 시작점 S를 큐에 넣는다.
  que.push(S);
  visited[S] = 1;
  // 5. 큐가 비어있지 않다면 반복
  while(!que.empty()) {
    // 2. 큐에서 한점을 뽑아 기준점으로 삼는다.
    int now = que.front();
    que.pop();
    // 3. 기준점이 목적지이면 종료
    if(now == E) {
      break;
    }
    // 4. 그렇지 않으면 탐색
    else {
      for(int i = 0; i <= N; i++) {
        int nxt = MAT[now][i];
        // 기존에 방문하지 않고
        // 현재 정점과 연결된 점을 탐색
        if(visited[nxt] == 0 && MAT[now][i] == 1) {
          visited[nxt] = 1;
          // 해당 지점을 큐에 넣는다.
          que.push(nxt);
        }
      }
    }
  }
}
*/
